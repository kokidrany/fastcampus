#include <stdio.h>
#include <fcntl.h> /* for mode_t */
#include <errno.h> /* for errno */
#include <string.h> /* for strerror */

int main()
{
	int fd;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char *filename = "/tmp/fileexp";
	fd = creat(filename, mode);
	if (fd < 0 ) {
		printf("creat error: %s", strerror(errno));
		return -1;
	}
	return 0;
}


