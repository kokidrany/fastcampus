#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define handle_error(msg)\
       do { perror(msg);exit(EXIT_FAILURE); } while(0)
#define LISTEN_BACKLOG 50
#define MAX(a,b)((a>b)?a:b)
#define MAX_SOCKFDS 50
int sockfds[MAX_SOCKFDS];
int cnt_sockfds;

void init_sockfds(){
	int i;
	for (i=0;i<MAX_SOCKFDS;i++)
		sockfds[i] = -1;
	cnt_sockfds = 0;
}

int add_socket(int fd){
	if(cnt_sockfds >= MAX_SOCKFDS)
		return -1;
	sockfds[cnt_sockfds++] = fd;
	return cnt_sockfds;
}
void del_socket(int fd){
	int i,lastidx=cnt_sockfds-1 ;
	for (i=1; i<cnt_sockfds;i++){
		//printf("%d, %d",i,lastidx);
		if(sockfds[i] == fd){
			if(i != lastidx)
				sockfds[i] = sockfds[lastidx];
			sockfds[lastidx] = -1;
			cnt_sockfds--;
			break;
		}
	}
}
int main(int argc, char *argv[]){
	int sfd,cfd;
	int portnum;
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;
	socklen_t caddr_len;
	int ret;
	char buf[1024]={0,};

	fd_set readfds;
	int ret_select;
	int i,maxfd=0;
	if (argc<2){
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	portnum = atoi(argv[1]);

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd == -1)
		handle_error("socket");

	memset(&saddr,0,sizeof(struct sockaddr_in));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(portnum);

	if(bind(sfd,(struct sockaddr *)&saddr,sizeof(saddr)) == -1)
		handle_error("bind");

	if(listen(sfd,LISTEN_BACKLOG) == -1)
		handle_error("listen");

	init_sockfds();

	add_socket(sfd);

	while(1){
		maxfd = 0;
		FD_ZERO(&readfds);
		for(i=0;i<cnt_sockfds;i++){
			FD_SET(sockfds[i],&readfds);
			maxfd = MAX(maxfd, sockfds[i]);
		}

		ret_select = select(maxfd+1,&readfds,NULL,NULL,NULL);
		if(ret_select == -1){
			perror("select error");
			exit(1);
		}

		if(FD_ISSET(sfd,&readfds)){
			caddr_len = sizeof(caddr);
			cfd = accept(sfd,(struct sockaddr *)&caddr,&caddr_len);

			if(cfd == -1)
				handle_error("accept");

			if(add_socket(cfd) == -1){
				printf("error: current socket count (%d) / max socket count (%d)\n",cnt_sockfds,MAX_SOCKFDS);
			}else{
				printf("add socket(%d) OK! (IP: %s, Port: %d)\n",cfd,inet_ntoa(((struct sockaddr_in *)&caddr)->sin_addr),ntohs(((struct sockaddr_in *)&caddr)->sin_port));
			}

			continue;
		}

		for(i=1; i<cnt_sockfds; i++){
			int sockfd = sockfds[i];
			if(sockfd >= 0 && FD_ISSET(sockfd,&readfds)){

				memset(buf,0,sizeof(buf));
				ret = recv(sockfd,buf,sizeof(buf),0);

				if(ret == -1)
					handle_error("recv");
				else if (ret == 0){
					del_socket(sockfd);
					printf("del socket (%d) OK!\n", sockfd);
					close(sockfd);
				}else{
					printf("recv data(sock: %d): %s\n",sockfd,buf);
				}
			}
		}
	}

return 0;
}


