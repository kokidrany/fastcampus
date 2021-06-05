#include <stdio.h>
#define FILENAME "./data.file"
int main(void){
	FILE *readfile, *writefile;
	struct address_info{
		unsigned int index;
		char name[32];
		char phone_number[16];
		char address[100];
	};
	struct address_info kim, who;
	kim.index = 1;
	sprintf(kim.name, "kim");
	sprintf(kim.phone_number, "010-1234-5678");
	sprintf(kim.address, "Seoul");
	writefile = fopen(FILENAME, "w");
	if (!writefile){
		perror("fopen error:");
		return -1;
	}
	if (!fwrite(&kim, sizeof(struct address_info), 1, writefile)){
		perror("fwrite error:");
		return -1;
	}
	if (fclose(writefile)){
		perror("fclose error:");
		return -1;
	}
	readfile = fopen(FILENAME,"r");
	if (!readfile){
		perror("fopen error:");
		return -1;
	}
	if (!fread(&who, sizeof(struct address_info),1, readfile)){
		perror("fread error:");
		return -1;
	}
	if (fclose(readfile)){
		perror("fclose error:");
		return -1;
	}
	printf("index: %d\n", who.index);
	printf("name: %s\n", who.name);
	printf("phone_number: %s\n", who.phone_number);
	printf("address: %s\n", who.address);
	return 0;
}
