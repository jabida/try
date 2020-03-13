#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int main()
{
	int fd,write_ret,chmod_ret;
	fd=creat("./abc",O_WRONLY);
		printf("fd:%d\n",fd);
	if(fd<0)
	{	perror("opening a file fails....");
		exit(-1);
	}

	else
	{
		chmod_ret=fchmod(fd,S_ISUID|S_IWUSR|S_IRUSR|S_IROTH|S_IWOTH|S_IXOTH);
		if(chmod_ret==0)
		{
		write_ret=write(fd,"Hello Mirafra",15);
		if(write_ret<0)
		{
			perror("Writing into a file fails...:");
				exit(-1);
		}
		else
			printf("Writing success...\n");
		}
		else
		{
			perror("changing permission fails..:");
			exit(-1);
		}
		
	}
}
