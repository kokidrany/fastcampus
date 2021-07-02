#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int wakeup = 0;
static void sig_handler(int signo){
	if(signo == SIGINT)
		printf("signal SIGINT received!\n");
	else if (signo == SIGTSTP)
		printf("signal SIGTSTP received!\n");
	else if (signo == SIGQUIT)
		printf("signal SIGQUIT received!\n");
	else
		printf("signal %d received!\n");
	wakeup =1;
}
static void wait_for_signal(void){
	printf("sleep 10sec\n");
	sleep(10);
	printf("wake up!\n");
}
int main(){
	sigset_t set, oldset;
	if(signal(SIGINT, sig_handler)==SIG_ERR){
		printf("signal handler(SIGINT) error!\n");
		return -1;
	}
	if(signal(SIGTSTP, sig_handler)==SIG_ERR){
		printf("signal handler(SIGTSTP) error!\n");
		return -1;
	}
	if(signal(SIGQUIT, sig_handler)==SIG_ERR){
		printf("signal handler(SIGQUIT) error!\n");
		return -1;
	}
	sigemptyset(&set);
	sigemptyset(&oldset);

	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGTSTP);

	sigprocmask(SIG_BLOCK, &set, NULL);
	printf("Block SIGINT and SIGTSTP\n");
	
	wait_for_signal();
	sigdelset(&set,SIGINT);
	sigprocmask(SIG_UNBLOCK, &set, &oldset);
	printf("Block only SIGINT\n");

	wait_for_signal();
	
	sigprocmask(SIG_SETMASK,&oldset,NULL);
	printf("Block SIGINT and SIGTSTP\n");

	wait_for_signal();

	return 0;
}
