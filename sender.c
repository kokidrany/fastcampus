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
	char buff[1024] = {0,};
	int bufflen, recvlen, receiver_len;

	if(argc < 3){
		fprintf(stderr, "Usage: %s <IP> <Port>\n", argv[0]);
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd == -1){
		perror("socket() error");
		exit(1);
	}

	memset(&receiver_addr, 0, sizeof(receiver_addr));
	receiver_addr.sin_family = AF_INET;
	receiver_addr.sin_addr.s_addr = inet_addr(argv[1]);
	receiver_addr.sin_port = htons(atoi(argv[2]));

	while(1){
		printf("Input message (quit:.) : ");
		memset(buff, 0, sizeof(buff));
		fgets(buff, sizeof(buff), stdin);
		bufflen = strlen(buff);

		if(sendto(sockfd, buff, bufflen, 0, (struct sockaddr *)&receiver_addr, sizeof(receiver_addr)) != bufflen){
			perror("sendto() error");
			exit(1);
		}

		if(strcmp(buff, ".\n") == 0)
			break;

		recvlen = recvfrom(sockfd, buff, sizeof(buff)-1, 0, (struct sockaddr *)&receiver_addr, &receiver_len);
		if(recvlen == -1){
			perror("recvfrom() error");
			exit(1);
		}

		buff[recvlen] = '\0';
		printf("Reply received: %s\n", buff);
	}

	close(sockfd);
	return 0;
}
