#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
void *start_func(void *arg){
	printf("start_func() just wait...\n");
	while(1){
		sleep(1);
		printf("sleep(1) continue...\n");
	}
	return NULL;
}
int main(){
	pthread_t thread_t;
	int ret;
	ret = pthread_create(&thread_t, NULL, start_func, NULL);
	if(ret){
		printf("pthread_create error:%s\n", strerror(ret));
		return -1;
	}
	sleep(5);
	ret = pthread_cancel(thread_t);
	if (ret){
		perror("pthread_cancel error:");
		return -1;
	}
	printf("thread canceled\n");
	return 0;
}
