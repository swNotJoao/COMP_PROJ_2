/*
generated at Thu May  7 17:53:55 2020
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
#define yyinstrs_NT 4
#define yyinstr_NT 5
#define yyprint_NT 6
#define yychars_NT 7

static YYCONST char *yyntname[] = {
	0,
	"file",
	"decls",
	"main",
	"instrs",
	"instr",
	"print",
	"chars",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "PSTMT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "",
	/* 60 */ "STMT",
 "", "", "",
	/* 64 */ "READOP",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "",
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
	/* 299 */ "uminus",
	""
};

struct yystate {
	short cost[8];
	struct {
		unsigned int yyfile:1;
		unsigned int yydecls:3;
		unsigned int yymain:1;
		unsigned int yyinstrs:1;
		unsigned int yyinstr:3;
		unsigned int yyprint:1;
		unsigned int yychars:3;
	} rule;
};

static short yynts_0[] = { yydecls_NT, yymain_NT, 0 };
static short yynts_1[] = { 0 };
static short yynts_2[] = { yydecls_NT, 0 };
static short yynts_3[] = { yydecls_NT, yydecls_NT, 0 };
static short yynts_4[] = { yyinstrs_NT, 0 };
static short yynts_5[] = { yyinstr_NT, 0 };
static short yynts_6[] = { yyinstr_NT, yyinstr_NT, 0 };
static short yynts_7[] = { yyprint_NT, 0 };
static short yynts_8[] = { yychars_NT, 0 };
static short yynts_9[] = { yychars_NT, yychars_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_1,	/* 4 */
	yynts_3,	/* 5 */
	yynts_4,	/* 6 */
	yynts_5,	/* 7 */
	yynts_5,	/* 8 */
	yynts_5,	/* 9 */
	yynts_6,	/* 10 */
	yynts_7,	/* 11 */
	yynts_8,	/* 12 */
	yynts_8,	/* 13 */
	yynts_1,	/* 14 */
	yynts_1,	/* 15 */
	yynts_1,	/* 16 */
	yynts_9,	/* 17 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"file: PROGRAM(decls,main)",
/* 2 */	"decls: NIL",
/* 3 */	"decls: DECL(NIL,decls)",
/* 4 */	"decls: VAR(NUMBER(ID,INT))",
/* 5 */	"decls: DECL(decls,decls)",
/* 6 */	"main: FUNCTION(END,instrs)",
/* 7 */	"instrs: FARGS(NIL,instr)",
/* 8 */	"instr: START(NIL,instr)",
/* 9 */	"instr: STMT(NIL,instr)",
/* 10 */	"instr: STMT(instr,instr)",
/* 11 */	"instr: print",
/* 12 */	"print: PSTMT(chars)",
/* 13 */	"chars: CHARS(NIL,chars)",
/* 14 */	"chars: INT",
/* 15 */	"chars: CHAR",
/* 16 */	"chars: STR",
/* 17 */	"chars: CHARS(chars,chars)",
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

static short yydecode_instrs[] = {
	0,
	7,
};

static short yydecode_instr[] = {
	0,
	8,
	9,
	10,
	11,
};

static short yydecode_print[] = {
	0,
	12,
};

static short yydecode_chars[] = {
	0,
	13,
	14,
	15,
	16,
	17,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 7)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfile_NT:	return yydecode_file[((struct yystate *)state)->rule.yyfile];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yymain_NT:	return yydecode_main[((struct yystate *)state)->rule.yymain];
	case yyinstrs_NT:	return yydecode_instrs[((struct yystate *)state)->rule.yyinstrs];
	case yyinstr_NT:	return yydecode_instr[((struct yystate *)state)->rule.yyinstr];
	case yyprint_NT:	return yydecode_print[((struct yystate *)state)->rule.yyprint];
	case yychars_NT:	return yydecode_chars[((struct yystate *)state)->rule.yychars];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_print(NODEPTR_TYPE, int);

static void yyclosure_print(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 0, p->cost[yyinstr_NT]);
	if (c + 0 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 0;
		p->rule.yyinstr = 4;
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PSTMT */
		yylabel(LEFT_CHILD(a),a);
		/* print: PSTMT(chars) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + 0;
		yytrace(a, 12, c + 0, p->cost[yyprint_NT]);
		if (c + 0 < p->cost[yyprint_NT]) {
			p->cost[yyprint_NT] = c + 0;
			p->rule.yyprint = 1;
			yyclosure_print(a, c + 0);
		}
		break;
	case 59: /* STMT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: STMT(NIL,instr) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
			yytrace(a, 9, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 2;
			}
		}
		/* instr: STMT(instr,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 0;
		yytrace(a, 10, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 3;
		}
		break;
	case 63: /* READOP */
		return;
	case 257: /* INT */
		/* chars: INT */
		yytrace(a, 14, 0 + 0, p->cost[yychars_NT]);
		if (0 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 0 + 0;
			p->rule.yychars = 2;
		}
		break;
	case 258: /* CHAR */
		/* chars: CHAR */
		yytrace(a, 15, 0 + 0, p->cost[yychars_NT]);
		if (0 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 0 + 0;
			p->rule.yychars = 3;
		}
		break;
	case 259: /* ID */
		return;
	case 260: /* STR */
		/* chars: STR */
		yytrace(a, 16, 0 + 0, p->cost[yychars_NT]);
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
			yytrace(a, 8, c + 0, p->cost[yyinstr_NT]);
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
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychars_NT] + 0;
			yytrace(a, 13, c + 0, p->cost[yychars_NT]);
			if (c + 0 < p->cost[yychars_NT]) {
				p->cost[yychars_NT] = c + 0;
				p->rule.yychars = 1;
			}
		}
		/* chars: CHARS(chars,chars) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychars_NT] + 0;
		yytrace(a, 17, c + 0, p->cost[yychars_NT]);
		if (c + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = c + 0;
			p->rule.yychars = 5;
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
		break;
	case 294: /* EQ */
		return;
	case 295: /* NE */
		return;
	case 296: /* GE */
		return;
	case 297: /* LE */
		return;
	case 298: /* uminus */
		return;
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
	case 17: /* chars: CHARS(chars,chars) */
	case 10: /* instr: STMT(instr,instr) */
	case 5: /* decls: DECL(decls,decls) */
	case 1: /* file: PROGRAM(decls,main) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 16: /* chars: STR */
	case 15: /* chars: CHAR */
	case 14: /* chars: INT */
	case 4: /* decls: VAR(NUMBER(ID,INT)) */
	case 2: /* decls: NIL */
		break;
	case 13: /* chars: CHARS(NIL,chars) */
	case 9: /* instr: STMT(NIL,instr) */
	case 8: /* instr: START(NIL,instr) */
	case 7: /* instrs: FARGS(NIL,instr) */
	case 6: /* main: FUNCTION(END,instrs) */
	case 3: /* decls: DECL(NIL,decls) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 11: /* instr: print */
		kids[0] = p;
		break;
	case 12: /* print: PSTMT(chars) */
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
		fprintf(stderr, "0x%p: line 50: file: PROGRAM(decls,main)\n",(void*)p);
#line 50 "minor.brg"
{}
		break;
	case 2: /* decls: NIL */
		fprintf(stderr, "0x%p: line 52: decls: NIL\n",(void*)p);
#line 52 "minor.brg"
{}
		break;
	case 3: /* decls: DECL(NIL,decls) */
		fprintf(stderr, "0x%p: line 53: decls: DECL(NIL,decls)\n",(void*)p);
#line 53 "minor.brg"
{}
		break;
	case 4: /* decls: VAR(NUMBER(ID,INT)) */
		fprintf(stderr, "0x%p: line 54: decls: VAR(NUMBER(ID,INT))\n",(void*)p);
#line 54 "minor.brg"
{ fprintf(yyout, pfIMM pfADDRA, p->SUB(0)->SUB(1)->value.i ,p->SUB(0)->SUB(0)->value.s); }
		break;
	case 5: /* decls: DECL(decls,decls) */
		fprintf(stderr, "0x%p: line 55: decls: DECL(decls,decls)\n",(void*)p);
#line 55 "minor.brg"
{}
		break;
	case 6: /* main: FUNCTION(END,instrs) */
		fprintf(stderr, "0x%p: line 57: main: FUNCTION(END,instrs)\n",(void*)p);
#line 57 "minor.brg"
{}
		break;
	case 7: /* instrs: FARGS(NIL,instr) */
		fprintf(stderr, "0x%p: line 59: instrs: FARGS(NIL,instr)\n",(void*)p);
#line 59 "minor.brg"
{}
		break;
	case 8: /* instr: START(NIL,instr) */
		fprintf(stderr, "0x%p: line 61: instr: START(NIL,instr)\n",(void*)p);
#line 61 "minor.brg"
{}
		break;
	case 9: /* instr: STMT(NIL,instr) */
		fprintf(stderr, "0x%p: line 63: instr: STMT(NIL,instr)\n",(void*)p);
#line 63 "minor.brg"

		break;
	case 10: /* instr: STMT(instr,instr) */
		fprintf(stderr, "0x%p: line 64: instr: STMT(instr,instr)\n",(void*)p);
#line 64 "minor.brg"

		break;
	case 11: /* instr: print */
		fprintf(stderr, "0x%p: line 65: instr: print\n",(void*)p);
#line 65 "minor.brg"

		break;
	case 12: /* print: PSTMT(chars) */
		fprintf(stderr, "0x%p: line 67: print: PSTMT(chars)\n",(void*)p);
#line 67 "minor.brg"
{
                      char *l = mklbl(++lbl); tmpStr[tmpStrInd++] = '\0';
                      fprintf(yyout, pfRODATA pfALIGN pfLABEL, l);
                      outstr(toPrint);
                      fprintf(yyout, pfTEXT pfADDR pfCALL pfTRASH,
                      l, "_prints", 4);
                      tmpStrInd = 0;
                      }
		break;
	case 13: /* chars: CHARS(NIL,chars) */
		fprintf(stderr, "0x%p: line 75: chars: CHARS(NIL,chars)\n",(void*)p);
#line 75 "minor.brg"
{}
		break;
	case 14: /* chars: INT */
		fprintf(stderr, "0x%p: line 76: chars: INT\n",(void*)p);
#line 76 "minor.brg"
{ tmpStr[tmpStrInd++] = p->value.i; toPrint = tmpStr;}
		break;
	case 15: /* chars: CHAR */
		fprintf(stderr, "0x%p: line 77: chars: CHAR\n",(void*)p);
#line 77 "minor.brg"
{ tmpStr[tmpStrInd++] = p->value.i; toPrint = tmpStr;}
		break;
	case 16: /* chars: STR */
		fprintf(stderr, "0x%p: line 78: chars: STR\n",(void*)p);
#line 78 "minor.brg"
{ toPrint = p->value.s; }
		break;
	case 17: /* chars: CHARS(chars,chars) */
		fprintf(stderr, "0x%p: line 79: chars: CHARS(chars,chars)\n",(void*)p);
#line 79 "minor.brg"
{}
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


#line 81 "minor.brg"

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
  IDevery(data,0);
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
