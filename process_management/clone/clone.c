#define _GNU_SOURCE
#include <sched.h>
#include<stdio.h>
#include<stdlib.h>
//nclude<stdin.h>
int fun(void * argv)
{
	int x,i;
	printf("hello...\n");
	//fflush(NULL);
	char * a;
	a=((char *)argv);
	printf("%s\n",a);
	x=atoi(a);
	printf("x:%d\n",x);
	fflush(NULL);
	printf("r%d\n",x+5);

}
int main()
{
	int pid;
	void * child_stack=malloc(1024);
	//printf("%s",argv[1]);
	pid=clone(fun,child_stack,CLONE_FILES,"12");
	if(pid<0)
	{
		perror("clone fails...");
		exit(-1);
	
	}
	else
	{
		printf("completed...\n");
	}

}

