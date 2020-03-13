#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int pid,status;
	pid=fork();
	if(pid<0)
		perror("Fork is not created");
	else if(pid==0)
	{

		//sleep(100);
		printf("child process....\n");
		getchar();
		printf("Hello..\n");
		exit(0);
	}
	else
	{
		//getchar();
		printf("parent process....\n");
		wait(&status);

	}
}
