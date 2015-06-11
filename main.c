#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

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


void  cutCommand(char *line, char **argv)
{
     while (*line != '\0') {   
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n') 
               line++;             
     }
     *argv = '\0';
}

void execute(char **prm){
	pid_t pid;
	int status;
	if((strcmp(*prm, "exit") == 0)){ 
			return;
	}
	if((strcmp(*prm, "cd") == 0)){ 
		*prm++;
		chdir(*prm);
	}else{
		if((pid=fork()) < 0){
			printf("ERROR: FORK CHILD PROCESS FAILED! \n");
			exit(EXIT_FAILURE);
		} else if (pid == 0){
			execvp(*prm, prm);
			printf("EXECUTE COMMAND FAILED! \n");
		} else{
			while (wait(&status) != pid);
		}
	}
}

/*void execute_1(char **prm){
}*/

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
		else if (strcmp(*prm, "exit") == 0)
			exit(0);
			execute(prm);
		}	
	
	return 0;
}
