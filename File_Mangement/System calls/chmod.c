#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd,chmod_ret;
	fd=creat("xyz",O_WRONLY);
	if(fd<0)
	{
		perror("open fails...");
		exit(-1);
	}
	else
	{
		printf("open Success...\n");
		chmod_ret=fchmod(fd,S_IRUSR|S_ISUID|S_ISGID|S_IWUSR);
		if(chmod_ret==0)
			printf("changing permissions success...");
		else
		{
			perror("chmod fails...");
			exit(-1);
		}

	}
}
