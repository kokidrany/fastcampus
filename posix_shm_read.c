#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	const int SIZE=1024;
	const char *name="shmtest";
	int shm_fd;
	void* ptr;
	shm_fd=shm_open(name,O_RDONLY,0666);
	if(shm_fd==-1){
		perror("shm_open error:");
		exit(1);
	}
	ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
	if(ptr==MAP_FAILED){
		perror("mmap error:");
		exit(1);
	}
	printf("%s",(char*)ptr);
	shm_unlink(name);
	return 0;
}

