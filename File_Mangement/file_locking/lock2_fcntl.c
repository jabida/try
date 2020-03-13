#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main()
{
	int fd,fcntl_ret,read_ret;
	struct flock fp;

	fd=open("xyz",O_RDONLY);
	if(fd<0)
	{
		perror("open fails...");
		exit(-1);
	}
	printf("fd:%d\n",fd);
	printf("open success...\n");
	//getchar();
	fp.l_type=F_RDLCK;
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
	char a[20];
	read_ret=read(fd,a,25);
	if(read_ret<0)
	{
		perror("read fails..");
		exit(-1);
	}
	printf("read success....\n");
	write(1,a,15);
	getchar();
}
