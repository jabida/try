#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t m;

int count=0, count1=0;


/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
	char s=*((char *)arg);
	while (1){
		if(s=='a')
		{
			pthread_mutex_lock(&m);
		printf("threadFunc says inc:Count=%d\n",count);
		count++;
			pthread_mutex_unlock(&m);
		sleep(2);
		}
		if(s=='b')
		{
			pthread_mutex_lock(&m);
		printf("threadFunc says dec:Count1=%d\n",count1);
		count1++;
			pthread_mutex_unlock(&m);
		sleep(4);
		}
	}
	return NULL;
}

int main(void)
{
	pthread_t tid,tid2;	// this is our thread identifier
	pthread_mutex_init(&m,NULL);
	int i = 0;
	char a,b;
	a='a',b='b';
	/* Create worker thread */
	pthread_create(&tid,NULL,threadFunc,(void*)&a);
	pthread_create(&tid2,NULL,threadFunc,(void*)&b);

	while(i < 10)
	{	
		printf("main() is running...\n");
		sleep(1);
		++i;
	}
	/* wait for our thread to finish before continuing */
	pthread_join(tid, NULL /* void ** return value could go here */);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&m);
	return 0;
}
