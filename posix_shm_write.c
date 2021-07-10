#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	const int SIZE = 1024;
	const char *name = "shmtest";
	int shm_fd;
	void* ptr;
	shm_fd=shm_open(name,O_CREAT|O_RDWR,0666);
	if(shm_fd==-1){
		perror("shm_open error:");
		exit(1);
	}
	if(ftruncate(shm_fd,SIZE)==-1){
		perror("ftruncate error:");
		exit(1);
	}
	ptr=mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0);
	if(ptr==MAP_FAILED){
		perror("mmap error:");
		exit(1);
	}
	printf("INPUT data: ");
	if(fgets(ptr,SIZE,stdin)==NULL){
		perror("gfets error:");
		exit(1);
	}
	printf("Written data: %s\n",ptr);
	munmap(ptr,SIZE);
	return 0;
}
