#include<stdio.h>
#include<unistd.h>


int main()
{
int pipefd1[2],pipefd2[2];
char msg[2] [20]={"hi","how r u"};
char recv[20];
int c,pid,d;
c=pipe(pipefd1);

if(c==1)
{
printf("pipe1 is create");
}


d=pipe(pipefd2);
if(d==1)
{

printf("pipi2 is create");
}



pid=fork();
if(pid>0)
{
close (pipefd1[0]);
close (pipefd2[1]);


write(pipefd1[1],msg[0],sizeof(msg[0]));
printf("write  from pipe 1:%s\n",msg[0]);
read(pipefd2[0],msg[0],sizeof(msg[1]));
printf("read from pipe 2:%s\n",msg[1]);



//write(pipefd[1],msg[1],sizeof(msg[1]));
//printf("write 1st values:%s\n",msg[1]);
}

else
{

close (pipefd1[1]);
close (pipefd2[0]);



read(pipefd1[0],msg[0],sizeof(msg[0]));
printf("read from pipe 1:%s\n",msg[0]);
write(pipefd2[1],msg[1],sizeof(msg[1]));
printf("write from pipe1:%s\n",msg[1]);




/*read(pipefd[0],recv,sizeof(recv));
printf("read 1st  value:%s\n",recv);
read(pipefd[0],recv,sizeof(recv));
printf("read 2 value:%s\n",recv);*/
}


}
