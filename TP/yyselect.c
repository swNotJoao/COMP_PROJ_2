/*
generated at Thu May 28 23:25:53 2020
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
#include "tabid.h"
#include "postfix.h"
#include "y.tab.h"
#include "minor.h"

#ifndef U_
#define U_ "_"
#endif

#define TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost);

extern FILE *yyout;
static int lbl, trash, cnt, stp[10], stpn;
static char *mklbl(int n) {
	static char buf[20];
	sprintf(buf, ".L%d", n);
	return strcpy(malloc(strlen(buf)+1),buf);
}
static char *mkfunc(char *s) {
	static char buf[80];
	strcpy(buf, "_");
	strcat(buf, s);
	return buf;
}
static int mkid(Node *p) {
	Node *addr;
	int type = IDfind(p->value.s, (void**)&addr);
	if (addr->attrib == VOID)
		fprintf(yyout, pfLOCAL, (int)addr->place * pfWORD);
	else
		fprintf(yyout, pfADDR, p->value.s);
	return tTYPE(type);
}
static void mkstr(char *s) {
	int l = ++lbl;
	fprintf(yyout, pfDATA pfLABEL, mklbl(l));
	while (*s)
		fprintf(yyout, pfCHAR, (unsigned char)*s++);
	fprintf(yyout, pfCHAR pfTEXT pfADDR, 0, mklbl(l));
}
static int isFunc(NODEPTR_TYPE p) {
	return (p->info & tFUNC) ? 1 : 1000; }
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
#define yyfunc_NT 3
#define yydecl_NT 4
#define yyfargs_NT 5
#define yyfarg_NT 6
#define yyid_NT 7
#define yyend_NT 8
#define yyeargs_NT 9
#define yyenter_NT 10
#define yystmt_NT 11
#define yyvars_NT 12
#define yyexpr_NT 13
#define yystr_NT 14
#define yythen_NT 15
#define yyif_NT 16
#define yycond_NT 17
#define yyuntil_NT 18
#define yystep_NT 19
#define yybegin_NT 20
#define yylv_NT 21
#define yydup_NT 22
#define yyargs_NT 23

static YYCONST char *yyntname[] = {
	0,
	"file",
	"decls",
	"func",
	"decl",
	"fargs",
	"farg",
	"id",
	"end",
	"eargs",
	"enter",
	"stmt",
	"vars",
	"expr",
	"str",
	"then",
	"if",
	"cond",
	"until",
	"step",
	"begin",
	"lv",
	"dup",
	"args",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "PRINT",
 "", "", "", "", "", "",
	/* 41 */ "CALL",
 "", "",
	/* 44 */ "ADD",
	/* 45 */ "ARG",
	/* 46 */ "SUB",
 "", "", "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "STMT",
	/* 61 */ "LT",
	/* 62 */ "EQUAL",
	/* 63 */ "GT",
	/* 64 */ "INPUT",
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
	/* 295 */ "TPAND",
	/* 296 */ "GOTO",
	/* 297 */ "LABEL",
	/* 298 */ "EQ",
	/* 299 */ "NE",
	/* 300 */ "GE",
	/* 301 */ "LE",
	/* 302 */ "uminus",
	""
};

struct yystate {
	short cost[24];
	struct {
		unsigned int yyfile:2;
		unsigned int yydecls:2;
		unsigned int yyfunc:1;
		unsigned int yydecl:3;
		unsigned int yyfargs:2;
		unsigned int yyfarg:2;
		unsigned int yyid:1;
		unsigned int yyend:1;
		unsigned int yyeargs:2;
		unsigned int yyenter:1;
		unsigned int yystmt:4;
		unsigned int yyvars:2;
		unsigned int yyexpr:4;
		unsigned int yystr:1;
		unsigned int yythen:1;
		unsigned int yyif:1;
		unsigned int yycond:1;
		unsigned int yyuntil:1;
		unsigned int yystep:1;
		unsigned int yybegin:1;
		unsigned int yylv:1;
		unsigned int yydup:1;
		unsigned int yyargs:2;
	} rule;
};

static short yynts_0[] = { yydecls_NT, 0 };
static short yynts_1[] = { yydecls_NT, yyfunc_NT, 0 };
static short yynts_2[] = { 0 };
static short yynts_3[] = { yydecls_NT, yydecl_NT, 0 };
static short yynts_4[] = { yyfargs_NT, 0 };
static short yynts_5[] = { yyfargs_NT, yyfarg_NT, 0 };
static short yynts_6[] = { yyfunc_NT, 0 };
static short yynts_7[] = { yydecl_NT, 0 };
static short yynts_8[] = { yyid_NT, 0 };
static short yynts_9[] = { yyend_NT, yyeargs_NT, yyenter_NT, yystmt_NT, 0 };
static short yynts_10[] = { yyeargs_NT, yyfarg_NT, 0 };
static short yynts_11[] = { yyvars_NT, 0 };
static short yynts_12[] = { yyvars_NT, yyfarg_NT, 0 };
static short yynts_13[] = { yystmt_NT, yystmt_NT, 0 };
static short yynts_14[] = { yyexpr_NT, 0 };
static short yynts_15[] = { yystr_NT, 0 };
static short yynts_16[] = { yythen_NT, yystmt_NT, 0 };
static short yynts_17[] = { yyif_NT, 0 };
static short yynts_18[] = { yycond_NT, yystmt_NT, 0 };
static short yynts_19[] = { yyuntil_NT, yystep_NT, 0 };
static short yynts_20[] = { yybegin_NT, yyexpr_NT, 0 };
static short yynts_21[] = { yystmt_NT, yyexpr_NT, 0 };
static short yynts_22[] = { yydup_NT, yylv_NT, 0 };
static short yynts_23[] = { yylv_NT, 0 };
static short yynts_24[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_25[] = { yyargs_NT, 0 };
static short yynts_26[] = { yyexpr_NT, yyargs_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_2,	/* 5 */
	yynts_4,	/* 6 */
	yynts_5,	/* 7 */
	yynts_2,	/* 8 */
	yynts_2,	/* 9 */
	yynts_2,	/* 10 */
	yynts_6,	/* 11 */
	yynts_7,	/* 12 */
	yynts_8,	/* 13 */
	yynts_8,	/* 14 */
	yynts_2,	/* 15 */
	yynts_9,	/* 16 */
	yynts_2,	/* 17 */
	yynts_10,	/* 18 */
	yynts_2,	/* 19 */
	yynts_11,	/* 20 */
	yynts_12,	/* 21 */
	yynts_2,	/* 22 */
	yynts_13,	/* 23 */
	yynts_2,	/* 24 */
	yynts_2,	/* 25 */
	yynts_14,	/* 26 */
	yynts_2,	/* 27 */
	yynts_14,	/* 28 */
	yynts_15,	/* 29 */
	yynts_15,	/* 30 */
	yynts_2,	/* 31 */
	yynts_14,	/* 32 */
	yynts_16,	/* 33 */
	yynts_17,	/* 34 */
	yynts_18,	/* 35 */
	yynts_14,	/* 36 */
	yynts_19,	/* 37 */
	yynts_20,	/* 38 */
	yynts_14,	/* 39 */
	yynts_21,	/* 40 */
	yynts_2,	/* 41 */
	yynts_22,	/* 42 */
	yynts_14,	/* 43 */
	yynts_23,	/* 44 */
	yynts_2,	/* 45 */
	yynts_2,	/* 46 */
	yynts_2,	/* 47 */
	yynts_23,	/* 48 */
	yynts_24,	/* 49 */
	yynts_24,	/* 50 */
	yynts_24,	/* 51 */
	yynts_24,	/* 52 */
	yynts_24,	/* 53 */
	yynts_25,	/* 54 */
	yynts_26,	/* 55 */
	yynts_2,	/* 56 */
	yynts_24,	/* 57 */
	yynts_2,	/* 58 */
	yynts_2,	/* 59 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"file: MODULE(decls)",
/* 2 */	"file: PROGRAM(decls,func)",
/* 3 */	"decls: NIL",
/* 4 */	"decls: DECL(decls,decl)",
/* 5 */	"decl: NIL",
/* 6 */	"decl: FUNCTION(END,FARGS(fargs,NIL))",
/* 7 */	"fargs: ARGS(fargs,farg)",
/* 8 */	"fargs: NIL",
/* 9 */	"farg: NUMBER(ID,NIL)",
/* 10 */	"farg: STRING(ID,NIL)",
/* 11 */	"decl: func",
/* 12 */	"decl: VAR(decl)",
/* 13 */	"decl: NUMBER(id,NIL)",
/* 14 */	"decl: NUMBER(id,INT)",
/* 15 */	"id: ID",
/* 16 */	"func: FUNCTION(end,FARGS(eargs,START(enter,stmt)))",
/* 17 */	"end: END",
/* 18 */	"eargs: ARGS(eargs,farg)",
/* 19 */	"eargs: NIL",
/* 20 */	"enter: vars",
/* 21 */	"vars: ARGS(vars,farg)",
/* 22 */	"vars: NIL",
/* 23 */	"stmt: STMT(stmt,stmt)",
/* 24 */	"stmt: NIL",
/* 25 */	"stmt: RETURN(NIL)",
/* 26 */	"stmt: RETURN(expr)",
/* 27 */	"stmt: STOP",
/* 28 */	"stmt: PRINT(expr)",
/* 29 */	"stmt: PRINT(str)",
/* 30 */	"expr: str",
/* 31 */	"str: CHARS(NIL,STR)",
/* 32 */	"stmt: expr",
/* 33 */	"stmt: FI(then,stmt)",
/* 34 */	"then: THEN(if,NIL)",
/* 35 */	"if: IF(cond,stmt)",
/* 36 */	"cond: expr",
/* 37 */	"stmt: FOR(until,step)",
/* 38 */	"until: UNTIL(begin,expr)",
/* 39 */	"begin: expr",
/* 40 */	"step: STEP(stmt,expr)",
/* 41 */	"lv: ID",
/* 42 */	"expr: EQ(dup,lv)",
/* 43 */	"dup: expr",
/* 44 */	"expr: lv",
/* 45 */	"expr: CHARS(NIL,INT)",
/* 46 */	"expr: ID",
/* 47 */	"expr: INPUT",
/* 48 */	"expr: ADDR(lv)",
/* 49 */	"expr: ADD(expr,expr)",
/* 50 */	"expr: SUB(expr,expr)",
/* 51 */	"expr: EQUAL(expr,expr)",
/* 52 */	"expr: GT(expr,expr)",
/* 53 */	"expr: LT(expr,expr)",
/* 54 */	"expr: CALL(ID,args)",
/* 55 */	"args: ARG(expr,args)",
/* 56 */	"args: NIL",
/* 57 */	"expr: TPAND(expr,expr)",
/* 58 */	"stmt: LABEL",
/* 59 */	"stmt: GOTO",
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
	2,
};

static short yydecode_decls[] = {
	0,
	3,
	4,
};

static short yydecode_func[] = {
	0,
	16,
};

static short yydecode_decl[] = {
	0,
	5,
	6,
	11,
	12,
	13,
	14,
};

static short yydecode_fargs[] = {
	0,
	7,
	8,
};

static short yydecode_farg[] = {
	0,
	9,
	10,
};

static short yydecode_id[] = {
	0,
	15,
};

static short yydecode_end[] = {
	0,
	17,
};

static short yydecode_eargs[] = {
	0,
	18,
	19,
};

static short yydecode_enter[] = {
	0,
	20,
};

static short yydecode_stmt[] = {
	0,
	23,
	24,
	25,
	26,
	27,
	28,
	29,
	32,
	33,
	37,
	58,
	59,
};

static short yydecode_vars[] = {
	0,
	21,
	22,
};

static short yydecode_expr[] = {
	0,
	30,
	42,
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
	57,
};

static short yydecode_str[] = {
	0,
	31,
};

static short yydecode_then[] = {
	0,
	34,
};

static short yydecode_if[] = {
	0,
	35,
};

static short yydecode_cond[] = {
	0,
	36,
};

static short yydecode_until[] = {
	0,
	38,
};

static short yydecode_step[] = {
	0,
	40,
};

static short yydecode_begin[] = {
	0,
	39,
};

static short yydecode_lv[] = {
	0,
	41,
};

static short yydecode_dup[] = {
	0,
	43,
};

static short yydecode_args[] = {
	0,
	55,
	56,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 23)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfile_NT:	return yydecode_file[((struct yystate *)state)->rule.yyfile];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yyfunc_NT:	return yydecode_func[((struct yystate *)state)->rule.yyfunc];
	case yydecl_NT:	return yydecode_decl[((struct yystate *)state)->rule.yydecl];
	case yyfargs_NT:	return yydecode_fargs[((struct yystate *)state)->rule.yyfargs];
	case yyfarg_NT:	return yydecode_farg[((struct yystate *)state)->rule.yyfarg];
	case yyid_NT:	return yydecode_id[((struct yystate *)state)->rule.yyid];
	case yyend_NT:	return yydecode_end[((struct yystate *)state)->rule.yyend];
	case yyeargs_NT:	return yydecode_eargs[((struct yystate *)state)->rule.yyeargs];
	case yyenter_NT:	return yydecode_enter[((struct yystate *)state)->rule.yyenter];
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
	case yyvars_NT:	return yydecode_vars[((struct yystate *)state)->rule.yyvars];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yystr_NT:	return yydecode_str[((struct yystate *)state)->rule.yystr];
	case yythen_NT:	return yydecode_then[((struct yystate *)state)->rule.yythen];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yyuntil_NT:	return yydecode_until[((struct yystate *)state)->rule.yyuntil];
	case yystep_NT:	return yydecode_step[((struct yystate *)state)->rule.yystep];
	case yybegin_NT:	return yydecode_begin[((struct yystate *)state)->rule.yybegin];
	case yylv_NT:	return yydecode_lv[((struct yystate *)state)->rule.yylv];
	case yydup_NT:	return yydecode_dup[((struct yystate *)state)->rule.yydup];
	case yyargs_NT:	return yydecode_args[((struct yystate *)state)->rule.yyargs];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_func(NODEPTR_TYPE, int);
static void yyclosure_vars(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_str(NODEPTR_TYPE, int);
static void yyclosure_lv(NODEPTR_TYPE, int);

static void yyclosure_func(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 0, p->cost[yydecl_NT]);
	if (c + 0 < p->cost[yydecl_NT]) {
		p->cost[yydecl_NT] = c + 0;
		p->rule.yydecl = 3;
	}
}

static void yyclosure_vars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 20, c + 1, p->cost[yyenter_NT]);
	if (c + 1 < p->cost[yyenter_NT]) {
		p->cost[yyenter_NT] = c + 1;
		p->rule.yyenter = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 43, c + 1, p->cost[yydup_NT]);
	if (c + 1 < p->cost[yydup_NT]) {
		p->cost[yydup_NT] = c + 1;
		p->rule.yydup = 1;
	}
	yytrace(a, 39, c + 1, p->cost[yybegin_NT]);
	if (c + 1 < p->cost[yybegin_NT]) {
		p->cost[yybegin_NT] = c + 1;
		p->rule.yybegin = 1;
	}
	yytrace(a, 36, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 32, c + 1, p->cost[yystmt_NT]);
	if (c + 1 < p->cost[yystmt_NT]) {
		p->cost[yystmt_NT] = c + 1;
		p->rule.yystmt = 8;
	}
}

static void yyclosure_str(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 30, c + 1000, p->cost[yyexpr_NT]);
	if (c + 1000 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1000;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 1000);
	}
}

static void yyclosure_lv(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 44, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 3;
		yyclosure_expr(a, c + 1);
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
	p->cost[14] =
	p->cost[15] =
	p->cost[16] =
	p->cost[17] =
	p->cost[18] =
	p->cost[19] =
	p->cost[20] =
	p->cost[21] =
	p->cost[22] =
	p->cost[23] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PRINT */
		yylabel(LEFT_CHILD(a),a);
		/* stmt: PRINT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 2;
		yytrace(a, 28, c + 0, p->cost[yystmt_NT]);
		if (c + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = c + 0;
			p->rule.yystmt = 6;
		}
		/* stmt: PRINT(str) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystr_NT] + 2;
		yytrace(a, 29, c + 0, p->cost[yystmt_NT]);
		if (c + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = c + 0;
			p->rule.yystmt = 7;
		}
		break;
	case 40: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,args) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 3;
			yytrace(a, 54, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 13;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 49, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 44: /* ARG */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* args: ARG(expr,args) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 1;
		yytrace(a, 55, c + 0, p->cost[yyargs_NT]);
		if (c + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = c + 0;
			p->rule.yyargs = 1;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: SUB(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 50, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 59: /* STMT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* stmt: STMT(stmt,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystmt_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 0;
		yytrace(a, 23, c + 0, p->cost[yystmt_NT]);
		if (c + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = c + 0;
			p->rule.yystmt = 1;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 53, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* EQUAL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQUAL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 51, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 10;
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
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 63: /* INPUT */
		/* expr: INPUT */
		yytrace(a, 47, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 257: /* INT */
		return;
	case 258: /* CHAR */
		return;
	case 259: /* ID */
		/* id: ID */
		yytrace(a, 15, 1 + 0, p->cost[yyid_NT]);
		if (1 + 0 < p->cost[yyid_NT]) {
			p->cost[yyid_NT] = 1 + 0;
			p->rule.yyid = 1;
		}
		/* lv: ID */
		yytrace(a, 41, 1 + 0, p->cost[yylv_NT]);
		if (1 + 0 < p->cost[yylv_NT]) {
			p->cost[yylv_NT] = 1 + 0;
			p->rule.yylv = 1;
			yyclosure_lv(a, 1 + 0);
		}
		/* expr: ID */
		c = (isFunc(a));
		yytrace(a, 46, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 5;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 260: /* STR */
		return;
	case 261: /* PROGRAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* file: PROGRAM(decls,func) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfunc_NT] + 0;
		yytrace(a, 2, c + 0, p->cost[yyfile_NT]);
		if (c + 0 < p->cost[yyfile_NT]) {
			p->cost[yyfile_NT] = c + 0;
			p->rule.yyfile = 2;
		}
		break;
	case 262: /* MODULE */
		yylabel(LEFT_CHILD(a),a);
		/* file: MODULE(decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + 0;
		yytrace(a, 1, c + 0, p->cost[yyfile_NT]);
		if (c + 0 < p->cost[yyfile_NT]) {
			p->cost[yyfile_NT] = c + 0;
			p->rule.yyfile = 1;
		}
		break;
	case 263: /* END */
		/* end: END */
		yytrace(a, 17, 1 + 0, p->cost[yyend_NT]);
		if (1 + 0 < p->cost[yyend_NT]) {
			p->cost[yyend_NT] = 1 + 0;
			p->rule.yyend = 1;
		}
		break;
	case 264: /* PUBLIC */
		return;
	case 265: /* FORWARD */
		return;
	case 266: /* STRING */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* farg: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 0;
			yytrace(a, 10, c + 0, p->cost[yyfarg_NT]);
			if (c + 0 < p->cost[yyfarg_NT]) {
				p->cost[yyfarg_NT] = c + 0;
				p->rule.yyfarg = 2;
			}
		}
		break;
	case 267: /* NUMBER */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* farg: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 0;
			yytrace(a, 9, c + 0, p->cost[yyfarg_NT]);
			if (c + 0 < p->cost[yyfarg_NT]) {
				p->cost[yyfarg_NT] = c + 0;
				p->rule.yyfarg = 1;
			}
		}
		if (	/* decl: NUMBER(id,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyid_NT] + 1;
			yytrace(a, 13, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 5;
			}
		}
		if (	/* decl: NUMBER(id,INT) */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyid_NT] + 1;
			yytrace(a, 14, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 6;
			}
		}
		break;
	case 268: /* ARRAY */
		return;
	case 269: /* FUNCTION */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* decl: FUNCTION(END,FARGS(fargs,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 263 && /* END */
			OP_LABEL(RIGHT_CHILD(a)) == 286 && /* FARGS */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyfargs_NT] + 1;
			yytrace(a, 6, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 2;
			}
		}
		if (	/* func: FUNCTION(end,FARGS(eargs,START(enter,stmt))) */
			OP_LABEL(RIGHT_CHILD(a)) == 286 && /* FARGS */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 278 /* START */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyend_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyeargs_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))))->cost[yyenter_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))))->cost[yystmt_NT] + 1;
			yytrace(a, 16, c + 0, p->cost[yyfunc_NT]);
			if (c + 0 < p->cost[yyfunc_NT]) {
				p->cost[yyfunc_NT] = c + 0;
				p->rule.yyfunc = 1;
				yyclosure_func(a, c + 0);
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
		/* if: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		break;
	case 273: /* THEN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* then: THEN(if,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyif_NT] + 0;
			yytrace(a, 34, c + 0, p->cost[yythen_NT]);
			if (c + 0 < p->cost[yythen_NT]) {
				p->cost[yythen_NT] = c + 0;
				p->rule.yythen = 1;
			}
		}
		break;
	case 274: /* FI */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* stmt: FI(then,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yythen_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yystmt_NT]);
		if (c + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = c + 0;
			p->rule.yystmt = 9;
		}
		break;
	case 275: /* ELIF */
		return;
	case 276: /* ELSE */
		return;
	case 277: /* RETURN */
		yylabel(LEFT_CHILD(a),a);
		if (	/* stmt: RETURN(NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = 2;
			yytrace(a, 25, c + 0, p->cost[yystmt_NT]);
			if (c + 0 < p->cost[yystmt_NT]) {
				p->cost[yystmt_NT] = c + 0;
				p->rule.yystmt = 3;
			}
		}
		/* stmt: RETURN(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 3;
		yytrace(a, 26, c + 0, p->cost[yystmt_NT]);
		if (c + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = c + 0;
			p->rule.yystmt = 4;
		}
		break;
	case 278: /* START */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 279: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* stmt: FOR(until,step) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyuntil_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystep_NT] + 1;
		yytrace(a, 37, c + 0, p->cost[yystmt_NT]);
		if (c + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = c + 0;
			p->rule.yystmt = 10;
		}
		break;
	case 280: /* UNTIL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* until: UNTIL(begin,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybegin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 2;
		yytrace(a, 38, c + 0, p->cost[yyuntil_NT]);
		if (c + 0 < p->cost[yyuntil_NT]) {
			p->cost[yyuntil_NT] = c + 0;
			p->rule.yyuntil = 1;
		}
		break;
	case 281: /* STEP */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* step: STEP(stmt,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystmt_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 40, c + 0, p->cost[yystep_NT]);
		if (c + 0 < p->cost[yystep_NT]) {
			p->cost[yystep_NT] = c + 0;
			p->rule.yystep = 1;
		}
		break;
	case 282: /* DO */
		return;
	case 283: /* DONE */
		return;
	case 284: /* REPEAT */
		return;
	case 285: /* STOP */
		/* stmt: STOP */
		yytrace(a, 27, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 5;
		}
		break;
	case 286: /* FARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 287: /* CHARS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* str: CHARS(NIL,STR) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 260 /* STR */
		) {
			c = 2;
			yytrace(a, 31, c + 0, p->cost[yystr_NT]);
			if (c + 0 < p->cost[yystr_NT]) {
				p->cost[yystr_NT] = c + 0;
				p->rule.yystr = 1;
				yyclosure_str(a, c + 0);
			}
		}
		if (	/* expr: CHARS(NIL,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 45, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 288: /* INTS */
		return;
	case 289: /* ADDR */
		yylabel(LEFT_CHILD(a),a);
		/* expr: ADDR(lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylv_NT] + 0;
		yytrace(a, 48, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 290: /* VAR */
		yylabel(LEFT_CHILD(a),a);
		/* decl: VAR(decl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecl_NT] + 0;
		yytrace(a, 12, c + 0, p->cost[yydecl_NT]);
		if (c + 0 < p->cost[yydecl_NT]) {
			p->cost[yydecl_NT] = c + 0;
			p->rule.yydecl = 4;
		}
		break;
	case 291: /* ARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* fargs: ARGS(fargs,farg) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfarg_NT] + 0;
		yytrace(a, 7, c + 0, p->cost[yyfargs_NT]);
		if (c + 0 < p->cost[yyfargs_NT]) {
			p->cost[yyfargs_NT] = c + 0;
			p->rule.yyfargs = 1;
		}
		/* eargs: ARGS(eargs,farg) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyeargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfarg_NT] + 0;
		yytrace(a, 18, c + 0, p->cost[yyeargs_NT]);
		if (c + 0 < p->cost[yyeargs_NT]) {
			p->cost[yyeargs_NT] = c + 0;
			p->rule.yyeargs = 1;
		}
		/* vars: ARGS(vars,farg) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfarg_NT] + 0;
		yytrace(a, 21, c + 0, p->cost[yyvars_NT]);
		if (c + 0 < p->cost[yyvars_NT]) {
			p->cost[yyvars_NT] = c + 0;
			p->rule.yyvars = 1;
			yyclosure_vars(a, c + 0);
		}
		break;
	case 292: /* DECL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* decls: DECL(decls,decl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecl_NT] + 0;
		yytrace(a, 4, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 2;
		}
		break;
	case 293: /* NIL */
		/* decls: NIL */
		yytrace(a, 3, 0 + 0, p->cost[yydecls_NT]);
		if (0 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 0 + 0;
			p->rule.yydecls = 1;
		}
		/* decl: NIL */
		yytrace(a, 5, 0 + 0, p->cost[yydecl_NT]);
		if (0 + 0 < p->cost[yydecl_NT]) {
			p->cost[yydecl_NT] = 0 + 0;
			p->rule.yydecl = 1;
		}
		/* fargs: NIL */
		yytrace(a, 8, 0 + 0, p->cost[yyfargs_NT]);
		if (0 + 0 < p->cost[yyfargs_NT]) {
			p->cost[yyfargs_NT] = 0 + 0;
			p->rule.yyfargs = 2;
		}
		/* eargs: NIL */
		yytrace(a, 19, 0 + 0, p->cost[yyeargs_NT]);
		if (0 + 0 < p->cost[yyeargs_NT]) {
			p->cost[yyeargs_NT] = 0 + 0;
			p->rule.yyeargs = 2;
		}
		/* vars: NIL */
		yytrace(a, 22, 0 + 0, p->cost[yyvars_NT]);
		if (0 + 0 < p->cost[yyvars_NT]) {
			p->cost[yyvars_NT] = 0 + 0;
			p->rule.yyvars = 2;
			yyclosure_vars(a, 0 + 0);
		}
		/* stmt: NIL */
		yytrace(a, 24, 0 + 0, p->cost[yystmt_NT]);
		if (0 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 0 + 0;
			p->rule.yystmt = 2;
		}
		/* args: NIL */
		yytrace(a, 56, 1 + 0, p->cost[yyargs_NT]);
		if (1 + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = 1 + 0;
			p->rule.yyargs = 2;
		}
		break;
	case 294: /* TPAND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: TPAND(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 57, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 14;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 295: /* GOTO */
		/* stmt: GOTO */
		yytrace(a, 59, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 12;
		}
		break;
	case 296: /* LABEL */
		/* stmt: LABEL */
		yytrace(a, 58, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 11;
		}
		break;
	case 297: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(dup,lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydup_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylv_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 2;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 298: /* NE */
		return;
	case 299: /* GE */
		return;
	case 300: /* LE */
		return;
	case 301: /* uminus */
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
	case 48: /* expr: ADDR(lv) */
	case 34: /* then: THEN(if,NIL) */
	case 29: /* stmt: PRINT(str) */
	case 28: /* stmt: PRINT(expr) */
	case 26: /* stmt: RETURN(expr) */
	case 14: /* decl: NUMBER(id,INT) */
	case 13: /* decl: NUMBER(id,NIL) */
	case 12: /* decl: VAR(decl) */
	case 1: /* file: MODULE(decls) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 57: /* expr: TPAND(expr,expr) */
	case 55: /* args: ARG(expr,args) */
	case 53: /* expr: LT(expr,expr) */
	case 52: /* expr: GT(expr,expr) */
	case 51: /* expr: EQUAL(expr,expr) */
	case 50: /* expr: SUB(expr,expr) */
	case 49: /* expr: ADD(expr,expr) */
	case 42: /* expr: EQ(dup,lv) */
	case 40: /* step: STEP(stmt,expr) */
	case 38: /* until: UNTIL(begin,expr) */
	case 37: /* stmt: FOR(until,step) */
	case 35: /* if: IF(cond,stmt) */
	case 33: /* stmt: FI(then,stmt) */
	case 23: /* stmt: STMT(stmt,stmt) */
	case 21: /* vars: ARGS(vars,farg) */
	case 18: /* eargs: ARGS(eargs,farg) */
	case 7: /* fargs: ARGS(fargs,farg) */
	case 4: /* decls: DECL(decls,decl) */
	case 2: /* file: PROGRAM(decls,func) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 59: /* stmt: GOTO */
	case 58: /* stmt: LABEL */
	case 56: /* args: NIL */
	case 47: /* expr: INPUT */
	case 46: /* expr: ID */
	case 45: /* expr: CHARS(NIL,INT) */
	case 41: /* lv: ID */
	case 31: /* str: CHARS(NIL,STR) */
	case 27: /* stmt: STOP */
	case 25: /* stmt: RETURN(NIL) */
	case 24: /* stmt: NIL */
	case 22: /* vars: NIL */
	case 19: /* eargs: NIL */
	case 17: /* end: END */
	case 15: /* id: ID */
	case 10: /* farg: STRING(ID,NIL) */
	case 9: /* farg: NUMBER(ID,NIL) */
	case 8: /* fargs: NIL */
	case 5: /* decl: NIL */
	case 3: /* decls: NIL */
		break;
	case 6: /* decl: FUNCTION(END,FARGS(fargs,NIL)) */
		kids[0] = LEFT_CHILD(RIGHT_CHILD(p));
		break;
	case 44: /* expr: lv */
	case 43: /* dup: expr */
	case 39: /* begin: expr */
	case 36: /* cond: expr */
	case 32: /* stmt: expr */
	case 30: /* expr: str */
	case 20: /* enter: vars */
	case 11: /* decl: func */
		kids[0] = p;
		break;
	case 16: /* func: FUNCTION(end,FARGS(eargs,START(enter,stmt))) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(p)));
		kids[3] = RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(p)));
		break;
	case 54: /* expr: CALL(ID,args) */
		kids[0] = RIGHT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[4];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* file: MODULE(decls) */
		fprintf(stderr, "0x%p: line 57: file: MODULE(decls)\n",(void*)p);
#line 57 "minor.brg"

		break;
	case 2: /* file: PROGRAM(decls,func) */
		fprintf(stderr, "0x%p: line 58: file: PROGRAM(decls,func)\n",(void*)p);
#line 58 "minor.brg"

		break;
	case 3: /* decls: NIL */
		fprintf(stderr, "0x%p: line 59: decls: NIL\n",(void*)p);
#line 59 "minor.brg"

		break;
	case 4: /* decls: DECL(decls,decl) */
		fprintf(stderr, "0x%p: line 60: decls: DECL(decls,decl)\n",(void*)p);
#line 60 "minor.brg"

		break;
	case 5: /* decl: NIL */
		fprintf(stderr, "0x%p: line 61: decl: NIL\n",(void*)p);
#line 61 "minor.brg"

		break;
	case 6: /* decl: FUNCTION(END,FARGS(fargs,NIL)) */
		fprintf(stderr, "0x%p: line 62: decl: FUNCTION(END,FARGS(fargs,NIL))\n",(void*)p);
#line 62 "minor.brg"
{ fprintf(yyout, pfEXTRN, mkfunc(LEFT_CHILD(LEFT_CHILD(p))->value.s)); }
		break;
	case 7: /* fargs: ARGS(fargs,farg) */
		fprintf(stderr, "0x%p: line 63: fargs: ARGS(fargs,farg)\n",(void*)p);
#line 63 "minor.brg"

		break;
	case 8: /* fargs: NIL */
		fprintf(stderr, "0x%p: line 64: fargs: NIL\n",(void*)p);
#line 64 "minor.brg"

		break;
	case 9: /* farg: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%p: line 65: farg: NUMBER(ID,NIL)\n",(void*)p);
#line 65 "minor.brg"

		break;
	case 10: /* farg: STRING(ID,NIL) */
		fprintf(stderr, "0x%p: line 66: farg: STRING(ID,NIL)\n",(void*)p);
#line 66 "minor.brg"

		break;
	case 11: /* decl: func */
		fprintf(stderr, "0x%p: line 67: decl: func\n",(void*)p);
#line 67 "minor.brg"

		break;
	case 12: /* decl: VAR(decl) */
		fprintf(stderr, "0x%p: line 68: decl: VAR(decl)\n",(void*)p);
#line 68 "minor.brg"

		break;
	case 13: /* decl: NUMBER(id,NIL) */
		fprintf(stderr, "0x%p: line 69: decl: NUMBER(id,NIL)\n",(void*)p);
#line 69 "minor.brg"
{ fprintf(yyout, pfINTEGER, 0); }
		break;
	case 14: /* decl: NUMBER(id,INT) */
		fprintf(stderr, "0x%p: line 70: decl: NUMBER(id,INT)\n",(void*)p);
#line 70 "minor.brg"
{ fprintf(yyout, pfINTEGER, RIGHT_CHILD(p)->value.i); }
		break;
	case 15: /* id: ID */
		fprintf(stderr, "0x%p: line 71: id: ID\n",(void*)p);
#line 71 "minor.brg"
{ fprintf(yyout, pfDATA pfALIGN pfLABEL, p->value.s); }
		break;
	case 16: /* func: FUNCTION(end,FARGS(eargs,START(enter,stmt))) */
		fprintf(stderr, "0x%p: line 73: func: FUNCTION(end,FARGS(eargs,START(enter,stmt)))\n",(void*)p);
#line 73 "minor.brg"
{ fprintf(yyout, pfIMM pfPOP pfLEAVE pfRET, 0); IDpop(); }
		break;
	case 17: /* end: END */
		fprintf(stderr, "0x%p: line 74: end: END\n",(void*)p);
#line 74 "minor.brg"
{ if (RIGHT_CHILD(p)->value.i & tPUB) fprintf(yyout, pfGLOBL, mkfunc(LEFT_CHILD(p)->value.s), pfFUNC); fprintf(yyout, pfTEXT pfALIGN pfLABEL, mkfunc(LEFT_CHILD(p)->value.s)); IDpush(); }
		break;
	case 18: /* eargs: ARGS(eargs,farg) */
		fprintf(stderr, "0x%p: line 75: eargs: ARGS(eargs,farg)\n",(void*)p);
#line 75 "minor.brg"
{ Node *n = nilNode(VOID); n->place = ++cnt; IDnew(RIGHT_CHILD(p)->info, LEFT_CHILD(RIGHT_CHILD(p))->value.s, n); }
		break;
	case 19: /* eargs: NIL */
		fprintf(stderr, "0x%p: line 76: eargs: NIL\n",(void*)p);
#line 76 "minor.brg"
{ cnt = 1; }
		break;
	case 20: /* enter: vars */
		fprintf(stderr, "0x%p: line 77: enter: vars\n",(void*)p);
#line 77 "minor.brg"
{ fprintf(yyout, pfENTER, -cnt * pfWORD); }
		break;
	case 21: /* vars: ARGS(vars,farg) */
		fprintf(stderr, "0x%p: line 78: vars: ARGS(vars,farg)\n",(void*)p);
#line 78 "minor.brg"
{ Node *n = nilNode(VOID); n->place = --cnt; IDnew(RIGHT_CHILD(p)->info, LEFT_CHILD(RIGHT_CHILD(p))->value.s, n); }
		break;
	case 22: /* vars: NIL */
		fprintf(stderr, "0x%p: line 79: vars: NIL\n",(void*)p);
#line 79 "minor.brg"
{ cnt = 0; }
		break;
	case 23: /* stmt: STMT(stmt,stmt) */
		fprintf(stderr, "0x%p: line 81: stmt: STMT(stmt,stmt)\n",(void*)p);
#line 81 "minor.brg"
{ char s[20]; sprintf(s, "line %d", p->line); fprintf(yyout, pfCOMM, s); }
		break;
	case 24: /* stmt: NIL */
		fprintf(stderr, "0x%p: line 82: stmt: NIL\n",(void*)p);
#line 82 "minor.brg"

		break;
	case 25: /* stmt: RETURN(NIL) */
		fprintf(stderr, "0x%p: line 83: stmt: RETURN(NIL)\n",(void*)p);
#line 83 "minor.brg"
{ fprintf(yyout, pfLEAVE pfRET); }
		break;
	case 26: /* stmt: RETURN(expr) */
		fprintf(stderr, "0x%p: line 84: stmt: RETURN(expr)\n",(void*)p);
#line 84 "minor.brg"
{ fprintf(yyout, pfPOP pfLEAVE pfRET); }
		break;
	case 27: /* stmt: STOP */
		fprintf(stderr, "0x%p: line 85: stmt: STOP\n",(void*)p);
#line 85 "minor.brg"
{ fprintf(yyout, pfJMP, mklbl(stp[stpn-1])); }
		break;
	case 28: /* stmt: PRINT(expr) */
		fprintf(stderr, "0x%p: line 86: stmt: PRINT(expr)\n",(void*)p);
#line 86 "minor.brg"
{ fprintf(yyout, pfEXTRN pfCALL pfTRASH, U_"printi", U_"printi", pfWORD); }
		break;
	case 29: /* stmt: PRINT(str) */
		fprintf(stderr, "0x%p: line 87: stmt: PRINT(str)\n",(void*)p);
#line 87 "minor.brg"
{ fprintf(yyout, pfEXTRN pfCALL pfTRASH, U_"prints", U_"prints", pfWORD); }
		break;
	case 30: /* expr: str */
		fprintf(stderr, "0x%p: line 88: expr: str\n",(void*)p);
#line 88 "minor.brg"

		break;
	case 31: /* str: CHARS(NIL,STR) */
		fprintf(stderr, "0x%p: line 89: str: CHARS(NIL,STR)\n",(void*)p);
#line 89 "minor.brg"
{ mkstr(RIGHT_CHILD(p)->value.s); }
		break;
	case 32: /* stmt: expr */
		fprintf(stderr, "0x%p: line 90: stmt: expr\n",(void*)p);
#line 90 "minor.brg"
{ fprintf(yyout, pfTRASH, pfWORD); }
		break;
	case 33: /* stmt: FI(then,stmt) */
		fprintf(stderr, "0x%p: line 92: stmt: FI(then,stmt)\n",(void*)p);
#line 92 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place)); }
		break;
	case 34: /* then: THEN(if,NIL) */
		fprintf(stderr, "0x%p: line 93: then: THEN(if,NIL)\n",(void*)p);
#line 93 "minor.brg"

		break;
	case 35: /* if: IF(cond,stmt) */
		fprintf(stderr, "0x%p: line 94: if: IF(cond,stmt)\n",(void*)p);
#line 94 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfJMP pfLABEL, mklbl(lbl), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 36: /* cond: expr */
		fprintf(stderr, "0x%p: line 95: cond: expr\n",(void*)p);
#line 95 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfJZ, mklbl(lbl)); }
		break;
	case 37: /* stmt: FOR(until,step) */
		fprintf(stderr, "0x%p: line 96: stmt: FOR(until,step)\n",(void*)p);
#line 96 "minor.brg"
{ fprintf(yyout, pfTRASH pfJMP pfLABEL, pfWORD, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place), mklbl(LEFT_CHILD(p)->place)); stpn--; }
		break;
	case 38: /* until: UNTIL(begin,expr) */
		fprintf(stderr, "0x%p: line 97: until: UNTIL(begin,expr)\n",(void*)p);
#line 97 "minor.brg"
{ stp[stpn++] = p->place = ++lbl; fprintf(yyout, pfJNZ, mklbl(lbl)); }
		break;
	case 39: /* begin: expr */
		fprintf(stderr, "0x%p: line 98: begin: expr\n",(void*)p);
#line 98 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfTRASH pfLABEL, pfWORD, mklbl(lbl)); }
		break;
	case 40: /* step: STEP(stmt,expr) */
		fprintf(stderr, "0x%p: line 99: step: STEP(stmt,expr)\n",(void*)p);
#line 99 "minor.brg"
{ fprintf(yyout, pfTRASH, pfWORD); }
		break;
	case 41: /* lv: ID */
		fprintf(stderr, "0x%p: line 101: lv: ID\n",(void*)p);
#line 101 "minor.brg"
{ mkid(p); }
		break;
	case 42: /* expr: EQ(dup,lv) */
		fprintf(stderr, "0x%p: line 102: expr: EQ(dup,lv)\n",(void*)p);
#line 102 "minor.brg"
{ fprintf(yyout, pfSTORE); }
		break;
	case 43: /* dup: expr */
		fprintf(stderr, "0x%p: line 103: dup: expr\n",(void*)p);
#line 103 "minor.brg"
{ fprintf(yyout, pfDUP); }
		break;
	case 44: /* expr: lv */
		fprintf(stderr, "0x%p: line 104: expr: lv\n",(void*)p);
#line 104 "minor.brg"
{ fprintf(yyout, pfLOAD); }
		break;
	case 45: /* expr: CHARS(NIL,INT) */
		fprintf(stderr, "0x%p: line 106: expr: CHARS(NIL,INT)\n",(void*)p);
#line 106 "minor.brg"
{ fprintf(yyout, pfIMM, RIGHT_CHILD(p)->value.i); }
		break;
	case 46: /* expr: ID */
		fprintf(stderr, "0x%p: line 107: expr: ID\n",(void*)p);
#line 107 "minor.brg"
{ fprintf(yyout, pfCALL pfPUSH, mkfunc(p->value.s)); }
		break;
	case 47: /* expr: INPUT */
		fprintf(stderr, "0x%p: line 108: expr: INPUT\n",(void*)p);
#line 108 "minor.brg"
{ fprintf(yyout, pfEXTRN pfCALL pfPUSH, U_"readi", U_"readi"); }
		break;
	case 48: /* expr: ADDR(lv) */
		fprintf(stderr, "0x%p: line 109: expr: ADDR(lv)\n",(void*)p);
#line 109 "minor.brg"

		break;
	case 49: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%p: line 110: expr: ADD(expr,expr)\n",(void*)p);
#line 110 "minor.brg"
{ fprintf(yyout, pfADD); /*fprintf(yyout, pfEXTRN pfCALL pfTRASH pfPUSH, "_incr", "_incr", 8);*/}
		break;
	case 50: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%p: line 111: expr: SUB(expr,expr)\n",(void*)p);
#line 111 "minor.brg"
{ fprintf(yyout, pfSUB); }
		break;
	case 51: /* expr: EQUAL(expr,expr) */
		fprintf(stderr, "0x%p: line 112: expr: EQUAL(expr,expr)\n",(void*)p);
#line 112 "minor.brg"
{ fprintf(yyout, pfEQ); }
		break;
	case 52: /* expr: GT(expr,expr) */
		fprintf(stderr, "0x%p: line 113: expr: GT(expr,expr)\n",(void*)p);
#line 113 "minor.brg"
{ fprintf(yyout, pfGT); }
		break;
	case 53: /* expr: LT(expr,expr) */
		fprintf(stderr, "0x%p: line 114: expr: LT(expr,expr)\n",(void*)p);
#line 114 "minor.brg"
{ fprintf(yyout, pfLT); }
		break;
	case 54: /* expr: CALL(ID,args) */
		fprintf(stderr, "0x%p: line 115: expr: CALL(ID,args)\n",(void*)p);
#line 115 "minor.brg"
{ fprintf(yyout, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), trash * pfWORD); }
		break;
	case 55: /* args: ARG(expr,args) */
		fprintf(stderr, "0x%p: line 116: args: ARG(expr,args)\n",(void*)p);
#line 116 "minor.brg"
{ trash += 1; }
		break;
	case 56: /* args: NIL */
		fprintf(stderr, "0x%p: line 117: args: NIL\n",(void*)p);
#line 117 "minor.brg"
{ trash = 0; }
		break;
	case 57: /* expr: TPAND(expr,expr) */
		fprintf(stderr, "0x%p: line 118: expr: TPAND(expr,expr)\n",(void*)p);
#line 118 "minor.brg"
{ fprintf(yyout, pfAND);}
		break;
	case 58: /* stmt: LABEL */
		fprintf(stderr, "0x%p: line 119: stmt: LABEL\n",(void*)p);
#line 119 "minor.brg"
{fprintf(yyout, pfLABEL, p->value.s);}
		break;
	case 59: /* stmt: GOTO */
		fprintf(stderr, "0x%p: line 120: stmt: GOTO\n",(void*)p);
#line 120 "minor.brg"
{fprintf(yyout, pfJMP, p->value.s);}
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


#line 121 "minor.brg"

extern char **yynames;
extern int trace, errors, debugNode;
void evaluate(Node *p) {
	if (errors) return;
	if (trace) printNode(p, stdout, yynames);
	if (trace) IDprint(0,0);
	if (!yyselect(p) && trace) fprintf(stderr, "selection successful\n");
}

#ifndef NOTRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	if (debugNode) fprintf(stderr, "%p:%s matched %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
	if (cost >= MAX_COST && bestcost >= MAX_COST) {
		fprintf(stderr, "%p:%s NO MATCH %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
		printNode(p, stderr, yynames);
	}
}
#endif
