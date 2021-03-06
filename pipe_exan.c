#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	int fd1[2];
	int fd2[2];
	pid_t p;
	if (pipe(fd1) == -1){
		fprintf(stderr,"pipe error:%m");
		return 1;
	}
	if(pipe(fd2) == -1){
		fprintf(stderr,"pipe error:%m");
		return 1;
	}
	p=fork();
	if(p<0){
		fprintf(stderr,"fork error:%m");
		return 1;
	} else if(p>0){ /* Parent */
		char writebuff[]="Did you understand? - Parent";
		char readbuff[128]={0};
		close(fd1[0]);	/* close read of fd1 */
		write(fd1[1], writebuff, strlen(writebuff)+1);
		close(fd1[1]);

		wait(NULL);

		close(fd2[1]);	/* close write of fd2 */
		read(fd2[0], readbuff, sizeof(readbuff));
		close(fd2[0]);
		printf("[Parent] read from child: %s\n", readbuff);
	} else { /* Child */
		char readbuff[128] = {0};
		char writebuff[]="OK! from - Child";
		close(fd1[1]); /*close write of fd1 */
		read(fd1[0], readbuff, sizeof(readbuff));
		close(fd1[0]);
		printf("[Child] read from Parent:%s\n", readbuff);
		close(fd2[0]); /* close read of fd2 */
		write(fd2[1], writebuff, strlen(writebuff)+1);
		close(fd2[1]);
		exit(0);
	}
	return 0;
}




