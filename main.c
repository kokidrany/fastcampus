#include <stdio.h>
#include <stdlib.h> /* for atoi() */
void func1(void);
void func2(void);
int main() {
	int result;
	char number[] = "abcd";
	printf("main() start\n");
/* func1();
func2();
*/
	result = atoi(number);
	printf("result: %d\n", result);
	if(NULL) printf("NULL is true\n");
	if(!NULL) printf("NULL is false\n");
	return 0;
}
