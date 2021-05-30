#include <stdio.h>
#include <pthread.h>
#include "make_test.h"

void *make_test_util(void *arg);
void *make_test_debug(void *arg);
void *make_test_log(void *arg);

int main()
{
	pthread_t thread_util;
	pthread_t thread_debug;
	pthread_t thread_log;

	int *thread_util_ret;
	int *thread_debug_ret;
	int *thread_log_ret;

	printf("main start\n");
	printf("MAX NUM is %d\n", MAX_NUM);

	pthread_create(&thread_util, NULL, make_test_util, NULL);
	pthread_create(&thread_debug, NULL, make_test_debug, NULL);
	pthread_create(&thread_log, NULL, make_test_log, NULL);

	pthread_join(thread_util, (void **)&thread_util_ret);
	pthread_join(thread_debug, (void **)&thread_debug_ret);
	pthread_join(thread_log, (void **)&thread_log_ret);

	return 0;
}

