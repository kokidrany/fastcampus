#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
	struct dirent *entry;
	DIR *dir;
	bool found = false;
	if (argc < 3){
		printf("Usage: %s <dir> <file>\n", argv[0]);
		return -1;
	}
	dir = opendir(argv[1]);
	if(dir == NULL){
		perror("opendir error:");
		return -1;
	}
	errno =0;
	while( (entry=readdir(dir)) != NULL ){
		if(strcmp(entry->d_name , argv[2]) == 0){
			printf("found! file (%s) exist\n",argv[2]);
			found = true;
			break;
		}
	}
	if (errno) {
		perror("readdir error:");
		closedir(dir);
		return -1;
	}
	if (!found)
		printf("file (%s) doesn't exist!\n", argv[2]);
	closedir(dir);
	return 0;
}
