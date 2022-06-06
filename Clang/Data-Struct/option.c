#include <stdio.h>
#include <stdlib.h>
#include <error.h>

enum Result {
	OK,
	ERR
};

union Either {
	void *just;
	int err;
};

typedef struct maybe {
	union Either value;
	enum Result result;
} maybe;

maybe openfile(char *filename, char* mode) {
	maybe res;
	FILE *file = fopen(filename, mode);
	if (file == NULL) {
		res = (maybe){ .value={NULL}, .result=ERR };
	} else {
		res = (maybe){ .value={file}, .result=OK };
	}
	return res;
}

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
