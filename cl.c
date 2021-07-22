#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[]){
	int sockfd;
	int portnum;
	struct sockaddr_in saddr;
	socklen_t saddr_len;
	int ret;
	char buf[1024] = {0,};

	if(argc < 2){
		printf("Usage: %s <ipaddr> <port>\n", argv[0]);
		exit(1);
	}

	portnum = atoi(argv[2]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
		handle_error("socket");

	memset(&saddr, 0, sizeof(struct sockaddr_in));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr(argv[1]);
	saddr.sin_port = htons(portnum);

	if(connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr)) == -1)
		handle_error("connect");

	while(1) {
		char buf[1024] = {0,};
		printf("Input message(.:quit) : ");
		fgets(buf, sizeof(buf), stdin);
		if (buf[0] == '.')
			break;
		if (send(sockfd, buf, strlen(buf), 0) == -1)
			handle_error("send");
	}

	printf("finish.\n");
	close(sockfd);
	return 0;
}
