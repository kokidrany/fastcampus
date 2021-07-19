#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define handle_error(msg)\
	do {perror(msg);exit(EXIT_FAILURE);} while(0)

#define LISTEN_BACKLOG 10

int main(int argc, char *argv[]){
	int sfd, cfd;
	int portnum;
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;
	socklen_t caddr_len;
	int ret;
	char buf[1024] = {0,};
	if(argc<2){
	printf("Usage: %s <port>\n",argv[0]);
	exit(1);
	}

	portnum = atoi(argv[1]);
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	handle_error("socket");

	memset(&saddr,0,sizeof(struct sockaddr_in));
	saddr.sin_family=AF_INET;
	saddr.sin_addr.s_addr=INADDR_ANY;
	saddr.sin_port=htons(portnum);

	if(bind(sfd,(struct sockaddr *)&saddr,sizeof(saddr))== -1)
		handle_error("bind");
	if(listen(sfd,LISTEN_BACKLOG)== -1)
		handle_error("listen");

	caddr_len=sizeof(caddr);
	cfd=accept(sfd,(struct sockaddr *)&caddr,&caddr_len);
	if(cfd==-1)
		handle_error("accept");

	printf("accepted host (IP: %s, Port: %s)\n",inet_ntoa(((struct sockaddr_in *)&caddr)->sin_addr),ntohs(((struct sockaddr_in *)&caddr)->sin_port));

	while(1){
		memset(buf,0,sizeof(buf));
		ret = recv(cfd,buf,sizeof(buf),0);
		if(ret == -1) {
			handle_error("recv");
		} else if(ret == 0){
			break;
		} else {
			printf("recv data: %s\n",buf);
		}
	}
	printf("finish.\n");
	close(cfd);
	return 0;
}
