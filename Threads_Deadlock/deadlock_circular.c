#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t m,n;

int count=0;

/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
	while (1){
		pthread_mutex_lock(&m);
		sleep(5);
		pthread_mutex_lock(&n);
		if(count%2==0){
		printf("threadFunc says even:Count=%d\n",count);
		count++;
		}
		pthread_mutex_unlock(&m);
		pthread_mutex_unlock(&n);
		if(count>=20)
			pthread_exit(NULL);
		}
	return NULL;
}

/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc1(void *arg)
{
	while (1){
		pthread_mutex_lock(&n);
		sleep(5);
		pthread_mutex_lock(&m);
		if(count%2!=0){
		printf("threadFunc says odd:Count=%d\n",count);
		count++;
		}
		sleep(4);
		pthread_mutex_unlock(&m);
		pthread_mutex_unlock(&n);
		if(count>=20)
			pthread_exit(NULL);
		}
	return NULL;
}

int main(void)
{
	//Create lock
	pthread_mutex_init(&m,NULL);
	pthread_mutex_init(&n,NULL);

	//local variables
	int i = 0;
	pthread_t tid,tid2;	// this is our thread identifier

	/* Create worker thread */
	pthread_create(&tid2,NULL,threadFunc1,NULL);
	pthread_create(&tid,NULL,threadFunc,NULL);
	
	/* wait for our thread to finish before continuing */
	pthread_join(tid, NULL );/* void ** return value could go here */
	pthread_join(tid2,NULL);

	//Destroy lock
	pthread_mutex_destroy(&m);
	pthread_mutex_destroy(&n);

	return 0;
}
