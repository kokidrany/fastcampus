#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc, char *argv[]){
	if(argc <3){
		printf("Usage: %s <signo> <pid>\n", argv[0]);
		return -1;
	}
	if(kill(atoi(argv[2]), atoi(argv[1])) == -1){
		perror("kill error:");
		return -1;
	}
	return 0;
}
