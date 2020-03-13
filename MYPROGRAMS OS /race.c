#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t m;

int count=0;

/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
	while (1){
		//pthread_mutex_lock(&m);
		if(count%2==0){
		printf("threadFunc says even:Count=%d\n",count);
		count++;
		}
		//pthread_mutex_unlock(&m);
		//sleep(4);
		if(count>=20)
			pthread_exit(NULL);
		}
	return NULL;
}

void *threadFunc1(void *arg)
{
	while (1){
		//pthread_mutex_lock(&m);
		if(count%2!=0){
		printf("threadFunc says odd:Count=%d\n",count);
		count++;
		}
		//pthread_mutex_unlock(&m);
		//sleep(4);
		if(count>=20)
			pthread_exit(NULL);
		}
	return NULL;
}

int main(void)
{
	pthread_t tid,tid2;	// this is our thread identifier
	pthread_mutex_init(&m,NULL);
	int i = 0;

	/* Create worker thread */
	pthread_create(&tid,NULL,threadFunc,NULL);
	pthread_create(&tid2,NULL,threadFunc1,NULL);

	/* wait for our thread to finish before continuing */
	pthread_join(tid, NULL /* void ** return value could go here */);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&m);
	return 0;
}
