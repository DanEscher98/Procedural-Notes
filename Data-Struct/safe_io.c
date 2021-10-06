// Based on "A beginners' guide away from scanf()"
// of Felix Palmen: https://0x0.st/NUnC

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int readInt(char *msg) {
	int num;
	char buff[1024];
	int success;
	do {
		fputs(msg, stdout);
		if(!fgets(buff, 1024, stdin)) return 1;

		char *endptr;		// reset error number
		errno = 0;
		num = strtol(buff, &endptr, 10);
		if (errno == ERANGE) {
			fputs("ERR => Incorrect size\n", stdout);
			success = 0;
		} else if (endptr == buff) {
			fputs("ERR => Non numeric string\n", stdout);
			success = 0;	// no character readed
		} else if (*endptr && *endptr != '\n') {
			fputs("ERR => Incorrect char\n", stdout);
			success = 0;
		} else success = 1;
	} while(!success);
	return num;
}

float readFloat(char *msg) {
	float num;
	char buff[1024];
	int success;
	do {
		fputs(msg, stdout);
		if(!fgets(buff, 1024, stdin)) return 1;

		char *endptr;		// reset error number
		errno = 0;
		num = strtof(buff, &endptr);
		if (errno == ERANGE) {
			fputs("ERR => Incorrect size\n", stdout);
			success = 0;
		} else if (endptr == buff) {
			fputs("ERR => Non numeric string\n", stdout);
			success = 0;	// no character readed
		} else if (*endptr && *endptr != '\n') {
			fputs("ERR => Incorrect char\n", stdout);
			success = 0;
		} else success = 1;
	} while(!success);
	return num;
}
