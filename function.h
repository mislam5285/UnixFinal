#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>
int checkValidCommand(char **command, char *cmd[]);
void  cutCommand(char *line, char **argv);
void execute(char **prm);
