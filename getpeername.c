#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc, char *argv[]){
	int sockfd;
	int client_sockfd;
	int client_len;
	int state;
	struct sockaddr_in clientaddr, serveraddr, myaddr, test;
	if(argc<2){
		printf("Usage: %s <Port>\n", argv[0]);
		exit(1);
	}
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
		perror("socket error");
		exit(1);
	}
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	serveraddr.sin_port=htons(atoi(argv[1]));
	state=bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(state==-1){
		perror("bind error");
		exit(0);
	}
	state=listen(sockfd,5);
	if(state==-1){
		perror("listen error");
		exit(0);
	}
	client_len=sizeof(clientaddr);
	client_sockfd=accept(sockfd,(struct sockaddr *)&clientaddr,&client_len);
	getpeername(client_sockfd,(struct sockaddr *)&myaddr,&client_len);
	printf("Port : %d\n",ntohs(myaddr.sin_port));
	printf("address : %s\n",inet_ntoa(myaddr.sin_addr));
	close(client_sockfd);
	return 1;
}
