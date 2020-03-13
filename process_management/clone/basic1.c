#define _GNU_SOURCE
#include <sched.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>

	char *child_stack;
	char *stack ;
	int x,i=1;
int fun(void *);
int main(int argc,char *argv[])
{
	int a;

	int  pid_ch;
	
	child_stack = (char*)malloc((1024*1024));
	stack = child_stack  + (1024*1024) -1 ;
	
	if(!child_stack)
	{
		printf("memory not allocated...\n");
		exit(1);
	}

	a=atoi(argv[1]);
	pid_ch=clone(fun,stack,SIGCHLD,&a);
	if(pid_ch == -1)
	{
		perror("clone fails....");
		exit(1);
	}
	printf("Done\n");
	//wait(NULL);
	
	
return 0;
}

int fun(void *a)
{
	 x = *(int*)a;
	printf("%d\n",x);
	//printf("%s",(char*)a);
	for(;i<11;i++)
	{
		printf("%d * %d = %d\n",x,i,x*i);
	}
	return 0;
}
