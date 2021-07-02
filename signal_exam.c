#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int loop = 1;
static void sigint_handler(int signo){
	printf("SIGINT received!\n");
	loop = 0;
}
int main(){
	if(signal(SIGINT, sigint_handler) == SIG_ERR){
		printf("register SIGINT handler fail!\n");
		return -1;
	}
	if(signal(SIGTSTP, SIG_IGN) == SIG_ERR){
		printf("register SIGTSTP handler fail!\n");
	}
	while(loop){
		sleep(1);
		printf("continue...\n");
	}
	printf("loop exit.\n");
	return 0;
}
