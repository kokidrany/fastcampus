#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
	char myIP[16];
	unsigned int myPort;
	struct sockaddr_in server_addr,my_addr;
	int sockfd;
	if(argc<3){
	printf("Usage: %s <IP> <Port>\n", argv[0]);
	exit(1);
	}
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
	perror("socket error");
	exit(1);
	}
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));
	if(connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0){
	perror("connect error");
	close(sockfd);
	exit(1);
	}
	bzero(&my_addr,sizeof(my_addr));
	int len = sizeof(my_addr);
	getsockname(sockfd,(struct sockaddr *)&my_addr,&len);
	inet_ntop(AF_INET,&my_addr.sin_addr,myIP,sizeof(myIP));
	myPort = ntohs(my_addr.sin_port);
	printf("Local ip address: %s\n",myIP);
	printf("Local port: %u\n", myPort);
	close(sockfd);
	return 0;
}


