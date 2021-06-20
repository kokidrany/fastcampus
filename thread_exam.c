#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *start_func(void *arg){
	int i, num = *(int *)arg;
	for (i=0; i<num; i++)
		printf(">> start_func %d\n", i);
	pthread_exit((void *)0);
}
int main(){
	int num = 10;
	pthread_t thread_t;
	int ret, status;
	ret = pthread_create(&thread_t, NULL, start_func, (void *)&num);
	if (ret) {
		printf("pthread_create error: %s\n",strerror(ret));
		return -1;
	}
	pthread_join(thread_t, (void **)&status);
	printf("Thread returned: %d\n", status);
	return 0;
}
