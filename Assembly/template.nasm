	BITS 64

	%macro Prelude 0
	push   rbp
	mov    rbp, rsp
	%endmacro

	%macro Epilogue 0
	mov    rsp, rbp
	pop    rbp
	%endmacro

	%macro Exit 0
	mov    rax, EXIT; syscall for exit
	mov    rdi, EXIT_SUCCESS; exit code 0
	syscall
	%endmacro

	%macro print 2
	mov    rax, WRITE; syscall for write
	mov    rdi, STDOUT; file descriptor (stdout)
	mov    rsi, %1
	mov    rdx, %2
	syscall
	%endmacro

	section .data
	NL      equ 0xa
	WRITE   equ 1
	STDOUT  equ 1
	EXIT    equ 60
	EXIT_SUCCESS    equ 0
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
