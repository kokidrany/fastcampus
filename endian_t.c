#include <stdio.h>
#include <arpa/inet.h>

union longbyte {
	long l;
	unsigned char c[4];
};

int main(){
	union longbyte lb;
	lb.l = 0x1234;
	printf("[Host Order] %02x, %02x, %02x, %02x\n", lb.c[0],lb.c[1],lb.c[2],lb.c[3]);

	lb.l = htonl(lb.l);
	printf("[Network Order] %02x, %02x, %02x, %02x\n", lb.c[0],lb.c[1],lb.c[2],lb.c[3]);

	return 0;
}
