#include <stdio.h>

#define RED(s) "\e[0;31m"s"\e[0m"
#define GREEN(s) "\e[0;32m"s"\e[0m"

int main(void) {
	printf("%s World%s\n", GREEN("Hello"), RED("!"));
}
