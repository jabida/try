#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <fcntl.h>
int main (int argc, char * * argv)

{

  struct flock fp;
  int ret,write_ret,read_ret;

  int fd1 = open ("./tmp2.txt", O_RDWR);

  int fd2 = open ("./tmp2.txt", O_RDWR);

  printf ("Fd1:%d, fd2:%d\n", fd1, fd2);

	fp.l_type=F_WRLCK;
	fp.l_whence=SEEK_SET;
	fp.l_start=0;
	fp.l_len=0;
	fp.l_pid=0;

	if(( ret = fcntl (fd1,F_SETLKW,&fp))<0)
	{
		perror("fcntl fails...");
		exit(-1);
	}

  printf ("lock success..\n");
	getchar();
	if((write_ret=write(fd1,"today Friday",12))<0)
	{
		perror("write fails..");
		exit(-1);
	}
	printf("write success...\n");
	//close(fd1);
	if((ret =  fcntl (fd2,F_SETLKW,&fp))<0)
	{
		perror("fcntl fails...");
		exit(-1);
	}
  printf ("lock2 success...\n");
	getchar();
	char a[12];
	if((read_ret=read(fd2,a,12))<0)
        {
                perror("read fails..");
                exit(-1);
        }
        printf("read success...\n");
	printf("\n%s\n",a);

  return 0;
}

