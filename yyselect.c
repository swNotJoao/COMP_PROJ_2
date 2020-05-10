/*
generated at Sun May 10 15:18:32 2020
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
#define yyprint_NT 7
#define yyexpr_NT 8

static YYCONST char *yyntname[] = {
	0,
	"file",
	"decls",
	"main",
	"chars",
	"instrs",
	"instr",
	"print",
	"expr",
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
 "",
	/* 63 */ "GT",
	/* 64 */ "READOP",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "",
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
	short cost[9];
	struct {
		unsigned int yyfile:1;
		unsigned int yydecls:3;
		unsigned int yymain:1;
		unsigned int yychars:3;
		unsigned int yyinstrs:1;
		unsigned int yyinstr:3;
		unsigned int yyprint:3;
		unsigned int yyexpr:4;
	} rule;
};

static short yynts_0[] = { yydecls_NT, yymain_NT, 0 };
static short yynts_1[] = { 0 };
static short yynts_2[] = { yydecls_NT, 0 };
static short yynts_3[] = { yychars_NT, 0 };
static short yynts_4[] = { yydecls_NT, yydecls_NT, 0 };
static short yynts_5[] = { yyinstrs_NT, 0 };
static short yynts_6[] = { yyinstr_NT, 0 };
static short yynts_7[] = { yyinstr_NT, yyinstr_NT, 0 };
static short yynts_8[] = { yyprint_NT, 0 };
static short yynts_9[] = { yyexpr_NT, 0 };
static short yynts_10[] = { yychars_NT, yychars_NT, 0 };
static short yynts_11[] = { yyexpr_NT, yyexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_1,	/* 4 */
	yynts_3,	/* 5 */
	yynts_4,	/* 6 */
	yynts_5,	/* 7 */
	yynts_6,	/* 8 */
	yynts_6,	/* 9 */
	yynts_1,	/* 10 */
	yynts_6,	/* 11 */
	yynts_7,	/* 12 */
	yynts_8,	/* 13 */
	yynts_9,	/* 14 */
	yynts_9,	/* 15 */
	yynts_1,	/* 16 */
	yynts_1,	/* 17 */
	yynts_3,	/* 18 */
	yynts_3,	/* 19 */
	yynts_1,	/* 20 */
	yynts_1,	/* 21 */
	yynts_1,	/* 22 */
	yynts_10,	/* 23 */
	yynts_1,	/* 24 */
	yynts_11,	/* 25 */
	yynts_11,	/* 26 */
	yynts_11,	/* 27 */
	yynts_11,	/* 28 */
	yynts_11,	/* 29 */
	yynts_11,	/* 30 */
	yynts_11,	/* 31 */
	yynts_11,	/* 32 */
	yynts_11,	/* 33 */
	yynts_11,	/* 34 */
	yynts_11,	/* 35 */
	yynts_9,	/* 36 */
	yynts_9,	/* 37 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"file: PROGRAM(decls,main)",
/* 2 */	"decls: NIL",
/* 3 */	"decls: DECL(NIL,decls)",
/* 4 */	"decls: VAR(NUMBER(ID,INT))",
/* 5 */	"decls: VAR(STRING(ID,chars))",
/* 6 */	"decls: DECL(decls,decls)",
/* 7 */	"main: FUNCTION(END,instrs)",
/* 8 */	"instrs: FARGS(NIL,instr)",
/* 9 */	"instr: START(NIL,instr)",
/* 10 */	"instr: NIL",
/* 11 */	"instr: STMT(NIL,instr)",
/* 12 */	"instr: STMT(instr,instr)",
/* 13 */	"instr: print",
/* 14 */	"instr: expr",
/* 15 */	"print: PSTMT(expr)",
/* 16 */	"print: PSTMT(READOP)",
/* 17 */	"print: PSTMT(ID)",
/* 18 */	"print: PSTMT(chars)",
/* 19 */	"chars: CHARS(NIL,chars)",
/* 20 */	"chars: INT",
/* 21 */	"chars: CHAR",
/* 22 */	"chars: STR",
/* 23 */	"chars: CHARS(chars,chars)",
/* 24 */	"expr: CHARS(NIL,INT)",
/* 25 */	"expr: ADD(expr,expr)",
/* 26 */	"expr: SUB(expr,expr)",
/* 27 */	"expr: MUL(expr,expr)",
/* 28 */	"expr: DIV(expr,expr)",
/* 29 */	"expr: MOD(expr,expr)",
/* 30 */	"expr: EQ(expr,expr)",
/* 31 */	"expr: NE(expr,expr)",
/* 32 */	"expr: LT(expr,expr)",
/* 33 */	"expr: LE(expr,expr)",
/* 34 */	"expr: GT(expr,expr)",
/* 35 */	"expr: GE(expr,expr)",
/* 36 */	"expr: UMINUS(expr)",
/* 37 */	"expr: NOT(expr)",
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
	6,
};

static short yydecode_main[] = {
	0,
	7,
};

static short yydecode_chars[] = {
	0,
	19,
	20,
	21,
	22,
	23,
};

static short yydecode_instrs[] = {
	0,
	8,
};

static short yydecode_instr[] = {
	0,
	9,
	10,
	11,
	12,
	13,
	14,
};

static short yydecode_print[] = {
	0,
	15,
	16,
	17,
	18,
};

static short yydecode_expr[] = {
	0,
	24,
	25,
	26,
	27,
	28,
	29,
	30,
	31,
	32,
	33,
	34,
	35,
	36,
	37,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 8)
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
	case yyprint_NT:	return yydecode_print[((struct yystate *)state)->rule.yyprint];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_print(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);

static void yyclosure_print(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 13, c + 0, p->cost[yyinstr_NT]);
	if (c + 0 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 0;
		p->rule.yyinstr = 5;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 14, c + 0, p->cost[yyinstr_NT]);
	if (c + 0 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 0;
		p->rule.yyinstr = 6;
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PSTMT */
		yylabel(LEFT_CHILD(a),a);
		/* print: PSTMT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 15, c + 0, p->cost[yyprint_NT]);
		if (c + 0 < p->cost[yyprint_NT]) {
			p->cost[yyprint_NT] = c + 0;
			p->rule.yyprint = 1;
			yyclosure_print(a, c + 0);
		}
		if (	/* print: PSTMT(READOP) */
			OP_LABEL(LEFT_CHILD(a)) == 63 /* READOP */
		) {
			c = 0;
			yytrace(a, 16, c + 0, p->cost[yyprint_NT]);
			if (c + 0 < p->cost[yyprint_NT]) {
				p->cost[yyprint_NT] = c + 0;
				p->rule.yyprint = 2;
				yyclosure_print(a, c + 0);
			}
		}
		if (	/* print: PSTMT(ID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = 0;
			yytrace(a, 17, c + 0, p->cost[yyprint_NT]);
			if (c + 0 < p->cost[yyprint_NT]) {
				p->cost[yyprint_NT] = c + 0;
				p->rule.yyprint = 3;
				yyclosure_print(a, c + 0);
			}
		}
		/* print: PSTMT(chars) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + 0;
		yytrace(a, 18, c + 0, p->cost[yyprint_NT]);
		if (c + 0 < p->cost[yyprint_NT]) {
			p->cost[yyprint_NT] = c + 0;
			p->rule.yyprint = 4;
			yyclosure_print(a, c + 0);
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MOD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 29, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 38: /* AND */
		return;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MUL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 27, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 4;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 2;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: SUB(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 3;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 28, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 5;
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
			yytrace(a, 11, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 3;
			}
		}
		/* instr: STMT(instr,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
		yytrace(a, 12, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 4;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 34, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 63: /* READOP */
		return;
	case 94: /* POW */
		return;
	case 124: /* OR */
		return;
	case 126: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 37, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 14;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* chars: INT */
		yytrace(a, 20, 0 + 0, p->cost[yychars_NT]);
		if (0 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 0 + 0;
			p->rule.yychars = 2;
		}
		break;
	case 258: /* CHAR */
		/* chars: CHAR */
		yytrace(a, 21, 0 + 0, p->cost[yychars_NT]);
		if (0 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 0 + 0;
			p->rule.yychars = 3;
		}
		break;
	case 259: /* ID */
		return;
	case 260: /* STR */
		/* chars: STR */
		yytrace(a, 22, 0 + 0, p->cost[yychars_NT]);
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
		return;
	case 268: /* ARRAY */
		return;
	case 269: /* FUNCTION */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* main: FUNCTION(END,instrs) */
			OP_LABEL(LEFT_CHILD(a)) == 263 /* END */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrs_NT] + 0;
			yytrace(a, 7, c + 0, p->cost[yymain_NT]);
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
		return;
	case 273: /* THEN */
		return;
	case 274: /* FI */
		return;
	case 275: /* ELIF */
		return;
	case 276: /* ELSE */
		return;
	case 277: /* RETURN */
		return;
	case 278: /* START */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: START(NIL,instr) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
			yytrace(a, 9, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 1;
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
			yytrace(a, 8, c + 0, p->cost[yyinstrs_NT]);
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
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychars_NT] + 0;
			yytrace(a, 19, c + 0, p->cost[yychars_NT]);
			if (c + 0 < p->cost[yychars_NT]) {
				p->cost[yychars_NT] = c + 0;
				p->rule.yychars = 1;
			}
		}
		/* chars: CHARS(chars,chars) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychars_NT] + 0;
		yytrace(a, 23, c + 0, p->cost[yychars_NT]);
		if (c + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = c + 0;
			p->rule.yychars = 5;
		}
		if (	/* expr: CHARS(NIL,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 24, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 1;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 288: /* INTS */
		return;
	case 289: /* ADDR */
		return;
	case 290: /* VAR */
		yylabel(LEFT_CHILD(a),a);
		if (	/* decls: VAR(NUMBER(ID,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 267 && /* NUMBER */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 /* INT */
		) {
			c = 0;
			yytrace(a, 4, c + 0, p->cost[yydecls_NT]);
			if (c + 0 < p->cost[yydecls_NT]) {
				p->cost[yydecls_NT] = c + 0;
				p->rule.yydecls = 3;
			}
		}
		if (	/* decls: VAR(STRING(ID,chars)) */
			OP_LABEL(LEFT_CHILD(a)) == 266 && /* STRING */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yychars_NT] + 0;
			yytrace(a, 5, c + 0, p->cost[yydecls_NT]);
			if (c + 0 < p->cost[yydecls_NT]) {
				p->cost[yydecls_NT] = c + 0;
				p->rule.yydecls = 4;
			}
		}
		break;
	case 291: /* ARGS */
		return;
	case 292: /* DECL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* decls: DECL(NIL,decls) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 0;
			yytrace(a, 3, c + 0, p->cost[yydecls_NT]);
			if (c + 0 < p->cost[yydecls_NT]) {
				p->cost[yydecls_NT] = c + 0;
				p->rule.yydecls = 2;
			}
		}
		/* decls: DECL(decls,decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 0;
		yytrace(a, 6, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 5;
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
		yytrace(a, 10, 0 + 0, p->cost[yyinstr_NT]);
		if (0 + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = 0 + 0;
			p->rule.yyinstr = 2;
		}
		break;
	case 294: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 30, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 295: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: NE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 31, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 296: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 297: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 298: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 36, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 13;
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
	case 35: /* expr: GE(expr,expr) */
	case 34: /* expr: GT(expr,expr) */
	case 33: /* expr: LE(expr,expr) */
	case 32: /* expr: LT(expr,expr) */
	case 31: /* expr: NE(expr,expr) */
	case 30: /* expr: EQ(expr,expr) */
	case 29: /* expr: MOD(expr,expr) */
	case 28: /* expr: DIV(expr,expr) */
	case 27: /* expr: MUL(expr,expr) */
	case 26: /* expr: SUB(expr,expr) */
	case 25: /* expr: ADD(expr,expr) */
	case 23: /* chars: CHARS(chars,chars) */
	case 12: /* instr: STMT(instr,instr) */
	case 6: /* decls: DECL(decls,decls) */
	case 1: /* file: PROGRAM(decls,main) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 24: /* expr: CHARS(NIL,INT) */
	case 22: /* chars: STR */
	case 21: /* chars: CHAR */
	case 20: /* chars: INT */
	case 17: /* print: PSTMT(ID) */
	case 16: /* print: PSTMT(READOP) */
	case 10: /* instr: NIL */
	case 4: /* decls: VAR(NUMBER(ID,INT)) */
	case 2: /* decls: NIL */
		break;
	case 19: /* chars: CHARS(NIL,chars) */
	case 11: /* instr: STMT(NIL,instr) */
	case 9: /* instr: START(NIL,instr) */
	case 8: /* instrs: FARGS(NIL,instr) */
	case 7: /* main: FUNCTION(END,instrs) */
	case 3: /* decls: DECL(NIL,decls) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 5: /* decls: VAR(STRING(ID,chars)) */
		kids[0] = RIGHT_CHILD(LEFT_CHILD(p));
		break;
	case 14: /* instr: expr */
	case 13: /* instr: print */
		kids[0] = p;
		break;
	case 37: /* expr: NOT(expr) */
	case 36: /* expr: UMINUS(expr) */
	case 18: /* print: PSTMT(chars) */
	case 15: /* print: PSTMT(expr) */
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
  NODEPTR_TYPE kids[2];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* file: PROGRAM(decls,main) */
		fprintf(stderr, "0x%p: line 51: file: PROGRAM(decls,main)\n",(void*)p);
#line 51 "minor.brg"
{}
		break;
	case 2: /* decls: NIL */
		fprintf(stderr, "0x%p: line 53: decls: NIL\n",(void*)p);
#line 53 "minor.brg"
{}
		break;
	case 3: /* decls: DECL(NIL,decls) */
		fprintf(stderr, "0x%p: line 54: decls: DECL(NIL,decls)\n",(void*)p);
#line 54 "minor.brg"
{}
		break;
	case 4: /* decls: VAR(NUMBER(ID,INT)) */
		fprintf(stderr, "0x%p: line 55: decls: VAR(NUMBER(ID,INT))\n",(void*)p);
#line 55 "minor.brg"
{
                              fprintf(yyout, pfDATA pfLABEL pfINTEGER,
                              p->SUB(0)->SUB(0)->value.s,
                              p->SUB(0)->SUB(1)->value.i);
                             }
		break;
	case 5: /* decls: VAR(STRING(ID,chars)) */
		fprintf(stderr, "0x%p: line 60: decls: VAR(STRING(ID,chars))\n",(void*)p);
#line 60 "minor.brg"
{
                                tmpStr[tmpStrInd++] = '\0'; toPrint = tmpStr;
                                fprintf(yyout, pfRODATA pfALIGN pfLABEL
                                , p->SUB(0)->SUB(0)->value.s);
                                outstr(toPrint);
                                tmpStrInd = 0;
                               }
		break;
	case 6: /* decls: DECL(decls,decls) */
		fprintf(stderr, "0x%p: line 67: decls: DECL(decls,decls)\n",(void*)p);
#line 67 "minor.brg"
{}
		break;
	case 7: /* main: FUNCTION(END,instrs) */
		fprintf(stderr, "0x%p: line 69: main: FUNCTION(END,instrs)\n",(void*)p);
#line 69 "minor.brg"
{}
		break;
	case 8: /* instrs: FARGS(NIL,instr) */
		fprintf(stderr, "0x%p: line 71: instrs: FARGS(NIL,instr)\n",(void*)p);
#line 71 "minor.brg"
{}
		break;
	case 9: /* instr: START(NIL,instr) */
		fprintf(stderr, "0x%p: line 73: instr: START(NIL,instr)\n",(void*)p);
#line 73 "minor.brg"
{}
		break;
	case 10: /* instr: NIL */
		fprintf(stderr, "0x%p: line 75: instr: NIL\n",(void*)p);
#line 75 "minor.brg"

		break;
	case 11: /* instr: STMT(NIL,instr) */
		fprintf(stderr, "0x%p: line 76: instr: STMT(NIL,instr)\n",(void*)p);
#line 76 "minor.brg"

		break;
	case 12: /* instr: STMT(instr,instr) */
		fprintf(stderr, "0x%p: line 77: instr: STMT(instr,instr)\n",(void*)p);
#line 77 "minor.brg"

		break;
	case 13: /* instr: print */
		fprintf(stderr, "0x%p: line 78: instr: print\n",(void*)p);
#line 78 "minor.brg"

		break;
	case 14: /* instr: expr */
		fprintf(stderr, "0x%p: line 79: instr: expr\n",(void*)p);
#line 79 "minor.brg"

		break;
	case 15: /* print: PSTMT(expr) */
		fprintf(stderr, "0x%p: line 81: print: PSTMT(expr)\n",(void*)p);
#line 81 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH, "_printi", 4);}
		break;
	case 16: /* print: PSTMT(READOP) */
		fprintf(stderr, "0x%p: line 82: print: PSTMT(READOP)\n",(void*)p);
#line 82 "minor.brg"
{}
		break;
	case 17: /* print: PSTMT(ID) */
		fprintf(stderr, "0x%p: line 83: print: PSTMT(ID)\n",(void*)p);
#line 83 "minor.brg"
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
	case 18: /* print: PSTMT(chars) */
		fprintf(stderr, "0x%p: line 95: print: PSTMT(chars)\n",(void*)p);
#line 95 "minor.brg"
{
                      char *l = mklbl(++lbl); tmpStr[tmpStrInd++] = '\0';
                      fprintf(yyout, pfRODATA pfALIGN pfLABEL, l);
                      outstr(toPrint);
                      fprintf(yyout, pfTEXT pfADDR pfCALL pfTRASH,
                      l, "_prints", 4);
                      tmpStrInd = 0;
                      }
		break;
	case 19: /* chars: CHARS(NIL,chars) */
		fprintf(stderr, "0x%p: line 103: chars: CHARS(NIL,chars)\n",(void*)p);
#line 103 "minor.brg"
{}
		break;
	case 20: /* chars: INT */
		fprintf(stderr, "0x%p: line 104: chars: INT\n",(void*)p);
#line 104 "minor.brg"
{ tmpStr[tmpStrInd++] = p->value.i; toPrint = tmpStr;}
		break;
	case 21: /* chars: CHAR */
		fprintf(stderr, "0x%p: line 105: chars: CHAR\n",(void*)p);
#line 105 "minor.brg"
{ tmpStr[tmpStrInd++] = p->value.i; toPrint = tmpStr;}
		break;
	case 22: /* chars: STR */
		fprintf(stderr, "0x%p: line 106: chars: STR\n",(void*)p);
#line 106 "minor.brg"
{ strcpy(&tmpStr[tmpStrInd], p->value.s); tmpStrInd = tmpStrInd + strlen(p->value.s); toPrint = tmpStr;}
		break;
	case 23: /* chars: CHARS(chars,chars) */
		fprintf(stderr, "0x%p: line 107: chars: CHARS(chars,chars)\n",(void*)p);
#line 107 "minor.brg"
{}
		break;
	case 24: /* expr: CHARS(NIL,INT) */
		fprintf(stderr, "0x%p: line 109: expr: CHARS(NIL,INT)\n",(void*)p);
#line 109 "minor.brg"
{fprintf(yyout, pfIMM, p->SUB(1)->value.i); }
		break;
	case 25: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%p: line 111: expr: ADD(expr,expr)\n",(void*)p);
#line 111 "minor.brg"
{ fprintf(yyout, pfADD); }
		break;
	case 26: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%p: line 112: expr: SUB(expr,expr)\n",(void*)p);
#line 112 "minor.brg"
{ fprintf(yyout, pfSUB); }
		break;
	case 27: /* expr: MUL(expr,expr) */
		fprintf(stderr, "0x%p: line 113: expr: MUL(expr,expr)\n",(void*)p);
#line 113 "minor.brg"
{ fprintf(yyout, pfMUL); }
		break;
	case 28: /* expr: DIV(expr,expr) */
		fprintf(stderr, "0x%p: line 114: expr: DIV(expr,expr)\n",(void*)p);
#line 114 "minor.brg"
{ fprintf(yyout, pfDIV); }
		break;
	case 29: /* expr: MOD(expr,expr) */
		fprintf(stderr, "0x%p: line 115: expr: MOD(expr,expr)\n",(void*)p);
#line 115 "minor.brg"
{ fprintf(yyout, pfMOD); }
		break;
	case 30: /* expr: EQ(expr,expr) */
		fprintf(stderr, "0x%p: line 116: expr: EQ(expr,expr)\n",(void*)p);
#line 116 "minor.brg"
{ fprintf(yyout, pfEQ); }
		break;
	case 31: /* expr: NE(expr,expr) */
		fprintf(stderr, "0x%p: line 117: expr: NE(expr,expr)\n",(void*)p);
#line 117 "minor.brg"
{ fprintf(yyout, pfNE); }
		break;
	case 32: /* expr: LT(expr,expr) */
		fprintf(stderr, "0x%p: line 118: expr: LT(expr,expr)\n",(void*)p);
#line 118 "minor.brg"
{ fprintf(yyout, pfLT); }
		break;
	case 33: /* expr: LE(expr,expr) */
		fprintf(stderr, "0x%p: line 119: expr: LE(expr,expr)\n",(void*)p);
#line 119 "minor.brg"
{ fprintf(yyout, pfLE); }
		break;
	case 34: /* expr: GT(expr,expr) */
		fprintf(stderr, "0x%p: line 120: expr: GT(expr,expr)\n",(void*)p);
#line 120 "minor.brg"
{ fprintf(yyout, pfGT); }
		break;
	case 35: /* expr: GE(expr,expr) */
		fprintf(stderr, "0x%p: line 121: expr: GE(expr,expr)\n",(void*)p);
#line 121 "minor.brg"
{ fprintf(yyout, pfGE); }
		break;
	case 36: /* expr: UMINUS(expr) */
		fprintf(stderr, "0x%p: line 122: expr: UMINUS(expr)\n",(void*)p);
#line 122 "minor.brg"
{ fprintf(yyout, pfNEG); }
		break;
	case 37: /* expr: NOT(expr) */
		fprintf(stderr, "0x%p: line 123: expr: NOT(expr)\n",(void*)p);
#line 123 "minor.brg"
{ fprintf(yyout, pfIMM pfEQ, 0); }
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


#line 125 "minor.brg"

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
