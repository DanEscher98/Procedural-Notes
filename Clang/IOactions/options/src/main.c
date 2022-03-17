#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

static float version = 1.0;
void print_help(void);
void printfile(char*);

void print_help(void) {
	printfile("help.txt");
}

void printfile(char *filename) {
	FILE *fptr;
	if ((fptr = fopen(filename, "r")) == NULL) {
		printf("Cannot open file.\n");
		exit(EXIT_FAILURE);
	} else {
		for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
			putc(c, stdout);
		}
	}
}

int main(int argc, char **argv) {
	int opt, option_index;
	static struct option long_opts[] = {
		{ "file", true, 0, 'f'},
		{ "version", false, 0, 'v' },
		{ "help", false, 0, 'h' },
		{ NULL, 0, 0, 0 }
	};
	while ((opt = getopt_long(argc, argv, "f:vh", long_opts, &option_index)) != -1) {
		switch (opt) {
			case 'f':
				printfile(optarg);
				break;
			case 'v':
				printf("v%.2f\n", version);
				exit(EXIT_SUCCESS);
				break;
			case 'h':
				print_help();
				break;
		}
	}
	return EXIT_SUCCESS;
}
