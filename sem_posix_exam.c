#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>
sem_t sem;
void* thread_t1(void* arg){
	int tidx = *(int *)arg;
	sem_wait(&sem);
	printf("[%d] Start...\n",tidx);
	/* Critical section */
	sleep(3);
	printf("[%d] End!\n\n",tidx);
	sem_post(&sem);
}
void* thread_t2(void* arg){
	int tidx=*(int *)arg;
	int ret;
try:
	ret=sem_trywait(&sem);
	if(ret==-1){
		if(errno==EAGAIN){
			printf("[%d] retry get semaphore...\n",tidx);
			sleep(1);
			goto try;
		}
		perror("sem_trywait");
		exit(1);
	}else if(ret==0){
		printf("[%d] Start...\n",tidx);
		/* Critical Section */
		sleep(3);
		printf("[%d] End\n\n", tidx);
		sem_post(&sem);
	}
}

int main(){
	int ret;
	pthread_t t1,t2,t3;
	int tidx[]={0,1,2};
	if(sem_init(&sem,0,1)==-1){
		perror("sem_init");
		exit(1);
	}
	ret=pthread_create(&t1,NULL,thread_t1,(void *)&tidx[0]);
	if(ret != 0){
		fprintf(stderr,"pthread_create error:%m");
		exit(1);
	}
	ret=pthread_create(&t2,NULL,thread_t1,(void *)&tidx[1]);
	if(ret!=0){
		fprintf(stderr,"pthread_create error:%m");
		exit(1);
	}
	ret=pthread_create(&t3,NULL,thread_t2,(void *)&tidx[2]);
	if(ret != 0){
		fprintf(stderr,"pthresd_create error:%m");
		exit(1);
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	sem_destroy(&sem);
	return 0;
}

