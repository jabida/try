#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd,lockf_ret,read_ret,i;
	off_t lseek_ret;
	fd=open("pqr",O_RDWR);
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
	char a[25];
	if((read_ret=read(fd,a,14))<0)
	{
		perror("read fails...");
		exit(-1);
	}
	printf("read successs...\n");
	for(i=0;i<14;i++)
	printf("%c",a[i]);
//	getchar();	
	
}

