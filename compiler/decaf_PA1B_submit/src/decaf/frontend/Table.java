/* This is auto-generated source by LL1-Parser-Gen.
 * Specification file: /home/zhy/codes/java/undergraduate/compiler/decaf_PA1B_2/src/decaf/frontend/Parser.spec
 * Options: unstrict mode
 * Generated at: Fri Nov 10 22:29:17 CST 2017
 * Please do NOT modify it!
 *
 * Project repository: https://github.com/paulzfm/LL1-Parser-Gen
 * Version: special version for decaf-PA1-B
 * Author: Zhu Fengmin (Paul)
 */

package decaf.frontend;

import decaf.Location;
import decaf.tree.Tree;
import decaf.tree.Tree.*;
import java.util.*;
import javafx.util.Pair;

public class Table
 {
    public static final int eof = -1;
    public static final int eos = 0;
    
    /* tokens and symbols */
    public static final int VOID = 257; //# line 15
    public static final int BOOL = 258; //# line 15
    public static final int INT = 259; //# line 15
    public static final int STRING = 260; //# line 15
    public static final int COMPLEX = 261; //# line 15
    public static final int CLASS = 262; //# line 15
    public static final int NULL = 263; //# line 17
    public static final int EXTENDS = 264; //# line 17
    public static final int THIS = 265; //# line 17
    public static final int WHILE = 266; //# line 17
    public static final int FOR = 267; //# line 17
    public static final int SUPER = 268; //# line 17
    public static final int IF = 269; //# line 18
    public static final int ELSE = 270; //# line 18
    public static final int RETURN = 271; //# line 18
    public static final int BREAK = 272; //# line 18
    public static final int NEW = 273; //# line 18
    public static final int DO = 274; //# line 20
    public static final int OD = 275; //# line 20
    public static final int DCOPY = 276; //# line 23
    public static final int SCOPY = 277; //# line 23
    public static final int PRINT = 278; //# line 26
    public static final int READ_INTEGER = 279; //# line 26
    public static final int READ_LINE = 280; //# line 26
    public static final int PRINTCOMP = 281; //# line 26
    public static final int LITERAL = 282; //# line 27
    public static final int IDENTIFIER = 283; //# line 28
    public static final int AND = 284; //# line 28
    public static final int OR = 285; //# line 28
    public static final int STATIC = 286; //# line 28
    public static final int INSTANCEOF = 287; //# line 28
    public static final int LESS_EQUAL = 288; //# line 30
    public static final int GREATER_EQUAL = 289; //# line 30
    public static final int EQUAL = 290; //# line 30
    public static final int NOT_EQUAL = 291; //# line 30
    public static final int VERTS = 292; //# line 30
    public static final int CASE = 293; //# line 35
    public static final int DEFAULT = 294; //# line 35
    
    public static final int VariableDef = 295;
    public static final int DoSubStmt = 296;
    public static final int ExprT5 = 297;
    public static final int Oper8 = 298;
    public static final int Oper3 = 299;
    public static final int Oper6 = 300;
    public static final int VariableList = 301;
    public static final int Formals = 302;
    public static final int Oper7 = 303;
    public static final int Expr8 = 304;
    public static final int AfterSimpleTypeExpr = 305;
    public static final int Expr2 = 306;
    public static final int Oper2 = 307;
    public static final int Expr6 = 308;
    public static final int BreakStmt = 309;
    public static final int ExprT2 = 310;
    public static final int PrintCompStmt = 311;
    public static final int StmtList = 312;
    public static final int Constant = 313;
    public static final int SubVariableList = 314;
    public static final int PrintStmt = 315;
    public static final int ForStmt = 316;
    public static final int Expr9 = 317;
    public static final int Expr1 = 318;
    public static final int Oper1 = 319;
    public static final int ElseClause = 320;
    public static final int FieldList = 321;
    public static final int ACaseExpr = 322;
    public static final int SubExprList = 323;
    public static final int AfterParenExpr = 324;
    public static final int ClassDef = 325;
    public static final int ReturnStmt = 326;
    public static final int ExprList = 327;
    public static final int StmtBlock = 328;
    public static final int FunctionField = 329;
    public static final int AfterIdentExpr = 330;
    public static final int DoStmt = 331;
    public static final int Program = 332;
    public static final int Expr = 333;
    public static final int CaseExpr = 334;
    public static final int Type = 335;
    public static final int Expr5 = 336;
    public static final int AfterNewExpr = 337;
    public static final int Assignment = 338;
    public static final int ExtendsClause = 339;
    public static final int Oper5 = 340;
    public static final int ACaseExprList = 341;
    public static final int ArrayType = 342;
    public static final int Expr3 = 343;
    public static final int Actuals = 344;
    public static final int Variable = 345;
    public static final int ExprT3 = 346;
    public static final int Stmt = 347;
    public static final int SimpleStmt = 348;
    public static final int SimpleType = 349;
    public static final int WhileStmt = 350;
    public static final int ExprT1 = 351;
    public static final int Expr4 = 352;
    public static final int ExprT4 = 353;
    public static final int ReturnExpr = 354;
    public static final int IfStmt = 355;
    public static final int ExprT6 = 356;
    public static final int DoBranchList = 357;
    public static final int DoList = 358;
    public static final int ExprT8 = 359;
    public static final int DefaultExpr = 360;
    public static final int Expr7 = 361;
    public static final int ClassList = 362;
    public static final int Oper4 = 363;
    public static final int Field = 364;
    
    /* start symbol */
    public final int start = Program;
    
    /**
      * Judge if a symbol (within valid range) is non-terminal.
      *
      * @param symbol the symbol to be judged.
      * @return true if and only if the symbol is non-terminal.
      */
        
    public boolean isNonTerminal(int symbol) {
        return symbol >= 295;
    }
    
    private final String[] allSymbols = {
        "VOID", "BOOL", "INT", "STRING", "COMPLEX",
        "CLASS", "NULL", "EXTENDS", "THIS", "WHILE",
        "FOR", "SUPER", "IF", "ELSE", "RETURN",
        "BREAK", "NEW", "DO", "OD", "DCOPY",
        "SCOPY", "PRINT", "READ_INTEGER", "READ_LINE", "PRINTCOMP",
        "LITERAL", "IDENTIFIER", "AND", "OR", "STATIC",
        "INSTANCEOF", "LESS_EQUAL", "GREATER_EQUAL", "EQUAL", "NOT_EQUAL",
        "VERTS", "CASE", "DEFAULT", "VariableDef", "DoSubStmt",
        "ExprT5", "Oper8", "Oper3", "Oper6", "VariableList",
        "Formals", "Oper7", "Expr8", "AfterSimpleTypeExpr", "Expr2",
        "Oper2", "Expr6", "BreakStmt", "ExprT2", "PrintCompStmt",
        "StmtList", "Constant", "SubVariableList", "PrintStmt", "ForStmt",
        "Expr9", "Expr1", "Oper1", "ElseClause", "FieldList",
        "ACaseExpr", "SubExprList", "AfterParenExpr", "ClassDef", "ReturnStmt",
        "ExprList", "StmtBlock", "FunctionField", "AfterIdentExpr", "DoStmt",
        "Program", "Expr", "CaseExpr", "Type", "Expr5",
        "AfterNewExpr", "Assignment", "ExtendsClause", "Oper5", "ACaseExprList",
        "ArrayType", "Expr3", "Actuals", "Variable", "ExprT3",
        "Stmt", "SimpleStmt", "SimpleType", "WhileStmt", "ExprT1",
        "Expr4", "ExprT4", "ReturnExpr", "IfStmt", "ExprT6",
        "DoBranchList", "DoList", "ExprT8", "DefaultExpr", "Expr7",
        "ClassList", "Oper4", "Field",
    };
    
    /**
      * Debugging function (pretty print).
      * Get string presentation of some token or symbol.
      *
      * @param symbol either terminal or non-terminal.
      * @return its string presentation.
      */
        
    public String name(int symbol) {
        if (symbol == eof) return "<eof>";
        if (symbol == eos) return "<eos>";
        if (symbol > 0 && symbol <= 256) return "'" + (char) symbol + "'";
        return allSymbols[symbol - 257];
    }
    
    /* begin lookahead symbols */
    private ArrayList<Set<Integer>> begin = new ArrayList<Set<Integer>>();
    private final Integer[][] beginRaw = {
        {COMPLEX, VOID, CLASS, INT, STRING, BOOL},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {Integer.valueOf('+'), Integer.valueOf('-'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>')},
        {Integer.valueOf('@'), Integer.valueOf('$'), Integer.valueOf('#')},
        {EQUAL, NOT_EQUAL},
        {Integer.valueOf('*'), Integer.valueOf('/'), Integer.valueOf('%')},
        {COMPLEX, VOID, CLASS, INT, STRING, BOOL},
        {COMPLEX, VOID, CLASS, INT, STRING, BOOL, Integer.valueOf(')')},
        {Integer.valueOf('-'), Integer.valueOf('!')},
        {CASE, READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {Integer.valueOf(']'), CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {AND},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {BREAK},
        {AND, Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf(';')},
        {PRINTCOMP},
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('@'), DO, IDENTIFIER, NEW, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{'), Integer.valueOf('}')},
        {LITERAL, NULL},
        {Integer.valueOf(','), Integer.valueOf(')')},
        {PRINT},
        {FOR},
        {LITERAL, NULL, READ_INTEGER, READ_LINE, THIS, SUPER, NEW, INSTANCEOF, Integer.valueOf('('), IDENTIFIER, CASE, DCOPY, SCOPY, Integer.valueOf('@'), Integer.valueOf('$'), Integer.valueOf('#')},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {OR},
        {ELSE, PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {COMPLEX, VOID, CLASS, INT, STRING, STATIC, BOOL, Integer.valueOf('}')},
        {LITERAL, NULL},
        {Integer.valueOf(','), Integer.valueOf(')')},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER, CLASS},
        {CLASS},
        {RETURN},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {Integer.valueOf('{')},
        {Integer.valueOf('('), Integer.valueOf(';')},
        {Integer.valueOf('('), Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {DO},
        {CLASS},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {CASE},
        {COMPLEX, VOID, CLASS, INT, STRING, BOOL},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {IDENTIFIER, COMPLEX, VOID, CLASS, INT, STRING, BOOL},
        {Integer.valueOf('='), Integer.valueOf(';'), Integer.valueOf(')')},
        {EXTENDS, Integer.valueOf('{')},
        {Integer.valueOf('+'), Integer.valueOf('-')},
        {LITERAL, NULL, DEFAULT},
        {Integer.valueOf('['), IDENTIFIER},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER, Integer.valueOf(')')},
        {COMPLEX, VOID, CLASS, INT, STRING, BOOL},
        {EQUAL, NOT_EQUAL, Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';')},
        {COMPLEX, VOID, CLASS, INT, STRING, BOOL, CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER, IF, WHILE, FOR, RETURN, PRINT, BREAK, Integer.valueOf('{'), PRINTCOMP, DO},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER, Integer.valueOf(';'), Integer.valueOf(')')},
        {INT, VOID, BOOL, STRING, COMPLEX, CLASS},
        {WHILE},
        {OR, Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), Integer.valueOf(';')},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {LESS_EQUAL, GREATER_EQUAL, Integer.valueOf('<'), Integer.valueOf('>'), Integer.valueOf(']'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';')},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER, Integer.valueOf(';')},
        {IF},
        {Integer.valueOf('*'), Integer.valueOf('/'), Integer.valueOf('%'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>')},
        {VERTS, OD},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {Integer.valueOf('['), Integer.valueOf('.'), Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>'), Integer.valueOf('%')},
        {DEFAULT},
        {Integer.valueOf('-'), Integer.valueOf('!'), CASE, READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {CLASS, eof, eos},
        {LESS_EQUAL, GREATER_EQUAL, Integer.valueOf('<'), Integer.valueOf('>')},
        {STATIC, COMPLEX, VOID, CLASS, INT, STRING, BOOL},
    };
    
    /**
      * Get begin lookahead tokens for `symbol`.
      *
      * @param symbol the non-terminal.
      * @return its begin lookahead tokens.
      */
        
    public Set<Integer> beginSet(int symbol) {
        return begin.get(symbol - 295);
    }
    
    /* follow set */
    private ArrayList<Set<Integer>> follow = new ArrayList<Set<Integer>>();
    private final Integer[][] followRaw = {
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, ELSE, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {VERTS, OD},
        {LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>')},
        {CASE, READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {Integer.valueOf(')')},
        {Integer.valueOf(')')},
        {CASE, READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>'), Integer.valueOf('%')},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf(';')},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>')},
        {Integer.valueOf(';')},
        {Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf(';')},
        {Integer.valueOf(';')},
        {Integer.valueOf('}')},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {Integer.valueOf(')')},
        {Integer.valueOf(';')},
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, ELSE, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), Integer.valueOf(';')},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, ELSE, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {Integer.valueOf('}')},
        {LITERAL, NULL, DEFAULT},
        {Integer.valueOf(')')},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {CLASS, eof, eos},
        {Integer.valueOf(';')},
        {Integer.valueOf(')')},
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, STATIC, ELSE, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {COMPLEX, VOID, CLASS, INT, Integer.valueOf('}'), STRING, STATIC, BOOL},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {Integer.valueOf(';')},
        {eof, eos},
        {Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), Integer.valueOf(';')},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {IDENTIFIER},
        {LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>')},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('.'), Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('['), Integer.valueOf('>'), Integer.valueOf('%')},
        {Integer.valueOf(';'), Integer.valueOf(')')},
        {Integer.valueOf('{')},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {DEFAULT},
        {IDENTIFIER},
        {Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';')},
        {Integer.valueOf(')')},
        {Integer.valueOf(';'), Integer.valueOf(','), Integer.valueOf(')')},
        {Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';')},
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, ELSE, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {Integer.valueOf(';'), Integer.valueOf(')')},
        {Integer.valueOf('['), IDENTIFIER},
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, ELSE, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {Integer.valueOf(']'), Integer.valueOf(':'), Integer.valueOf(')'), Integer.valueOf(','), Integer.valueOf('='), Integer.valueOf(';')},
        {Integer.valueOf(']'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';')},
        {Integer.valueOf(']'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, AND, Integer.valueOf(';')},
        {Integer.valueOf(';')},
        {PRINT, CASE, COMPLEX, VOID, FOR, Integer.valueOf('!'), Integer.valueOf('-'), CLASS, PRINTCOMP, READ_LINE, WHILE, RETURN, NULL, INT, SCOPY, Integer.valueOf('}'), Integer.valueOf('@'), DO, IDENTIFIER, NEW, VERTS, Integer.valueOf('$'), IF, THIS, INSTANCEOF, STRING, LITERAL, ELSE, Integer.valueOf('('), Integer.valueOf(';'), Integer.valueOf('#'), OD, DCOPY, BOOL, SUPER, BREAK, READ_INTEGER, Integer.valueOf('{')},
        {LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>')},
        {OD},
        {OD},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>'), Integer.valueOf('%')},
        {Integer.valueOf('}')},
        {Integer.valueOf('/'), LESS_EQUAL, Integer.valueOf(']'), GREATER_EQUAL, Integer.valueOf('-'), Integer.valueOf(':'), EQUAL, Integer.valueOf(')'), NOT_EQUAL, Integer.valueOf(','), Integer.valueOf('='), OR, Integer.valueOf('+'), AND, Integer.valueOf('*'), Integer.valueOf(';'), Integer.valueOf('<'), Integer.valueOf('>'), Integer.valueOf('%')},
        {eof, eos},
        {CASE, Integer.valueOf('!'), Integer.valueOf('-'), READ_LINE, NULL, SCOPY, Integer.valueOf('@'), IDENTIFIER, NEW, Integer.valueOf('$'), THIS, INSTANCEOF, LITERAL, Integer.valueOf('('), Integer.valueOf('#'), DCOPY, SUPER, READ_INTEGER},
        {COMPLEX, VOID, CLASS, INT, Integer.valueOf('}'), STRING, STATIC, BOOL},
    };
    
    /**
      * Get follow set for `symbol`.
      *
      * @param symbol the non-terminal.
      * @return its follow set.
      */
        
    public Set<Integer> followSet(int symbol) {
        return follow.get(symbol - 295);
    }
    
    public Table() {
        for (int i = 0; i < 70; i++) {
            begin.add(new HashSet(Arrays.asList(beginRaw[i])));
            follow.add(new HashSet(Arrays.asList(followRaw[i])));
        }
    }
    
    /**
      * Predictive table `M` query function.
      * `query(A, a)` will return the corresponding term `M(A, a)`, i.e., the target production
      * for non-terminal `A` when the lookahead token is `a`.
      *
      * @param nonTerminal   the non-terminal.
      * @param lookahead     the lookahead symbol.
      * @return a pair `<id, right>` where `right` is the right-hand side of the target
      * production `nonTerminal -> right`, and `id` is the corresponding action id. To execute
      * such action, call `act(id, params)`.
      * If the corresponding term is undefined in the table, `null` will be returned.
      */
        
    public Pair<Integer, List<Integer>> query(int nonTerminal, int lookahead) {
        switch (nonTerminal) {
            //# line 61
            case VariableDef: {
                switch (lookahead) {
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(0, Arrays.asList(Variable, Integer.valueOf(';')));
                    default: return null;
                }
            }
            //# line 879
            case DoSubStmt: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(1, Arrays.asList(Expr, Integer.valueOf(':'), Stmt));
                    default: return null;
                }
            }
            //# line 532
            case ExprT5: {
                switch (lookahead) {
                    case '+':
                    case '-':
                        return new Pair<>(2, Arrays.asList(Oper5, Expr6, ExprT5));
                    case LESS_EQUAL:
                    case ']':
                    case GREATER_EQUAL:
                    case ':':
                    case EQUAL:
                    case ')':
                    case NOT_EQUAL:
                    case ',':
                    case '=':
                    case OR:
                    case AND:
                    case ';':
                    case '<':
                    case '>':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 379
            case Oper8: {
                switch (lookahead) {
                    case '@':
                        return new Pair<>(4, Arrays.asList(Integer.valueOf('@')));
                    case '$':
                        return new Pair<>(5, Arrays.asList(Integer.valueOf('$')));
                    case '#':
                        return new Pair<>(6, Arrays.asList(Integer.valueOf('#')));
                    default: return null;
                }
            }
            //# line 304
            case Oper3: {
                switch (lookahead) {
                    case EQUAL:
                        return new Pair<>(7, Arrays.asList(EQUAL));
                    case NOT_EQUAL:
                        return new Pair<>(8, Arrays.asList(NOT_EQUAL));
                    default: return null;
                }
            }
            //# line 350
            case Oper6: {
                switch (lookahead) {
                    case '*':
                        return new Pair<>(9, Arrays.asList(Integer.valueOf('*')));
                    case '/':
                        return new Pair<>(10, Arrays.asList(Integer.valueOf('/')));
                    case '%':
                        return new Pair<>(11, Arrays.asList(Integer.valueOf('%')));
                    default: return null;
                }
            }
            //# line 181
            case VariableList: {
                switch (lookahead) {
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(12, Arrays.asList(Variable, SubVariableList));
                    default: return null;
                }
            }
            //# line 171
            case Formals: {
                switch (lookahead) {
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(13, Arrays.asList(VariableList));
                    case ')':
                        return new Pair<>(14, Arrays.asList());
                    default: return null;
                }
            }
            //# line 367
            case Oper7: {
                switch (lookahead) {
                    case '-':
                        return new Pair<>(15, Arrays.asList(Integer.valueOf('-')));
                    case '!':
                        return new Pair<>(16, Arrays.asList(Integer.valueOf('!')));
                    default: return null;
                }
            }
            //# line 588
            case Expr8: {
                switch (lookahead) {
                    case CASE:
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(17, Arrays.asList(Expr9, ExprT8));
                    default: return null;
                }
            }
            //# line 755
            case AfterSimpleTypeExpr: {
                switch (lookahead) {
                    case ']':
                        return new Pair<>(18, Arrays.asList(Integer.valueOf(']'), Integer.valueOf('['), AfterSimpleTypeExpr));
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(19, Arrays.asList(Expr, Integer.valueOf(']')));
                    default: return null;
                }
            }
            //# line 433
            case Expr2: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(20, Arrays.asList(Expr3, ExprT2));
                    default: return null;
                }
            }
            //# line 297
            case Oper2: {
                switch (lookahead) {
                    case AND:
                        return new Pair<>(21, Arrays.asList(AND));
                    default: return null;
                }
            }
            //# line 549
            case Expr6: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(22, Arrays.asList(Expr7, ExprT6));
                    default: return null;
                }
            }
            //# line 832
            case BreakStmt: {
                switch (lookahead) {
                    case BREAK:
                        return new Pair<>(23, Arrays.asList(BREAK));
                    default: return null;
                }
            }
            //# line 445
            case ExprT2: {
                switch (lookahead) {
                    case AND:
                        return new Pair<>(24, Arrays.asList(Oper2, Expr3, ExprT2));
                    case ']':
                    case ':':
                    case ')':
                    case ',':
                    case '=':
                    case OR:
                    case ';':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 871
            case PrintCompStmt: {
                switch (lookahead) {
                    case PRINTCOMP:
                        return new Pair<>(26, Arrays.asList(PRINTCOMP, Integer.valueOf('('), ExprList, Integer.valueOf(')')));
                    default: return null;
                }
            }
            //# line 208
            case StmtList: {
                switch (lookahead) {
                    case PRINT:
                    case CASE:
                    case COMPLEX:
                    case VOID:
                    case FOR:
                    case '!':
                    case '-':
                    case CLASS:
                    case PRINTCOMP:
                    case READ_LINE:
                    case WHILE:
                    case RETURN:
                    case NULL:
                    case INT:
                    case SCOPY:
                    case '@':
                    case DO:
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case IF:
                    case THIS:
                    case INSTANCEOF:
                    case STRING:
                    case LITERAL:
                    case '(':
                    case ';':
                    case '#':
                    case DCOPY:
                    case BOOL:
                    case SUPER:
                    case BREAK:
                    case READ_INTEGER:
                    case '{':
                        return new Pair<>(27, Arrays.asList(Stmt, StmtList));
                    case '}':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 779
            case Constant: {
                switch (lookahead) {
                    case LITERAL:
                        return new Pair<>(29, Arrays.asList(LITERAL));
                    case NULL:
                        return new Pair<>(30, Arrays.asList(NULL));
                    default: return null;
                }
            }
            //# line 191
            case SubVariableList: {
                switch (lookahead) {
                    case ',':
                        return new Pair<>(31, Arrays.asList(Integer.valueOf(','), Variable, SubVariableList));
                    case ')':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 864
            case PrintStmt: {
                switch (lookahead) {
                    case PRINT:
                        return new Pair<>(33, Arrays.asList(PRINT, Integer.valueOf('('), ExprList, Integer.valueOf(')')));
                    default: return null;
                }
            }
            //# line 826
            case ForStmt: {
                switch (lookahead) {
                    case FOR:
                        return new Pair<>(34, Arrays.asList(FOR, Integer.valueOf('('), SimpleStmt, Integer.valueOf(';'), Expr, Integer.valueOf(';'), SimpleStmt, Integer.valueOf(')'), Stmt));
                    default: return null;
                }
            }
            //# line 640
            case Expr9: {
                switch (lookahead) {
                    case LITERAL:
                    case NULL:
                        return new Pair<>(35, Arrays.asList(Constant));
                    case READ_INTEGER:
                        return new Pair<>(36, Arrays.asList(READ_INTEGER, Integer.valueOf('('), Integer.valueOf(')')));
                    case READ_LINE:
                        return new Pair<>(37, Arrays.asList(READ_LINE, Integer.valueOf('('), Integer.valueOf(')')));
                    case THIS:
                        return new Pair<>(38, Arrays.asList(THIS));
                    case SUPER:
                        return new Pair<>(39, Arrays.asList(SUPER));
                    case NEW:
                        return new Pair<>(40, Arrays.asList(NEW, AfterNewExpr));
                    case INSTANCEOF:
                        return new Pair<>(41, Arrays.asList(INSTANCEOF, Integer.valueOf('('), Expr, Integer.valueOf(','), IDENTIFIER, Integer.valueOf(')')));
                    case '(':
                        return new Pair<>(42, Arrays.asList(Integer.valueOf('('), AfterParenExpr));
                    case IDENTIFIER:
                        return new Pair<>(43, Arrays.asList(IDENTIFIER, AfterIdentExpr));
                    case CASE:
                        return new Pair<>(44, Arrays.asList(CaseExpr));
                    case DCOPY:
                        return new Pair<>(45, Arrays.asList(DCOPY, Integer.valueOf('('), Expr, Integer.valueOf(')')));
                    case SCOPY:
                        return new Pair<>(46, Arrays.asList(SCOPY, Integer.valueOf('('), Expr, Integer.valueOf(')')));
                    case '@':
                    case '$':
                    case '#':
                        return new Pair<>(47, Arrays.asList(Oper8, Expr9));
                    default: return null;
                }
            }
            //# line 404
            case Expr1: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(48, Arrays.asList(Expr2, ExprT1));
                    default: return null;
                }
            }
            //# line 290
            case Oper1: {
                switch (lookahead) {
                    case OR:
                        return new Pair<>(49, Arrays.asList(OR));
                    default: return null;
                }
            }
            //# line 844
            case ElseClause: {
                switch (lookahead) {
                    case ELSE:
                        return new Pair<>(50, Arrays.asList(ELSE, Stmt));
                    case PRINT:
                    case CASE:
                    case COMPLEX:
                    case VOID:
                    case FOR:
                    case '!':
                    case '-':
                    case CLASS:
                    case PRINTCOMP:
                    case READ_LINE:
                    case WHILE:
                    case RETURN:
                    case NULL:
                    case INT:
                    case SCOPY:
                    case '}':
                    case '@':
                    case DO:
                    case IDENTIFIER:
                    case NEW:
                    case VERTS:
                    case '$':
                    case IF:
                    case THIS:
                    case INSTANCEOF:
                    case STRING:
                    case LITERAL:
                    case '(':
                    case ';':
                    case '#':
                    case OD:
                    case DCOPY:
                    case BOOL:
                    case SUPER:
                    case BREAK:
                    case READ_INTEGER:
                    case '{':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 131
            case FieldList: {
                switch (lookahead) {
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case STATIC:
                    case BOOL:
                        return new Pair<>(52, Arrays.asList(Field, FieldList));
                    case '}':
                        return new Pair<>(53, Arrays.asList());
                    default: return null;
                }
            }
            //# line 716
            case ACaseExpr: {
                switch (lookahead) {
                    case LITERAL:
                    case NULL:
                        return new Pair<>(54, Arrays.asList(Constant, Integer.valueOf(':'), Expr, Integer.valueOf(';')));
                    default: return null;
                }
            }
            //# line 807
            case SubExprList: {
                switch (lookahead) {
                    case ',':
                        return new Pair<>(55, Arrays.asList(Integer.valueOf(','), Expr, SubExprList));
                    case ')':
                        return new Pair<>(56, Arrays.asList());
                    default: return null;
                }
            }
            //# line 767
            case AfterParenExpr: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(57, Arrays.asList(Expr, Integer.valueOf(')')));
                    case CLASS:
                        return new Pair<>(58, Arrays.asList(CLASS, IDENTIFIER, Integer.valueOf(')'), Expr9));
                    default: return null;
                }
            }
            //# line 118
            case ClassDef: {
                switch (lookahead) {
                    case CLASS:
                        return new Pair<>(59, Arrays.asList(CLASS, IDENTIFIER, ExtendsClause, Integer.valueOf('{'), FieldList, Integer.valueOf('}')));
                    default: return null;
                }
            }
            //# line 851
            case ReturnStmt: {
                switch (lookahead) {
                    case RETURN:
                        return new Pair<>(60, Arrays.asList(RETURN, ReturnExpr));
                    default: return null;
                }
            }
            //# line 799
            case ExprList: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(61, Arrays.asList(Expr, SubExprList));
                    default: return null;
                }
            }
            //# line 202
            case StmtBlock: {
                switch (lookahead) {
                    case '{':
                        return new Pair<>(62, Arrays.asList(Integer.valueOf('{'), StmtList, Integer.valueOf('}')));
                    default: return null;
                }
            }
            //# line 163
            case FunctionField: {
                switch (lookahead) {
                    case '(':
                        return new Pair<>(63, Arrays.asList(Integer.valueOf('('), Formals, Integer.valueOf(')'), StmtBlock));
                    case ';':
                        return new Pair<>(131, Arrays.asList(Integer.valueOf(';')));
                    default: return null;
                }
            }
            //# line 633
            case AfterIdentExpr: {
                switch (lookahead) {
                    case '(':
                        return new Pair<>(65, Arrays.asList(Integer.valueOf('('), Actuals, Integer.valueOf(')')));
                    case '/':
                    case LESS_EQUAL:
                    case ']':
                    case GREATER_EQUAL:
                    case '.':
                    case '-':
                    case ':':
                    case EQUAL:
                    case ')':
                    case NOT_EQUAL:
                    case ',':
                    case '=':
                    case OR:
                    case '+':
                    case AND:
                    case '*':
                    case ';':
                    case '<':
                    case '[':
                    case '>':
                    case '%':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 897
            case DoStmt: {
                switch (lookahead) {
                    case DO:
                        return new Pair<>(67, Arrays.asList(DO, DoList, OD));
                    default: return null;
                }
            }
            //# line 39
            case Program: {
                switch (lookahead) {
                    case CLASS:
                        return new Pair<>(68, Arrays.asList(ClassDef, ClassList));
                    default: return null;
                }
            }
            //# line 398
            case Expr: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(69, Arrays.asList(Expr1));
                    default: return null;
                }
            }
            //# line 734
            case CaseExpr: {
                switch (lookahead) {
                    case CASE:
                        return new Pair<>(70, Arrays.asList(CASE, Integer.valueOf('('), Expr, Integer.valueOf(')'), Integer.valueOf('{'), ACaseExprList, DefaultExpr, Integer.valueOf('}')));
                    default: return null;
                }
            }
            //# line 99
            case Type: {
                switch (lookahead) {
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(71, Arrays.asList(SimpleType, ArrayType));
                    default: return null;
                }
            }
            //# line 520
            case Expr5: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(72, Arrays.asList(Expr6, ExprT5));
                    default: return null;
                }
            }
            //# line 741
            case AfterNewExpr: {
                switch (lookahead) {
                    case IDENTIFIER:
                        return new Pair<>(73, Arrays.asList(IDENTIFIER, Integer.valueOf('('), Integer.valueOf(')')));
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(74, Arrays.asList(SimpleType, Integer.valueOf('['), AfterSimpleTypeExpr));
                    default: return null;
                }
            }
            //# line 281
            case Assignment: {
                switch (lookahead) {
                    case '=':
                        return new Pair<>(75, Arrays.asList(Integer.valueOf('='), Expr));
                    case ';':
                    case ')':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 124
            case ExtendsClause: {
                switch (lookahead) {
                    case EXTENDS:
                        return new Pair<>(77, Arrays.asList(EXTENDS, IDENTIFIER));
                    case '{':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 338
            case Oper5: {
                switch (lookahead) {
                    case '+':
                        return new Pair<>(79, Arrays.asList(Integer.valueOf('+')));
                    case '-':
                        return new Pair<>(80, Arrays.asList(Integer.valueOf('-')));
                    default: return null;
                }
            }
            //# line 722
            case ACaseExprList: {
                switch (lookahead) {
                    case LITERAL:
                    case NULL:
                        return new Pair<>(81, Arrays.asList(ACaseExpr, ACaseExprList));
                    case DEFAULT:
                        return new Pair<>(82, Arrays.asList());
                    default: return null;
                }
            }
            //# line 108
            case ArrayType: {
                switch (lookahead) {
                    case '[':
                        return new Pair<>(83, Arrays.asList(Integer.valueOf('['), Integer.valueOf(']'), ArrayType));
                    case IDENTIFIER:
                        return new Pair<>(84, Arrays.asList());
                    default: return null;
                }
            }
            //# line 462
            case Expr3: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(85, Arrays.asList(Expr4, ExprT3));
                    default: return null;
                }
            }
            //# line 789
            case Actuals: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(86, Arrays.asList(ExprList));
                    case ')':
                        return new Pair<>(87, Arrays.asList());
                    default: return null;
                }
            }
            //# line 67
            case Variable: {
                switch (lookahead) {
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(88, Arrays.asList(Type, IDENTIFIER));
                    default: return null;
                }
            }
            //# line 474
            case ExprT3: {
                switch (lookahead) {
                    case EQUAL:
                    case NOT_EQUAL:
                        return new Pair<>(89, Arrays.asList(Oper3, Expr4, ExprT3));
                    case ']':
                    case ':':
                    case ')':
                    case ',':
                    case '=':
                    case OR:
                    case AND:
                    case ';':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 216
            case Stmt: {
                switch (lookahead) {
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(91, Arrays.asList(VariableDef));
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case ';':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(92, Arrays.asList(SimpleStmt, Integer.valueOf(';')));
                    case IF:
                        return new Pair<>(93, Arrays.asList(IfStmt));
                    case WHILE:
                        return new Pair<>(94, Arrays.asList(WhileStmt));
                    case FOR:
                        return new Pair<>(95, Arrays.asList(ForStmt));
                    case RETURN:
                        return new Pair<>(96, Arrays.asList(ReturnStmt, Integer.valueOf(';')));
                    case PRINT:
                        return new Pair<>(97, Arrays.asList(PrintStmt, Integer.valueOf(';')));
                    case BREAK:
                        return new Pair<>(98, Arrays.asList(BreakStmt, Integer.valueOf(';')));
                    case '{':
                        return new Pair<>(99, Arrays.asList(StmtBlock));
                    case PRINTCOMP:
                        return new Pair<>(100, Arrays.asList(PrintCompStmt, Integer.valueOf(';')));
                    case DO:
                        return new Pair<>(101, Arrays.asList(DoStmt, Integer.valueOf(';')));
                    default: return null;
                }
            }
            //# line 270
            case SimpleStmt: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(102, Arrays.asList(Expr, Assignment));
                    case ';':
                    case ')':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 73
            case SimpleType: {
                switch (lookahead) {
                    case INT:
                        return new Pair<>(104, Arrays.asList(INT));
                    case VOID:
                        return new Pair<>(105, Arrays.asList(VOID));
                    case BOOL:
                        return new Pair<>(106, Arrays.asList(BOOL));
                    case STRING:
                        return new Pair<>(107, Arrays.asList(STRING));
                    case COMPLEX:
                        return new Pair<>(108, Arrays.asList(COMPLEX));
                    case CLASS:
                        return new Pair<>(109, Arrays.asList(CLASS, IDENTIFIER));
                    default: return null;
                }
            }
            //# line 820
            case WhileStmt: {
                switch (lookahead) {
                    case WHILE:
                        return new Pair<>(110, Arrays.asList(WHILE, Integer.valueOf('('), Expr, Integer.valueOf(')'), Stmt));
                    default: return null;
                }
            }
            //# line 416
            case ExprT1: {
                switch (lookahead) {
                    case OR:
                        return new Pair<>(111, Arrays.asList(Oper1, Expr2, ExprT1));
                    case ']':
                    case ':':
                    case ')':
                    case ',':
                    case '=':
                    case ';':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 491
            case Expr4: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(113, Arrays.asList(Expr5, ExprT4));
                    default: return null;
                }
            }
            //# line 503
            case ExprT4: {
                switch (lookahead) {
                    case LESS_EQUAL:
                    case GREATER_EQUAL:
                    case '<':
                    case '>':
                        return new Pair<>(114, Arrays.asList(Oper4, Expr5, ExprT4));
                    case ']':
                    case ':':
                    case EQUAL:
                    case ')':
                    case NOT_EQUAL:
                    case ',':
                    case '=':
                    case OR:
                    case AND:
                    case ';':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 857
            case ReturnExpr: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(116, Arrays.asList(Expr));
                    case ';':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 838
            case IfStmt: {
                switch (lookahead) {
                    case IF:
                        return new Pair<>(118, Arrays.asList(IF, Integer.valueOf('('), Expr, Integer.valueOf(')'), Stmt, ElseClause));
                    default: return null;
                }
            }
            //# line 561
            case ExprT6: {
                switch (lookahead) {
                    case '*':
                    case '/':
                    case '%':
                        return new Pair<>(119, Arrays.asList(Oper6, Expr7, ExprT6));
                    case LESS_EQUAL:
                    case ']':
                    case GREATER_EQUAL:
                    case '-':
                    case ':':
                    case EQUAL:
                    case ')':
                    case NOT_EQUAL:
                    case ',':
                    case '=':
                    case OR:
                    case '+':
                    case AND:
                    case ';':
                    case '<':
                    case '>':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 884
            case DoBranchList: {
                switch (lookahead) {
                    case VERTS:
                        return new Pair<>(121, Arrays.asList(VERTS, DoSubStmt, DoBranchList));
                    case OD:
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 891
            case DoList: {
                switch (lookahead) {
                    case CASE:
                    case '!':
                    case '-':
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(123, Arrays.asList(DoSubStmt, DoBranchList));
                    default: return null;
                }
            }
            //# line 608
            case ExprT8: {
                switch (lookahead) {
                    case '[':
                        return new Pair<>(124, Arrays.asList(Integer.valueOf('['), Expr, Integer.valueOf(']'), ExprT8));
                    case '.':
                        return new Pair<>(125, Arrays.asList(Integer.valueOf('.'), IDENTIFIER, AfterIdentExpr, ExprT8));
                    case '/':
                    case LESS_EQUAL:
                    case ']':
                    case GREATER_EQUAL:
                    case '-':
                    case ':':
                    case EQUAL:
                    case ')':
                    case NOT_EQUAL:
                    case ',':
                    case '=':
                    case OR:
                    case '+':
                    case AND:
                    case '*':
                    case ';':
                    case '<':
                    case '>':
                    case '%':
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 710
            case DefaultExpr: {
                switch (lookahead) {
                    case DEFAULT:
                        return new Pair<>(127, Arrays.asList(DEFAULT, Integer.valueOf(':'), Expr, Integer.valueOf(';')));
                    default: return null;
                }
            }
            //# line 578
            case Expr7: {
                switch (lookahead) {
                    case '-':
                    case '!':
                        return new Pair<>(128, Arrays.asList(Oper7, Expr8));
                    case CASE:
                    case READ_LINE:
                    case NULL:
                    case SCOPY:
                    case '@':
                    case IDENTIFIER:
                    case NEW:
                    case '$':
                    case THIS:
                    case INSTANCEOF:
                    case LITERAL:
                    case '(':
                    case '#':
                    case DCOPY:
                    case SUPER:
                    case READ_INTEGER:
                        return new Pair<>(129, Arrays.asList(Expr8));
                    default: return null;
                }
            }
            //# line 50
            case ClassList: {
                switch (lookahead) {
                    case CLASS:
                        return new Pair<>(130, Arrays.asList(ClassDef, ClassList));
                    case eof:
                    case eos:
                        return new Pair<>(131, Arrays.asList());
                    default: return null;
                }
            }
            //# line 316
            case Oper4: {
                switch (lookahead) {
                    case LESS_EQUAL:
                        return new Pair<>(132, Arrays.asList(LESS_EQUAL));
                    case GREATER_EQUAL:
                        return new Pair<>(133, Arrays.asList(GREATER_EQUAL));
                    case '<':
                        return new Pair<>(134, Arrays.asList(Integer.valueOf('<')));
                    case '>':
                        return new Pair<>(135, Arrays.asList(Integer.valueOf('>')));
                    default: return null;
                }
            }
            //# line 147
            case Field: {
                switch (lookahead) {
                    case STATIC:
                        return new Pair<>(136, Arrays.asList(STATIC, Type, IDENTIFIER, Integer.valueOf('('), Formals, Integer.valueOf(')'), StmtBlock));
                    case COMPLEX:
                    case VOID:
                    case CLASS:
                    case INT:
                    case STRING:
                    case BOOL:
                        return new Pair<>(137, Arrays.asList(Type, IDENTIFIER, FunctionField));
                    default: return null;
                }
            }
            default: return null;
        }
    }
    
    /**
      * Execute some user-defined semantic action on the specification file.
      * Note that `$$ = params[0], $1 = params[1], ...`. Nothing will be returned, so please
      * do not forget to store the parsed AST result in `params[0]`.
      *
      * @param id      the action id.
      * @param params  parameter array.
      */
        
    public void act(int id, SemValue[] params) {
        switch (id) {
            case 0: {
                //# line 62
                params[0].vdef = params[1].vdef;
                return;
            }
            case 1: {
                //# line 880
                params[0].stmt = new DoSubStmt(params[1].expr, params[3].stmt, params[2].loc);
                return;
            }
            case 2: {
                //# line 533
                params[0].svec = new Vector<Integer>();
                params[0].lvec = new Vector<Location>();
                params[0].evec = new Vector<Expr>();
                params[0].svec.add(params[1].counter);
                params[0].lvec.add(params[1].loc);
                params[0].evec.add(params[2].expr);
                if (params[3].svec != null) {
                    params[0].svec.addAll(params[3].svec);
                    params[0].lvec.addAll(params[3].lvec);
                    params[0].evec.addAll(params[3].evec);
                }
                return;
            }
            case 3: {
                /* no action */
                return;
            }
            case 4: {
                //# line 380
                params[0].counter = Tree.RE;
                params[0].loc = params[1].loc;
                return;
            }
            case 5: {
                //# line 385
                params[0].counter = Tree.IM;
                params[0].loc = params[1].loc;
                return;
            }
            case 6: {
                //# line 390
                params[0].counter = Tree.TOCOMPLEX;
                params[0].loc = params[1].loc;
                return;
            }
            case 7: {
                //# line 305
                params[0].counter = Tree.EQ;
                params[0].loc = params[1].loc;
                return;
            }
            case 8: {
                //# line 310
                params[0].counter = Tree.NE;
                params[0].loc = params[1].loc;
                return;
            }
            case 9: {
                //# line 351
                params[0].counter = Tree.MUL;
                params[0].loc = params[1].loc;
                return;
            }
            case 10: {
                //# line 356
                params[0].counter = Tree.DIV;
                params[0].loc = params[1].loc;
                return;
            }
            case 11: {
                //# line 361
                params[0].counter = Tree.MOD;
                params[0].loc = params[1].loc;
                return;
            }
            case 12: {
                //# line 182
                params[0].vlist = new ArrayList<VarDef>();
                params[0].vlist.add(params[1].vdef);
                if (params[2].vlist != null) {
                    params[0].vlist.addAll(params[2].vlist);
                }
                return;
            }
            case 13: {
                //# line 172
                params[0].vlist = params[1].vlist;
                return;
            }
            case 14: {
                //# line 176
                params[0].vlist = new ArrayList<VarDef>();
                return;
            }
            case 15: {
                //# line 368
                params[0].counter = Tree.NEG;
                params[0].loc = params[1].loc;
                return;
            }
            case 16: {
                //# line 373
                params[0].counter = Tree.NOT;
                params[0].loc = params[1].loc;
                return;
            }
            case 17: {
                //# line 589
                params[0].expr = params[1].expr;
                params[0].loc = params[1].loc;
                if (params[2].vec != null) {
                    for (SemValue v : params[2].vec) {
                        if (v.expr != null) {
                            params[0].expr = new Tree.Indexed(params[0].expr, v.expr, params[0].loc);
                        } else if (v.elist != null) {
                            params[0].expr = new Tree.CallExpr(params[0].expr, v.ident, v.elist, v.loc);
                            params[0].loc = v.loc;
                        } else {
                            params[0].expr = new Tree.Ident(params[0].expr, v.ident, v.loc);
                            params[0].loc = v.loc;
                        }
                    }
                }
                return;
            }
            case 18: {
                //# line 756
                params[0].expr = params[3].expr;
                params[0].counter = 1 + params[3].counter;
                return;
            }
            case 19: {
                //# line 761
                params[0].expr = params[1].expr;
                params[0].counter = 0;
                return;
            }
            case 20: {
                //# line 434
                params[0].expr = params[1].expr;
                if (params[2].svec != null) {
                    for (int i = 0; i < params[2].svec.size(); ++i) {
                        params[0].expr = new Tree.Binary(params[2].svec.get(i), params[0].expr,
                            params[2].evec.get(i), params[2].lvec.get(i));
                    }
                }
                return;
            }
            case 21: {
                //# line 298
                params[0].counter = Tree.AND;
                params[0].loc = params[1].loc;
                return;
            }
            case 22: {
                //# line 550
                params[0].expr = params[1].expr;
                if (params[2].svec != null) {
                    for (int i = 0; i < params[2].svec.size(); ++i) {
                        params[0].expr = new Tree.Binary(params[2].svec.get(i), params[0].expr,
                            params[2].evec.get(i), params[2].lvec.get(i));
                    }
                }
                return;
            }
            case 23: {
                //# line 833
                params[0].stmt = new Tree.Break(params[1].loc);
                return;
            }
            case 24: {
                //# line 446
                params[0].svec = new Vector<Integer>();
                params[0].lvec = new Vector<Location>();
                params[0].evec = new Vector<Expr>();
                params[0].svec.add(params[1].counter);
                params[0].lvec.add(params[1].loc);
                params[0].evec.add(params[2].expr);
                if (params[3].svec != null) {
                    params[0].svec.addAll(params[3].svec);
                    params[0].lvec.addAll(params[3].lvec);
                    params[0].evec.addAll(params[3].evec);
                }
                return;
            }
            case 25: {
                /* no action */
                return;
            }
            case 26: {
                //# line 872
                params[0].stmt = new PrintComp(params[3].elist, params[1].loc);
                return;
            }
            case 27: {
                //# line 209
                params[0].slist.add(params[1].stmt);
                params[0].slist.addAll(params[2].slist);
                return;
            }
            case 28: {
                /* no action */
                return;
            }
            case 29: {
                //# line 780
                params[0].expr = new Tree.Literal(params[1].typeTag, params[1].literal, params[1].loc);
                return;
            }
            case 30: {
                //# line 784
                params[0].expr = new Null(params[1].loc);
                return;
            }
            case 31: {
                //# line 192
                params[0].vlist = new ArrayList<VarDef>();
                params[0].vlist.add(params[2].vdef);
                if (params[3].vlist != null) {
                    params[0].vlist.addAll(params[3].vlist);
                }
                return;
            }
            case 32: {
                /* no action */
                return;
            }
            case 33: {
                //# line 865
                params[0].stmt = new Tree.Print(params[3].elist, params[1].loc);
                return;
            }
            case 34: {
                //# line 827
                params[0].stmt = new Tree.ForLoop(params[3].stmt, params[5].expr, params[7].stmt, params[9].stmt, params[1].loc);
                return;
            }
            case 35: {
                //# line 641
                params[0].expr = params[1].expr;
                return;
            }
            case 36: {
                //# line 645
                params[0].expr = new Tree.ReadIntExpr(params[1].loc);
                return;
            }
            case 37: {
                //# line 649
                params[0].expr = new Tree.ReadLineExpr(params[1].loc);
                return;
            }
            case 38: {
                //# line 653
                params[0].expr = new Tree.ThisExpr(params[1].loc);
                return;
            }
            case 39: {
                //# line 658
                params[0].expr = new Tree.SuperExpr(params[1].loc);
                return;
            }
            case 40: {
                //# line 663
                if (params[2].ident != null) {
                    params[0].expr = new Tree.NewClass(params[2].ident, params[1].loc);
                } else {
                    params[0].expr = new Tree.NewArray(params[2].type, params[2].expr, params[1].loc);
                }
                return;
            }
            case 41: {
                //# line 671
                params[0].expr = new Tree.TypeTest(params[3].expr, params[5].ident, params[1].loc);
                return;
            }
            case 42: {
                //# line 675
                params[0].expr = params[2].expr;
                return;
            }
            case 43: {
                //# line 679
                if (params[2].elist != null) {
                    params[0].expr = new Tree.CallExpr(null, params[1].ident, params[2].elist, params[1].loc);
                } else {
                    params[0].expr = new Tree.Ident(null, params[1].ident, params[1].loc);
                }
                return;
            }
            case 44: {
                //# line 688
                params[0].expr = params[1].expr;
                return;
            }
            case 45: {
                //# line 695
                params[0].expr = new DcopyExpr(params[3].expr, params[1].loc);
                return;
            }
            case 46: {
                //# line 699
                params[0].expr = new ScopyExpr(params[3].expr, params[1].loc);
                return;
            }
            case 47: {
                //# line 705
                params[0].expr = new Tree.Unary(params[1].counter, params[2].expr, params[1].loc);
                return;
            }
            case 48: {
                //# line 405
                params[0].expr = params[1].expr;
                if (params[2].svec != null) {
                    for (int i = 0; i < params[2].svec.size(); ++i) {
                        params[0].expr = new Tree.Binary(params[2].svec.get(i), params[0].expr,
                            params[2].evec.get(i), params[2].lvec.get(i));
                    }
                }
                return;
            }
            case 49: {
                //# line 291
                params[0].counter = Tree.OR;
                params[0].loc = params[1].loc;
                return;
            }
            case 50: {
                //# line 845
                params[0].stmt = params[2].stmt;
                return;
            }
            case 51: {
                /* no action */
                return;
            }
            case 52: {
                //# line 132
                params[0].flist = new ArrayList<Tree>();
                if (params[1].vdef != null) {
                    params[0].flist.add(params[1].vdef);
                } else {
                    params[0].flist.add(params[1].fdef);
                }
                params[0].flist.addAll(params[2].flist);
                return;
            }
            case 53: {
                //# line 142
                params[0].flist = new ArrayList<Tree>();
                return;
            }
            case 54: {
                //# line 717
                params[0].expr = new Tree.ACaseExpr(params[1].expr, params[3].expr, params[2].loc);
                return;
            }
            case 55: {
                //# line 808
                params[0].elist = new ArrayList<Tree.Expr>();
                params[0].elist.add(params[2].expr);
                params[0].elist.addAll(params[3].elist);
                return;
            }
            case 56: {
                //# line 814
                params[0].elist = new ArrayList<Tree.Expr>();
                return;
            }
            case 57: {
                //# line 768
                params[0].expr = params[1].expr;
                return;
            }
            case 58: {
                //# line 772
                params[0].expr = new Tree.TypeCast(params[2].ident, params[4].expr, params[4].loc);
                return;
            }
            case 59: {
                //# line 119
                params[0].cdef = new Tree.ClassDef(params[2].ident, params[3].ident, params[5].flist, params[1].loc);
                return;
            }
            case 60: {
                //# line 852
                params[0].stmt = new Tree.Return(params[2].expr, params[1].loc);
                return;
            }
            case 61: {
                //# line 800
                params[0].elist = new ArrayList<Tree.Expr>();
                params[0].elist.add(params[1].expr);
                params[0].elist.addAll(params[2].elist);
                return;
            }
            case 62: {
                //# line 203
                params[0].stmt = new Tree.Block(params[2].slist, params[1].loc);
                return;
            }
            case 63: {
                //# line 164
                params[0].vlist = params[2].vlist;
                params[0].stmt = params[4].stmt;
                return;
            }
            case 64: {
                /* no action */
                return;
            }
            case 65: {
                //# line 634
                params[0].elist = params[2].elist;
                return;
            }
            case 66: {
                /* no action */
                return;
            }
            case 67: {
                //# line 898
                params[0].stmt = new DoStmt(params[2].slist, params[1].loc);
                return;
            }
            case 68: {
                //# line 40
                params[0].clist = new ArrayList<ClassDef>();
                params[0].clist.add(params[1].cdef);
                if (params[2].clist != null) {
                    params[0].clist.addAll(params[2].clist);
                }
                params[0].prog = new Tree.TopLevel(params[0].clist, params[0].loc);
                return;
            }
            case 69: {
                //# line 399
                params[0].expr = params[1].expr;
                return;
            }
            case 70: {
                //# line 735
                params[0].expr = new Tree.CaseExpr(params[3].expr, params[6].elist, params[7].expr, params[1].loc);
                return;
            }
            case 71: {
                //# line 100
                params[0].type = params[1].type;
                for (int i = 0; i < params[2].counter; ++i) {
                    params[0].type = new Tree.TypeArray(params[0].type, params[1].loc);
                }
                return;
            }
            case 72: {
                //# line 521
                params[0].expr = params[1].expr;
                if (params[2].svec != null) {
                    for (int i = 0; i < params[2].svec.size(); ++i) {
                        params[0].expr = new Tree.Binary(params[2].svec.get(i), params[0].expr,
                            params[2].evec.get(i), params[2].lvec.get(i));
                    }
                }
                return;
            }
            case 73: {
                //# line 742
                params[0].ident = params[1].ident;
                return;
            }
            case 74: {
                //# line 746
                params[0].type = params[1].type;
                for (int i = 0; i < params[3].counter; ++i) {
                    params[0].type = new Tree.TypeArray(params[0].type, params[1].loc);
                }
                params[0].expr = params[3].expr;
                return;
            }
            case 75: {
                //# line 282
                params[0].loc = params[1].loc;
                params[0].expr = params[2].expr;
                return;
            }
            case 76: {
                /* no action */
                return;
            }
            case 77: {
                //# line 125
                params[0].ident = params[2].ident;
                return;
            }
            case 78: {
                /* no action */
                return;
            }
            case 79: {
                //# line 339
                params[0].counter = Tree.PLUS;
                params[0].loc = params[1].loc;
                return;
            }
            case 80: {
                //# line 344
                params[0].counter = Tree.MINUS;
                params[0].loc = params[1].loc;
                return;
            }
            case 81: {
                //# line 723
                params[0].elist = new ArrayList<Tree.Expr>();
                params[0].elist.add(params[1].expr);
                params[0].elist.addAll(params[2].elist);
                return;
            }
            case 82: {
                //# line 729
                params[0].elist = new ArrayList<Tree.Expr>();
                return;
            }
            case 83: {
                //# line 109
                params[0].counter = 1 + params[3].counter;
                return;
            }
            case 84: {
                //# line 113
                params[0].counter = 0;
                return;
            }
            case 85: {
                //# line 463
                params[0].expr = params[1].expr;
                if (params[2].svec != null) {
                    for (int i = 0; i < params[2].svec.size(); ++i) {
                        params[0].expr = new Tree.Binary(params[2].svec.get(i), params[0].expr,
                            params[2].evec.get(i), params[2].lvec.get(i));
                    }
                }
                return;
            }
            case 86: {
                //# line 790
                params[0].elist = params[1].elist;
                return;
            }
            case 87: {
                //# line 794
                params[0].elist = new ArrayList<Tree.Expr>();
                return;
            }
            case 88: {
                //# line 68
                params[0].vdef = new Tree.VarDef(params[2].ident, params[1].type, params[2].loc);
                return;
            }
            case 89: {
                //# line 475
                params[0].svec = new Vector<Integer>();
                params[0].lvec = new Vector<Location>();
                params[0].evec = new Vector<Expr>();
                params[0].svec.add(params[1].counter);
                params[0].lvec.add(params[1].loc);
                params[0].evec.add(params[2].expr);
                if (params[3].svec != null) {
                    params[0].svec.addAll(params[3].svec);
                    params[0].lvec.addAll(params[3].lvec);
                    params[0].evec.addAll(params[3].evec);
                }
                return;
            }
            case 90: {
                /* no action */
                return;
            }
            case 91: {
                //# line 217
                params[0].stmt = params[1].vdef;
                return;
            }
            case 92: {
                //# line 221
                if (params[1].stmt == null) {
                    params[0].stmt = new Tree.Skip(params[2].loc);
                } else {
                    params[0].stmt = params[1].stmt;
                }
                return;
            }
            case 93: {
                //# line 229
                params[0].stmt = params[1].stmt;
                return;
            }
            case 94: {
                //# line 233
                params[0].stmt = params[1].stmt;
                return;
            }
            case 95: {
                //# line 237
                params[0].stmt = params[1].stmt;
                return;
            }
            case 96: {
                //# line 241
                params[0].stmt = params[1].stmt;
                return;
            }
            case 97: {
                //# line 245
                params[0].stmt = params[1].stmt;
                return;
            }
            case 98: {
                //# line 249
                params[0].stmt = params[1].stmt;
                return;
            }
            case 99: {
                //# line 253
                params[0].stmt = params[1].stmt;
                return;
            }
            case 100: {
                //# line 258
                params[0].stmt = params[1].stmt;
                return;
            }
            case 101: {
                //# line 264
                params[0].stmt = params[1].stmt;
                return;
            }
            case 102: {
                //# line 271
                if (params[2].expr == null) {
                    params[0].stmt = new Tree.Calculate(params[1].expr, params[1].loc);
                } else {
                    params[0].stmt = new Tree.Assign(params[1].expr, params[2].expr, params[2].loc);
                }
                return;
            }
            case 103: {
                /* no action */
                return;
            }
            case 104: {
                //# line 74
                params[0].type = new Tree.TypeIdent(Tree.INT, params[1].loc);
                return;
            }
            case 105: {
                //# line 78
                params[0].type = new Tree.TypeIdent(Tree.VOID, params[1].loc);
                return;
            }
            case 106: {
                //# line 82
                params[0].type = new Tree.TypeIdent(Tree.BOOL, params[1].loc);
                return;
            }
            case 107: {
                //# line 86
                params[0].type = new Tree.TypeIdent(Tree.STRING, params[1].loc);
                return;
            }
            case 108: {
                //# line 90
                params[0].type = new Tree.TypeIdent(Tree.COMPLEX, params[1].loc);
                return;
            }
            case 109: {
                //# line 94
                params[0].type = new Tree.TypeClass(params[2].ident, params[1].loc);
                return;
            }
            case 110: {
                //# line 821
                params[0].stmt = new Tree.WhileLoop(params[3].expr, params[5].stmt, params[1].loc);
                return;
            }
            case 111: {
                //# line 417
                params[0].svec = new Vector<Integer>();
                params[0].lvec = new Vector<Location>();
                params[0].evec = new Vector<Expr>();
                params[0].svec.add(params[1].counter);
                params[0].lvec.add(params[1].loc);
                params[0].evec.add(params[2].expr);
                if (params[3].svec != null) {
                    params[0].svec.addAll(params[3].svec);
                    params[0].lvec.addAll(params[3].lvec);
                    params[0].evec.addAll(params[3].evec);
                }
                return;
            }
            case 112: {
                /* no action */
                return;
            }
            case 113: {
                //# line 492
                params[0].expr = params[1].expr;
                if (params[2].svec != null) {
                    for (int i = 0; i < params[2].svec.size(); ++i) {
                        params[0].expr = new Tree.Binary(params[2].svec.get(i), params[0].expr,
                            params[2].evec.get(i), params[2].lvec.get(i));
                    }
                }
                return;
            }
            case 114: {
                //# line 504
                params[0].svec = new Vector<Integer>();
                params[0].lvec = new Vector<Location>();
                params[0].evec = new Vector<Expr>();
                params[0].svec.add(params[1].counter);
                params[0].lvec.add(params[1].loc);
                params[0].evec.add(params[2].expr);
                if (params[3].svec != null) {
                    params[0].svec.addAll(params[3].svec);
                    params[0].lvec.addAll(params[3].lvec);
                    params[0].evec.addAll(params[3].evec);
                }
                return;
            }
            case 115: {
                /* no action */
                return;
            }
            case 116: {
                //# line 858
                params[0].expr = params[1].expr;
                return;
            }
            case 117: {
                /* no action */
                return;
            }
            case 118: {
                //# line 839
                params[0].stmt = new Tree.If(params[3].expr, params[5].stmt, params[6].stmt, params[1].loc);
                return;
            }
            case 119: {
                //# line 562
                params[0].svec = new Vector<Integer>();
                params[0].lvec = new Vector<Location>();
                params[0].evec = new Vector<Expr>();
                params[0].svec.add(params[1].counter);
                params[0].lvec.add(params[1].loc);
                params[0].evec.add(params[2].expr);
                if (params[3].svec != null) {
                    params[0].svec.addAll(params[3].svec);
                    params[0].lvec.addAll(params[3].lvec);
                    params[0].evec.addAll(params[3].evec);
                }
                return;
            }
            case 120: {
                /* no action */
                return;
            }
            case 121: {
                //# line 885
                params[0].slist.add(params[2].stmt);
                params[0].slist.addAll(params[3].slist);
                return;
            }
            case 122: {
                /* no action */
                return;
            }
            case 123: {
                //# line 892
                params[0].slist.add(params[1].stmt);
                params[0].slist.addAll(params[2].slist);
                return;
            }
            case 124: {
                //# line 609
                SemValue sem = new SemValue();
                sem.expr = params[2].expr;
                params[0].vec = new Vector<SemValue>();
                params[0].vec.add(sem);
                if (params[4].vec != null) {
                    params[0].vec.addAll(params[4].vec);
                }
                return;
            }
            case 125: {
                //# line 619
                SemValue sem = new SemValue();
                sem.ident = params[2].ident;
                sem.loc = params[2].loc;
                sem.elist = params[3].elist;
                params[0].vec = new Vector<SemValue>();
                params[0].vec.add(sem);
                if (params[4].vec != null) {
                    params[0].vec.addAll(params[4].vec);
                }
                return;
            }
            case 126: {
                /* no action */
                return;
            }
            case 127: {
                //# line 711
                params[0].expr = new Tree.DefaultExpr(params[3].expr, params[1].loc);
                return;
            }
            case 128: {
                //# line 579
                params[0].expr = new Tree.Unary(params[1].counter, params[2].expr, params[1].loc);
                return;
            }
            case 129: {
                //# line 583
                params[0].expr = params[1].expr;
                return;
            }
            case 130: {
                //# line 51
                params[0].clist = new ArrayList<ClassDef>();
                params[0].clist.add(params[1].cdef);
                if (params[2].clist != null) {
                    params[0].clist.addAll(params[2].clist);
                }
                return;
            }
            case 131: {
                /* no action */
                return;
            }
            case 132: {
                //# line 317
                params[0].counter = Tree.LE;
                params[0].loc = params[1].loc;
                return;
            }
            case 133: {
                //# line 322
                params[0].counter = Tree.GE;
                params[0].loc = params[1].loc;
                return;
            }
            case 134: {
                //# line 327
                params[0].counter = Tree.LT;
                params[0].loc = params[1].loc;
                return;
            }
            case 135: {
                //# line 332
                params[0].counter = Tree.GT;
                params[0].loc = params[1].loc;
                return;
            }
            case 136: {
                //# line 148
                params[0].fdef = new Tree.MethodDef(true, params[3].ident, params[2].type, params[5].vlist,
                    (Block) params[7].stmt, params[3].loc);
                return;
            }
            case 137: {
                //# line 153
                if (params[3].vlist != null) {
                    params[0].fdef = new Tree.MethodDef(false, params[2].ident, params[1].type, params[3].vlist,
                        (Block) params[3].stmt, params[2].loc);
                } else {
                    params[0].vdef = new Tree.VarDef(params[2].ident, params[1].type, params[2].loc);
                }
                return;
            }
        }
    }
}
/* end of file */
