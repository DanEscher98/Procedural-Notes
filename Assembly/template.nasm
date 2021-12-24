    BITS 64

    %macro prelude 0
    push rbp
    mov rbp, rsp
    %endmacro

    %macro epilogue 0
    mov rsp, rbp
    pop rbp
    %endmacro

