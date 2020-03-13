// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping 
// when child process exits. 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	// Fork returns process id 
	// in parent process 
	int child_pid = fork(); 

	// Parent process 
	if (child_pid > 0)
{

	printf("jabida"); 
		sleep(50);
         wait(); 
}
	// Child process


	else
{
        printf("shaik");
		
	exit(0); 
}

	return 0; 
} 

