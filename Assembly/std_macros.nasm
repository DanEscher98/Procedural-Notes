%macro Prelude 0
push   rbp
mov    rbp, rsp
%endmacro

%macro Epilogue 0
mov    rsp, rbp
pop    rbp
%endmacro

%macro Exit 0
mov    rax, 60; syscall for exit
mov    rdi, 0; exit code 0
syscall
%endmacro

	section .data
	STDOUT  equ 1
