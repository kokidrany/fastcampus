#include <stdio.h>
void print_func(char *str){
	str[0] = ' ';
	printf("String: %s\n",str);
}

int main(){
	char *str = NULL;
	print_func(str);
	return 0;
}
