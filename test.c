#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void segv_handler(int sig) {
	int j, nptrs;
#define SIZE 100
	void *buffer[100];
	char **strings;

	nptrs = backtrace(buffer, SIZE);
	printf("backtrace() returned %d addresses\n", nptrs);

	fprintf(stderr, "ERROR: signal(%d)\n", sig);
	backtrace_symbols_fd(buffer, nptrs, STDERR_FILENO);
	exit(1);
}

void foo(){
	printf("foo\n");
}

void bar(){
	printf("bar\n");
}

void first_to_space(char *str){
	printf("func start\n");
	str[0] = ' ';
	printf("func end\n");
}

int main(int argc, char **argv){
	char *str = NULL;

	signal(SIGSEGV, segv_handler);

	foo();
	bar();
	first_to_space(str);

	return 0;
}

