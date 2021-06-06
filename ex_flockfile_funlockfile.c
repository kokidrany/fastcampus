#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *mod_file_thread(void *fpp){
 FILE *fp = (FILE *)fpp;
 char buf[1024];
 printf("<thread start>\n");
 flockfile(fp);
 printf("lock!, data file contents:\n");
 while (fgets(buf, sizeof(buf), fp)){
	 printf("%s", buf);
 }
 printf("now add data \"HELLO WORLD!\\n\"\n");
 sprintf(buf, "HELLO WORLD!\n");
 if (fputs(buf, fp) == EOF){
	 perror("fputs error:");
	 pthread_exit(NULL);
 }
 sleep(3);
 printf("finish, unlock!\n");
 funlockfile(fp);
 pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	FILE *fp;
	pthread_t th1, th2;
	if (argc<2){
		printf("Usage: %s <data-file>\n", argv[0]);
		return -1;
	}
	fp = fopen(argv[1], "r+");
	if (!fp){
		perror("fopen error");
		return -1;
	}
	pthread_create(&th1, NULL, mod_file_thread, (void *)fp);
	pthread_create(&th2, NULL, mod_file_thread, (void *)fp);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	return 0;
}

