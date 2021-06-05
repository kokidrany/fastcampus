#include <stdio.h>
int main (int argc, char *argv[]) {
	FILE *fp;
	int c;
	if (argc < 2){
		printf("Usage: %s <file>\n", argv[0]);
		return -1;
	}
	fp = fopen(argv[1], "r+");
	if (!fp){
		perror("fopen error:");
		return -1;
	}
	while( (c=fgetc(fp)) != EOF ){
		if( c == '!' || c=='@' || c=='#' || c=='$' || c=='%' || c=='^' || c=='&' || c=='*' || c=='-' || c=='_' ){
			if ( ungetc(c, fp) == EOF){
				perror("ungetc error:");
				return -1;
			}
		if ( fputc(' ', fp) == EOF){
			perror("fputc error:");
			return -1;
		}
		}
	}
	if (fclose(fp) == EOF){
		perror("fclose error:");
		return -1;
	}
	return 0;
}
