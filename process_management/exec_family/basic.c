#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
char * const argv[]={"ls","-l",0};
int main()
{
	int res;
	res=execve("/bin/ls",argv,NULL);
	if(res<0)
	{
		perror("exec fails...\n");
		exit(0);
	}
	else
	{	sleep(50);
		printf("exec success..\n");
	}
}
