#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ctype.h>
#include<string.h>

int checkValidCommand(char *command, char *cmd[]){
	int i;
	int match =0;
	for (i = 0; i < 6; i++){
		if(*cmd[i] == *command){ 
			match =1;
			break;
		}
	}
	
	return match;	
}

void cutCommand(char *commandline, char **argv){
	while (*commandline != '\0'){
		while (*commandline == ' ' || *commandline == '\t' || *commandline == '\n'){
			*commandline++ = '\0';
		}
		
		*argv++ = commandline;
		
		while (*commandline != ' ' && *commandline != '\t' && *commandline != '\n' && *commandline != '\0'){
			commandline++;
		}
	}
	
	*argv = '\0';
}

int main(){
	char commandline[1024];
	char *cmd[7] = {"cd", "cp", "ls", "date", "who", "cat", "exit"};
	char *argv[3];
	int match =0;
	while(1){
		printf("Enter command: ");
		scanf("%s", commandline);
	
		cutCommand(commandline,argv);
		
		match = checkValidCommand(argv, cmd);
		if (match == 1){
			printf("Valid Command! \n");
		} else{
			printf("Invalid Command! \n");
			break;
		}
			
	}
	
	return 0;
}
