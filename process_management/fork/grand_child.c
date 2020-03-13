#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid,status,pid2;
	pid=fork();
	if(pid<0)
	{
		perror("Fork fials..");
	}
	else if(pid==0)
	{
		printf("child...\n");
		printf("child id:%d\nchild ppid:%d\n",getpid(),getppid());
		pid=fork();
		if(pid==0)
		{	printf("grandchild id:%d\ngrandchild ppid:%d\n",getpid(),getppid());
			printf("grand child.....\n");
			getchar();
		}
		exit(0);
	}
	else
	{
		//printf("child id:%d\nchild ppid:%d\n",getpid(),getppid());
		getchar();
		printf("parent....\n");
		//wait(&status);
	}
}
