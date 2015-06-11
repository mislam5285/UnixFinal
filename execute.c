#include "function.h"
void execute(char **prm){
	pid_t pid;
	int status;
	
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
