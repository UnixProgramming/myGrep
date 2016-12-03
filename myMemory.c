#include "myMemory.h"

//if memory is full. span memory
void spanMemory(char **arr, int* maxSize, int addSize ){
	int exSize = *maxSize + addSize;
	int i;
	char* temp = (char*)malloc(sizeof(char)*(exSize));

	for(i=0; i<(*maxSize); i++)
		temp[i] = (*arr)[i];	
	free(*arr);
	*arr = temp;
	*maxSize = exSize;

}

//init memory when Line be changed
void initMemory(char **arr,int* maxSize, int initSize){
	free(*arr);
	*arr = (char*)malloc(sizeof(char)*initSize);
	*maxSize = 0;
}
