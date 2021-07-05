#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fp;
	int status;
	char buff[1024];
	fp = popen("pwd", "r");
	if (fp == NULL){
		fprintf(stderr, "popen error:%m\n");
		exit(1);
	}
	printf("Current Path is:");
	while(fgets(buff, sizeof(buff), fp) != NULL){
		printf("%s",buff);
	}
	status = pclose(fp);
	if (status == -1){
		fprintf(stderr, "pclose error:%m\n");
		exit(1);
	}
	return 0;
}
