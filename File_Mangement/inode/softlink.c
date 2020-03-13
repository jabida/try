#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ret_symlink,ret_link;
	ret_symlink=symlink("ABC","abc_shortcut");
	if(ret_symlink)
	{
		perror("symlink fails...\n");
		exit(-1);
	}
	else
		printf("symlink success...\n");

	ret_link=link("XYZ","xyz_hardlink");
	if(ret_link)
        	{
                	perror("link fails...\n");
	                exit(-1);
        	}
        	else
                	printf("link success...\n");
}
