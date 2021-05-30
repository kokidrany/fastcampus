#include <stdio.h>
int main() {
#ifdef MY_MACRO
	printf("Macro Defined\n");
#endif
	char c = -10;
printf ("hello World\n");
printf ("c is %d\n", c);
return 0;
}
