#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char *filename = "./a.out";
	int mode = F_OK;
	if (access(filename, mode) == 0){
		if(chmod(filename, S_IRWXU|S_IRWXG) != 0){
			printf("chmod() error\n");
			return -1;
		}
	} else {
		printf("file(%s) access error\n", filename);
		return -1;
	}
	return 0;
}
