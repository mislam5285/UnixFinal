#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ctype.h>
#include<string.h>

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

void execute(char **argv){
	pid_t pid;
	int status;
	if((pid=fork()) < 0){
		printf("ERROR: FORK CHILD PROCESS FAILED! \n");
		exit(EXIT_FAILURE);
	} else if (pid == 0){
		execvp(argv[0], argv);
		printf("EXECUTE COMMAND FAILED! \n");
	} else{
		while (wait(&status) != pid);
	}
}

int main(){
	char commandline[1024];
	char *cmd[7] = {"cd", "cp", "ls", "date", "who", "cat", "exit"};
	char *argv[3];
	int match;
	while(1){
		printf("Enter command: ");
		scanf("%s", commandline);
	
		cutCommand(commandline,argv);
		
		match =0;
		match = checkValidCommand(argv, cmd);
		if (match == 1){
			printf("\n");
		} else{
			printf("Invalid Command! \n");
			continue;
		}
		
		execute(argv);
			
	}
	
	return 0;
}
