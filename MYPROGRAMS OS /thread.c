#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<signal.h>


pthread_mutex_t l;
sem_t mutex1;

int m=0;

void *fun(void *ar)
{ 

	//printf("thread1\n");

	while(1)
	{

		//pthread_mutex_lock(&l);
		//pthread_mutex_lock(&l);
		sem_wait(&mutex1);
		printf("Thread1 cs\n");

		sleep(3);
		if(m%2==0)
		{
			printf("even %d\n",m);
			m++;
		}

		//pthread_exit(NULL);
		//pthread_mutex_unlock(&l);
		//pthread_mutex_unlock(&l);
		sem_post(&mutex1);


		//sleep(5);

		//pthread_mutex_unlock(&l);

		if(m>=20)
			pthread_exit(NULL);
	}
}



void *fun1(void *ar) 
{
	//sleep(5);
	//printf("thread2\n");
	while(1)
	{

		sem_wait(&mutex1);
		printf("thread2 cs\n");
		sleep(3);
		//pthread_mutex_lock(&l);
		if(m%2!=0)
		{
			printf(" odd %d\n",m);
			m++;
		}
		//pthread_mutex_unlock(&l);
		sem_post(&mutex1);

		//sleep(5); 

		if(m>=20)
			pthread_exit(NULL);
	}

}


void *f3(void *arg)
{

	//printf("thread3\n");
	while(1)
	{
		sem_wait(&mutex1);

		printf("Thread3 cs\n");
		sleep(3);
		if(m%2==0)
		{
			printf("m:%d\n",m);
			m++;
		}

		sem_post(&mutex1);

		if(m>=20)
			pthread_exit(NULL);
	}

}



void set_sig_handler(void)
{
	struct sigaction action;
	action.sa_flags = SA_SIGINFO; 
	action.sa_sigaction = handler();
	if (sigaction(SIGRTMIN + 3, &action, NULL) == -1) 
	{ 
		perror("sigusr: sigaction");
		_exit(1);
	}

}



void handler(int signo, siginfo_t *info, void *extra) 
{
	int i;
	for(i=0;i<10;i++)
	{
		puts("signal");
		sleep(2);
	}

	mask_sig();
}



void mask_sig(void)
{
	sigset_t mask;
	sigemptyset(&mask); 
        sigaddset(&mask, SIGRTMIN+3); 
                
        pthread_sigmask(SIG_BLOCK, &mask, NULL);
        
}




int main()
{



	//sem_init(&mutex1,0,1);
	sem_init(&mutex1,0,2);

	//pthread_mutex_init(&l,NULL);
	//int i,a=8,b=9,c;
	pthread_t t1,t2,t3;
	//printf("out thread\n");
	//for(i=0;i<=10;i++)

	set_sig_handler();


	pthread_create(&t1,NULL,&fun,NULL);
	pthread_create(&t2,NULL,&fun1,NULL);
	pthread_create(&t2,NULL,&f3,NULL);


	//pthread_join(t1,NULL);
	//pthread_join(t2,NULL);
	//pthread_join(t3,NULL);


	sleep(3);
	pthread_kill(t1,SIGRTMIN+3);
	sleep(15);
	pthread_kill(t2,SIGRTMIN+3);
	pthread_kill(t3,SIGRTMIN+3);
	pthread_exit(NULL);





	//pthread_mutex_destroy(&l);

	//printf("in thread\n");

	//c=a+b;

	//printf("%d",c);

	//pthread_exit(NULL);

}
