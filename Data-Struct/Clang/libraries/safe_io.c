// Based on "A beginners' guide away from scanf()"
// of Felix Palmen: https://0x0.st/NUnC

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char *toString(int num) {
	int num_len = snprintf(NULL, 0, "%d", num) + 1;
	char *string = malloc(num_len);                                             
	snprintf(string, num_len, "%d", num);
	return string;
}

int parseInt(char *value) {
	int num;
	char *endptr;	   // reset error number
	errno = 0;
	// The problems set maxium size at 1000, so the max
	// length of a number is set to 4 digits
	num = strtol(value, &endptr, 10);
	if (errno == ERANGE) {
		fputs("ERR => Number too big\n", stdout);
		exit(1);
	} else if (endptr == value) {
		fputs("ERR => The arg must be an int\n", stdout);
		exit(1);   // no character readed
	} else if (*endptr && *endptr != '\n') {
		fputs("ERR => Incorrect char\n", stdout);
		exit(1);
	} else return num;
}

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
