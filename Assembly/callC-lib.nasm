    BITS 64

    %macro prelude 0
    push	rbp
    mov		rbp, rsp
    %endmacro

    %macro epilogue 0
    mov		rsp, rbp
    pop		rbp
    %endmacro

    %macro exit 0
    mov		rax, 60             ; syscall for exit
    mov		rdi, 0              ; exit code 0
    syscall
    %endmacro

    %macro call_printf 2
    mov		rax, 0              ; no registers involved
    mov		rdi, %1             ; first argument for printf
    mov		rsi, %2             ; second argument for printf
    call	printf              ; call the function
    %endmacro

    %macro printf_float 2
    mov		rax, 1              ; 1 register used
    mov		rdi, %1
    movq	xmm0, %2
    call	printf
    %endmacro

    section .data
msg:
    db "uwu", 0
fmtstr:
    db "A string: %s", 0xa, 0
num:
    dd 1234
fmtint:
    db "A number: %d", 0xa, 0
pi:
    dq 3.1416
fmtflt:
    db "A float: %lf", 0xa, 0

    section .bss

    section .text
    extern printf            ; declare the function as external
; use flag '-no-pie' to link with gcc
    global main
main:
    prelude

    call_printf		fmtstr, msg
    call_printf		fmtint, [num]
    printf_float	fmtflt, [pi]

    epilogue
    exit
