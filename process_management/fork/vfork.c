#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid;
	printf("before vfork..\n");
	pid=vfork();
	getchar();
	printf("after fork...\n");
	exit(0);
}

