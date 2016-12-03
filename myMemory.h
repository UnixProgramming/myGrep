#ifndef _MYMEMORY_H_
#define _MYMEMORY_H_

#include <stdio.h>

#define ARR_ADD_COUNT 20

//if memory almost full, span memory
void spanMemory(char**, int*, int );

//init memory when Line be changed
void initMemory(char**,int*, int);

#endif
