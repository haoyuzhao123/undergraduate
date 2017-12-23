package decaf.translate;

import java.util.Stack;

import decaf.symbol.Class;
import decaf.tree.Tree;
import decaf.backend.OffsetCounter;
import decaf.machdesc.Intrinsic;
import decaf.symbol.Variable;
import decaf.tac.Label;
import decaf.tac.Temp;
import decaf.type.BaseType;
import decaf.type.ClassType;

import decaf.tac.Tac;

public class TransPass2 extends Tree.Visitor {

	private Translater tr;

	private Temp currentThis;

	//add SUPER
	private Class currentClass;
	//end SUPER

	private Stack<Label> loopExits;

	public TransPass2(Translater tr) {
		this.tr = tr;
		loopExits = new Stack<Label>();
	}

	@Override
	public void visitClassDef(Tree.ClassDef classDef) {
		//add SUPER
		currentClass = classDef.symbol;
		//end SUPER
		for (Tree f : classDef.fields) {
			f.accept(this);
		}
	}

	@Override
	public void visitMethodDef(Tree.MethodDef funcDefn) {
		if (!funcDefn.statik) {
			currentThis = ((Variable) funcDefn.symbol.getAssociatedScope()
					.lookup("this")).getTemp();
		}
		tr.beginFunc(funcDefn.symbol);
		funcDefn.body.accept(this);
		tr.endFunc();
		currentThis = null;
	}

	@Override
	public void visitTopLevel(Tree.TopLevel program) {
		for (Tree.ClassDef cd : program.classes) {
			cd.accept(this);
		}
	}

	@Override
	public void visitVarDef(Tree.VarDef varDef) {
		if (varDef.symbol.isLocalVar()) {
			//add COMPLEX
			if (varDef.symbol.getType().equal(BaseType.COMPLEX)) {
				/*
				Temp t = Temp.createTempI4();
				Temp len = tr.genLoadImm4(2);
				Temp add = tr.genNewArray(len);
				tr.genAssign(t,add);
				t.sym = varDef.symbol;
				varDef.symbol.setTemp(t);
				*/
				Temp t1 = Temp.createTempI4();
				Temp t2 = Temp.createTempI4();
				t1.sym = varDef.symbol;
				t2.sym = varDef.symbol;
				varDef.symbol.setRetemp(t1);
				varDef.symbol.setImtemp(t2);
			} else {
				Temp t = Temp.createTempI4();
				t.sym = varDef.symbol;
				varDef.symbol.setTemp(t);
			}
			//end COMPLEX
		}
	}

	@Override
	public void visitBinary(Tree.Binary expr) {
		expr.left.accept(this);
		expr.right.accept(this);
		switch (expr.tag) {
		case Tree.PLUS:
			//add COMPLEX
				if(expr.left.type.equal(BaseType.COMPLEX)
						|| expr.right.type.equal(BaseType.COMPLEX)) {
					if (!expr.left.type.equal(BaseType.COMPLEX)) {
						expr.left.reval = tr.genLoadImm4(0);
						tr.genAssign(expr.left.reval,expr.left.val);
						expr.left.imval = tr.genLoadImm4(0);
					}
					if (!expr.right.type.equal(BaseType.COMPLEX)) {
						expr.right.reval = tr.genLoadImm4(0);
						tr.genAssign(expr.right.reval,expr.right.val);
						expr.right.imval = tr.genLoadImm4(0);
					}
					expr.imval = tr.genAdd(expr.left.imval, expr.right.imval);
					expr.reval = tr.genAdd(expr.left.reval, expr.right.reval);
				} else {
					expr.val = tr.genAdd(expr.left.val, expr.right.val);
				}
			//end COMPLEX
			break;
		case Tree.MINUS:
			expr.val = tr.genSub(expr.left.val, expr.right.val);
			break;
		case Tree.MUL:
			//add COMPLEX
			if(expr.left.type.equal(BaseType.COMPLEX)
					|| expr.right.type.equal(BaseType.COMPLEX)) {
				if (!expr.left.type.equal(BaseType.COMPLEX)) {
					expr.left.reval = tr.genLoadImm4(0);
					tr.genAssign(expr.left.reval,expr.left.val);
					expr.left.imval = tr.genLoadImm4(0);
				}
				if (!expr.right.type.equal(BaseType.COMPLEX)) {
					expr.right.reval = tr.genLoadImm4(0);
					tr.genAssign(expr.right.reval,expr.right.val);
					expr.right.imval = tr.genLoadImm4(0);
				}
				Temp t1 = tr.genMul(expr.left.reval, expr.right.reval);
				Temp t2 = tr.genMul(expr.left.imval, expr.right.imval);
				Temp t3 = tr.genMul(expr.left.reval, expr.right.imval);
				Temp t4 = tr.genMul(expr.left.imval, expr.right.reval);
				expr.imval = tr.genAdd(t3, t4);
				expr.reval = tr.genSub(t1, t2);
			} else {
				expr.val = tr.genMul(expr.left.val, expr.right.val);
			}
			//end COMPLEX
			break;
		case Tree.DIV:
			//add DIVISION BY ZERO
			tr.genCheckNum(expr.right.val);
			//END DIVISION BY ZERO
			expr.val = tr.genDiv(expr.left.val, expr.right.val);
			break;
		case Tree.MOD:
			//add DIVISION BY ZERO
			tr.genCheckNum(expr.right.val);
			//END DIVISION BY ZERO
			expr.val = tr.genMod(expr.left.val, expr.right.val);
			break;
		case Tree.AND:
			expr.val = tr.genLAnd(expr.left.val, expr.right.val);
			break;
		case Tree.OR:
			expr.val = tr.genLOr(expr.left.val, expr.right.val);
			break;
		case Tree.LT:
			expr.val = tr.genLes(expr.left.val, expr.right.val);
			break;
		case Tree.LE:
			expr.val = tr.genLeq(expr.left.val, expr.right.val);
			break;
		case Tree.GT:
			expr.val = tr.genGtr(expr.left.val, expr.right.val);
			break;
		case Tree.GE:
			expr.val = tr.genGeq(expr.left.val, expr.right.val);
			break;
		case Tree.EQ:
		case Tree.NE:
			genEquNeq(expr);
			break;
		}
	}

	private void genEquNeq(Tree.Binary expr) {
		if (expr.left.type.equal(BaseType.STRING)
				|| expr.right.type.equal(BaseType.STRING)) {
			tr.genParm(expr.left.val);
			tr.genParm(expr.right.val);
			expr.val = tr.genDirectCall(Intrinsic.STRING_EQUAL.label,
					BaseType.BOOL);
			if(expr.tag == Tree.NE){
				expr.val = tr.genLNot(expr.val);
			}
		} else {
			if(expr.tag == Tree.EQ)
				expr.val = tr.genEqu(expr.left.val, expr.right.val);
			else
				expr.val = tr.genNeq(expr.left.val, expr.right.val);
		}
	}

	@Override
	public void visitAssign(Tree.Assign assign) {
		assign.left.accept(this);
		assign.expr.accept(this);
		switch (assign.left.lvKind) {
		case ARRAY_ELEMENT:
			Tree.Indexed arrayRef = (Tree.Indexed) assign.left;
			Temp esz = tr.genLoadImm4(OffsetCounter.WORD_SIZE);
			Temp t = tr.genMul(arrayRef.index.val, esz);
			Temp base = tr.genAdd(arrayRef.array.val, t);
			tr.genStore(assign.expr.val, base, 0);
			break;
		case MEMBER_VAR:
			Tree.Ident varRef = (Tree.Ident) assign.left;
			//add COMPLEX
			if (varRef.type.equal(BaseType.COMPLEX)) {
				tr.genStore(assign.expr.reval, varRef.owner.val, varRef.symbol
					.getOffset());
				tr.genStore(assign.expr.imval, varRef.owner.val, varRef.symbol
						.getImoffset());
			}
			else {
				tr.genStore(assign.expr.val, varRef.owner.val, varRef.symbol
						.getOffset());
			}
			//end COMPLEX
			break;
		case PARAM_VAR:
		case LOCAL_VAR:
			//add COMPLEX
			if (assign.left.type.equal(BaseType.COMPLEX)) {
				/*
				Temp nesz = tr.genLoadImm4(OffsetCounter.WORD_SIZE);
				Temp re = tr.genLoadImm4(0);
				Temp im = tr.genLoadImm4(1);
				Temp read = tr.genMul(re, nesz);
				Temp imad = tr.genMul(im, nesz);
				Temp rebase = tr.genAdd(((Tree.Ident) assign.left).symbol.getTemp(),read);
				Temp imbase = tr.genAdd(((Tree.Ident) assign.left).symbol.getTemp(),imad);

				tr.genStore(assign.expr.reval, rebase, 0);
				tr.genStore(assign.expr.imval, imbase, 0);
				break;
				*/

				tr.genAssign(((Tree.Ident) assign.left).symbol.getRetemp(),
						assign.expr.reval);
				tr.genAssign(((Tree.Ident) assign.left).symbol.getImtemp(),
						assign.expr.imval);

			} else {
				tr.genAssign(((Tree.Ident) assign.left).symbol.getTemp(),
						assign.expr.val);
			}
			//end COMPLEX
			break;
		}
	}

	@Override
	public void visitLiteral(Tree.Literal literal) {
		switch (literal.typeTag) {
		case Tree.INT:
			literal.val = tr.genLoadImm4(((Integer)literal.value).intValue());
			break;
		case Tree.BOOL:
			literal.val = tr.genLoadImm4((Boolean)(literal.value) ? 1 : 0);
			break;
			//add COMPLEX
			case Tree.COMPLEX:
				literal.reval = tr.genLoadImm4(0);
				literal.imval = tr.genLoadImm4(literal.imvalue);
				break;
			//end COMPLEX
		default:
			literal.val = tr.genLoadStrConst((String)literal.value);
		}
	}

	@Override
	public void visitExec(Tree.Exec exec) {
		exec.expr.accept(this);
	}

	@Override
	public void visitUnary(Tree.Unary expr) {
		expr.expr.accept(this);
		switch (expr.tag){
		case Tree.NEG:
			expr.val = tr.genNeg(expr.expr.val);
			break;
			//add COMPLEX
			case Tree.RE:
				expr.val = tr.genLoadImm4(0);
				tr.genAssign(expr.val, expr.expr.reval);
				break;
			case Tree.IM:
				expr.val = tr.genLoadImm4(0);
				tr.genAssign(expr.val, expr.expr.imval);
				break;
			case Tree.TOCOMPLEX:
				expr.imval = tr.genLoadImm4(0);
				expr.reval = tr.genLoadImm4(0);
				tr.genAssign(expr.reval,expr.expr.val);
				break;
			//end COMPLEX
		default:
			expr.val = tr.genLNot(expr.expr.val);
		}
	}

	@Override
	public void visitNull(Tree.Null nullExpr) {
		nullExpr.val = tr.genLoadImm4(0);
	}

	@Override
	public void visitBlock(Tree.Block block) {
		for (Tree s : block.block) {
			s.accept(this);
		}
	}

	@Override
	public void visitThisExpr(Tree.ThisExpr thisExpr) {
		thisExpr.val = currentThis;
	}

	@Override
	public void visitReadIntExpr(Tree.ReadIntExpr readIntExpr) {
		readIntExpr.val = tr.genIntrinsicCall(Intrinsic.READ_INT);
	}

	@Override
	public void visitReadLineExpr(Tree.ReadLineExpr readStringExpr) {
		readStringExpr.val = tr.genIntrinsicCall(Intrinsic.READ_LINE);
	}

	@Override
	public void visitReturn(Tree.Return returnStmt) {
		if (returnStmt.expr != null) {
			returnStmt.expr.accept(this);
			tr.genReturn(returnStmt.expr.val);
		} else {
			tr.genReturn(null);
		}

	}

	@Override
	public void visitPrint(Tree.Print printStmt) {
		for (Tree.Expr r : printStmt.exprs) {
			r.accept(this);
			tr.genParm(r.val);
			if (r.type.equal(BaseType.BOOL)) {
				tr.genIntrinsicCall(Intrinsic.PRINT_BOOL);
			} else if (r.type.equal(BaseType.INT)) {
				tr.genIntrinsicCall(Intrinsic.PRINT_INT);
			} else if (r.type.equal(BaseType.STRING)) {
				tr.genIntrinsicCall(Intrinsic.PRINT_STRING);
			}
		}
	}

	@Override
	public void visitIndexed(Tree.Indexed indexed) {
		indexed.array.accept(this);
		indexed.index.accept(this);
		tr.genCheckArrayIndex(indexed.array.val, indexed.index.val);
		
		Temp esz = tr.genLoadImm4(OffsetCounter.WORD_SIZE);
		Temp t = tr.genMul(indexed.index.val, esz);
		Temp base = tr.genAdd(indexed.array.val, t);
		indexed.val = tr.genLoad(base, 0);
	}

	@Override
	public void visitIdent(Tree.Ident ident) {
		if(ident.lvKind == Tree.LValue.Kind.MEMBER_VAR){
			ident.owner.accept(this);
		}
		
		switch (ident.lvKind) {
		case MEMBER_VAR:
			//add COMPLEX
			if (ident.type.equal(BaseType.COMPLEX)) {
				//ident.val = tr.genLoad(ident.owner.val, ident.symbol.getOffset());
				ident.reval = tr.genLoad(ident.owner.val, ident.symbol.getOffset());
				ident.imval = tr.genLoad(ident.owner.val, ident.symbol.getImoffset());
			}
			else {
				ident.val = tr.genLoad(ident.owner.val, ident.symbol.getOffset());
			}
			//end COMPLEX
			break;
		default:
			//add COMPLEX
			if (ident.type.equal(BaseType.COMPLEX)) {
				/*
				Temp esz = tr.genLoadImm4(OffsetCounter.WORD_SIZE);
				Temp re = tr.genLoadImm4(0);
				Temp im = tr.genLoadImm4(1);
				Temp read = tr.genMul(re, esz);
				Temp imad = tr.genMul(im, esz);
				Temp rebase = tr.genAdd(ident.symbol.getTemp(),read);
				Temp imbase = tr.genAdd(ident.symbol.getTemp(),imad);

				ident.reval = tr.genLoad(rebase, 0);
				ident.imval = tr.genLoad(imbase, 0);
				*/
				ident.reval = ident.symbol.getRetemp();
				ident.imval = ident.symbol.getImtemp();

			} else {
				ident.val = ident.symbol.getTemp();
			}
			//end COMPLEX
			break;
		}
	}
	
	@Override
	public void visitBreak(Tree.Break breakStmt) {
		tr.genBranch(loopExits.peek());
	}

	@Override
	public void visitCallExpr(Tree.CallExpr callExpr) {
		if (callExpr.isArrayLength) {
			callExpr.receiver.accept(this);
			callExpr.val = tr.genLoad(callExpr.receiver.val,
					-OffsetCounter.WORD_SIZE);
		} else {
			if (callExpr.receiver != null) {
				callExpr.receiver.accept(this);
			}
			for (Tree.Expr expr : callExpr.actuals) {
				expr.accept(this);
			}
			if (callExpr.receiver != null) {
				tr.genParm(callExpr.receiver.val);
			}
			for (Tree.Expr expr : callExpr.actuals) {
				//add COMPLEX
				if (expr.type.equal(BaseType.COMPLEX)) {
					tr.genParm(expr.reval);
					tr.genParm(expr.imval);
				}
				else {
					tr.genParm(expr.val);
				}
				//end COMPLEX
			}
			if (callExpr.receiver == null) {
				callExpr.val = tr.genDirectCall(
						callExpr.symbol.getFuncty().label, callExpr.symbol
								.getReturnType());
			} else {
				Temp vt = tr.genLoad(callExpr.receiver.val, 0);

				//add SUPER

				if (callExpr.receiver.tag == Tree.SUPEREXPR) {
					vt = tr.genLoadVTable(currentClass.getParent().getVtable());
				}
				else if (callExpr.receiver.tag == Tree.THISEXPR) {
					vt = tr.genLoadVTable(currentClass.getVtable());
				}
				//end SUPER

				Temp func = tr.genLoad(vt, callExpr.symbol.getOffset());
				callExpr.val = tr.genIndirectCall(func, callExpr.symbol
						.getReturnType());
			}
		}

	}

	@Override
	public void visitForLoop(Tree.ForLoop forLoop) {
		if (forLoop.init != null) {
			forLoop.init.accept(this);
		}
		Label cond = Label.createLabel();
		Label loop = Label.createLabel();
		tr.genBranch(cond);
		tr.genMark(loop);
		if (forLoop.update != null) {
			forLoop.update.accept(this);
		}
		tr.genMark(cond);
		forLoop.condition.accept(this);
		Label exit = Label.createLabel();
		tr.genBeqz(forLoop.condition.val, exit);
		loopExits.push(exit);
		if (forLoop.loopBody != null) {
			forLoop.loopBody.accept(this);
		}
		tr.genBranch(loop);
		loopExits.pop();
		tr.genMark(exit);
	}

	@Override
	public void visitIf(Tree.If ifStmt) {
		ifStmt.condition.accept(this);
		if (ifStmt.falseBranch != null) {
			Label falseLabel = Label.createLabel();
			tr.genBeqz(ifStmt.condition.val, falseLabel);
			ifStmt.trueBranch.accept(this);
			Label exit = Label.createLabel();
			tr.genBranch(exit);
			tr.genMark(falseLabel);
			ifStmt.falseBranch.accept(this);
			tr.genMark(exit);
		} else if (ifStmt.trueBranch != null) {
			Label exit = Label.createLabel();
			tr.genBeqz(ifStmt.condition.val, exit);
			if (ifStmt.trueBranch != null) {
				ifStmt.trueBranch.accept(this);
			}
			tr.genMark(exit);
		}
	}

	@Override
	public void visitNewArray(Tree.NewArray newArray) {
		newArray.length.accept(this);
		newArray.val = tr.genNewArray(newArray.length.val);
	}

	@Override
	public void visitNewClass(Tree.NewClass newClass) {
		newClass.val = tr.genDirectCall(newClass.symbol.getNewFuncLabel(),
				BaseType.INT);
	}

	@Override
	public void visitWhileLoop(Tree.WhileLoop whileLoop) {
		Label loop = Label.createLabel();
		tr.genMark(loop);
		whileLoop.condition.accept(this);
		Label exit = Label.createLabel();
		tr.genBeqz(whileLoop.condition.val, exit);
		loopExits.push(exit);
		if (whileLoop.loopBody != null) {
			whileLoop.loopBody.accept(this);
		}
		tr.genBranch(loop);
		loopExits.pop();
		tr.genMark(exit);
	}

	@Override
	public void visitTypeTest(Tree.TypeTest typeTest) {
		typeTest.instance.accept(this);
		typeTest.val = tr.genInstanceof(typeTest.instance.val,
				typeTest.symbol);
	}

	@Override
	public void visitTypeCast(Tree.TypeCast typeCast) {
		typeCast.expr.accept(this);
		if (!typeCast.expr.type.compatible(typeCast.symbol.getType())) {
			tr.genClassCast(typeCast.expr.val, typeCast.symbol);
		}
		typeCast.val = typeCast.expr.val;
	}

	//add CASE,DEFAULT
	@Override
	public void visitDefaultExpr(Tree.DefaultExpr defaultExpr) {
		defaultExpr.expr.accept(this);
		//add COMPLEX
		if (defaultExpr.expr.type.equal(BaseType.COMPLEX)) {
			defaultExpr.reval = defaultExpr.expr.reval;
			defaultExpr.imval = defaultExpr.expr.imval;
		}
		else {
			defaultExpr.val = defaultExpr.expr.val;
		}
		//end COMPLEX
	}

	@Override
	public void visitACaseExpr(Tree.ACaseExpr aCaseExpr) {
		aCaseExpr.constant.accept(this);
		aCaseExpr.expr.accept(this);
		//add COMPLEX
		if (aCaseExpr.expr.type.equal(BaseType.COMPLEX)) {
			aCaseExpr.reval = aCaseExpr.expr.reval;
			aCaseExpr.imval = aCaseExpr.expr.imval;
		}
		else {
			aCaseExpr.val = aCaseExpr.expr.val;
		}
		//end COMPLEX
	}

	@Override
	public void visitCaseExpr(Tree.CaseExpr caseExpr) {
		Label exit = Label.createLabel();
		caseExpr.cond.accept(this);
		Temp condVal = caseExpr.cond.val;
		Temp res = tr.genLoadImm4(0);
		Temp reres = tr.genLoadImm4(0);
		Temp imres = tr.genLoadImm4(0);
		if(caseExpr.acaseexprlist != null) {
			for (Tree.Expr e: caseExpr.acaseexprlist) {
				Tree.ACaseExpr newe = (Tree.ACaseExpr)e;
				Label nextcond = Label.createLabel();

				newe.constant.accept(this);
				Temp acasecond = newe.constant.val;
				Temp temp = tr.genEqu(condVal,acasecond);
				tr.genBeqz(temp, nextcond);
				newe.expr.accept(this);

				//add COMPLEX
				if (newe.expr.type.equal(BaseType.COMPLEX)) {
					caseExpr.reval = newe.expr.reval;
					caseExpr.imval = newe.expr.imval;
					tr.genAssign(reres, newe.reval);
					tr.genAssign(imres, newe.imval);
				}
				else {
					newe.val = newe.expr.val;
					tr.genAssign(res, newe.val);
				}
				//end COMPLEX
				//caseExpr.val = newe.val;
				//tr.genAssign(caseExpr.val, newe.val);
				tr.genBranch(exit);
				tr.genMark(nextcond);
			}
		}
		caseExpr.defaultexpr.accept(this);
		//add COMPLEX
		if(caseExpr.defaultexpr.type.equal(BaseType.COMPLEX)) {
			caseExpr.reval = caseExpr.defaultexpr.reval;
			caseExpr.imval = caseExpr.defaultexpr.imval;
			tr.genAssign(reres, caseExpr.defaultexpr.reval);
			tr.genAssign(imres, caseExpr.defaultexpr.imval);
		}
		else {
			caseExpr.val = caseExpr.defaultexpr.val;
			tr.genAssign(res, caseExpr.defaultexpr.val);
		}
		//end COMPLEX
		tr.genMark(exit);
		//add COMPLEX
		if(caseExpr.type.equal(BaseType.COMPLEX)) {

		}
		else {
			caseExpr.val = res;
		}
	}
	//end CASE,DEFAULT

	//add DO,OD
	@Override
	public void visitDoSubStmt(Tree.DoSubStmt doSubStmt) {

	}

	@Override
	public void visitDoStmt(Tree.DoStmt doStmt) {
		Label loop = Label.createLabel();
		tr.genMark(loop);
		Label exit = Label.createLabel();
		loopExits.push(exit);
		for (Tree s : doStmt.stmtlist) {
			Label next = Label.createLabel();
			Tree.DoSubStmt news = (Tree.DoSubStmt) s;

			news.condition.accept(this);
			tr.genBeqz(news.condition.val, next);

			news.stmt.accept(this);
			tr.genBranch(loop);

			tr.genMark(next);
		}
		loopExits.pop();
		tr.genMark(exit);
	}
	//end DO,OD

	//add COMPLEX
	@Override
	public void visitPrintComp(Tree.PrintComp printCompStmt) {
		for (Tree.Expr r : printCompStmt.exprs) {
			r.accept(this);
			tr.genParm(r.reval);
			tr.genIntrinsicCall(Intrinsic.PRINT_INT);
			Temp t = tr.genLoadStrConst("+");
			tr.genParm(t);
			tr.genIntrinsicCall(Intrinsic.PRINT_STRING);
			tr.genParm(r.imval);
			tr.genIntrinsicCall(Intrinsic.PRINT_INT);
			Temp s = tr.genLoadStrConst("j");
			tr.genParm(s);
			tr.genIntrinsicCall(Intrinsic.PRINT_STRING);
		}
	}
	//end COMPLEX

	//add SUPER
	@Override
	public void visitSuperExpr(Tree.SuperExpr superExpr) {
		superExpr.val = currentThis;
	}
	//end SUPER

	//add SCOPY,DCOPY
	@Override
	public void visitScopyExpr(Tree.ScopyExpr scopyExpr) {
		//System.out.println("ScopyExpr.");

		scopyExpr.expr.accept(this);

		scopyExpr.val = tr.genDirectCall(((ClassType)scopyExpr.expr.type).
				getSymbol().getNewFuncLabel(),BaseType.INT);

		Temp ste = tr.genLoadImm4(OffsetCounter.WORD_SIZE);
		Temp store = tr.genLoadImm4(0);
		Temp ptr1 = tr.genLoadImm4(0);
		Temp ptr2 = tr.genLoadImm4(0);
		tr.genAssign(ptr1, scopyExpr.expr.val);
		tr.genAssign(ptr2, scopyExpr.val);

		/*
		store = tr.genLoad(ptr1, 0);
		tr.genStore(store, ptr2, 0);

		tr.genAssign(ptr1,tr.genAdd(ptr1, ste));
		tr.genAssign(ptr2,tr.genAdd(ptr2, ste));
		*/


		int s = ((ClassType)scopyExpr.expr.type).
				getSymbol().getSize();
		Temp siz = tr.genLoadImm4(s);

		Label loop = Label.createLabel();
		Label exit = Label.createLabel();
		tr.genMark(loop);
		tr.genBeqz(siz,exit);

		store = tr.genLoad(ptr1, 0);
		tr.genStore(store, ptr2, 0);

		tr.genAssign(ptr1,tr.genAdd(ptr1, ste));
		tr.genAssign(ptr2,tr.genAdd(ptr2, ste));

		tr.genAssign(siz, tr.genSub(siz, ste));

		tr.genBranch(loop);

		tr.genMark(exit);

		//scopyExpr.val = scopyExpr.expr.val;

		//System.out.println("ExitScopyExpr.");
	}

	@Override
	public void visitDcopyExpr(Tree.DcopyExpr dcopyExpr) {
		dcopyExpr.expr.accept(this);
		Temp ptr = dcopyExpr.expr.val;
		Class c = (Class)((ClassType)dcopyExpr.expr.type).getSymbol();
		dcopyExpr.val = tr.genDCOPY(ptr,c);
	}
	//end SCOPY,DCOPY
}
