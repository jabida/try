#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid;
	write(1,"before vfork..\n",16);
	pid=vfork();
	//getchar();
	write(1,"after fork...\n",15);
	exit(0);
}

