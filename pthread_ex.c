#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int total_money;
void *withdrawal(void *arg){
	int money = *(int *)arg;
	pthread_mutex_lock(&mutex);
	printf("withdrawal $%d from total balanced\n", money);
	total_money -= money;
	sleep(3);
	printf("calculation finish. (withdrawal $%d)\n", money);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main(){
	pthread_t thread1, thread2;
	int money1 = 100;
	int money2 = 200;
	total_money = 1000;
	printf("Total balance is $%d\n", total_money);
	pthread_create(&thread1, NULL, withdrawal, (void *)&money1);
	pthread_create(&thread2, NULL, withdrawal, (void *)&money2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("The remained balance is $%d\n", total_money);
	return 0;
}

