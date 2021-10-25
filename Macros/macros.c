#include <stdio.h>
// Definir el sistema operativo
#if defined(__linux__) || defined(__linux)
    #define LINUX
	#if defined(__x86_64__) || defined(__aarch64__)
		#define ENV64BITS
	#else
		#define ENV32BITS
	#endif
#elif defined(_WIN32) || defined(_WIN64)
    #define WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
	#define MACOS
#else
	#error Unsupported OS
#endif

int main(void) {
#ifdef LINUX
	printf("Hola desde Linux.\n");
#endif
#ifdef WINDOWS
	printf("Hola desde Windows.\n");
#endif
	printf("Current date: %s\n", __DATE__);
	printf("Current time: %s\n", __TIME__);
	return 0;
}
