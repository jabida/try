#include<stdio.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>

#define  bufsz 4096
#define shm_key 0x2345

struct shmseg
{
int cnt,finish;
char buf[bufsz];
};



int fillup(char *bufptr,int size)
{
static char ch='A';

int filled;
//memset(a,size-1);
//a[size-1]='\0';
if(ch>=122)
ch=65;
if((ch>=65)&&(ch<=122))
{
if((ch>=91)&&(ch<=96))
{
ch=65;
}

}

filled=strlen(bufptr);


ch++;
return filled;

}


int main()
{

struct shmseg *shmp;

int shmid,space,i;
char *bufptr;

shmid=shmget(shm_key,sizeof(struct shmseg),0622|IPC_CREAT);//create mem

printf("%d\n",shmid);


shmp=shmat(shmid,NULL,0);// to get pointer to shared mem address 

printf("%d\n",shmp);


 if (shmid == -1) {
      perror("Shared memory");
      return 1;
   }
   
   // Attach to the segment to get a pointer to it.
   shmp = shmat(shmid, NULL, 0);
   if (shmp == (void *) -1) {
      perror("Shared memory attach");
      return 1;
   }
   







//transfer dato to sh mem
bufptr =shmp->buf;
space=bufsz;
for(i=0;i<=5;i++)
{
shmp->cnt=fillup(bufptr,space);
shmp->finish=0;
printf("write shared mem %d",shmp->cnt);
bufptr =shmp->buf;
space=bufsz;

printf("%d",i);




}


}
