	BITS 64

	;      ## macro for write syscall ####
	%macro putln 2
	mov    rax, 1; syscall for write
	mov    rdi, 1; file descriptor (stdout)
	mov    rsi, %1
	mov    rdx, %2
	syscall
	%endmacro

	section .data
	NL      equ 0xa
	msg     db     "Hello, world!", NL, 0
	length  equ $-msg-1

	section .text
	global  main

main:
	;    ## Prologue #####################
	push rbp
	mov  rbp, rsp

	;     ## Code ########################
	putln msg, length
	;     ## Epilogue ####################
	mov   rsp, rbp
	pop   rbp
	mov   rax, 60; syscall for exit
	mov   rdi, 0; exit code 0
	syscall
