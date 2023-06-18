	BITS     64
	%include "std_macros.nasm"

	%macro print 2
	mov    rax, 1; syscall for write
	mov    rdi, 1; file descriptor (stdout)
	mov    rsi, %1
	mov    rdx, %2
	syscall
	%endmacro

	section .data
	NL      equ 0xa
	msg1    db   "Hello world!", NL, 0
	len1    equ $-msg1-1

	section .text
	global  main

main:
	Prelude
	;     MAIN CODE
	print msg1, len1
	;     ---------
	Epilogue
	Exit
