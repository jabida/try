#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	char s[11];
	int fd1,fd2;
	fd_set rfds,wfds;
	struct timeval tv;
        int retval,a;
	if((fd1=open("abc",O_RDONLY))<0)
	{
		perror("open fails..");
		return -1;
	}
	if((fd2=open("xyz",O_WRONLY))<0)
        {
                perror("open fails..");
                return -1;
        }

while(1)
{	sleep(2);
	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	FD_SET(0, &rfds);
	FD_SET(1, &wfds);
	FD_SET(fd1,&rfds);
	FD_SET(fd2,&wfds);
	tv.tv_sec = 5;
        tv.tv_usec = 0;
//while(1)
//{
	if((retval=select(6,&rfds,&wfds,NULL,&tv))<0)
	{
		perror("select fails..");
		return -1;
	}
//	printf("select successs...\n");
//	while(1)
//	{
	/*read(0,&a,4);
	if(FD_ISSET(0,&rfds))
	{
		printf("fd=0::%d\n",a);
	}*/
	if(FD_ISSET(1,&wfds))
        {
                printf("fd=1::Hellooo...\n");
        }
	read(fd1,s,10);
	write(fd2,s,10);
	if(FD_ISSET(3,&rfds))
        {
                printf("fd=3::%s\n",s);
        }
	if(FD_ISSET(4,&wfds))
        {
                printf("fd=4__written to file\n");
        }

}
return 0;
}

