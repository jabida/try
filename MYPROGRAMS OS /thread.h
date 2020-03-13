#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


int main()
{

pthread_t id;
pthread_create(&thread_id,NULL,fun,NULL)
pthread_join(id,NULL);
printf("in thread");


}




