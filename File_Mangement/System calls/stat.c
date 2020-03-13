 #include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct stat s;
	int ret;
	ret=stat("abc",&s);
	if(ret<0)
	{
		perror("Stat fails...");
		exit(-1);
	}
	else
	{	printf("stat success...\n");
		printf("uid:%d   inode:%ld\n",s.st_uid,s.st_ino);
	}
}
