#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
struct information {
	int index;
	char name[32];
	char phone_number[32];
	char mobile_number[32];
	char address[128];
};
/* addr_book : memory for store address information */
/* memidx : start index of addr_book array */
/* pidx : start index of person's index */
/* pnum : count of input person */

void input_person_information(struct information *addr_book, int memidx, int pidx, int pnum);

void print_person_information(struct information *addr_book, int pnum);

int main(){
	int nperson;
	int i;
	struct information *addr, newaddr;
	char yn[2];

	/* STEP 1 - input address book */
	printf("Input total number of person:");
	scanf("%d", &nperson);
	if (nperson <= 0){
		printf("please input at least one person!\n");
		return 0;
	}

	addr = (struct information *)calloc(nperson, sizeof(struct information));
	if (!addr){
		perror("calloc error:");
		return -1;
	}

	input_person_information(addr, 0, 1, nperson);

	/* STEP 2 - add address */
	printf("\nanyone else? [y/n]");
	scanf("%s", &yn);
	if (yn[0] == 'y' || yn[0] == 'Y'){
		int addnum;
		printf("Input add number of person:");
		scanf("%d", &addnum);
		if (addnum > 0){
			addr = (struct information *)realloc(addr, (nperson+addnum)*sizeof(struct information));
			if(!addr){
				perror("realloc error:");
				return -1;
			}
			input_person_information(addr, nperson, nperson+1,addnum);
			nperson+=addnum;
		}
	}

	printf("\t<print original address book>\n");
	print_person_information(addr, nperson);

	/* STEP 3 - change address */
	printf("\nanyone change? [yn]");
	scanf("%s", &yn);
	if (yn[0] == 'y' || yn[0] == 'Y'){
		int cidx;
		printf("Input change index:");
		scanf("%d", &cidx);
		if (cidx <0 || cidx > nperson){
			printf("There's only %d persons\n", nperson);
			return 0;
		}
		printf("\n<change first person's information>\n");
		
		memset(&newaddr, 0, sizeof(struct information));
		input_person_information(&newaddr, 0, cidx, 1);
		if (memcmp(&addr[cidx-1], &newaddr, sizeof(struct information))){
			memmove(&addr[cidx-1], &newaddr, sizeof(struct information));
			printf("\n<print new address book>\n");
			print_person_information(addr, nperson);
		} else
			printf("\nThe information is same!\n");
	}
	
	printf("finish!\n");
	free(addr);
	return 0;
}

void input_person_information(struct information *addr_book, int memidx, int pidx, int pnum){
	int i;
	for (i=0; i<pnum; i++){
		struct information *pinfo = &addr_book[memidx+i];
		printf("\nInput %d person's information.\n", pidx+i);
		pinfo->index = pidx+i;
		printf("Input name:");
		scanf("%s", pinfo->name);
		printf("Input phone number:");
		scanf("%s", pinfo->phone_number);
		printf("Input mobile number:");
		scanf("%s", pinfo->mobile_number);
		printf("Input address:");
		scanf("%s", pinfo->address);
	}
}

void print_person_information(struct information *addr_book, int pnum){
	int i;
	for (i=0; i<pnum; i++){
		struct information *pinfo = &addr_book[i];
		printf("[%d]\n", pinfo->index);
		printf("\tName:%s\n", pinfo->name);
		printf("\tPhone:%s\n", pinfo->phone_number);
		printf("\tMobile:%s\n", pinfo->mobile_number);
		printf("\tAddress:%s\n", pinfo->address);
	}
}

