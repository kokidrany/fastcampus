#include <pthread.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#define handle_error(msg)\
	do{perror(msg);exit(EXIT_FAILURE);}while(0)
static void tfunc(union sigval sv){
	struct mq_attr attr;
	ssize_t nr;
	void *buf;
	mqd_t mqdes=*((mqd_t*)sv.sival_ptr);
	if(mq_getattr(mqdes,&attr)==-1)
		handle_error("mq_getattr");
	buf=malloc(attr.mq_msgsize);
	if(buf==NULL)
		handle_error("malloc");
	nr=mq_receive(mqdes,buf,attr.mq_msgsize, NULL);
	if(nr==-1)
		handle_error("mq_receive");
	printf("Read %zd bytes from MQ\n",nr);
	printf("message:%s\n",buf);
	free(buf);
	exit(EXIT_SUCCESS);
}
int main(int argc, char *argv[]){
	mqd_t mqdes;
	struct mq_attr attr;
	struct sigevent sev;
	if(argc !=2){
		fprintf(stderr,"Usage:%s <mq-name>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if(argv[1][0] != '/'){
		fprintf(stderr,"mq-name(%s) is must start with slash(/)\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	memset(&attr,0,sizeof attr);
	attr.mq_maxmsg=2;
	attr.mq_msgsize=1024;
	mqdes=mq_open(argv[1], O_CREAT|O_RDONLY,0644,&attr);
	if(mqdes==(mqd_t)-1)
		handle_error("mq_open");
	sev.sigev_notify=SIGEV_THREAD;
	sev.sigev_notify_function=tfunc;
	sev.sigev_notify_attributes=NULL;
	sev.sigev_value.sival_ptr=&mqdes;
	if(mq_notify(mqdes,&sev)==-1)
		handle_error("mq_notify");

	pause();
}
