#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int main() {
   pid_t pid;
   printf("Testing SIGSTOP\n");
   pid=getpid();
   printf("open another terminal");
   printf("kill -SIGCONT %d or kill -CONT %d or kill -18 %d\n",pid,pid,pid);
   raise(SIGSTOP);
   printf("received signal SIGCONT\n");
   return 0;
}
