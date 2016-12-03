#include "myMatch.h"

//false : normal  true : all character
_Bool optionSet = false; //false : normal  true : all character

//mingu
void n_parsing(int linecnt, char* line, const char* patt, char* filename, _Bool showFilename){
}

//mingu
void v_parsing(char* line, const char* patt, char* filename, _Bool showFilename){
}

//mingu
void c_parsing(int* matchcnt, char* line, const char* patt){
}

//mingu
_Bool l_parsing(char* line, const char* patt, char* filename, _Bool showFilename){
}
//hyunchang
void w_parsing(char* line, const char* patt, char* filename, _Bool showFilename){
	regex_t state;
	int status;
	//for option 'w'. save End_Offset of pattern 
	int offset = 0;
	//if pattern matched, save offset of pattern 
	regmatch_t data;
	_Bool isMatched = false;

	if(optionSet){	
		if(regcomp(&state,patt,REG_ICASE)){
			perror("pattern parsing error");
			exit(1);
		}
	}
	else{
		if(regcomp(&state, patt, 0)){
			perror("pattern parsing error");
			exit(1);
		}
	}

	while(status = regexec(&state, line+offset,1,&data,0) == 0){
		if((data.rm_so == 0) && (data.rm_eo == strlen(line)))
			isMatched = true;
		else if((data.rm_so == 0) && (line[data.rm_eo] == ' '))
			isMatched = true;
		else if((line[data.rm_so-1] == ' ')&&(data.rm_eo==strlen(line)))
			isMatched = true;
		else if((line[data.rm_so-1]==' ')&&(line[data.rm_eo]==' '))
			isMatched = true;
		offset += data.rm_eo;
	}

	if(isMatched)
		if(showFilename)
			printf("<%s>: %s\n",filename,line);
		else
			printf("%s\n",line);

	regfree(&state);
}

//mingu
_Bool lv_parsing(char* line, const char* patt){
}
//hyunchang
_Bool lw_parsing(char* line, const char* patt){
	regex_t state;
	int status;
	//for option 'w'. save End_Offset of pattern 
	int offset = 0;
	//if pattern matched, save offset of pattern 
	regmatch_t data;
	_Bool isMatched = false;

	if(optionSet){	
		if(regcomp(&state,patt,REG_ICASE)){
			perror("pattern parsing error");
			exit(1);
		}
	}
	else{
		if(regcomp(&state, patt, 0)){
			perror("pattern parsing error");
			exit(1);
		}
	}

	while(status = regexec(&state, line+offset,1,&data,0) == 0){
		if((data.rm_so == 0) && (data.rm_eo == strlen(line)))
			isMatched = true;
		else if((data.rm_so == 0) && (line[data.rm_eo] == ' '))
			isMatched = true;
		else if((line[data.rm_so-1] == ' ')&&(data.rm_eo==strlen(line)))
			isMatched = true;
		else if((line[data.rm_so-1]==' ')&&(line[data.rm_eo]==' '))
			isMatched = true;
		offset += data.rm_eo;
	}

	regfree(&state);
	return isMatched;
}
//mingu
void nv_parsing(int linecnt, char* line, const char* patt, char* filename, _Bool showFilename){
}
//hyunchang
//line number, indipendent word
void nw_parsing(char* line, const char* patt, int* linenum,char* filename, _Bool showFilename){
	regex_t state;
	int status;
	//for option 'w'. save End_Offset of pattern 
	int offset = 0;
	//if pattern matched, save offset of pattern 
	regmatch_t data;
	_Bool isMatched = false;

	if(optionSet){	
		if(regcomp(&state,patt,REG_ICASE)){
			perror("pattern parsing error");
			exit(1);
		}
	}
	else{
		if(regcomp(&state, patt, 0)){
			perror("pattern parsing error");
			exit(1);
		}
	}

	while(status = regexec(&state, line+offset,1,&data,0) == 0){
		if((data.rm_so == 0) && (data.rm_eo == strlen(line)))
			isMatched = true;
		else if((data.rm_so == 0) && (line[data.rm_eo] == ' '))
			isMatched = true;
		else if((line[data.rm_so-1] == ' ')&&(data.rm_eo==strlen(line)))
			isMatched = true;
		else if((line[data.rm_so-1]==' ')&&(line[data.rm_eo]==' '))
			isMatched = true;
		offset += data.rm_eo;
	}

	if(isMatched)
		if(showFilename)
			printf("<%s>:%d - %s\n",filename,*linenum,line);
		else
			printf("%d - %s\n",*linenum,line);

	(*linenum)++;
	regfree(&state);
}
//mingu
void vc_parsing(int* matchcnt, char* line, const char* patt){
}
//hyun chang
void cw_parsing(char* line, const char* patt, int* matchcnt){
	regex_t state;
	int status;
	//for option 'w'. save End_Offset of pattern 
	int offset = 0;
	//if pattern matched, save offset of pattern 
	regmatch_t data;
	_Bool isMatched = false;

	if(optionSet){	
		if(regcomp(&state,patt,REG_ICASE)){
			perror("pattern parsing error");
			exit(1);
		}
	}
	else{
		if(regcomp(&state, patt, 0)){
			perror("pattern parsing error");
			exit(1);
		}
	}

	while(status = regexec(&state, line+offset,1,&data,0) == 0){
		if((data.rm_so == 0) && (data.rm_eo == strlen(line)))
			isMatched = true;
		else if((data.rm_so == 0) && (line[data.rm_eo] == ' '))
			isMatched = true;
		else if((line[data.rm_so-1] == ' ')&&(data.rm_eo==strlen(line)))
			isMatched = true;
		else if((line[data.rm_so-1]==' ')&&(line[data.rm_eo]==' '))
			isMatched = true;
		offset += data.rm_eo;
	}

	if(isMatched)
		(*matchcnt)++;

	regfree(&state);
}

//hyun chang
//if return is true, print filename
void no_parsing(char* line,const char* patt,char* filename,_Bool showFilename){
	regex_t state;
	int status;

	if(optionSet){	
		if(regcomp(&state,patt,REG_ICASE)){
			perror("pattern parsing error");
			exit(1);
		}
	}
	else{
		if(regcomp(&state, patt, 0)){
			perror("pattern parsing error");
			exit(1);
		}
	}

	status = regexec(&state, line,0,NULL,0);
	if(!status)
		if(showFilename)
			printf("<%s>: %s\n",filename,line);
		else
			printf("%s\n",line);

	regfree(&state);
}



// Get Line From File AND Search String(parsing())
//	char* patt		: pattern string
//	char* filename  : filename 
//  int   option    : option
void match(char* patt, char* filename,int option,_Bool showFilename) {
	//array index of string arr(temp)
	int cur_tempIdx=0;
	//array max size of string arr(temp) 
	int maxSize = ARR_ADD_COUNT;
	//get char from file
	char c;
	//file pointer
	FILE* fp;	
	//save line
	char* temp = (char*)malloc(sizeof(char)*ARR_ADD_COUNT);
	//if option is 'c', matched line count
	int matchcnt = 0;
	//if option is 'n', for print matched line number
	int linecnt = 1;
	//is matched word?
	_Bool findword = false;

	if( (fp = fopen(filename,"r")) == NULL){
		printf("%s open error, checkout filename\n",filename);
		exit(1);
	}

	while(1){
		c = fgetc(fp);
		//if memory is full, span memory
		if( maxSize - cur_tempIdx < 3)
			spanMemory(&temp,&maxSize,ARR_ADD_COUNT);

		//save char in temp[]
		temp[cur_tempIdx++] = c;

		//check line's end point
		if(c == '\n' || c == EOF){
			temp[cur_tempIdx-1] = '\0';
			
			//if line is empty (if EOF)
			if(strlen(temp) == NULL){
				if(showFilename){
					if(option == VC)
						printf("<%s>: %d\n",filename, matchcnt);
					if(option == CW )
						printf("<%s>: %d\n",filename, matchcnt);
					if(option == C)
						printf("<%s>: %d\n", filename, matchcnt);
				}
				else{
					if(option == VC)
						printf("%d\n",matchcnt);
					if(option == CW)
						printf("%d\n",matchcnt);
					if(option == C)
						printf("%d\n",matchcnt);
				}
				break;
			}

			//search pattern. parsing General Expression
			switch(option){
				case NO:
					no_parsing(temp,patt,filename,showFilename);
					break;
				case L:
					if(findword = l_parsing(temp, patt, filename, showFilename))
						printf("%s\n", filename);
					break;
				case N:
					n_parsing(linecnt, temp, patt, filename, showFilename);
					linecnt++;
					break;
				case V:
					v_parsing(temp, patt, filename, showFilename);
					break;
				case C:
					c_parsing(&matchcnt, temp, patt);
					break;
				case W:
					w_parsing(temp,patt,filename,showFilename);
					break;
				case LV:
					if(lv_parsing(temp,patt)){
						printf("%s\n",filename);
						findword = true;
					}
					break;
				case LW:
					if(lw_parsing(temp,patt)){
						printf("%s\n",filename);
						findword = true;
					}
					break;
				case NV:
					nv_parsing(linecnt, temp, patt, filename, showFilename);
					linecnt++;
					break;
				case NW:
					nw_parsing(temp,patt,&linecnt,filename,showFilename);
					break;
				case VC:
					vc_parsing(&matchcnt, temp, patt);
					break;
				case CW:
					cw_parsing(temp,patt,&matchcnt);
					break;
			}

			if(findword || c == EOF)
				break;

			//init variance
			cur_tempIdx = 0;
			//init spaned memory
			initMemory(&temp,&maxSize,ARR_ADD_COUNT);
		}
	}

	free(temp);
	fclose(fp);
}

//get option
int getOption(char* optList){
	int optType;
	int collectCount = 0;

	//if no option
	if(strlen(optList) == 0)	optType = NO;	

	//if one option
	if(strlen(optList) == 1){
		if(optList[0] == 'l')	optType = L;
		if(optList[0] == 'n')	optType = N;
		if(optList[0] == 'v')	optType = V;
		if(optList[0] == 'c')	optType = C;
		if(optList[0] == 'w')	optType = W;
	}

	//if two option
	if(strlen(optList) == 2){
		//if 'lv' 
		if((optList[0] == 'l' && optList[1] == 'v') 
				|| (optList[0] == 'v' && optList[1] == 'l'))
			optType = LV;

		//if 'lw'
		if((optList[0] == 'l' && optList[1] == 'w') 
				|| (optList[0] == 'w' && optList[1] == 'l'))
			optType = LW;

		//if 'nv'
		if((optList[0] == 'n' && optList[1] == 'v') 
				|| (optList[0] == 'v' && optList[1] == 'n'))
			optType = NV;

		//if 'nw'
		if((optList[0] == 'n' && optList[1] == 'w') 
				|| (optList[0] == 'w' && optList[1] == 'n'))
			optType = NW;

		//if 'vc'
		if((optList[0] == 'v' && optList[1] == 'c') 
				|| (optList[0] == 'c' && optList[1] == 'v'))
			optType = VC;

		//if 'cw'
		if((optList[0] == 'c' && optList[1] == 'w') 
				|| (optList[0] == 'w' && optList[1] == 'c'))
			optType = CW;
	}


	return optType;
}
