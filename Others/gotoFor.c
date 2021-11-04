#include <stdio.h>
#include <stdlib.h>

#define ciclo(init, cond, updt, action) \
	init;if(!(cond))goto LOOP_END;\
	LOOP_START:action;updt;\
	if(cond)goto LOOP_START;\
	LOOP_END:

int main(void) {
	ciclo(int i=0, i<5, i++, printf("%d ", i));
	printf("My goto loooop!\n");
	return EXIT_SUCCESS;
}

