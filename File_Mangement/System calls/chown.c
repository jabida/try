#include <unistd.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{

	int ret;
	struct  group *sg;
	struct passwd *sp;
	sg=getgrnam("games");
	sp=getpwnam("root");
	if(sg==NULL)
	{
		perror("getgrnam fails..");
		exit(-1);
	}
	if(sp==NULL)
	{
		perror("getprnam fails...");
		exit(-1);
	}
	ret=chown("xyz",sg->gr_gid,sp->pw_uid);
	if(ret<0)
	{
		perror("chown fails...");
		exit(-1);
	}
	else
		printf("chown success..");
}
