#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include<stdio.h>
#include<stdlib.h>
//include<unistd.h>


int main()
{

int pid,status=-1;
printf("before fork\n");

pid=fork();
//getchar();
//pid=fork();
//pid=fork();

if(pid<0)
{
	printf("error\n");
}

if(pid==0)
{
//	sleep(10);

	printf("pid=%d\n%d\n",getpid(),getppid());
	printf("child\n");
//	sleep(10);
//	return 1;       
	
}
//pid=fork();

if(pid>0)
{
//        wait(NULL);
	printf("pid=%d\n%d\n",getpid(),getppid());
	printf("parent\n");
//	wait(&status);
        printf("after waiting\n");

  /*      pid=fork();
	if(pid==0)
	{
	printf("child1\n");
	}*/

}
return 0;
}

