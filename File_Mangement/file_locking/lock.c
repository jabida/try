#include <sys/file.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int flock_ret,fd,chmod_ret,ret;
	fd=open("abc",O_RDWR);
	printf("lock_fd:%d\n",fd);
	if(fd<0)
	{
		perror("open fails...");
		exit(-1);
	}
	printf("open success..\n");

	flock_ret=flock(fd, LOCK_EX|LOCK_NB );
        if(flock_ret<0)
        {
                perror("flock fails...");
                exit(-1);
        }
       	printf("flock success...\n");
getchar();
	ret=write(fd,"ferwerwrwr",10);
	if(ret<0)
	{
		perror("write..");
		exit(-1);
	}
printf("write success\n");

	getchar();

}

