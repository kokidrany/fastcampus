#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv){
	struct hostent *hp = NULL;
	int i;
	if (argc < 2) {
		printf("Usage: %s <hostname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	hp = gethostbyname(argv[1]);
	if (!hp) {
		printf("gethostbyname error: %s\n", hstrerror(h_errno));
		return 0;
	}

	printf("h_name: %s\n", hp->h_name);
	printf("h_length: %d\n", hp->h_length);

	for (i=0; i<hp->h_length && hp->h_addr_list[i]; i++){
		char *addr = (char *)hp->h_addr_list[i];
		struct in_addr *in = (struct in_addr *)addr;
		printf("h_addr_list [%d]: %s\n", i, inet_ntoa(*in));
	}

	return 0;
}
