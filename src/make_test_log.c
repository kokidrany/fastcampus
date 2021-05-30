#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "make_test.h"

void *make_test_log(void *arg)
{
	int i;
	for (i=0; i<MAX_NUM; i++) {
		printf("(%d) make_test_log\n", i+1);
		sleep(1);
	}
	pthread_exit((void *)1);
}

