#include "function.h"

int main(){
	char commandline[1024];
	char *cmd[7] = {"cd", "cp", "ls", "date", "who", "cat", "exit"};
	char *prm[4];
	int match;
	while(1){
		printf("Enter command: ");
		fgets(commandline,sizeof(commandline),stdin);
	
		cutCommand(commandline,prm);
		
		/*if((strcmp(*prm, "exit") == 0)){ 
			return;
		}*/
		
		match =0;
		match = checkValidCommand(prm, cmd);
		if (match == 0){
			printf("Command Not Build-in! \n");
				//continue;
		}
		
			execute(prm);
	}		
	return 0;
}
