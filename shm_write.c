#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
int main(){
	key_t key;
	int shmid;
	char *str;
	key = ftok("shmtest", 1234);
	shmid = shmget(key,1024,IPC_CREAT|0666);
	str = (char *)shmat(shmid,(void *)0,0);;
	printf("Input data:");
	if(fgets(str, sizeof(str),stdin) == NULL){
		perror("fgets error:");
		exit(1);
	}
	printf("Written data:%s\n", str);
	sleep(100);
	shmdt(str);
	return 0;
}

