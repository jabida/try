#include <sys/types.h>
#include <dirent.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	DIR *dir;
	struct dirent *dent;
	dir=opendir("/home/sys2/manasa/LSYS/");
	if(dir==NULL)
	{
		perror("opendir fails..");
		exit(-1);
	}
	else
	{
		dent=readdir(dir);
		if(dent==NULL)
		{
			perror("readdir fails...");
			exit(-1);
		}
		else
		{
			printf("readdir success...\n");
			printf("%s\n",dent->d_name);
		}
	}
}
