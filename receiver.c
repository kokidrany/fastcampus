#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc, char *argv[]){
	int sockfd;
	struct sockaddr_in receiver_addr;
	struct sockaddr_in sender_addr;
	int sender_len;
	char buff[1024] = {0,};
	int recvlen, sendlen;

	if(argc<2){
		fprintf(stderr,"Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd == -1){
		perror("socket() error");
		exit(1);
	}

	memset(&receiver_addr, 0, sizeof(receiver_addr));
	receiver_addr.sin_family = AF_INET;
	receiver_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	receiver_addr.sin_port = htons(atoi(argv[1]));
	
	if(bind(sockfd, (struct sockaddr *)&receiver_addr, sizeof(receiver_addr)) == -1){
		perror("bind() error");
		exit(1);
	}

	while(1){
		memset(buff, 0, sizeof(buff));
		sender_len = sizeof(sender_addr);
		recvlen = recvfrom(sockfd, buff, sizeof(buff)-1, 0, (struct sockaddr *)&sender_addr, &sender_len);
		if (recvlen == -1){
			perror("recvfrom() error");
			exit(1);
		}

		buff[recvlen] = '\0';
		if(strcmp(buff, ".\n") == 0)
			break;

		printf("Received Data: %s\n", buff);

		snprintf(buff, sizeof(buff), "OK!");
		sendlen = strlen(buff);

		if(sendto(sockfd, buff, sendlen, 0, (struct sockaddr *)&sender_addr, sizeof(sender_addr)) != sendlen){
			perror("sendto() error");
			exit(1);
		}
	}

	close(sockfd);
	return 0;
}

