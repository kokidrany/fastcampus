#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "make_test.h"

void *make_test_debug(void *arg)
{
	int i;
	for (i=0; i<MAX_NUM; i++){
		printf("(%d) make_test_debug\n", i+1);
		sleep(1);
	}
	pthread_exit((void *)1);
}
