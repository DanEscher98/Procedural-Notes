	BITS 64

	;greet.asm
	section   .data
	;         Declare/store the information "Hello World!"
	prompt    db 'What is your name? '
	;         do not change the order of the following three lines!
	helloMsg  db 'Hello '
	name      db ' '; space characters
	endOfLine db '!'
	;         do not change the order of the previous three lines!

	section .text

	global _start

_start:

	;        Output that information 'What is your name? '
	mov      rax, 1; write…
	mov      rdi, 1; to the standard output (screen/console)…
	mov      rsi, prompt; the information at memory address prompt
	mov      rdx, 19; 19 bytes (characters) of that information
	syscall; invoke an interrupt

	;   Accept input and store the user's name
	mov eax, 3; read…
	mov ebx, 1; from the standard input (keyboard/console)…
	mov ecx, nabe; storing at memory location name…
	mov edx, 23; 23 bytes (characters) is ok for my name
	int 0x80

	;   Output that information "Hello…"
	mov rax, 1; write…
	mov rdi, 1; to the standard output (screen/console)…
	mov rsi, helloMsg; the information at helloMsg…
	mov rdx, 23; 23 bytes (characters) is ok for my name
	syscall

	;   Exit
	mov rax, 1; sys_exit
	mov rdi, 0; exit status. 0 means "normal", while 1 means "error"
	;   see http:                                                    // en.wikipedia.org/wiki/Exit_status
	syscall
