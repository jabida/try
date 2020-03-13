#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t child_pid;
	child_pid=fork();
	if(child_pid<0)
	{
		perror("Fork fails");
		
	}
	if(child_pid==0)
	{
		printf("It is child process");
		printf("\npid:%d\nppid:%d\n",getpid(),getppid());
		//getchar();
	}
	else
	{
		printf("It is in parent process");
		printf("pid:%d\nppid:%d\n",getpid(),getppid());
		getchar();
	}
}
