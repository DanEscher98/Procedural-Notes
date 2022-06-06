#include <stdio.h>
#include <threads.h>

#define NUM_THREADS 20

static int threadData[NUM_THREADS];

unsigned long factorial(unsigned long n) {
	if (n <= 1) {
		return 1;
	} else {
		return n * factorial(n-1);
	}
}

int threadFunction(void * data) {
	int value = *(int*)data;
    printf("%d-th thread up => %lu\n", value, factorial(value));
    return 0;
}

int main(void) {
    thrd_t threadId[NUM_THREADS];

    // init thread data
    for (int i=0; i < NUM_THREADS; ++i)
        threadData[i] = i;

    // start NUM_THREADS amount of threads
    for (int i=0; i < NUM_THREADS; ++i) {
        if (thrd_create(threadId+i, threadFunction, threadData+i) != thrd_success) {
            printf("%d-th thread create error\n", i);
            return 0;
        }
    }

    // wait until all threads terminates
    for (int i=0; i < NUM_THREADS; ++i)
        thrd_join(threadId[i], NULL);

    return 0;
}
