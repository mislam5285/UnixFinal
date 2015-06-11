#include "function.h"
int checkValidCommand(char **command, char *cmd[]){
	int i;
	int match =0;
	for (i = 0; i < 7; i++){
		if(*cmd[i] == **command){ 
			match =1;
			break;
		}
	}
	
	return match;	
}

