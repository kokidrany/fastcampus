#include <stdio.h>
#include <unistd.h>

int main (){
	char *filename = "./a.out";
	int mode = F_OK;
	if (access(filename, mode) == 0 ){
		if (chown(filename, 1, 2) !=0 ){
			printf("chown() error\n");
			return -1;
		}
	} else {
		printf("file (%s) access error\n", filename);
		return -1;
	}
	return 0;
}
