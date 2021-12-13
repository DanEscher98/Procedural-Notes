#include <stdio.h>

#define RED(s) "\e[0;31m"s"\e[0m"
#define GREEN(s)                                                               \
	"\e[0;32m"s                                                                \
	"\e[0m"

int main(int argc, char** argv)
{
	printf("Hello %s%s\n", RED(arg[1]), RED("!"));
}
