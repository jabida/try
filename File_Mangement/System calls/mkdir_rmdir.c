#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int mkdir_ret,rmdir_ret;
	mkdir_ret=mkdir("manasa",S_IRWXU);
	if(mkdir_ret<0)
	{
		perror("mkdir fails..");
		exit(-1);
	}
	else
		printf("directory is successfully created..\n");
	rmdir_ret=rmdir("manasa");
	if(rmdir_ret<0)
	{
		perror("rmdir fails...");
		exit(-1);
	}
	else
		printf("directory is removed successfully....\n");
}
