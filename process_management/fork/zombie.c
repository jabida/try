#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid,status;
	pid=fork();
	if(pid<0)
	{
		perror("Fork is not successfull");
	}
	else if(pid>0)
	{
		//sleep(100);
		printf("Parent...\n");
	//	wait(&status);
		getchar();
	}
	else
	{
		//sleep(100);
		printf("Child....\n");
		exit(0);
		return 0;
	}
}
