#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void){
	int status;
	pid_t pid;
	if(fork() == 0) /* child process */
		return 1;
	pid = wait(&status);
	if (pid == -1)
		perror("wait error:");
	printf(">> pid = %d\n", pid);
	if (WIFEXITED(status)){
		printf("child process terminated with exit status (%d)\n", WEXITSTATUS(status));
	}
	if (WIFSIGNALED(status)){
		printf("child process killed by signal (%d)\n", WTERMSIG(status));
		if (WCOREDUMP(status)){ /* signal received SIGSEGV, etc */
			printf("child process dumped core\n");
		}
	}
	if (WIFSTOPPED(status))
		printf("child process stopped by signal (%d)\n", WSTOPSIG(status));
	if (WIFCONTINUED(status))
		printf("child process continued\n");

	return 0;
}


