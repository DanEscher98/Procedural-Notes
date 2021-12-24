    BITS 64

; ## Macro for the write system call #####
    %macro putLn 2
    mov		rax, 1              ; syscall for write
    mov		rdi, 1              ; file descriptor (stdout)
    mov		rsi, %1
    mov		rdx, %2
    syscall
    %endmacro

    section .data
msg1:
    db "Hello, world!", 0xa, 0
    len1	equ $-msg1-1
msg2:
    db "I'm a human :)", 0xa, 0
    len2	equ $-msg2-1

    section .bss

    section .text
    global main

main:
; ## Prologue ########################
    push	rbp
    mov		rbp, rsp

; ## Code ############################
    putLn	msg1, len1
    putLn	msg2, len2

; ## Epilogue ########################
    mov		rsp, rbp
    pop		rbp
    mov		rax, 60             ; syscall for exit
    mov		rdi, 0              ; exit code 0
    syscall
