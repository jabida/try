#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd,lockf_ret,write_ret;
	off_t lseek_ret;
	fd=open("pqr",O_WRONLY);
	printf("fd:%d\n",fd);
	if(fd<0)
	{
		perror("open fails...");
		exit(-1);
	}
	printf("open success...\n");
	if((lseek_ret=lseek(fd,5,SEEK_SET))<0)
	{
		perror("lseek fails...\n");
		exit(-1);
	}
	printf("lseek success...\n");
	if((lockf_ret=lockf(fd,F_LOCK,15))<0)
	{
		perror("lockf fails...");
		exit(-1);
	}
	printf("lockf success...\n");
	getchar();
	if((write_ret=write(fd,"12345678910120",14))<0)
	{
		perror("write fails...");
		exit(-1);
	}
	printf("write successs...\n");
//	getchar();	
	
}

