#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ret;
	ret=access("abc",R_OK);
	if(ret<0)
	{
		perror("file not exists..");
		exit(-1);
	}
	else
		printf("file exists...\n");
}
