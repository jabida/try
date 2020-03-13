#include<stdio.h>
#include<unistd.h>

int main() 
{ 
    int pid;
    int a,b;
    pid = fork(); 
    if (pid == 0) 
    { 
        printf("\nParent Process id "); 
        a=getpid() ;
        printf("%d",a);
 
        printf("\nChild Process with parent id "); 
        b=getppid();
	printf("%d",b); 
    } 
    return 0; 
} 
