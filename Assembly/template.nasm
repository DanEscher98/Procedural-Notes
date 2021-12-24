	BITS 64

	%macro prelude 0
	push   rbp
	mov    rbp, rsp
	%endmacro

	%macro epilogue 0
	mov    rsp, rbp
	pop    rbp
	%endmacro

	%macro exit 0
	mov    rax, 60; syscall for exit
	mov    rdi, 0; exit code 0
	syscall
	%endmacro

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
	prelude
	;     MAIN CODE
	print msg1, len1
	;     ---------
	epilogue
	exit
