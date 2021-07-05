#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(){
	printf("time returned: %ld\n", (long)time(NULL));

	struct timeval tv;
	int ret;
	ret = gettimeofday(&tv, NULL);
	if(ret == -1){
		perror("gettimeofday error:");
		return -1;
	}
	printf("seconds= %ld, useconds= %ld\n", (long)tv.tv_sec, (long)tv.tv_usec);

	time_t t = time(NULL);
	printf("time: %s\n", ctime(&t));

	struct tm *tm1, *tm2;
	tm1 = gmtime(&t);
	tm2 = localtime(&t);
	if(!tm1 || !tm2){
		perror("gmtime, localtime error:");
		return -1;
	}

	printf("%d %d %d %d:%d:%d\n", tm1->tm_year+1900, tm1->tm_mon+1, tm1->tm_mday,tm1->tm_hour, tm1->tm_min, tm1->tm_sec);

	printf("%d %d %d %d:%d:%d\n", tm2->tm_year+1900, tm2->tm_mon+1, tm2->tm_mday,tm2->tm_hour, tm2->tm_min, tm2->tm_sec);

	time_t t1 = time(NULL);
	struct tm tm3, tm4;

	gmtime_r(&t1, &tm3);
	localtime_r(&t1, &tm4);

	printf("%d %d %d %d:%d:%d\n", tm3.tm_year+1900, tm3.tm_mon+1, tm3.tm_mday,tm3.tm_hour, tm3.tm_min, tm3.tm_sec);

	printf("%d %d %d %d:%d:%d\n", tm4.tm_year+1900, tm4.tm_mon+1, tm4.tm_mday,tm4.tm_hour, tm4.tm_min, tm4.tm_sec);

	return 0;
}
