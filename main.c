#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "myMatch.h"
#include "myError.h"

extern _Bool optionSet;

int main(int argc, char** argv){
	//getopt & parsed opt variable
	int opt;
	//options buffer
	char options[3];	
	//option buffer index
	int optionIdx=0;
	//loof index 
	int i;

	//get parameter and option check
	//if no option -> option := -1
	while((opt = getopt(argc,argv,"ilnvcw")) != -1){
		//max option count
		if(optionIdx >= 2)
			break;

		//if 'i' option. set optionSet 'true' 
		if(opt == 'i'){
			optionSet = true;
			continue;
		}

		options[optionIdx++] = (char)opt;	
	}
	
	options[optionIdx] = '\0';

	//if illegal parameter 
	if( ((!optionSet && strlen(options)==0) && argc < 3 ) 
			|| ((optionSet || strlen(options)!=0) && argc < 4) ){
		printUsage();
		exit(1);
	}

	//get option
	opt = getOption(options);

	//if no option. search pattern for all files
	if( (!optionSet && strlen(options) == 0) )
		//lots of file. show filename
		if(argc > 3)
			for(i=2; i<argc; i++)
				match(argv[1],argv[i],opt,true);
		else
			for(i=2; i<argc; i++)
				match(argv[1],argv[i],opt,false);


	//if exist option. search pattern for all files
	if( (optionSet || strlen(options) != 0) )
		if(argc > 4)
			for(i=3; i<argc; i++)
				match(argv[2],argv[i],opt,true);	
		else
			for(i=3; i<argc; i++)
				match(argv[2],argv[i],opt,false);

	return 0;
}
