#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	int pid,status;
	pid=fork();
	if(pid<0)
	{
		perror("Fork fails");
	}
	else if(pid>0)
	{
		printf("Parent....\n");
		//getchar();
		sleep(100);
		//wait(&status);
	}
	else
	{
		printf("child....\n");
		//getchar();
		exit(0);
		return 0;
	}
}
