#include <stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char * const argv[]={"ls","-l",0};
int main()
{
	int pid,status;
	pid=fork();
	if(pid<0)
	{
		perror("fork fails..\n");
		exit(0);
	}
	else if(pid==0)
	{
		int res;
		printf("Child process....\n");
		printf("pid:%d\tppid:%d\n",getpid(),getppid());
		res=execve("/bin/ls",argv,NULL);
		if(res<0)
		{
			perror("exec fails...\n");
			exit(0);
		}
		else
		{
			printf("exec_pid:%d\texec_ppid:%d\n",getpid(),getppid());
			printf("Completed....\n");
		}
		return 0;

	}
	else
	{
		wait(&status);
		printf("pid:%d\tppid:%d\n",getpid(),getppid());
		getchar();
		printf("parent....\n");
	}
}
