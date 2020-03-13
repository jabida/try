#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t m;

struct student{
	int id;
	char *name;
};


/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
	struct student *str;
	int i = 0;

	str=(struct student*)arg;
	pthread_mutex_lock(&m);
	while(i < 10 )
	{
		usleep(5);
		printf("threadFunc says:Id=%d,name=%s\n",str->id,str->name);
		++i;
	}
	pthread_mutex_unlock(&m);
	return NULL;
}

int main(void)
{
	pthread_t tid,tid2;	// this is our thread identifier
	pthread_mutex_init(&m,NULL);
	int i = 0;
	struct student s,s1;
	s.id=7;
	s.name="Name_name";
	
	s1.id=9;
	s1.name="......";

	/* Create worker thread */
	pthread_create(&tid,NULL,threadFunc,&s);
	pthread_create(&tid2,NULL,threadFunc,&s1);
	pthread_join(tid2,NULL);
	while(i < 10 )
	{	
		printf("main() is running...\n");
		usleep(1);
		++i;
	}
	/* wait for our thread to finish before continuing */
	pthread_join(tid, NULL /* void ** return value could go here */);

	pthread_mutex_destroy(&m);
	return 0;
}
