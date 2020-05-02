/*
generated at Sat May  2 16:59:59 2020
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
#include "minor.h"

#ifndef U_
#define U_ "_"
#endif

#define TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost);

int lbl;

extern FILE *yyout;
static char *mklbl(int n) {
	static char buf[20];
	sprintf(buf, "%cL%d", n < 0 ? '.' : '_', n);
	return strcpy(malloc(strlen(buf)+1),buf);
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
#define yyexpr_NT 7

static YYCONST char *yyntname[] = {
	0,
	"file",
	"decls",
	"main",
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
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "",
	/* 60 */ "STMT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
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
		unsigned int yydecls:1;
		unsigned int yymain:1;
		unsigned int yyinstrs:1;
		unsigned int yyinstr:1;
		unsigned int yyprint:1;
		unsigned int yyexpr:1;
	} rule;
};

static short yynts_0[] = { yydecls_NT, yymain_NT, 0 };
static short yynts_1[] = { 0 };
static short yynts_2[] = { yyinstrs_NT, 0 };
static short yynts_3[] = { yyinstr_NT, 0 };
static short yynts_4[] = { yyprint_NT, 0 };
static short yynts_5[] = { yyexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_1,	/* 7 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"file: PROGRAM(decls,main)",
/* 2 */	"decls: NIL",
/* 3 */	"main: FUNCTION(END,instrs)",
/* 4 */	"instrs: FARGS(NIL,instr)",
/* 5 */	"instr: START(NIL,STMT(NIL,print))",
/* 6 */	"print: PSTMT(expr)",
/* 7 */	"expr: CHARS(NIL,STR)",
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
};

static short yydecode_main[] = {
	0,
	3,
};

static short yydecode_instrs[] = {
	0,
	4,
};

static short yydecode_instr[] = {
	0,
	5,
};

static short yydecode_print[] = {
	0,
	6,
};

static short yydecode_expr[] = {
	0,
	7,
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
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
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
		/* print: PSTMT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 6, c + 0, p->cost[yyprint_NT]);
		if (c + 0 < p->cost[yyprint_NT]) {
			p->cost[yyprint_NT] = c + 0;
			p->rule.yyprint = 1;
		}
		break;
	case 59: /* STMT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 257: /* INT */
		return;
	case 258: /* CHAR */
		return;
	case 259: /* ID */
		return;
	case 260: /* STR */
		return;
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
			yytrace(a, 3, c + 0, p->cost[yymain_NT]);
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
		if (	/* instr: START(NIL,STMT(NIL,print)) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 59 && /* STMT */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyprint_NT] + 0;
			yytrace(a, 5, c + 0, p->cost[yyinstr_NT]);
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
			yytrace(a, 4, c + 0, p->cost[yyinstrs_NT]);
			if (c + 0 < p->cost[yyinstrs_NT]) {
				p->cost[yyinstrs_NT] = c + 0;
				p->rule.yyinstrs = 1;
			}
		}
		break;
	case 287: /* CHARS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CHARS(NIL,STR) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 260 /* STR */
		) {
			c = 0;
			yytrace(a, 7, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 1;
			}
		}
		break;
	case 288: /* INTS */
		return;
	case 289: /* ADDR */
		return;
	case 290: /* VAR */
		return;
	case 291: /* ARGS */
		return;
	case 292: /* DECL */
		return;
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
	case 1: /* file: PROGRAM(decls,main) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 7: /* expr: CHARS(NIL,STR) */
	case 2: /* decls: NIL */
		break;
	case 4: /* instrs: FARGS(NIL,instr) */
	case 3: /* main: FUNCTION(END,instrs) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 5: /* instr: START(NIL,STMT(NIL,print)) */
		kids[0] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 6: /* print: PSTMT(expr) */
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
		fprintf(stderr, "0x%p: line 40: file: PROGRAM(decls,main)\n",(void*)p);
#line 40 "minor.brg"
{}
		break;
	case 2: /* decls: NIL */
		fprintf(stderr, "0x%p: line 42: decls: NIL\n",(void*)p);
#line 42 "minor.brg"
{}
		break;
	case 3: /* main: FUNCTION(END,instrs) */
		fprintf(stderr, "0x%p: line 44: main: FUNCTION(END,instrs)\n",(void*)p);
#line 44 "minor.brg"
{}
		break;
	case 4: /* instrs: FARGS(NIL,instr) */
		fprintf(stderr, "0x%p: line 46: instrs: FARGS(NIL,instr)\n",(void*)p);
#line 46 "minor.brg"
{}
		break;
	case 5: /* instr: START(NIL,STMT(NIL,print)) */
		fprintf(stderr, "0x%p: line 48: instr: START(NIL,STMT(NIL,print))\n",(void*)p);
#line 48 "minor.brg"
{}
		break;
	case 6: /* print: PSTMT(expr) */
		fprintf(stderr, "0x%p: line 50: print: PSTMT(expr)\n",(void*)p);
#line 50 "minor.brg"
{}
		break;
	case 7: /* expr: CHARS(NIL,STR) */
		fprintf(stderr, "0x%p: line 52: expr: CHARS(NIL,STR)\n",(void*)p);
#line 52 "minor.brg"
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


#line 54 "minor.brg"


extern char **yynames;
extern int trace, errors, debugNode;

void evaluate(Node *p) {
	if (errors) return;
	/* if (trace) */ printNode(p, stdout, yynames);
	if (!yyselect(p) && trace) printf("selection successful\n");
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
