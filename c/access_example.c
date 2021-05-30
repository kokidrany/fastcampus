
#include <stdio.h>
#include <unistd.h>
int main(){
	char *pathname = "./create_example";
	int mode = R_OK | W_OK;
	if (access(pathname, mode) == 0 ) {
		printf("Read Write OK!\n");
	} else {
		printf("You do not have permission or do not exist.\n");
	}
	return 0;
}

