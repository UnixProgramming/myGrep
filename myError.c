#include "myError.h"

void printUsage(){
			printf("usage: [option] *[pattern] *[filename]...\n* : essential\n... : dozen\n\n");
			printf("options:\n");
			printf("  -i: check big,small character\n");
			printf("  -l: if pattern is collect, print Filename\n");
			printf("  -n: print line with LineNumber\n");
			printf("  -v: if pattern is not collect, print line\n");
			printf("  -c: print lines number\n");
			printf("  -w: if be collected pattern is 'WORD', print line\n\n");
			printf("usable Duplication Option:\n");
			printf("  -i: usable at all option\n");
			printf("  -lv, -lw, -nv, -nw, -vc, -cw\n");
}
