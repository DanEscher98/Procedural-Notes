#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *myfile = fopen("sample.txt", "w");
	printf("Writing a file.\n");
	fprintf(myfile, "Hello!\n");
	fprintf(myfile, "another line.\n");
	fclose(myfile);

	myfile = fopen("sample.txt", "r");
	char line[255];
	fgets(line, 255, myfile);
	printf("First line: %s", line);
	fclose(myfile);
	return EXIT_SUCCESS;
}
