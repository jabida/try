#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>

char * const ls_argv[]={"ls","-l",0};
int main()
{
	int pid,status;
	pid=vfork();
	if(pid<0)
	{
		perror("vfork fails...\n");
		exit(0);
	}
	else if(pid==0)
	{
		printf("child...\n");
		/*int res;
		res=execve("/bin/ls",ls_argv,NULL);
		if(res<0)
		{
			perror("exec fails....\n");
			exit(0);
		}
		else
			printf("completed...\n");
		return 0;*/
	}
	else
	{
		//wait(&status);
		printf("parent....\n");
	}

}
