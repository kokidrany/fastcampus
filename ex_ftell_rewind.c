#include <stdio.h>
#include <unistd.h>
int main(){
 FILE *fp;
 long pos;
 int i;
 fp = fopen("./test.file", "w+");
 if (fp == NULL){
	 perror("fopen error:");
	 return -1;
 }
 fprintf(fp, "HELLO WORLD\n");
 pos = ftell(fp);
 if (pos == -1){
	 perror("ftell error:");
	 return -1;
 }
 printf("current pos is %ld\n", pos);
 printf("move pos to start\n");
 rewind(fp);
 pos = ftell(fp);
 if (pos == -1){
	 perror("ftell error:");
	 return -1;
 }
 printf("current pos is %ld\n", pos);
 fclose(fp);
 for(i=0; i<5; i++){
	 fprintf(stdout, ".");
	 sleep(1);
 }
 printf("\n");
 for (i=0; i<5; i++){
	 fprintf(stdout, ".");
	 fflush(stdout);
	 sleep(1);
 }
 printf("\n");
 return 0;
}

