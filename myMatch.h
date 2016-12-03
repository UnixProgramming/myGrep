#ifndef _MYMATCH_H_
#define _MYMATCH_H_

#include <regex.h>
#include <stdbool.h>
#include "myMemory.h"


//options list
enum{
	NO, //normal option(no option)
	L,	// l     option
	N,  // n	 option
	V,  // v	 option
	C,  // c	 option
	W,  // w	 option
	LV, // lv	 option
	LW, // lw	 option
	NV, // nv	 option
	NW, // nw	 option
	VC, // vc	 option
	CW  // cw	 option
};

//matching 
void match(char*, char*,int,_Bool);
//get option
int getOption(char*);

//set regcompile
void setRegexComp(regex_t* , const char*);

//string parsing 
//ihc
void no_parsing(char*, const char*, char*, _Bool);
//mingu
_Bool l_parsing(char*, const char*, char*, _Bool);
//mingu
void n_parsing(int, char*, const char*, char*, _Bool);
//mingu
void v_parsing(char*,const char*,char*,_Bool);
//mingu
void c_parsing(int*, char*, const char*);
//ihc
void w_parsing(char*, const char*, char*, _Bool);
//mingu
_Bool lv_parsing(char*, const char*);
//ihc
_Bool lw_parsing(char*, const char*);
//mingu
void nv_parsing(int, char*, const char*, char*, _Bool);
//ihc
void nw_parsing(char*, const char*, int*, char*, _Bool);
//mingu
void vc_parsing(int*, char*, const char*);
//ihc
void cw_parsing(char*, const char*, int*);

#endif
