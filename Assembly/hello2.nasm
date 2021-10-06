BITS 64

section .data
	msg1	db "Hello, world!", 0xa, 0
	msg1len equ $-msg1-1
	msg2	db "I'm a human :)", 0xa, 0
	msg2len equ $-msg2-1

section .bss

section .text
	global main

main:
	; ## Prologue ########################
	push	rbp
	mov		rbp, rsp

	; ## Code ############################
	mov		rax, 1			; syscall for write
	mov		rdi, 1			; stdout
	mov		rsi, msg1
	mov		rdx, msg1len
	syscall

	mov		rax, 1
	mov		rdi, 1
	mov		rsi, msg2
	mov		rdx, msg2len
	syscall

	; ## Epilogue ########################
	mov		rsp, rbp
	pop		rbp
	mov		rax, 60			; syscall for exit
	mov		rdi, 0			; exit code 0
	syscall
