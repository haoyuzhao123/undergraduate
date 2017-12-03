//### This file created by BYACC 1.8(/Java extension  1.13)
//### Java capabilities added 7 Jan 97, Bob Jamison
//### Updated : 27 Nov 97  -- Bob Jamison, Joe Nieten
//###           01 Jan 98  -- Bob Jamison -- fixed generic semantic constructor
//###           01 Jun 99  -- Bob Jamison -- added Runnable support
//###           06 Aug 00  -- Bob Jamison -- made state variables class-global
//###           03 Jan 01  -- Bob Jamison -- improved flags, tracing
//###           16 May 01  -- Bob Jamison -- added custom stack sizing
//###           04 Mar 02  -- Yuval Oren  -- improved java performance, added options
//###           14 Mar 02  -- Tomas Hurka -- -d support, static initializer workaround
//###           14 Sep 06  -- Keltin Leung-- ReduceListener support, eliminate underflow report in error recovery
//### Please send bug reports to tom@hukatronic.cz
//### static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";






//#line 11 "Parser.y"
package decaf.frontend;

import decaf.tree.Tree;
import decaf.tree.Tree.*;
import decaf.error.*;
import java.util.*;
//#line 25 "Parser.java"
interface ReduceListener {
  public boolean onReduce(String rule);
}




public class Parser
             extends BaseParser
             implements ReduceListener
{

boolean yydebug;        //do I want debug output?
int yynerrs;            //number of errors so far
int yyerrflag;          //was there an error?
int yychar;             //the current working character

ReduceListener reduceListener = null;
void yyclearin ()       {yychar = (-1);}
void yyerrok ()         {yyerrflag=0;}
void addReduceListener(ReduceListener l) {
  reduceListener = l;}


//########## MESSAGES ##########
//###############################################################
// method: debug
//###############################################################
void debug(String msg)
{
  if (yydebug)
    System.out.println(msg);
}

//########## STATE STACK ##########
final static int YYSTACKSIZE = 500;  //maximum stack size
int statestk[] = new int[YYSTACKSIZE]; //state stack
int stateptr;
int stateptrmax;                     //highest index of stackptr
int statemax;                        //state when highest index reached
//###############################################################
// methods: state stack push,pop,drop,peek
//###############################################################
final void state_push(int state)
{
  try {
		stateptr++;
		statestk[stateptr]=state;
	 }
	 catch (ArrayIndexOutOfBoundsException e) {
     int oldsize = statestk.length;
     int newsize = oldsize * 2;
     int[] newstack = new int[newsize];
     System.arraycopy(statestk,0,newstack,0,oldsize);
     statestk = newstack;
     statestk[stateptr]=state;
  }
}
final int state_pop()
{
  return statestk[stateptr--];
}
final void state_drop(int cnt)
{
  stateptr -= cnt; 
}
final int state_peek(int relative)
{
  return statestk[stateptr-relative];
}
//###############################################################
// method: init_stacks : allocate and prepare stacks
//###############################################################
final boolean init_stacks()
{
  stateptr = -1;
  val_init();
  return true;
}
//###############################################################
// method: dump_stacks : show n levels of the stacks
//###############################################################
void dump_stacks(int count)
{
int i;
  System.out.println("=index==state====value=     s:"+stateptr+"  v:"+valptr);
  for (i=0;i<count;i++)
    System.out.println(" "+i+"    "+statestk[i]+"      "+valstk[i]);
  System.out.println("======================");
}


//########## SEMANTIC VALUES ##########
//## **user defined:SemValue
String   yytext;//user variable to return contextual strings
SemValue yyval; //used to return semantic vals from action routines
SemValue yylval;//the 'lval' (result) I got from yylex()
SemValue valstk[] = new SemValue[YYSTACKSIZE];
int valptr;
//###############################################################
// methods: value stack push,pop,drop,peek.
//###############################################################
final void val_init()
{
  yyval=new SemValue();
  yylval=new SemValue();
  valptr=-1;
}
final void val_push(SemValue val)
{
  try {
    valptr++;
    valstk[valptr]=val;
  }
  catch (ArrayIndexOutOfBoundsException e) {
    int oldsize = valstk.length;
    int newsize = oldsize*2;
    SemValue[] newstack = new SemValue[newsize];
    System.arraycopy(valstk,0,newstack,0,oldsize);
    valstk = newstack;
    valstk[valptr]=val;
  }
}
final SemValue val_pop()
{
  return valstk[valptr--];
}
final void val_drop(int cnt)
{
  valptr -= cnt;
}
final SemValue val_peek(int relative)
{
  return valstk[valptr-relative];
}
//#### end semantic value section ####
public final static short VOID=257;
public final static short BOOL=258;
public final static short INT=259;
public final static short STRING=260;
public final static short COMPLEX=261;
public final static short CLASS=262;
public final static short NULL=263;
public final static short EXTENDS=264;
public final static short THIS=265;
public final static short WHILE=266;
public final static short FOR=267;
public final static short SUPER=268;
public final static short IF=269;
public final static short ELSE=270;
public final static short RETURN=271;
public final static short BREAK=272;
public final static short NEW=273;
public final static short DO=274;
public final static short OD=275;
public final static short DCOPY=276;
public final static short SCOPY=277;
public final static short PRINT=278;
public final static short READ_INTEGER=279;
public final static short READ_LINE=280;
public final static short PRINTCOMP=281;
public final static short LITERAL=282;
public final static short IDENTIFIER=283;
public final static short AND=284;
public final static short OR=285;
public final static short STATIC=286;
public final static short INSTANCEOF=287;
public final static short LESS_EQUAL=288;
public final static short GREATER_EQUAL=289;
public final static short EQUAL=290;
public final static short NOT_EQUAL=291;
public final static short VERTS=292;
public final static short CASE=293;
public final static short DEFAULT=294;
public final static short UMINUS=295;
public final static short EMPTY=296;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    1,    1,    3,    4,    5,    5,    5,    5,    5,
    5,    5,    2,    6,    6,    7,    7,    7,    9,    9,
   10,   10,    8,    8,   11,   12,   12,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   14,   14,
   14,   26,   26,   23,   23,   25,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   29,
   29,   30,   30,   32,   31,   28,   28,   27,   27,   33,
   33,   16,   17,   20,   15,   34,   34,   18,   18,   19,
   21,   35,   36,   37,   37,   38,   22,
};
final static short yylen[] = {                            2,
    1,    2,    1,    2,    2,    1,    1,    1,    1,    1,
    2,    3,    6,    2,    0,    2,    2,    0,    1,    0,
    3,    1,    7,    6,    3,    2,    0,    1,    2,    1,
    1,    1,    2,    2,    2,    1,    2,    1,    3,    1,
    0,    2,    0,    2,    4,    5,    1,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    2,    2,    2,    2,    3,    3,
    1,    1,    4,    5,    6,    5,    1,    4,    4,    8,
    7,    2,    1,    4,    4,    1,    1,    1,    0,    3,
    1,    5,    9,    1,    6,    2,    0,    2,    1,    4,
    4,    3,    2,    2,    0,    2,    4,
};
final static short yydefred[] = {                         0,
    0,    0,    0,    3,    0,    2,    0,    0,   14,   18,
    0,    7,    8,    6,    9,   10,    0,    0,   13,   16,
    0,    0,   17,   11,    0,    4,    0,    0,    0,    0,
   12,    0,   22,    0,    0,    0,    0,    5,    0,    0,
    0,   27,   24,   21,   23,    0,   87,   71,    0,    0,
   72,    0,    0,   94,    0,  105,    0,    0,    0,    0,
    0,    0,   86,    0,    0,    0,    0,    0,    0,    0,
   25,    0,   28,   36,   26,    0,   30,   31,   32,    0,
    0,    0,    0,   38,    0,    0,    0,    0,   49,   77,
    0,    0,    0,   47,    0,   48,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   66,   67,
   68,    0,    0,    0,    0,   29,   33,   34,   35,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   42,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  104,    0,    0,    0,    0,    0,
   69,   70,    0,    0,    0,   63,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   73,    0,    0,  103,
  107,   78,   79,    0,  100,  101,    0,    0,    0,   45,
    0,    0,   92,    0,    0,   74,  102,    0,    0,   76,
    0,   46,    0,    0,   95,   75,    0,    0,    0,    0,
   83,    0,   96,    0,    0,    0,   82,   81,    0,    0,
    0,   80,   93,   85,   84,
};
final static short yydgoto[] = {                          2,
    3,    4,   73,   21,   34,    8,   11,   23,   35,   36,
   74,   46,   75,   76,   77,   78,   79,   80,   81,   82,
   83,   84,   94,   86,   96,   88,  191,   89,   90,  209,
  210,  211,  150,  205,  144,  145,   99,  100,
};
final static short yysindex[] = {                      -253,
 -249,    0, -253,    0, -202,    0, -200,  -34,    0,    0,
  -71,    0,    0,    0,    0,    0, -192,  251,    0,    0,
   34,  -90,    0,    0,  -74,    0,   60,    8,   68,  251,
    0,  251,    0,  -73,   69,   67,   71,    0,   -5,  251,
   -5,    0,    0,    0,    0,    4,    0,    0,   74,   79,
    0,   81,   98,    0, -238,    0,   82,   88,   90,   92,
   95,   96,    0,   97,   98,   98,   98,   98,   98,   62,
    0,   99,    0,    0,    0,   83,    0,    0,    0,   87,
  100,  102,  106,    0,   86,  919,    0, -143,    0,    0,
   98,   98,   98,    0,  919,    0,  101,   66,   98, -119,
   98,   98,   98,  130,  131,   98,   98,  -38,    0,    0,
    0,  -38, -109,  460,   98,    0,    0,    0,    0,    0,
   98,   98,   98,   98,   98,   98,   98,   98,   98,   98,
   98,   98,   98,   98,    0,   98,  136,  487,  125,  498,
  151,   80,  519,  -98,    0,  143,  545,  556,  919,   29,
    0,    0,   38,  577,  154,    0,  588,  919,  972,  951,
  629,  629,  -32,  -32,   57,   57,  -38,  -38,  -38,  629,
  629,  646,   98,   41,   98,   41,    0,  847,   41,    0,
    0,    0,    0,   98,    0,    0,  -79,   98,   84,    0,
  164,  167,    0,  858,  -62,    0,    0,  919,  172,    0,
 -222,    0,   98,   41,    0,    0,  156,  158, -222,   93,
    0,  176,    0,   98,   98,   94,    0,    0,   41,  882,
  908,    0,    0,    0,    0,
};
final static short yyrindex[] = {                         0,
    0,    0,  222,    0,  114,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  192,    0,    0,  182,
    0,  182,    0,    0,    0,  211,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -30,    0,    0,    0,    0,
    0,    0,   -4,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -15,  -15,  -15,  -15,  -15,  -15,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  940,    0,    5,    0,    0,    0,
  -15,  -30,  -15,    0,  228,    0,    0,    0,  -15,    0,
  -15,  -15,  -15,    0,    0,  -15,  -15,  138,    0,    0,
    0,  372,    0,    0,  -15,    0,    0,    0,    0,    0,
  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
  -15,  -15,  -15,  -15,    0,  -15,  108,    0,    0,    0,
    0,  -15,    0,   13,    0,    0,    0,    0,   43,    0,
    0,    0,    0,    0,    0,    0,    0,   16,  119,   65,
  162,  798,  288,  328,  755,  962,  396,  425,  434,  839,
  992,    0,  -25,  -30,  -15,  -30,    0,    0,  -30,    0,
    0,    0,    0,  -15,    0,    0,    0,  -15,    0,    0,
    0,  264,    0,    0,  -33,    0,    0,   44,    0,    0,
    0,    0,   -9,  -30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -15,  -15,    0,    0,    0,  -30,    0,
    0,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
    0,  289,  300,   26,   25,    0,    0,    0,  284,    0,
  -14,    0, -141,  -86,    0,    0,    0,    0,    0,    0,
    0,    0,  523, 1201,  554,    0,    0, -140,    0,    0,
  117,  122, -102,    0,    0,    0,    0,    0,
};
final static int YYTABLESIZE=1416;
static short yytable[];
static { yytable();}
static void yytable(){
yytable = new short[]{                         97,
   28,   97,   97,  153,  132,  139,   97,  135,    1,  130,
  128,   97,  129,  135,  131,   89,   28,   28,   12,   13,
   14,   15,   16,   17,   43,   97,   45,  134,   41,  133,
   97,   41,  193,    5,  195,   22,   69,  197,   68,   67,
   47,   48,   25,   70,   97,   40,   48,   48,   65,   48,
   48,   48,  136,   19,   99,   33,   39,   33,  136,   63,
  208,    7,  213,   40,   48,   44,   48,   66,  208,  185,
  192,  207,  184,   69,   39,   68,   67,  223,  186,   98,
   70,  184,    9,   91,   90,   65,   91,   90,   10,   97,
   24,   97,   26,  132,   69,   48,   68,   67,  130,   30,
   31,   70,  135,  131,   66,   62,   65,   32,   62,   39,
   40,   41,   69,   91,   68,   67,  212,   42,   92,   70,
   93,  101,   62,   62,   65,   66,   42,  102,   71,  103,
   69,  104,   68,   67,  105,  106,  107,   70,  115,  137,
  141,  116,   65,   66,   44,  117,  121,  136,   44,   44,
   44,   44,   44,   44,   44,  146,  142,   62,  118,   61,
  119,   66,   61,   42,  120,   44,   44,   44,   44,   44,
  151,  152,   31,  155,   64,  173,   61,   61,   64,   64,
   64,   64,   64,  175,   64,   12,   13,   14,   15,   16,
   17,  177,   27,  180,  188,   64,   64,   64,   44,   64,
   44,  181,   59,  199,  202,   59,  201,  204,   29,   38,
  184,   61,  206,  214,   18,  215,  219,  218,  222,   59,
   59,    1,   20,   97,   97,   97,   97,   97,   97,   97,
   64,   97,   97,   97,   97,   97,   15,   97,   97,   97,
   97,   97,   97,   97,   97,   97,   97,   97,   97,   97,
    5,   19,   43,   97,   59,  124,  125,   43,   97,   97,
   12,   13,   14,   15,   16,   17,   47,   43,   48,   49,
   50,   51,   52,   43,   53,   54,   55,   56,   43,   57,
   58,   59,   60,   61,   62,   63,   98,  106,   48,   48,
   64,    6,   48,   48,   48,   48,   72,   12,   13,   14,
   15,   16,   17,   47,   88,   48,   49,   50,   51,   52,
   20,   53,   54,   55,   56,   37,   57,   58,   59,   60,
   61,   62,   63,  113,   47,  216,   48,   64,   55,   51,
  217,   55,    0,   72,   55,    0,    0,   57,   58,    0,
   60,   61,   47,   63,   48,   55,   55,   51,   64,   62,
    0,    0,   55,    0,   72,   57,   58,    0,   60,   61,
   47,   63,   48,    0,    0,   51,   64,    0,   56,    0,
   55,   56,   72,   57,   58,    0,   60,   61,    0,   63,
   55,    0,    0,    0,   64,   56,   56,    0,    0,    0,
   72,   44,   44,    0,    0,   44,   44,   44,   44,    0,
    0,    0,   61,   61,    0,    0,    0,    0,   65,    0,
    0,    0,   65,   65,   65,   65,   65,    0,   65,    0,
   56,   64,   64,    0,    0,   64,   64,   64,   64,   65,
   65,   65,   52,   65,    0,    0,   52,   52,   52,   52,
   52,    0,   52,    0,    0,   59,   59,    0,    0,    0,
    0,   59,   59,   52,   52,   52,    0,   52,    0,    0,
    0,   53,    0,    0,   65,   53,   53,   53,   53,   53,
   54,   53,    0,    0,   54,   54,   54,   54,   54,    0,
   54,    0,   53,   53,   53,    0,   53,    0,   52,    0,
    0,   54,   54,   54,    0,   54,  132,    0,    0,    0,
  156,  130,  128,    0,  129,  135,  131,   12,   13,   14,
   15,   16,   17,    0,    0,    0,    0,   53,    0,  134,
    0,  133,    0,  132,    0,    0,   54,  174,  130,  128,
    0,  129,  135,  131,  132,    0,    0,    0,  176,  130,
  128,    0,  129,  135,  131,    0,  134,    0,  133,    0,
  136,    0,    0,    0,    0,  132,    0,  134,    0,  133,
  130,  128,    0,  129,  135,  131,    0,    0,   85,    0,
    0,   55,   55,    0,    0,    0,  179,  136,  134,    0,
  133,  132,    0,    0,    0,  182,  130,  128,  136,  129,
  135,  131,  132,    0,    0,    0,  183,  130,  128,   87,
  129,  135,  131,    0,  134,    0,  133,    0,    0,  136,
    0,   56,   56,  132,   85,  134,    0,  133,  130,  128,
  187,  129,  135,  131,  132,    0,    0,    0,  189,  130,
  128,    0,  129,  135,  131,  136,  134,    0,  133,    0,
    0,    0,    0,    0,    0,   87,  136,  134,    0,  133,
    0,    0,    0,    0,    0,   65,   65,    0,    0,   65,
   65,   65,   65,    0,    0,  132,    0,  136,    0,    0,
  130,  128,    0,  129,  135,  131,    0,    0,  136,   52,
   52,    0,  132,   52,   52,   52,   52,  130,  128,    0,
  129,  135,  131,    0,    0,    0,   85,    0,   85,    0,
    0,   85,    0,    0,    0,  134,    0,  133,   53,   53,
    0,    0,   53,   53,   53,   53,    0,   54,   54,  136,
    0,   54,   54,   54,   54,   85,   85,   87,    0,   87,
    0,    0,   87,    0,    0,    0,  136,    0,  190,    0,
    0,   85,    0,  122,  123,    0,    0,  124,  125,  126,
  127,    0,    0,    0,    0,    0,   87,   87,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  122,  123,   87,    0,  124,  125,  126,  127,    0,    0,
    0,  122,  123,    0,    0,  124,  125,  126,  127,    0,
    0,    0,    0,    0,    0,   50,    0,   50,   50,   50,
    0,    0,  122,  123,    0,    0,  124,  125,  126,  127,
    0,    0,   50,   50,   50,    0,   50,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  122,  123,
    0,    0,  124,  125,  126,  127,    0,    0,   60,  122,
  123,   60,    0,  124,  125,  126,  127,   50,    0,    0,
    0,    0,    0,    0,    0,   60,   60,    0,    0,    0,
  122,  123,    0,    0,  124,  125,  126,  127,    0,    0,
    0,  122,  123,    0,    0,  124,  125,  126,  127,   58,
    0,    0,   58,  132,    0,    0,    0,    0,  130,  128,
   60,  129,  135,  131,  132,    0,   58,   58,    0,  130,
  128,    0,  129,  135,  131,    0,  134,    0,  133,    0,
    0,    0,    0,    0,    0,    0,  203,  134,  132,  133,
    0,    0,    0,  130,  128,    0,  129,  135,  131,  122,
  123,   58,    0,  124,  125,  126,  127,  136,    0,  196,
  224,  134,    0,  133,  132,    0,    0,    0,  136,  130,
  128,    0,  129,  135,  131,  132,    0,    0,    0,    0,
  130,  128,    0,  129,  135,  131,  225,  134,    0,  133,
    0,    0,  136,    0,    0,    0,   47,    0,  134,    0,
  133,   47,   47,    0,   47,   47,   47,  132,    0,    0,
    0,    0,  130,  128,    0,  129,  135,  131,  136,   47,
    0,   47,   51,    0,   51,   51,   51,    0,  132,  136,
  134,    0,  133,  130,  128,    0,  129,  135,  131,   51,
   51,   51,    0,   51,    0,    0,    0,    0,    0,    0,
   47,  134,   57,  133,    0,   57,    0,    0,   50,   50,
    0,  136,   50,   50,   50,   50,    0,    0,    0,   57,
   57,    0,    0,    0,   51,    0,    0,    0,    0,    0,
    0,    0,  136,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   60,   60,    0,   57,    0,    0,   60,   60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   58,   58,    0,    0,    0,    0,   58,   58,
  122,  123,    0,    0,  124,  125,  126,  127,    0,    0,
    0,  122,  123,    0,    0,  124,  125,  126,  127,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  122,  123,    0,    0,  124,
  125,  126,  127,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  122,  123,    0,    0,  124,  125,  126,  127,    0,
    0,    0,  122,  123,    0,    0,  124,  125,  126,  127,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   47,   47,    0,    0,   47,   47,   47,
   47,    0,    0,    0,  122,    0,    0,    0,  124,  125,
  126,  127,    0,    0,    0,   51,   51,    0,    0,   51,
   51,   51,   51,   95,    0,    0,    0,    0,    0,  124,
  125,  126,  127,    0,    0,  108,  109,  110,  111,  112,
  114,    0,    0,    0,    0,   57,   57,    0,    0,    0,
    0,   57,   57,    0,    0,    0,    0,    0,    0,    0,
    0,  138,    0,  140,    0,    0,    0,    0,    0,  143,
    0,  147,  148,  149,    0,    0,  149,  154,    0,    0,
    0,    0,    0,    0,    0,  157,    0,    0,    0,    0,
    0,  158,  159,  160,  161,  162,  163,  164,  165,  166,
  167,  168,  169,  170,  171,    0,  172,    0,    0,    0,
    0,    0,  178,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  149,    0,  194,    0,    0,    0,    0,
    0,    0,    0,    0,  198,    0,    0,    0,  200,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  220,  221,
};
}
static short yycheck[];
static { yycheck(); }
static void yycheck() {
yycheck = new short[] {                         33,
   91,   35,   36,  106,   37,   92,   40,   46,  262,   42,
   43,   45,   45,   46,   47,   41,   91,   91,  257,  258,
  259,  260,  261,  262,   39,   59,   41,   60,   59,   62,
   64,   41,  174,  283,  176,   11,   33,  179,   35,   36,
  263,   37,   18,   40,  283,   41,   42,   43,   45,   45,
   46,   47,   91,  125,   59,   30,   41,   32,   91,  282,
  201,  264,  204,   59,   60,   40,   62,   64,  209,   41,
  173,  294,   44,   33,   59,   35,   36,  219,   41,   55,
   40,   44,  283,   41,   41,   45,   44,   44,  123,  123,
  283,  125,   59,   37,   33,   91,   35,   36,   42,   40,
   93,   40,   46,   47,   64,   41,   45,   40,   44,   41,
   44,   41,   33,   40,   35,   36,  203,  123,   40,   40,
   40,   40,   58,   59,   45,   64,  123,   40,  125,   40,
   33,   40,   35,   36,   40,   40,   40,   40,   40,  283,
   40,   59,   45,   64,   37,   59,   61,   91,   41,   42,
   43,   44,   45,   46,   47,  275,   91,   93,   59,   41,
   59,   64,   44,  123,   59,   58,   59,   60,   61,   62,
   41,   41,   93,  283,   37,   40,   58,   59,   41,   42,
   43,   44,   45,   59,   47,  257,  258,  259,  260,  261,
  262,   41,  283,  292,   41,   58,   59,   60,   91,   62,
   93,   59,   41,  283,   41,   44,  123,  270,  283,  283,
   44,   93,   41,   58,  286,   58,   41,  125,  125,   58,
   59,    0,   41,  257,  258,  259,  260,  261,  262,  263,
   93,  265,  266,  267,  268,  269,  123,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
   59,   41,  283,  287,   93,  288,  289,  283,  292,  293,
  257,  258,  259,  260,  261,  262,  263,  283,  265,  266,
  267,  268,  269,  283,  271,  272,  273,  274,  283,  276,
  277,  278,  279,  280,  281,  282,   59,  275,  284,  285,
  287,    3,  288,  289,  290,  291,  293,  257,  258,  259,
  260,  261,  262,  263,   41,  265,  266,  267,  268,  269,
   11,  271,  272,  273,  274,   32,  276,  277,  278,  279,
  280,  281,  282,  262,  263,  209,  265,  287,   41,  268,
  209,   44,   -1,  293,  273,   -1,   -1,  276,  277,   -1,
  279,  280,  263,  282,  265,   58,   59,  268,  287,  285,
   -1,   -1,  273,   -1,  293,  276,  277,   -1,  279,  280,
  263,  282,  265,   -1,   -1,  268,  287,   -1,   41,   -1,
  273,   44,  293,  276,  277,   -1,  279,  280,   -1,  282,
   93,   -1,   -1,   -1,  287,   58,   59,   -1,   -1,   -1,
  293,  284,  285,   -1,   -1,  288,  289,  290,  291,   -1,
   -1,   -1,  284,  285,   -1,   -1,   -1,   -1,   37,   -1,
   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,
   93,  284,  285,   -1,   -1,  288,  289,  290,  291,   58,
   59,   60,   37,   62,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,  284,  285,   -1,   -1,   -1,
   -1,  290,  291,   58,   59,   60,   -1,   62,   -1,   -1,
   -1,   37,   -1,   -1,   93,   41,   42,   43,   44,   45,
   37,   47,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,   -1,   58,   59,   60,   -1,   62,   -1,   93,   -1,
   -1,   58,   59,   60,   -1,   62,   37,   -1,   -1,   -1,
   41,   42,   43,   -1,   45,   46,   47,  257,  258,  259,
  260,  261,  262,   -1,   -1,   -1,   -1,   93,   -1,   60,
   -1,   62,   -1,   37,   -1,   -1,   93,   41,   42,   43,
   -1,   45,   46,   47,   37,   -1,   -1,   -1,   41,   42,
   43,   -1,   45,   46,   47,   -1,   60,   -1,   62,   -1,
   91,   -1,   -1,   -1,   -1,   37,   -1,   60,   -1,   62,
   42,   43,   -1,   45,   46,   47,   -1,   -1,   46,   -1,
   -1,  284,  285,   -1,   -1,   -1,   58,   91,   60,   -1,
   62,   37,   -1,   -1,   -1,   41,   42,   43,   91,   45,
   46,   47,   37,   -1,   -1,   -1,   41,   42,   43,   46,
   45,   46,   47,   -1,   60,   -1,   62,   -1,   -1,   91,
   -1,  284,  285,   37,   92,   60,   -1,   62,   42,   43,
   44,   45,   46,   47,   37,   -1,   -1,   -1,   41,   42,
   43,   -1,   45,   46,   47,   91,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   92,   91,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,  284,  285,   -1,   -1,  288,
  289,  290,  291,   -1,   -1,   37,   -1,   91,   -1,   -1,
   42,   43,   -1,   45,   46,   47,   -1,   -1,   91,  284,
  285,   -1,   37,  288,  289,  290,  291,   42,   43,   -1,
   45,   46,   47,   -1,   -1,   -1,  174,   -1,  176,   -1,
   -1,  179,   -1,   -1,   -1,   60,   -1,   62,  284,  285,
   -1,   -1,  288,  289,  290,  291,   -1,  284,  285,   91,
   -1,  288,  289,  290,  291,  203,  204,  174,   -1,  176,
   -1,   -1,  179,   -1,   -1,   -1,   91,   -1,   93,   -1,
   -1,  219,   -1,  284,  285,   -1,   -1,  288,  289,  290,
  291,   -1,   -1,   -1,   -1,   -1,  203,  204,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  284,  285,  219,   -1,  288,  289,  290,  291,   -1,   -1,
   -1,  284,  285,   -1,   -1,  288,  289,  290,  291,   -1,
   -1,   -1,   -1,   -1,   -1,   41,   -1,   43,   44,   45,
   -1,   -1,  284,  285,   -1,   -1,  288,  289,  290,  291,
   -1,   -1,   58,   59,   60,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,
   -1,   -1,  288,  289,  290,  291,   -1,   -1,   41,  284,
  285,   44,   -1,  288,  289,  290,  291,   93,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   58,   59,   -1,   -1,   -1,
  284,  285,   -1,   -1,  288,  289,  290,  291,   -1,   -1,
   -1,  284,  285,   -1,   -1,  288,  289,  290,  291,   41,
   -1,   -1,   44,   37,   -1,   -1,   -1,   -1,   42,   43,
   93,   45,   46,   47,   37,   -1,   58,   59,   -1,   42,
   43,   -1,   45,   46,   47,   -1,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   37,   62,
   -1,   -1,   -1,   42,   43,   -1,   45,   46,   47,  284,
  285,   93,   -1,  288,  289,  290,  291,   91,   -1,   93,
   59,   60,   -1,   62,   37,   -1,   -1,   -1,   91,   42,
   43,   -1,   45,   46,   47,   37,   -1,   -1,   -1,   -1,
   42,   43,   -1,   45,   46,   47,   59,   60,   -1,   62,
   -1,   -1,   91,   -1,   -1,   -1,   37,   -1,   60,   -1,
   62,   42,   43,   -1,   45,   46,   47,   37,   -1,   -1,
   -1,   -1,   42,   43,   -1,   45,   46,   47,   91,   60,
   -1,   62,   41,   -1,   43,   44,   45,   -1,   37,   91,
   60,   -1,   62,   42,   43,   -1,   45,   46,   47,   58,
   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   91,   60,   41,   62,   -1,   44,   -1,   -1,  284,  285,
   -1,   91,  288,  289,  290,  291,   -1,   -1,   -1,   58,
   59,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   91,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  284,  285,   -1,   93,   -1,   -1,  290,  291,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  284,  285,   -1,   -1,   -1,   -1,  290,  291,
  284,  285,   -1,   -1,  288,  289,  290,  291,   -1,   -1,
   -1,  284,  285,   -1,   -1,  288,  289,  290,  291,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  284,  285,   -1,   -1,  288,
  289,  290,  291,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  284,  285,   -1,   -1,  288,  289,  290,  291,   -1,
   -1,   -1,  284,  285,   -1,   -1,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  284,  285,   -1,   -1,  288,  289,  290,
  291,   -1,   -1,   -1,  284,   -1,   -1,   -1,  288,  289,
  290,  291,   -1,   -1,   -1,  284,  285,   -1,   -1,  288,
  289,  290,  291,   53,   -1,   -1,   -1,   -1,   -1,  288,
  289,  290,  291,   -1,   -1,   65,   66,   67,   68,   69,
   70,   -1,   -1,   -1,   -1,  284,  285,   -1,   -1,   -1,
   -1,  290,  291,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   91,   -1,   93,   -1,   -1,   -1,   -1,   -1,   99,
   -1,  101,  102,  103,   -1,   -1,  106,  107,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  115,   -1,   -1,   -1,   -1,
   -1,  121,  122,  123,  124,  125,  126,  127,  128,  129,
  130,  131,  132,  133,  134,   -1,  136,   -1,   -1,   -1,
   -1,   -1,  142,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  173,   -1,  175,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  184,   -1,   -1,   -1,  188,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  214,  215,
};
}
final static short YYFINAL=2;
final static short YYMAXTOKEN=296;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,"'!'",null,"'#'","'$'","'%'",null,null,"'('","')'","'*'","'+'",
"','","'-'","'.'","'/'",null,null,null,null,null,null,null,null,null,null,"':'",
"';'","'<'","'='","'>'",null,"'@'",null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,"'['",null,"']'",null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,"'{'",null,"'}'",null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,"VOID","BOOL","INT","STRING",
"COMPLEX","CLASS","NULL","EXTENDS","THIS","WHILE","FOR","SUPER","IF","ELSE",
"RETURN","BREAK","NEW","DO","OD","DCOPY","SCOPY","PRINT","READ_INTEGER",
"READ_LINE","PRINTCOMP","LITERAL","IDENTIFIER","AND","OR","STATIC","INSTANCEOF",
"LESS_EQUAL","GREATER_EQUAL","EQUAL","NOT_EQUAL","VERTS","CASE","DEFAULT",
"UMINUS","EMPTY",
};
final static String yyrule[] = {
"$accept : Program",
"Program : ClassList",
"ClassList : ClassList ClassDef",
"ClassList : ClassDef",
"VariableDef : Variable ';'",
"Variable : Type IDENTIFIER",
"Type : INT",
"Type : VOID",
"Type : BOOL",
"Type : STRING",
"Type : COMPLEX",
"Type : CLASS IDENTIFIER",
"Type : Type '[' ']'",
"ClassDef : CLASS IDENTIFIER ExtendsClause '{' FieldList '}'",
"ExtendsClause : EXTENDS IDENTIFIER",
"ExtendsClause :",
"FieldList : FieldList VariableDef",
"FieldList : FieldList FunctionDef",
"FieldList :",
"Formals : VariableList",
"Formals :",
"VariableList : VariableList ',' Variable",
"VariableList : Variable",
"FunctionDef : STATIC Type IDENTIFIER '(' Formals ')' StmtBlock",
"FunctionDef : Type IDENTIFIER '(' Formals ')' StmtBlock",
"StmtBlock : '{' StmtList '}'",
"StmtList : StmtList Stmt",
"StmtList :",
"Stmt : VariableDef",
"Stmt : SimpleStmt ';'",
"Stmt : IfStmt",
"Stmt : WhileStmt",
"Stmt : ForStmt",
"Stmt : ReturnStmt ';'",
"Stmt : PrintStmt ';'",
"Stmt : BreakStmt ';'",
"Stmt : StmtBlock",
"Stmt : PrintCompStmt ';'",
"Stmt : DoStmt",
"SimpleStmt : LValue '=' Expr",
"SimpleStmt : Call",
"SimpleStmt :",
"Receiver : Expr '.'",
"Receiver :",
"LValue : Receiver IDENTIFIER",
"LValue : Expr '[' Expr ']'",
"Call : Receiver IDENTIFIER '(' Actuals ')'",
"Expr : LValue",
"Expr : Call",
"Expr : Constant",
"Expr : Expr '+' Expr",
"Expr : Expr '-' Expr",
"Expr : Expr '*' Expr",
"Expr : Expr '/' Expr",
"Expr : Expr '%' Expr",
"Expr : Expr EQUAL Expr",
"Expr : Expr NOT_EQUAL Expr",
"Expr : Expr '<' Expr",
"Expr : Expr '>' Expr",
"Expr : Expr LESS_EQUAL Expr",
"Expr : Expr GREATER_EQUAL Expr",
"Expr : Expr AND Expr",
"Expr : Expr OR Expr",
"Expr : '(' Expr ')'",
"Expr : '-' Expr",
"Expr : '!' Expr",
"Expr : '@' Expr",
"Expr : '$' Expr",
"Expr : '#' Expr",
"Expr : READ_INTEGER '(' ')'",
"Expr : READ_LINE '(' ')'",
"Expr : THIS",
"Expr : SUPER",
"Expr : NEW IDENTIFIER '(' ')'",
"Expr : NEW Type '[' Expr ']'",
"Expr : INSTANCEOF '(' Expr ',' IDENTIFIER ')'",
"Expr : '(' CLASS IDENTIFIER ')' Expr",
"Expr : CaseExpr",
"Expr : DCOPY '(' Expr ')'",
"Expr : SCOPY '(' Expr ')'",
"CaseExpr : CASE '(' Expr ')' '{' ACaseExprList DefaultExpr '}'",
"CaseExpr : CASE '(' Expr ')' '{' DefaultExpr '}'",
"ACaseExprList : ACaseExprList ACaseExpr",
"ACaseExprList : ACaseExpr",
"ACaseExpr : Constant ':' Expr ';'",
"DefaultExpr : DEFAULT ':' Expr ';'",
"Constant : LITERAL",
"Constant : NULL",
"Actuals : ExprList",
"Actuals :",
"ExprList : ExprList ',' Expr",
"ExprList : Expr",
"WhileStmt : WHILE '(' Expr ')' Stmt",
"ForStmt : FOR '(' SimpleStmt ';' Expr ';' SimpleStmt ')' Stmt",
"BreakStmt : BREAK",
"IfStmt : IF '(' Expr ')' Stmt ElseClause",
"ElseClause : ELSE Stmt",
"ElseClause :",
"ReturnStmt : RETURN Expr",
"ReturnStmt : RETURN",
"PrintStmt : PRINT '(' ExprList ')'",
"PrintCompStmt : PRINTCOMP '(' ExprList ')'",
"DoSubStmt : Expr ':' Stmt",
"DoBranch : DoSubStmt VERTS",
"DoBranchList : DoBranchList DoBranch",
"DoBranchList :",
"DoList : DoBranchList DoSubStmt",
"DoStmt : DO DoList OD ';'",
};

//#line 560 "Parser.y"
    
	/**
	 * 打印当前归约所用的语法规则<br>
	 * 请勿修改。
	 */
    public boolean onReduce(String rule) {
		if (rule.startsWith("$$"))
			return false;
		else
			rule = rule.replaceAll(" \\$\\$\\d+", "");

   	    if (rule.endsWith(":"))
    	    System.out.println(rule + " <empty>");
   	    else
			System.out.println(rule);
		return false;
    }
    
    public void diagnose() {
		addReduceListener(this);
		yyparse();
	}
//#line 715 "Parser.java"
//###############################################################
// method: yylexdebug : check lexer state
//###############################################################
void yylexdebug(int state,int ch)
{
String s=null;
  if (ch < 0) ch=0;
  if (ch <= YYMAXTOKEN) //check index bounds
     s = yyname[ch];    //now get it
  if (s==null)
    s = "illegal-symbol";
  debug("state "+state+", reading "+ch+" ("+s+")");
}





//The following are now global, to aid in error reporting
int yyn;       //next next thing to do
int yym;       //
int yystate;   //current parsing state from state table
String yys;    //current token string


//###############################################################
// method: yyparse : parse input and execute indicated items
//###############################################################
int yyparse()
{
boolean doaction;
  init_stacks();
  yynerrs = 0;
  yyerrflag = 0;
  yychar = -1;          //impossible char forces a read
  yystate=0;            //initial state
  state_push(yystate);  //save it
  while (true) //until parsing is done, either correctly, or w/error
    {
    doaction=true;
    //if (yydebug) debug("loop"); 
    //#### NEXT ACTION (from reduction table)
    for (yyn=yydefred[yystate];yyn==0;yyn=yydefred[yystate])
      {
      //if (yydebug) debug("yyn:"+yyn+"  state:"+yystate+"  yychar:"+yychar);
      if (yychar < 0)      //we want a char?
        {
        yychar = yylex();  //get next token
        //if (yydebug) debug(" next yychar:"+yychar);
        //#### ERROR CHECK ####
        //if (yychar < 0)    //it it didn't work/error
        //  {
        //  yychar = 0;      //change it to default string (no -1!)
          //if (yydebug)
          //  yylexdebug(yystate,yychar);
        //  }
        }//yychar<0
      yyn = yysindex[yystate];  //get amount to shift by (shift index)
      if ((yyn != 0) && (yyn += yychar) >= 0 &&
          yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
        {
        //if (yydebug)
          //debug("state "+yystate+", shifting to state "+yytable[yyn]);
        //#### NEXT STATE ####
        yystate = yytable[yyn];//we are in a new state
        state_push(yystate);   //save it
        val_push(yylval);      //push our lval as the input for next rule
        yychar = -1;           //since we have 'eaten' a token, say we need another
        if (yyerrflag > 0)     //have we recovered an error?
           --yyerrflag;        //give ourselves credit
        doaction=false;        //but don't process yet
        break;   //quit the yyn=0 loop
        }

    yyn = yyrindex[yystate];  //reduce
    if ((yyn !=0 ) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
      {   //we reduced!
      //if (yydebug) debug("reduce");
      yyn = yytable[yyn];
      doaction=true; //get ready to execute
      break;         //drop down to actions
      }
    else //ERROR RECOVERY
      {
      if (yyerrflag==0)
        {
        yyerror("syntax error");
        yynerrs++;
        }
      if (yyerrflag < 3) //low error count?
        {
        yyerrflag = 3;
        while (true)   //do until break
          {
          if (stateptr<0 || valptr<0)   //check for under & overflow here
            {
            return 1;
            }
          yyn = yysindex[state_peek(0)];
          if ((yyn != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
            //if (yydebug)
              //debug("state "+state_peek(0)+", error recovery shifting to state "+yytable[yyn]+" ");
            yystate = yytable[yyn];
            state_push(yystate);
            val_push(yylval);
            doaction=false;
            break;
            }
          else
            {
            //if (yydebug)
              //debug("error recovery discarding state "+state_peek(0)+" ");
            if (stateptr<0 || valptr<0)   //check for under & overflow here
              {
              return 1;
              }
            state_pop();
            val_pop();
            }
          }
        }
      else            //discard this token
        {
        if (yychar == 0)
          return 1; //yyabort
        //if (yydebug)
          //{
          //yys = null;
          //if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
          //if (yys == null) yys = "illegal-symbol";
          //debug("state "+yystate+", error recovery discards token "+yychar+" ("+yys+")");
          //}
        yychar = -1;  //read another
        }
      }//end error recovery
    }//yyn=0 loop
    if (!doaction)   //any reason not to proceed?
      continue;      //skip action
    yym = yylen[yyn];          //get count of terminals on rhs
    //if (yydebug)
      //debug("state "+yystate+", reducing "+yym+" by rule "+yyn+" ("+yyrule[yyn]+")");
    if (yym>0)                 //if count of rhs not 'nil'
      yyval = val_peek(yym-1); //get current semantic value
    if (reduceListener == null || reduceListener.onReduce(yyrule[yyn])) // if intercepted!
      switch(yyn)
      {
//########## USER-SUPPLIED ACTIONS ##########
case 1:
//#line 68 "Parser.y"
{
						tree = new Tree.TopLevel(val_peek(0).clist, val_peek(0).loc);
					}
break;
case 2:
//#line 74 "Parser.y"
{
						yyval.clist.add(val_peek(0).cdef);
					}
break;
case 3:
//#line 78 "Parser.y"
{
                		yyval.clist = new ArrayList<Tree.ClassDef>();
                		yyval.clist.add(val_peek(0).cdef);
                	}
break;
case 5:
//#line 88 "Parser.y"
{
						yyval.vdef = new Tree.VarDef(val_peek(0).ident, val_peek(1).type, val_peek(0).loc);
					}
break;
case 6:
//#line 94 "Parser.y"
{
						yyval.type = new Tree.TypeIdent(Tree.INT, val_peek(0).loc);
					}
break;
case 7:
//#line 98 "Parser.y"
{
                		yyval.type = new Tree.TypeIdent(Tree.VOID, val_peek(0).loc);
                	}
break;
case 8:
//#line 102 "Parser.y"
{
                		yyval.type = new Tree.TypeIdent(Tree.BOOL, val_peek(0).loc);
                	}
break;
case 9:
//#line 106 "Parser.y"
{
                		yyval.type = new Tree.TypeIdent(Tree.STRING, val_peek(0).loc);
                	}
break;
case 10:
//#line 111 "Parser.y"
{
                        yyval.type = new Tree.TypeIdent(Tree.COMPLEX, val_peek(0).loc);
                    }
break;
case 11:
//#line 115 "Parser.y"
{
                		yyval.type = new Tree.TypeClass(val_peek(0).ident, val_peek(1).loc);
                	}
break;
case 12:
//#line 119 "Parser.y"
{
                		yyval.type = new Tree.TypeArray(val_peek(2).type, val_peek(2).loc);
                	}
break;
case 13:
//#line 125 "Parser.y"
{
						yyval.cdef = new Tree.ClassDef(val_peek(4).ident, val_peek(3).ident, val_peek(1).flist, val_peek(5).loc);
					}
break;
case 14:
//#line 131 "Parser.y"
{
						yyval.ident = val_peek(0).ident;
					}
break;
case 15:
//#line 135 "Parser.y"
{
                		yyval = new SemValue();
                	}
break;
case 16:
//#line 141 "Parser.y"
{
						yyval.flist.add(val_peek(0).vdef);
					}
break;
case 17:
//#line 145 "Parser.y"
{
						yyval.flist.add(val_peek(0).fdef);
					}
break;
case 18:
//#line 149 "Parser.y"
{
                		yyval = new SemValue();
                		yyval.flist = new ArrayList<Tree>();
                	}
break;
case 20:
//#line 157 "Parser.y"
{
                		yyval = new SemValue();
                		yyval.vlist = new ArrayList<Tree.VarDef>(); 
                	}
break;
case 21:
//#line 164 "Parser.y"
{
						yyval.vlist.add(val_peek(0).vdef);
					}
break;
case 22:
//#line 168 "Parser.y"
{
                		yyval.vlist = new ArrayList<Tree.VarDef>();
						yyval.vlist.add(val_peek(0).vdef);
                	}
break;
case 23:
//#line 175 "Parser.y"
{
						yyval.fdef = new MethodDef(true, val_peek(4).ident, val_peek(5).type, val_peek(2).vlist, (Block) val_peek(0).stmt, val_peek(4).loc);
					}
break;
case 24:
//#line 179 "Parser.y"
{
						yyval.fdef = new MethodDef(false, val_peek(4).ident, val_peek(5).type, val_peek(2).vlist, (Block) val_peek(0).stmt, val_peek(4).loc);
					}
break;
case 25:
//#line 185 "Parser.y"
{
						yyval.stmt = new Block(val_peek(1).slist, val_peek(2).loc);
					}
break;
case 26:
//#line 191 "Parser.y"
{
						yyval.slist.add(val_peek(0).stmt);
					}
break;
case 27:
//#line 195 "Parser.y"
{
                		yyval = new SemValue();
                		yyval.slist = new ArrayList<Tree>();
                	}
break;
case 28:
//#line 202 "Parser.y"
{
						yyval.stmt = val_peek(0).vdef;
					}
break;
case 29:
//#line 207 "Parser.y"
{
                		if (yyval.stmt == null) {
                			yyval.stmt = new Tree.Skip(val_peek(0).loc);
                		}
                	}
break;
case 39:
//#line 230 "Parser.y"
{
						yyval.stmt = new Tree.Assign(val_peek(2).lvalue, val_peek(0).expr, val_peek(1).loc);
					}
break;
case 40:
//#line 234 "Parser.y"
{
                		yyval.stmt = new Tree.Exec(val_peek(0).expr, val_peek(0).loc);
                	}
break;
case 41:
//#line 238 "Parser.y"
{
                		yyval = new SemValue();
                	}
break;
case 43:
//#line 245 "Parser.y"
{
                		yyval = new SemValue();
                	}
break;
case 44:
//#line 251 "Parser.y"
{
						yyval.lvalue = new Tree.Ident(val_peek(1).expr, val_peek(0).ident, val_peek(0).loc);
						if (val_peek(1).loc == null) {
							yyval.loc = val_peek(0).loc;
						}
					}
break;
case 45:
//#line 258 "Parser.y"
{
                		yyval.lvalue = new Tree.Indexed(val_peek(3).expr, val_peek(1).expr, val_peek(3).loc);
                	}
break;
case 46:
//#line 264 "Parser.y"
{
						yyval.expr = new Tree.CallExpr(val_peek(4).expr, val_peek(3).ident, val_peek(1).elist, val_peek(3).loc);
						if (val_peek(4).loc == null) {
							yyval.loc = val_peek(3).loc;
						}
					}
break;
case 47:
//#line 273 "Parser.y"
{
						yyval.expr = val_peek(0).lvalue;
					}
break;
case 50:
//#line 279 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.PLUS, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 51:
//#line 283 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.MINUS, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 52:
//#line 287 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.MUL, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 53:
//#line 291 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.DIV, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 54:
//#line 295 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.MOD, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 55:
//#line 299 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.EQ, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 56:
//#line 303 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.NE, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 57:
//#line 307 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.LT, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 58:
//#line 311 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.GT, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 59:
//#line 315 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.LE, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 60:
//#line 319 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.GE, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 61:
//#line 323 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.AND, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 62:
//#line 327 "Parser.y"
{
                		yyval.expr = new Tree.Binary(Tree.OR, val_peek(2).expr, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 63:
//#line 331 "Parser.y"
{
                		yyval = val_peek(1);
                	}
break;
case 64:
//#line 335 "Parser.y"
{
                		yyval.expr = new Tree.Unary(Tree.NEG, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 65:
//#line 339 "Parser.y"
{
                		yyval.expr = new Tree.Unary(Tree.NOT, val_peek(0).expr, val_peek(1).loc);
                	}
break;
case 66:
//#line 345 "Parser.y"
{
                        yyval.expr = new Tree.Unary(Tree.RE, val_peek(0).expr, val_peek(1).loc);
                    }
break;
case 67:
//#line 349 "Parser.y"
{
                        yyval.expr = new Tree.Unary(Tree.IM, val_peek(0).expr, val_peek(1).loc);
                    }
break;
case 68:
//#line 353 "Parser.y"
{
                        yyval.expr = new Tree.Unary(Tree.TOCOMPLEX, val_peek(0).expr, val_peek(1).loc);
                    }
break;
case 69:
//#line 359 "Parser.y"
{
                		yyval.expr = new Tree.ReadIntExpr(val_peek(2).loc);
                	}
break;
case 70:
//#line 363 "Parser.y"
{
                		yyval.expr = new Tree.ReadLineExpr(val_peek(2).loc);
                	}
break;
case 71:
//#line 367 "Parser.y"
{
                		yyval.expr = new Tree.ThisExpr(val_peek(0).loc);
                	}
break;
case 72:
//#line 372 "Parser.y"
{
                        yyval.expr = new Tree.SuperExpr(val_peek(0).loc);
                    }
break;
case 73:
//#line 377 "Parser.y"
{
                		yyval.expr = new Tree.NewClass(val_peek(2).ident, val_peek(3).loc);
                	}
break;
case 74:
//#line 381 "Parser.y"
{
                		yyval.expr = new Tree.NewArray(val_peek(3).type, val_peek(1).expr, val_peek(4).loc);
                	}
break;
case 75:
//#line 385 "Parser.y"
{
                		yyval.expr = new Tree.TypeTest(val_peek(3).expr, val_peek(1).ident, val_peek(5).loc);
                	}
break;
case 76:
//#line 389 "Parser.y"
{
                		yyval.expr = new Tree.TypeCast(val_peek(2).ident, val_peek(0).expr, val_peek(0).loc);
                	}
break;
case 78:
//#line 397 "Parser.y"
{
                        yyval.expr = new DcopyExpr(val_peek(1).expr, val_peek(3).loc);
                    }
break;
case 79:
//#line 401 "Parser.y"
{
                        yyval.expr = new ScopyExpr(val_peek(1).expr, val_peek(3).loc);
                    }
break;
case 80:
//#line 409 "Parser.y"
{
                        yyval.expr = new Tree.CaseExpr(val_peek(5).expr, val_peek(2).elist, val_peek(1).expr, val_peek(7).loc);
                    }
break;
case 81:
//#line 413 "Parser.y"
{
                        yyval.expr = new Tree.CaseExpr(val_peek(4).expr, val_peek(1).expr, val_peek(6).loc);
                    }
break;
case 82:
//#line 419 "Parser.y"
{
                        yyval.elist.add(val_peek(0).expr);
                    }
break;
case 83:
//#line 423 "Parser.y"
{
                        /*$$ = new SemValue();*/
                        yyval.elist = new ArrayList<Tree.Expr>();
                        yyval.elist.add(val_peek(0).expr);
                    }
break;
case 84:
//#line 430 "Parser.y"
{
                        yyval.expr = new Tree.ACaseExpr(val_peek(3).expr, val_peek(1).expr, val_peek(3).loc);
                    }
break;
case 85:
//#line 436 "Parser.y"
{
                        yyval.expr = new Tree.DefaultExpr(val_peek(1).expr, val_peek(3).loc);
                    }
break;
case 86:
//#line 444 "Parser.y"
{
						yyval.expr = new Tree.Literal(val_peek(0).typeTag, val_peek(0).literal, val_peek(0).loc);
					}
break;
case 87:
//#line 448 "Parser.y"
{
						yyval.expr = new Null(val_peek(0).loc);
					}
break;
case 89:
//#line 455 "Parser.y"
{
                		yyval = new SemValue();
                		yyval.elist = new ArrayList<Tree.Expr>();
                	}
break;
case 90:
//#line 462 "Parser.y"
{
						yyval.elist.add(val_peek(0).expr);
					}
break;
case 91:
//#line 466 "Parser.y"
{
                		yyval.elist = new ArrayList<Tree.Expr>();
						yyval.elist.add(val_peek(0).expr);
                	}
break;
case 92:
//#line 473 "Parser.y"
{
						yyval.stmt = new Tree.WhileLoop(val_peek(2).expr, val_peek(0).stmt, val_peek(4).loc);
					}
break;
case 93:
//#line 479 "Parser.y"
{
						yyval.stmt = new Tree.ForLoop(val_peek(6).stmt, val_peek(4).expr, val_peek(2).stmt, val_peek(0).stmt, val_peek(8).loc);
					}
break;
case 94:
//#line 485 "Parser.y"
{
						yyval.stmt = new Tree.Break(val_peek(0).loc);
					}
break;
case 95:
//#line 491 "Parser.y"
{
						yyval.stmt = new Tree.If(val_peek(3).expr, val_peek(1).stmt, val_peek(0).stmt, val_peek(5).loc);
					}
break;
case 96:
//#line 497 "Parser.y"
{
						yyval.stmt = val_peek(0).stmt;
					}
break;
case 97:
//#line 501 "Parser.y"
{
						yyval = new SemValue();
					}
break;
case 98:
//#line 507 "Parser.y"
{
						yyval.stmt = new Tree.Return(val_peek(0).expr, val_peek(1).loc);
					}
break;
case 99:
//#line 511 "Parser.y"
{
                		yyval.stmt = new Tree.Return(null, val_peek(0).loc);
                	}
break;
case 100:
//#line 517 "Parser.y"
{
						yyval.stmt = new Print(val_peek(1).elist, val_peek(3).loc);
					}
break;
case 101:
//#line 523 "Parser.y"
{
                        yyval.stmt = new PrintComp(val_peek(1).elist, val_peek(3).loc);
                    }
break;
case 102:
//#line 529 "Parser.y"
{
                        yyval.stmt = new DoSubStmt(val_peek(2).expr, val_peek(0).stmt, val_peek(1).loc);
                    }
break;
case 103:
//#line 534 "Parser.y"
{
                        /*$$.stmt = new DoSubStmt($1.expr, $*/
                    }
break;
case 104:
//#line 539 "Parser.y"
{
						yyval.slist.add(val_peek(0).stmt);
					}
break;
case 105:
//#line 543 "Parser.y"
{
                		yyval = new SemValue();
                		yyval.slist = new ArrayList<Tree>();
                	}
break;
case 106:
//#line 549 "Parser.y"
{
                        yyval.slist.add(val_peek(0).stmt);
                    }
break;
case 107:
//#line 554 "Parser.y"
{
                        yyval.stmt = new DoStmt(val_peek(2).slist, val_peek(3).loc);
                    }
break;
//#line 1425 "Parser.java"
//########## END OF USER-SUPPLIED ACTIONS ##########
    }//switch
    //#### Now let's reduce... ####
    //if (yydebug) debug("reduce");
    state_drop(yym);             //we just reduced yylen states
    yystate = state_peek(0);     //get new state
    val_drop(yym);               //corresponding value drop
    yym = yylhs[yyn];            //select next TERMINAL(on lhs)
    if (yystate == 0 && yym == 0)//done? 'rest' state and at first TERMINAL
      {
      //if (yydebug) debug("After reduction, shifting from state 0 to state "+YYFINAL+"");
      yystate = YYFINAL;         //explicitly say we're done
      state_push(YYFINAL);       //and save it
      val_push(yyval);           //also save the semantic value of parsing
      if (yychar < 0)            //we want another character?
        {
        yychar = yylex();        //get next character
        //if (yychar<0) yychar=0;  //clean, if necessary
        //if (yydebug)
          //yylexdebug(yystate,yychar);
        }
      if (yychar == 0)          //Good exit (if lex returns 0 ;-)
         break;                 //quit the loop--all DONE
      }//if yystate
    else                        //else not done yet
      {                         //get next state and push, for next yydefred[]
      yyn = yygindex[yym];      //find out where to go
      if ((yyn != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn]; //get new state
      else
        yystate = yydgoto[yym]; //else go to new defred
      //if (yydebug) debug("after reduction, shifting from state "+state_peek(0)+" to state "+yystate+"");
      state_push(yystate);     //going again, so push state & val...
      val_push(yyval);         //for next action
      }
    }//main loop
  return 0;//yyaccept!!
}
//## end of method parse() ######################################



//## run() --- for Thread #######################################
//## The -Jnorun option was used ##
//## end of method run() ########################################



//## Constructors ###############################################
//## The -Jnoconstruct option was used ##
//###############################################################



}
//################### END OF CLASS ##############################
