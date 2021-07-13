#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
struct sembuf p={0,-1,SEM_UNDO};
struct sembuf v={0,+1,SEM_UNDO};
#define SEM_P(ID)({\
		if(semop(ID,&p,1)<0){\
		perror("semop p");\
		exit(1);\
		}\
		})
#define SEM_V(ID)({\
		if(semop(ID,&v,1)<0){\
		perror("semop v");\
		exit(1);\
		}\
		})

int sem_use;
int semid;
char shared_buf[]="Hello, World!\n";
int shared_index=0;

void *print_one(void *arg){
int tidx = *(int *)arg;
bool b=true;
char c;
while(b){
if(sem_use) SEM_P(semid);
if(shared_index>=strlen(shared_buf)){
b=false;
}else{
if(tidx)
	c=toupper(shared_buf[shared_index++]);
else
	c=tolower(shared_buf[shared_index++]);
sleep(rand()%2);
putchar(c);
fflush(stdout);
}
if(sem_use)SEM_V(semid);
}
pthread_exit((void *)0);
}

int main(int argc, char *argv[]){
	key_t key;
	union semun u;
	int pid;
	pthread_t thread_t;
	int i,ret;
	int tidx[2]={0,1};
	if(argc<2){
		printf("Uasge:%s[0(OFF)/1(ON)]\n",argv[0]);
		exit(1);
	}
	sem_use=atoi(argv[1]);
	printf("%d\n",sem_use);
	key=ftok("shmtest",1234);
	semid=semget(key,1,0666|IPC_CREAT);
	if(semid<0){
		perror("semget");
		exit(1);
	}
	u.val=1;
	if(semctl(semid,0,SETVAL,u)<0){
		perror("semctl");
		exit(1);
	}
	for(i=0;i<=1;i++){
		ret=pthread_create(&thread_t,NULL,print_one,(void *)&tidx[i]);
		if(ret){
			perror("pthread_create");
			exit(1);
		}
	}

	pthread_join(thread_t,NULL);
	return 0;
}
