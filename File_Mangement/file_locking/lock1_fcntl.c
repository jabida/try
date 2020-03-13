#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main()
{
	int fd,fcntl_ret,write_ret;
	struct flock fp;

	fd=open("xyz",O_WRONLY);
	if(fd<0)
	{
		perror("open fails...");
		exit(-1);
	}
	printf("fd:%d\n",fd);
	printf("open success...\n");

	fp.l_type=F_WRLCK;
	fp.l_whence=SEEK_SET;
	fp.l_start = 0;         // starting offset is zero
	fp.l_len = 0;
	fp.l_pid=0;
	fcntl_ret=fcntl(fd,F_SETLK,&fp);
	if(fcntl_ret<0)
	{
		perror("fcntl fails..");
		exit(-1);
	}
	printf("fcntl success...\n");
	getchar();
	write_ret=write(fd,"Good Evening... everyone",25);
	if(write_ret<0)
	{
		perror("write fails..");
		exit(-1);
	}
	printf("Write success....\n");
	getchar();
}
