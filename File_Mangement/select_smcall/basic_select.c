#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio_ext.h>
       int
       main(void)
       {
           fd_set rfds;
           struct timeval tv;
           int retval,fd1,a;
		char s[10];
	if((fd1=open("abc",O_RDONLY))<0)
	{
		perror("open fails...");
		return -1;
	}

           /* Watch stdin (fd 0) to see when it has input. */
        while(1)
	{

	   if(fflush(stdout)==0)
		printf("cleared..");
	   FD_ZERO(&rfds);
           FD_SET(0, &rfds);
	   FD_SET(fd1,&rfds);

           /* Wait up to five seconds. */

	   tv.tv_sec = 5;
           tv.tv_usec = 0;
           retval = select(1, &rfds, NULL, NULL, &tv);
           /* Don't rely on the value of tv now! */
		
         

           if (retval == -1)
            {
		perror("select()");
		return -1;
	    }
	if(FD_ISSET(0,&rfds))
	{
		printf("data available..\n");

	}
	else
		printf("data is not available...\n");
	
	/*	if((read(fd1,s,10))<0)
			perror("read fails..");

	if(FD_ISSET(fd1,&rfds))
		printf("data:%s\n",s);
	//else
	//	printf("no data in file...\n");*/
		

       }
}


