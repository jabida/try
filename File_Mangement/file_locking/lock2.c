#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd,write_ret,flock_ret;
	fd=open("abc",O_RDWR);
	printf("lock2_fd:%d\n",fd);
	if(fd<0)
	{
		perror("open fails..");
		exit(-1);
	}
	printf("open succes...\n");
        flock_ret=flock(fd, LOCK_EX|LOCK_NB);
        if(flock_ret<0)
        {
                perror("flock fails...");
                exit(-1);
        }
        printf("flock success...\n");

	getchar();
	char a[10];
	write_ret=read(fd,a,7);
	if(write_ret<0)
        {
                perror("write fails..");
                exit(-1);
        }
	write(1,a,7);
	printf("\n");
//getchar();
return 0;
}
