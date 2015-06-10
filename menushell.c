#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	char *cmd[]={"who","ls","date"};
	int i;
	while( 1 )
	{
	scanf("%d",&i);
	if(fork() == 0)
		{
		execlp(cmd[i],cmd[i],(char *)0);	
		printf("execlp failed\n");
		//exit(1);
		}	
	else
		{
		//wait((int *)0);
		printf("cf");
		}
	}
}
