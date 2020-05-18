/*
generated at Mon May 18 23:35:14 2020
by $Id: pburg.c,v 2.7 2020/04/06 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.7"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "minor.brg"

/*
 * selecção de instruções com postfix
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "postfix.h"
#include "y.tab.h"
#include "tabid.h"
#include "minor.h"

#ifndef U_
#define U_ "_"
#endif

#define TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost);

int lbl;
int tmpStrInd = 0;
char tmpStr[1024];
char *toPrint = NULL;

extern FILE *yyout;
static char *mklbl(int n) {
	static char buf[20];
	sprintf(buf, "%cL%d", n < 0 ? '.' : '_', n);
	return strcpy(malloc(strlen(buf)+1),buf);
}

static void outstr(char *s) {
  while (*s) fprintf(yyout, pfCHAR, (unsigned char)*s++);
  fprintf(yyout, pfCHAR, 0);
}

static char *mkpowlbl(char *s) {
static char buf[80];
strcpy(buf, "_");
strcat(buf, s);
return buf;
}

static char *mkfunc(char *s) {
	static char buf[80];
	strcpy(buf, "_");
	strcat(buf, s);
	return buf;
}
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyfile_NT 1
#define yydecls_NT 2
#define yymain_NT 3
#define yychars_NT 4
#define yyinstrs_NT 5
#define yyinstr_NT 6
#define yyfvars_NT 7
#define yyfvar_NT 8
#define yyprint_NT 9
#define yyexpr_NT 10
#define yyif_NT 11
#define yyelif_NT 12
#define yycond_NT 13

static YYCONST char *yyntname[] = {
	0,
	"file",
	"decls",
	"main",
	"chars",
	"instrs",
	"instr",
	"fvars",
	"fvar",
	"print",
	"expr",
	"if",
	"elif",
	"cond",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "PSTMT",
 "", "", "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "", "", "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
 "",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "STMT",
	/* 61 */ "LT",
	/* 62 */ "ISEQ",
	/* 63 */ "GT",
	/* 64 */ "READOP",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "",
	/* 92 */ "IND",
 "", "",
	/* 95 */ "POW",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
	/* 125 */ "OR",
 "",
	/* 127 */ "NOT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "CHAR",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "PROGRAM",
	/* 263 */ "MODULE",
	/* 264 */ "END",
	/* 265 */ "PUBLIC",
	/* 266 */ "FORWARD",
	/* 267 */ "STRING",
	/* 268 */ "NUMBER",
	/* 269 */ "ARRAY",
	/* 270 */ "FUNCTION",
	/* 271 */ "VOID",
	/* 272 */ "CONST",
	/* 273 */ "IF",
	/* 274 */ "THEN",
	/* 275 */ "FI",
	/* 276 */ "ELIF",
	/* 277 */ "ELSE",
	/* 278 */ "RETURN",
	/* 279 */ "START",
	/* 280 */ "FOR",
	/* 281 */ "UNTIL",
	/* 282 */ "STEP",
	/* 283 */ "DO",
	/* 284 */ "DONE",
	/* 285 */ "REPEAT",
	/* 286 */ "STOP",
	/* 287 */ "FARGS",
	/* 288 */ "CHARS",
	/* 289 */ "INTS",
	/* 290 */ "ADDR",
	/* 291 */ "VAR",
	/* 292 */ "ARGS",
	/* 293 */ "DECL",
	/* 294 */ "NIL",
	/* 295 */ "EQ",
	/* 296 */ "NE",
	/* 297 */ "GE",
	/* 298 */ "LE",
	/* 299 */ "UMINUS",
	""
};

struct yystate {
	short cost[14];
	struct {
		unsigned int yyfile:1;
		unsigned int yydecls:3;
		unsigned int yymain:1;
		unsigned int yychars:3;
		unsigned int yyinstrs:1;
		unsigned int yyinstr:4;
		unsigned int yyfvars:2;
		unsigned int yyfvar:1;
		unsigned int yyprint:3;
		unsigned int yyexpr:5;
		unsigned int yyif:1;
		unsigned int yyelif:2;
		unsigned int yycond:1;
	} rule;
};

static short yynts_0[] = { yydecls_NT, yymain_NT, 0 };
static short yynts_1[] = { 0 };
static short yynts_2[] = { yychars_NT, 0 };
static short yynts_3[] = { yydecls_NT, yydecls_NT, 0 };
static short yynts_4[] = { yyinstrs_NT, 0 };
static short yynts_5[] = { yyinstr_NT, 0 };
static short yynts_6[] = { yyfvars_NT, yyinstr_NT, 0 };
static short yynts_7[] = { yyfvars_NT, 0 };
static short yynts_8[] = { yyfvar_NT, 0 };
static short yynts_9[] = { yyinstr_NT, yyinstr_NT, 0 };
static short yynts_10[] = { yyprint_NT, 0 };
static short yynts_11[] = { yyexpr_NT, 0 };
static short yynts_12[] = { yyif_NT, yyelif_NT, yyinstr_NT, 0 };
static short yynts_13[] = { yyelif_NT, yyif_NT, 0 };
static short yynts_14[] = { yyif_NT, yyinstr_NT, 0 };
static short yynts_15[] = { yycond_NT, yyinstr_NT, 0 };
static short yynts_16[] = { yychars_NT, yychars_NT, 0 };
static short yynts_17[] = { yyexpr_NT, yyexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_1,	/* 3 */
	yynts_2,	/* 4 */
	yynts_3,	/* 5 */
	yynts_4,	/* 6 */
	yynts_5,	/* 7 */
	yynts_6,	/* 8 */
	yynts_5,	/* 9 */
	yynts_7,	/* 10 */
	yynts_8,	/* 11 */
	yynts_1,	/* 12 */
	yynts_1,	/* 13 */
	yynts_5,	/* 14 */
	yynts_9,	/* 15 */
	yynts_10,	/* 16 */
	yynts_11,	/* 17 */
	yynts_12,	/* 18 */
	yynts_13,	/* 19 */
	yynts_1,	/* 20 */
	yynts_14,	/* 21 */
	yynts_15,	/* 22 */
	yynts_5,	/* 23 */
	yynts_15,	/* 24 */
	yynts_11,	/* 25 */
	yynts_1,	/* 26 */
	yynts_2,	/* 27 */
	yynts_11,	/* 28 */
	yynts_1,	/* 29 */
	yynts_2,	/* 30 */
	yynts_1,	/* 31 */
	yynts_1,	/* 32 */
	yynts_1,	/* 33 */
	yynts_16,	/* 34 */
	yynts_1,	/* 35 */
	yynts_1,	/* 36 */
	yynts_1,	/* 37 */
	yynts_11,	/* 38 */
	yynts_1,	/* 39 */
	yynts_1,	/* 40 */
	yynts_11,	/* 41 */
	yynts_11,	/* 42 */
	yynts_17,	/* 43 */
	yynts_17,	/* 44 */
	yynts_17,	/* 45 */
	yynts_17,	/* 46 */
	yynts_17,	/* 47 */
	yynts_17,	/* 48 */
	yynts_17,	/* 49 */
	yynts_17,	/* 50 */
	yynts_17,	/* 51 */
	yynts_17,	/* 52 */
	yynts_17,	/* 53 */
	yynts_17,	/* 54 */
	yynts_17,	/* 55 */
	yynts_11,	/* 56 */
	yynts_11,	/* 57 */
	yynts_17,	/* 58 */
	yynts_11,	/* 59 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"file: PROGRAM(decls,main)",
/* 2 */	"decls: NIL",
/* 3 */	"decls: VAR(NUMBER(ID,INT))",
/* 4 */	"decls: VAR(STRING(ID,chars))",
/* 5 */	"decls: DECL(decls,decls)",
/* 6 */	"main: FUNCTION(END,instrs)",
/* 7 */	"instrs: FARGS(NIL,instr)",
/* 8 */	"instr: START(fvars,instr)",
/* 9 */	"instr: START(NIL,instr)",
/* 10 */	"fvars: ARGS(NIL,fvars)",
/* 11 */	"fvars: fvar",
/* 12 */	"fvar: NUMBER(ID,NIL)",
/* 13 */	"instr: NIL",
/* 14 */	"instr: STMT(NIL,instr)",
/* 15 */	"instr: STMT(instr,instr)",
/* 16 */	"instr: print",
/* 17 */	"instr: expr",
/* 18 */	"instr: FI(THEN(if,elif),instr)",
/* 19 */	"elif: ELIF(elif,if)",
/* 20 */	"elif: NIL",
/* 21 */	"instr: FI(THEN(if,NIL),instr)",
/* 22 */	"if: IF(cond,instr)",
/* 23 */	"instr: FI(THEN(instr,NIL),NIL)",
/* 24 */	"instr: IF(cond,instr)",
/* 25 */	"cond: expr",
/* 26 */	"print: PSTMT(ID)",
/* 27 */	"print: PSTMT(chars)",
/* 28 */	"print: PSTMT(expr)",
/* 29 */	"print: PSTMT(CHARS(NIL,INT))",
/* 30 */	"chars: CHARS(NIL,chars)",
/* 31 */	"chars: INT",
/* 32 */	"chars: CHAR",
/* 33 */	"chars: STR",
/* 34 */	"chars: CHARS(chars,chars)",
/* 35 */	"expr: CHARS(NIL,INT)",
/* 36 */	"expr: CHARS(NIL,CHAR)",
/* 37 */	"expr: ID",
/* 38 */	"expr: IND(expr,ID)",
/* 39 */	"expr: READOP",
/* 40 */	"expr: ADDR(ID)",
/* 41 */	"expr: ADDR(IND(expr,ID))",
/* 42 */	"expr: UMINUS(expr)",
/* 43 */	"expr: ADD(expr,expr)",
/* 44 */	"expr: SUB(expr,expr)",
/* 45 */	"expr: MUL(expr,expr)",
/* 46 */	"expr: DIV(expr,expr)",
/* 47 */	"expr: MOD(expr,expr)",
/* 48 */	"expr: ISEQ(expr,expr)",
/* 49 */	"expr: NE(expr,expr)",
/* 50 */	"expr: LT(expr,expr)",
/* 51 */	"expr: LE(expr,expr)",
/* 52 */	"expr: GT(expr,expr)",
/* 53 */	"expr: GE(expr,expr)",
/* 54 */	"expr: AND(expr,expr)",
/* 55 */	"expr: OR(expr,expr)",
/* 56 */	"expr: UMINUS(expr)",
/* 57 */	"expr: NOT(expr)",
/* 58 */	"expr: POW(expr,expr)",
/* 59 */	"expr: EQ(expr,ID)",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%p:%s matched %s with cost %d vs. %d\n", (void*)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_file[] = {
	0,
	1,
};

static short yydecode_decls[] = {
	0,
	2,
	3,
	4,
	5,
};

static short yydecode_main[] = {
	0,
	6,
};

static short yydecode_chars[] = {
	0,
	30,
	31,
	32,
	33,
	34,
};

static short yydecode_instrs[] = {
	0,
	7,
};

static short yydecode_instr[] = {
	0,
	8,
	9,
	13,
	14,
	15,
	16,
	17,
	18,
	21,
	23,
	24,
};

static short yydecode_fvars[] = {
	0,
	10,
	11,
};

static short yydecode_fvar[] = {
	0,
	12,
};

static short yydecode_print[] = {
	0,
	26,
	27,
	28,
	29,
};

static short yydecode_expr[] = {
	0,
	35,
	36,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
	51,
	52,
	53,
	54,
	55,
	56,
	57,
	58,
	59,
};

static short yydecode_if[] = {
	0,
	22,
};

static short yydecode_elif[] = {
	0,
	19,
	20,
};

static short yydecode_cond[] = {
	0,
	25,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 13)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfile_NT:	return yydecode_file[((struct yystate *)state)->rule.yyfile];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yymain_NT:	return yydecode_main[((struct yystate *)state)->rule.yymain];
	case yychars_NT:	return yydecode_chars[((struct yystate *)state)->rule.yychars];
	case yyinstrs_NT:	return yydecode_instrs[((struct yystate *)state)->rule.yyinstrs];
	case yyinstr_NT:	return yydecode_instr[((struct yystate *)state)->rule.yyinstr];
	case yyfvars_NT:	return yydecode_fvars[((struct yystate *)state)->rule.yyfvars];
	case yyfvar_NT:	return yydecode_fvar[((struct yystate *)state)->rule.yyfvar];
	case yyprint_NT:	return yydecode_print[((struct yystate *)state)->rule.yyprint];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yyelif_NT:	return yydecode_elif[((struct yystate *)state)->rule.yyelif];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_fvar(NODEPTR_TYPE, int);
static void yyclosure_print(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);

static void yyclosure_fvar(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 0, p->cost[yyfvars_NT]);
	if (c + 0 < p->cost[yyfvars_NT]) {
		p->cost[yyfvars_NT] = c + 0;
		p->rule.yyfvars = 2;
	}
}

static void yyclosure_print(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 16, c + 0, p->cost[yyinstr_NT]);
	if (c + 0 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 0;
		p->rule.yyinstr = 6;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 25, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 17, c + 0, p->cost[yyinstr_NT]);
	if (c + 0 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 0;
		p->rule.yyinstr = 7;
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
	p->cost[13] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PSTMT */
		yylabel(LEFT_CHILD(a),a);
		if (	/* print: PSTMT(ID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = 1;
			yytrace(a, 26, c + 0, p->cost[yyprint_NT]);
			if (c + 0 < p->cost[yyprint_NT]) {
				p->cost[yyprint_NT] = c + 0;
				p->rule.yyprint = 1;
				yyclosure_print(a, c + 0);
			}
		}
		/* print: PSTMT(chars) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + 0;
		yytrace(a, 27, c + 0, p->cost[yyprint_NT]);
		if (c + 0 < p->cost[yyprint_NT]) {
			p->cost[yyprint_NT] = c + 0;
			p->rule.yyprint = 2;
			yyclosure_print(a, c + 0);
		}
		/* print: PSTMT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 2;
		yytrace(a, 28, c + 0, p->cost[yyprint_NT]);
		if (c + 0 < p->cost[yyprint_NT]) {
			p->cost[yyprint_NT] = c + 0;
			p->rule.yyprint = 3;
			yyclosure_print(a, c + 0);
		}
		if (	/* print: PSTMT(CHARS(NIL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 29, c + 0, p->cost[yyprint_NT]);
			if (c + 0 < p->cost[yyprint_NT]) {
				p->cost[yyprint_NT] = c + 0;
				p->rule.yyprint = 4;
				yyclosure_print(a, c + 0);
			}
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MOD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 47, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 13;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: AND(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 20;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MUL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 45, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 43, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: SUB(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 44, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 46, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 59: /* STMT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: STMT(NIL,instr) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
			yytrace(a, 14, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 4;
			}
		}
		/* instr: STMT(instr,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
		yytrace(a, 15, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 5;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 50, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 16;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* ISEQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ISEQ(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 48, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 14;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 52, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 18;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 63: /* READOP */
		/* expr: READOP */
		yytrace(a, 39, 0 + 0, p->cost[yyexpr_NT]);
		if (0 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 0 + 0;
			p->rule.yyexpr = 5;
			yyclosure_expr(a, 0 + 0);
		}
		break;
	case 91: /* IND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: IND(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 0;
			yytrace(a, 38, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 94: /* POW */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: POW(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 58, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 24;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: OR(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 55, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 21;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 126: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 57, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 23;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* chars: INT */
		yytrace(a, 31, 0 + 0, p->cost[yychars_NT]);
		if (0 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 0 + 0;
			p->rule.yychars = 2;
		}
		break;
	case 258: /* CHAR */
		/* chars: CHAR */
		yytrace(a, 32, 0 + 0, p->cost[yychars_NT]);
		if (0 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 0 + 0;
			p->rule.yychars = 3;
		}
		break;
	case 259: /* ID */
		/* expr: ID */
		yytrace(a, 37, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 3;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 260: /* STR */
		/* chars: STR */
		yytrace(a, 33, 0 + 0, p->cost[yychars_NT]);
		if (0 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 0 + 0;
			p->rule.yychars = 4;
		}
		break;
	case 261: /* PROGRAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* file: PROGRAM(decls,main) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yymain_NT] + 1;
		yytrace(a, 1, c + 0, p->cost[yyfile_NT]);
		if (c + 0 < p->cost[yyfile_NT]) {
			p->cost[yyfile_NT] = c + 0;
			p->rule.yyfile = 1;
		}
		break;
	case 262: /* MODULE */
		return;
	case 263: /* END */
		return;
	case 264: /* PUBLIC */
		return;
	case 265: /* FORWARD */
		return;
	case 266: /* STRING */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 267: /* NUMBER */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* fvar: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 0;
			yytrace(a, 12, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 1;
				yyclosure_fvar(a, c + 0);
			}
		}
		break;
	case 268: /* ARRAY */
		return;
	case 269: /* FUNCTION */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* main: FUNCTION(END,instrs) */
			OP_LABEL(LEFT_CHILD(a)) == 263 /* END */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrs_NT] + 0;
			yytrace(a, 6, c + 0, p->cost[yymain_NT]);
			if (c + 0 < p->cost[yymain_NT]) {
				p->cost[yymain_NT] = c + 0;
				p->rule.yymain = 1;
			}
		}
		break;
	case 270: /* VOID */
		return;
	case 271: /* CONST */
		return;
	case 272: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* if: IF(cond,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
		yytrace(a, 22, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* instr: IF(cond,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 1;
		yytrace(a, 24, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 11;
		}
		break;
	case 273: /* THEN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 274: /* FI */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: FI(THEN(if,elif),instr) */
			OP_LABEL(LEFT_CHILD(a)) == 273 /* THEN */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyelif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 1;
			yytrace(a, 18, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 8;
			}
		}
		if (	/* instr: FI(THEN(if,NIL),instr) */
			OP_LABEL(LEFT_CHILD(a)) == 273 && /* THEN */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 1;
			yytrace(a, 21, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 9;
			}
		}
		if (	/* instr: FI(THEN(instr,NIL),NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 273 && /* THEN */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyinstr_NT] + 0;
			yytrace(a, 23, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 10;
			}
		}
		break;
	case 275: /* ELIF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* elif: ELIF(elif,if) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyelif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyif_NT] + 0;
		yytrace(a, 19, c + 0, p->cost[yyelif_NT]);
		if (c + 0 < p->cost[yyelif_NT]) {
			p->cost[yyelif_NT] = c + 0;
			p->rule.yyelif = 1;
		}
		break;
	case 276: /* ELSE */
		return;
	case 277: /* RETURN */
		return;
	case 278: /* START */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instr: START(fvars,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
		yytrace(a, 8, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 1;
		}
		if (	/* instr: START(NIL,instr) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
			yytrace(a, 9, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 2;
			}
		}
		break;
	case 279: /* FOR */
		return;
	case 280: /* UNTIL */
		return;
	case 281: /* STEP */
		return;
	case 282: /* DO */
		return;
	case 283: /* DONE */
		return;
	case 284: /* REPEAT */
		return;
	case 285: /* STOP */
		return;
	case 286: /* FARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instrs: FARGS(NIL,instr) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
			yytrace(a, 7, c + 0, p->cost[yyinstrs_NT]);
			if (c + 0 < p->cost[yyinstrs_NT]) {
				p->cost[yyinstrs_NT] = c + 0;
				p->rule.yyinstrs = 1;
			}
		}
		break;
	case 287: /* CHARS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* chars: CHARS(NIL,chars) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychars_NT] + 2;
			yytrace(a, 30, c + 0, p->cost[yychars_NT]);
			if (c + 0 < p->cost[yychars_NT]) {
				p->cost[yychars_NT] = c + 0;
				p->rule.yychars = 1;
			}
		}
		/* chars: CHARS(chars,chars) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychars_NT] + 0;
		yytrace(a, 34, c + 0, p->cost[yychars_NT]);
		if (c + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = c + 0;
			p->rule.yychars = 5;
		}
		if (	/* expr: CHARS(NIL,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 35, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 1;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CHARS(NIL,CHAR) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 258 /* CHAR */
		) {
			c = 1;
			yytrace(a, 36, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 2;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 288: /* INTS */
		return;
	case 289: /* ADDR */
		yylabel(LEFT_CHILD(a),a);
		if (	/* expr: ADDR(ID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = 0;
			yytrace(a, 40, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 6;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: ADDR(IND(expr,ID)) */
			OP_LABEL(LEFT_CHILD(a)) == 91 && /* IND */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpr_NT] + 0;
			yytrace(a, 41, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 7;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 290: /* VAR */
		yylabel(LEFT_CHILD(a),a);
		if (	/* decls: VAR(NUMBER(ID,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 267 && /* NUMBER */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 /* INT */
		) {
			c = 0;
			yytrace(a, 3, c + 0, p->cost[yydecls_NT]);
			if (c + 0 < p->cost[yydecls_NT]) {
				p->cost[yydecls_NT] = c + 0;
				p->rule.yydecls = 2;
			}
		}
		if (	/* decls: VAR(STRING(ID,chars)) */
			OP_LABEL(LEFT_CHILD(a)) == 266 && /* STRING */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yychars_NT] + 0;
			yytrace(a, 4, c + 0, p->cost[yydecls_NT]);
			if (c + 0 < p->cost[yydecls_NT]) {
				p->cost[yydecls_NT] = c + 0;
				p->rule.yydecls = 3;
			}
		}
		break;
	case 291: /* ARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* fvars: ARGS(NIL,fvars) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvars_NT] + 0;
			yytrace(a, 10, c + 0, p->cost[yyfvars_NT]);
			if (c + 0 < p->cost[yyfvars_NT]) {
				p->cost[yyfvars_NT] = c + 0;
				p->rule.yyfvars = 1;
			}
		}
		break;
	case 292: /* DECL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* decls: DECL(decls,decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 0;
		yytrace(a, 5, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 4;
		}
		break;
	case 293: /* NIL */
		/* decls: NIL */
		yytrace(a, 2, 0 + 0, p->cost[yydecls_NT]);
		if (0 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 0 + 0;
			p->rule.yydecls = 1;
		}
		/* instr: NIL */
		yytrace(a, 13, 0 + 0, p->cost[yyinstr_NT]);
		if (0 + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = 0 + 0;
			p->rule.yyinstr = 3;
		}
		/* elif: NIL */
		yytrace(a, 20, 2 + 0, p->cost[yyelif_NT]);
		if (2 + 0 < p->cost[yyelif_NT]) {
			p->cost[yyelif_NT] = 2 + 0;
			p->rule.yyelif = 2;
		}
		break;
	case 294: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: EQ(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 59, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 25;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 295: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: NE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 49, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 15;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 296: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 53, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 297: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 51, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 298: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, c + 0);
		}
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 56, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 22;
			yyclosure_expr(a, c + 0);
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 58: /* expr: POW(expr,expr) */
	case 55: /* expr: OR(expr,expr) */
	case 54: /* expr: AND(expr,expr) */
	case 53: /* expr: GE(expr,expr) */
	case 52: /* expr: GT(expr,expr) */
	case 51: /* expr: LE(expr,expr) */
	case 50: /* expr: LT(expr,expr) */
	case 49: /* expr: NE(expr,expr) */
	case 48: /* expr: ISEQ(expr,expr) */
	case 47: /* expr: MOD(expr,expr) */
	case 46: /* expr: DIV(expr,expr) */
	case 45: /* expr: MUL(expr,expr) */
	case 44: /* expr: SUB(expr,expr) */
	case 43: /* expr: ADD(expr,expr) */
	case 34: /* chars: CHARS(chars,chars) */
	case 24: /* instr: IF(cond,instr) */
	case 22: /* if: IF(cond,instr) */
	case 19: /* elif: ELIF(elif,if) */
	case 15: /* instr: STMT(instr,instr) */
	case 8: /* instr: START(fvars,instr) */
	case 5: /* decls: DECL(decls,decls) */
	case 1: /* file: PROGRAM(decls,main) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 40: /* expr: ADDR(ID) */
	case 39: /* expr: READOP */
	case 37: /* expr: ID */
	case 36: /* expr: CHARS(NIL,CHAR) */
	case 35: /* expr: CHARS(NIL,INT) */
	case 33: /* chars: STR */
	case 32: /* chars: CHAR */
	case 31: /* chars: INT */
	case 29: /* print: PSTMT(CHARS(NIL,INT)) */
	case 26: /* print: PSTMT(ID) */
	case 20: /* elif: NIL */
	case 13: /* instr: NIL */
	case 12: /* fvar: NUMBER(ID,NIL) */
	case 3: /* decls: VAR(NUMBER(ID,INT)) */
	case 2: /* decls: NIL */
		break;
	case 4: /* decls: VAR(STRING(ID,chars)) */
		kids[0] = RIGHT_CHILD(LEFT_CHILD(p));
		break;
	case 30: /* chars: CHARS(NIL,chars) */
	case 14: /* instr: STMT(NIL,instr) */
	case 10: /* fvars: ARGS(NIL,fvars) */
	case 9: /* instr: START(NIL,instr) */
	case 7: /* instrs: FARGS(NIL,instr) */
	case 6: /* main: FUNCTION(END,instrs) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 25: /* cond: expr */
	case 17: /* instr: expr */
	case 16: /* instr: print */
	case 11: /* fvars: fvar */
		kids[0] = p;
		break;
	case 18: /* instr: FI(THEN(if,elif),instr) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 21: /* instr: FI(THEN(if,NIL),instr) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(p);
		break;
	case 41: /* expr: ADDR(IND(expr,ID)) */
	case 23: /* instr: FI(THEN(instr,NIL),NIL) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		break;
	case 59: /* expr: EQ(expr,ID) */
	case 57: /* expr: NOT(expr) */
	case 56: /* expr: UMINUS(expr) */
	case 42: /* expr: UMINUS(expr) */
	case 38: /* expr: IND(expr,ID) */
	case 28: /* print: PSTMT(expr) */
	case 27: /* print: PSTMT(chars) */
		kids[0] = LEFT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[3];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* file: PROGRAM(decls,main) */
		fprintf(stderr, "0x%p: line 58: file: PROGRAM(decls,main)\n",(void*)p);
#line 58 "minor.brg"
{}
		break;
	case 2: /* decls: NIL */
		fprintf(stderr, "0x%p: line 60: decls: NIL\n",(void*)p);
#line 60 "minor.brg"
{}
		break;
	case 3: /* decls: VAR(NUMBER(ID,INT)) */
		fprintf(stderr, "0x%p: line 61: decls: VAR(NUMBER(ID,INT))\n",(void*)p);
#line 61 "minor.brg"
{
                              fprintf(yyout, pfDATA pfLABEL pfINTEGER,
                              p->SUB(0)->SUB(0)->value.s,
                              p->SUB(0)->SUB(1)->value.i);
                             }
		break;
	case 4: /* decls: VAR(STRING(ID,chars)) */
		fprintf(stderr, "0x%p: line 66: decls: VAR(STRING(ID,chars))\n",(void*)p);
#line 66 "minor.brg"
{
                                tmpStr[tmpStrInd++] = '\0'; toPrint = tmpStr;
                                fprintf(yyout, pfRODATA pfALIGN pfLABEL
                                , p->SUB(0)->SUB(0)->value.s);
                                outstr(toPrint);
                                tmpStrInd = 0;
                               }
		break;
	case 5: /* decls: DECL(decls,decls) */
		fprintf(stderr, "0x%p: line 73: decls: DECL(decls,decls)\n",(void*)p);
#line 73 "minor.brg"
{fprintf(yyout, pfTEXT);}
		break;
	case 6: /* main: FUNCTION(END,instrs) */
		fprintf(stderr, "0x%p: line 75: main: FUNCTION(END,instrs)\n",(void*)p);
#line 75 "minor.brg"
{}
		break;
	case 7: /* instrs: FARGS(NIL,instr) */
		fprintf(stderr, "0x%p: line 77: instrs: FARGS(NIL,instr)\n",(void*)p);
#line 77 "minor.brg"
{}
		break;
	case 8: /* instr: START(fvars,instr) */
		fprintf(stderr, "0x%p: line 79: instr: START(fvars,instr)\n",(void*)p);
#line 79 "minor.brg"
{}
		break;
	case 9: /* instr: START(NIL,instr) */
		fprintf(stderr, "0x%p: line 80: instr: START(NIL,instr)\n",(void*)p);
#line 80 "minor.brg"
{}
		break;
	case 10: /* fvars: ARGS(NIL,fvars) */
		fprintf(stderr, "0x%p: line 82: fvars: ARGS(NIL,fvars)\n",(void*)p);
#line 82 "minor.brg"
{}
		break;
	case 11: /* fvars: fvar */
		fprintf(stderr, "0x%p: line 83: fvars: fvar\n",(void*)p);
#line 83 "minor.brg"
{}
		break;
	case 12: /* fvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%p: line 84: fvar: NUMBER(ID,NIL)\n",(void*)p);
#line 84 "minor.brg"
{fprintf(yyout, pfDATA pfLABEL pfINTEGER pfTEXT,
                        p->SUB(0)->value.s,
                        0);}
		break;
	case 13: /* instr: NIL */
		fprintf(stderr, "0x%p: line 88: instr: NIL\n",(void*)p);
#line 88 "minor.brg"

		break;
	case 14: /* instr: STMT(NIL,instr) */
		fprintf(stderr, "0x%p: line 89: instr: STMT(NIL,instr)\n",(void*)p);
#line 89 "minor.brg"

		break;
	case 15: /* instr: STMT(instr,instr) */
		fprintf(stderr, "0x%p: line 90: instr: STMT(instr,instr)\n",(void*)p);
#line 90 "minor.brg"

		break;
	case 16: /* instr: print */
		fprintf(stderr, "0x%p: line 91: instr: print\n",(void*)p);
#line 91 "minor.brg"

		break;
	case 17: /* instr: expr */
		fprintf(stderr, "0x%p: line 92: instr: expr\n",(void*)p);
#line 92 "minor.brg"

		break;
	case 18: /* instr: FI(THEN(if,elif),instr) */
		fprintf(stderr, "0x%p: line 94: instr: FI(THEN(if,elif),instr)\n",(void*)p);
#line 94 "minor.brg"
{ fprintf(yyout, pfLABEL,
                                      mklbl(LEFT_CHILD(p)->SUB(0)->place)); }
		break;
	case 19: /* elif: ELIF(elif,if) */
		fprintf(stderr, "0x%p: line 96: elif: ELIF(elif,if)\n",(void*)p);
#line 96 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfJMP pfLABEL,
				                mklbl(RIGHT_CHILD(p)->place), mklbl(p->place)); }
		break;
	case 20: /* elif: NIL */
		fprintf(stderr, "0x%p: line 98: elif: NIL\n",(void*)p);
#line 98 "minor.brg"
{}
		break;
	case 21: /* instr: FI(THEN(if,NIL),instr) */
		fprintf(stderr, "0x%p: line 100: instr: FI(THEN(if,NIL),instr)\n",(void*)p);
#line 100 "minor.brg"
{ fprintf(yyout, pfLABEL,
                                      mklbl(LEFT_CHILD(p)->SUB(0)->place)); }
		break;
	case 22: /* if: IF(cond,instr) */
		fprintf(stderr, "0x%p: line 102: if: IF(cond,instr)\n",(void*)p);
#line 102 "minor.brg"
{p->place = ++lbl; fprintf(yyout, pfJMP pfLABEL,
				            mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 23: /* instr: FI(THEN(instr,NIL),NIL) */
		fprintf(stderr, "0x%p: line 105: instr: FI(THEN(instr,NIL),NIL)\n",(void*)p);
#line 105 "minor.brg"
{/*Simple if*/}
		break;
	case 24: /* instr: IF(cond,instr) */
		fprintf(stderr, "0x%p: line 106: instr: IF(cond,instr)\n",(void*)p);
#line 106 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 25: /* cond: expr */
		fprintf(stderr, "0x%p: line 107: cond: expr\n",(void*)p);
#line 107 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfJZ, mklbl(p->place)); }
		break;
	case 26: /* print: PSTMT(ID) */
		fprintf(stderr, "0x%p: line 109: print: PSTMT(ID)\n",(void*)p);
#line 109 "minor.brg"
{
                  switch(p->SUB(0)->info){
                    case tINT:
                      fprintf(yyout, pfADDRV pfCALL pfTRASH,
                      p->SUB(0)->value.s, "_printi", 4);
                    break;
                    case tSTR:
                      fprintf(yyout, pfADDR pfCALL pfTRASH,
                      p->SUB(0)->value.s, "_prints", 4);
                    break;
                  }
                  }
		break;
	case 27: /* print: PSTMT(chars) */
		fprintf(stderr, "0x%p: line 121: print: PSTMT(chars)\n",(void*)p);
#line 121 "minor.brg"
{
                      char *l = mklbl(++lbl); tmpStr[tmpStrInd++] = '\0';
                      fprintf(yyout, pfRODATA pfALIGN pfLABEL, l);
                      outstr(toPrint);
                      fprintf(yyout, pfTEXT pfADDR pfCALL pfTRASH,
                      l, "_prints", 4);
                      tmpStrInd = 0;
                      }
		break;
	case 28: /* print: PSTMT(expr) */
		fprintf(stderr, "0x%p: line 129: print: PSTMT(expr)\n",(void*)p);
#line 129 "minor.brg"
{fprintf(yyout, pfTEXT pfCALL pfTRASH, "_printi", 4);}
		break;
	case 29: /* print: PSTMT(CHARS(NIL,INT)) */
		fprintf(stderr, "0x%p: line 130: print: PSTMT(CHARS(NIL,INT))\n",(void*)p);
#line 130 "minor.brg"
{fprintf(yyout, pfTEXT pfIMM pfCALL pfTRASH, p->SUB(0)->SUB(1)->value.i, "_printi", 4);}
		break;
	case 30: /* chars: CHARS(NIL,chars) */
		fprintf(stderr, "0x%p: line 132: chars: CHARS(NIL,chars)\n",(void*)p);
#line 132 "minor.brg"
{}
		break;
	case 31: /* chars: INT */
		fprintf(stderr, "0x%p: line 133: chars: INT\n",(void*)p);
#line 133 "minor.brg"
{ tmpStr[tmpStrInd++] = p->value.i; toPrint = tmpStr;}
		break;
	case 32: /* chars: CHAR */
		fprintf(stderr, "0x%p: line 134: chars: CHAR\n",(void*)p);
#line 134 "minor.brg"
{ tmpStr[tmpStrInd++] = p->value.i; toPrint = tmpStr;}
		break;
	case 33: /* chars: STR */
		fprintf(stderr, "0x%p: line 135: chars: STR\n",(void*)p);
#line 135 "minor.brg"
{ strcpy(&tmpStr[tmpStrInd], p->value.s); tmpStrInd = tmpStrInd + strlen(p->value.s); toPrint = tmpStr;}
		break;
	case 34: /* chars: CHARS(chars,chars) */
		fprintf(stderr, "0x%p: line 136: chars: CHARS(chars,chars)\n",(void*)p);
#line 136 "minor.brg"
{}
		break;
	case 35: /* expr: CHARS(NIL,INT) */
		fprintf(stderr, "0x%p: line 138: expr: CHARS(NIL,INT)\n",(void*)p);
#line 138 "minor.brg"
{fprintf(yyout, pfIMM, p->SUB(1)->value.i);}
		break;
	case 36: /* expr: CHARS(NIL,CHAR) */
		fprintf(stderr, "0x%p: line 139: expr: CHARS(NIL,CHAR)\n",(void*)p);
#line 139 "minor.brg"
{fprintf(yyout, pfIMM, p->SUB(1)->value.i); }
		break;
	case 37: /* expr: ID */
		fprintf(stderr, "0x%p: line 140: expr: ID\n",(void*)p);
#line 140 "minor.brg"
{ fprintf(yyout, pfADDRV, p->value.s); }
		break;
	case 38: /* expr: IND(expr,ID) */
		fprintf(stderr, "0x%p: line 141: expr: IND(expr,ID)\n",(void*)p);
#line 141 "minor.brg"
{ fprintf(yyout, pfADDR pfADD, p->SUB(1)->value.s); }
		break;
	case 39: /* expr: READOP */
		fprintf(stderr, "0x%p: line 142: expr: READOP\n",(void*)p);
#line 142 "minor.brg"
{fprintf(yyout, pfCALL pfPUSH, "_readi"); }
		break;
	case 40: /* expr: ADDR(ID) */
		fprintf(stderr, "0x%p: line 144: expr: ADDR(ID)\n",(void*)p);
#line 144 "minor.brg"
{ fprintf(yyout, pfADDR, p->SUB(0)->value.s); }
		break;
	case 41: /* expr: ADDR(IND(expr,ID)) */
		fprintf(stderr, "0x%p: line 145: expr: ADDR(IND(expr,ID))\n",(void*)p);
#line 145 "minor.brg"
{ switch(p->SUB(0)->SUB(1)->info){
                              case tINT:
                                fprintf(yyout, pfIMM pfMUL pfADDR pfADD,
                                4, p->SUB(0)->SUB(1)->value.s);
                              break;
                              case tSTR:
                                fprintf(yyout, pfADDR pfADD,
                                p->SUB(0)->SUB(1)->value.s);
                              break;
                            }}
		break;
	case 42: /* expr: UMINUS(expr) */
		fprintf(stderr, "0x%p: line 155: expr: UMINUS(expr)\n",(void*)p);
#line 155 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL, -1); }
		break;
	case 43: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%p: line 156: expr: ADD(expr,expr)\n",(void*)p);
#line 156 "minor.brg"
{ fprintf(yyout, pfADD); }
		break;
	case 44: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%p: line 157: expr: SUB(expr,expr)\n",(void*)p);
#line 157 "minor.brg"
{ fprintf(yyout, pfSUB); }
		break;
	case 45: /* expr: MUL(expr,expr) */
		fprintf(stderr, "0x%p: line 158: expr: MUL(expr,expr)\n",(void*)p);
#line 158 "minor.brg"
{ fprintf(yyout, pfMUL); }
		break;
	case 46: /* expr: DIV(expr,expr) */
		fprintf(stderr, "0x%p: line 159: expr: DIV(expr,expr)\n",(void*)p);
#line 159 "minor.brg"
{ fprintf(yyout, pfDIV); }
		break;
	case 47: /* expr: MOD(expr,expr) */
		fprintf(stderr, "0x%p: line 160: expr: MOD(expr,expr)\n",(void*)p);
#line 160 "minor.brg"
{ fprintf(yyout, pfMOD); }
		break;
	case 48: /* expr: ISEQ(expr,expr) */
		fprintf(stderr, "0x%p: line 161: expr: ISEQ(expr,expr)\n",(void*)p);
#line 161 "minor.brg"
{ fprintf(yyout, pfEQ); }
		break;
	case 49: /* expr: NE(expr,expr) */
		fprintf(stderr, "0x%p: line 162: expr: NE(expr,expr)\n",(void*)p);
#line 162 "minor.brg"
{ fprintf(yyout, pfNE); }
		break;
	case 50: /* expr: LT(expr,expr) */
		fprintf(stderr, "0x%p: line 163: expr: LT(expr,expr)\n",(void*)p);
#line 163 "minor.brg"
{ fprintf(yyout, pfLT); }
		break;
	case 51: /* expr: LE(expr,expr) */
		fprintf(stderr, "0x%p: line 164: expr: LE(expr,expr)\n",(void*)p);
#line 164 "minor.brg"
{ fprintf(yyout, pfLE); }
		break;
	case 52: /* expr: GT(expr,expr) */
		fprintf(stderr, "0x%p: line 165: expr: GT(expr,expr)\n",(void*)p);
#line 165 "minor.brg"
{ fprintf(yyout, pfGT); }
		break;
	case 53: /* expr: GE(expr,expr) */
		fprintf(stderr, "0x%p: line 166: expr: GE(expr,expr)\n",(void*)p);
#line 166 "minor.brg"
{ fprintf(yyout, pfGE); }
		break;
	case 54: /* expr: AND(expr,expr) */
		fprintf(stderr, "0x%p: line 167: expr: AND(expr,expr)\n",(void*)p);
#line 167 "minor.brg"
{ fprintf(yyout, pfAND); }
		break;
	case 55: /* expr: OR(expr,expr) */
		fprintf(stderr, "0x%p: line 168: expr: OR(expr,expr)\n",(void*)p);
#line 168 "minor.brg"
{ fprintf(yyout, pfLOR); }
		break;
	case 56: /* expr: UMINUS(expr) */
		fprintf(stderr, "0x%p: line 169: expr: UMINUS(expr)\n",(void*)p);
#line 169 "minor.brg"
{ fprintf(yyout, pfNEG); }
		break;
	case 57: /* expr: NOT(expr) */
		fprintf(stderr, "0x%p: line 170: expr: NOT(expr)\n",(void*)p);
#line 170 "minor.brg"
{ fprintf(yyout, pfIMM pfEQ, 0); }
		break;
	case 58: /* expr: POW(expr,expr) */
		fprintf(stderr, "0x%p: line 171: expr: POW(expr,expr)\n",(void*)p);
#line 171 "minor.brg"
{lbl++; fprintf(yyout, ";POW\n"
                                                "pop ebx\n"
                                                "pop ecx\n"
                                                "mov eax,1\n"
                                                "%s:\n"
                                                "jcxz %s\n"
                                                "mul ebx\n"
                                                "loop %s\n"
                                                "%s:\n"
                                                "push eax\n",
                                                mklbl(lbl+1), mklbl(lbl),
                                                mklbl(lbl+1), mklbl(lbl));
                                                lbl = lbl + 2;}
		break;
	case 59: /* expr: EQ(expr,ID) */
		fprintf(stderr, "0x%p: line 184: expr: EQ(expr,ID)\n",(void*)p);
#line 184 "minor.brg"
{fprintf(yyout, pfADDRA, p->SUB(1)->value.s); }
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyfile == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 186 "minor.brg"

extern char **yynames;
extern int trace, errors, debugNode;

static int data(int t, char *s, void *a, void *user) {
  if (s) fprintf(yyout, pfLABEL pfINTEGER, s, 0);
  return 1;
}

void evaluate(Node *p) {
	if (errors) return;
	/* if (trace) */ printNode(p, stdout, yynames);
  fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL, "_main", pfFUNC, "_main");
	if (!yyselect(p) && trace) printf("selection successful\n");
  fprintf(yyout, pfIMM pfPOP pfRET pfDATA, 0);
  /*IDevery(data,0);*/
  fprintf(yyout, pfEXTRN pfEXTRN pfEXTRN pfEXTRN,
  		"_prints", "_printi", "_println", "_readi");
}

#ifndef NOTRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	if (debugNode) fprintf(stderr, "0x%p:%s matched %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
	if (cost >= MAX_COST && bestcost >= MAX_COST) {
		fprintf(stderr, "0x%p:%s NO MATCH %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
		printNode(p, stderr, yynames);
	}
}
#endif
