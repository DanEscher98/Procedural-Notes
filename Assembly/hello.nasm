BITS 64
; global _start ; ld linker

; ##############################
; Constants
; ##############################
section .data
message: db "Hello, world", 0xa, 0 ; const char * message
length:	 equ $-message		; int length = len(message)==12


; ##############################
; Variables
; ##############################
section .bss


; ##############################
; Program
; ##############################
section .text
global main
main:
; write(1, message, length)
mov rax, 1				; system call for write
mov rdi, 1				; making file handle stdout
mov rsi, message		; passing address of string to output
mov rdx, length			; number of bytes
syscall					; invoking os to write

; exit(0)
mov rax, 60				; system call for exit
mov rdi, 0				; exit code 0
syscall					; invoke os to exit
