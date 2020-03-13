#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>

int main (int argc, char * * argv)

{

  int ret,write_ret,read_ret;

  int fd1 = open ("./tmp.txt", O_RDWR);

  int fd2 = open ("./tmp.txt", O_RDWR);

  printf ("Fd1:%d, fd2:%d\n", fd1, fd2);

	
  ret = flock (fd1,LOCK_EX);

  printf ("Get Lock1, ret:%d\n", ret);
	getchar();
	if((write_ret=write(fd1,"morning",7))<0)
	{
		perror("write fails..");
		exit(-1);
	}
	printf("write success...\n");
	close(fd1);
  ret = flock (fd2,LOCK_EX);

  printf ("Get Lock2, ret:%d\n", ret);
	getchar();
	char a[7];
	if((read_ret=read(fd2,a,7))<0)
        {
                perror("read fails..");
                exit(-1);
        }
        printf("read success...\n");
	printf("\n%s\n",a);

  return 0;
}

