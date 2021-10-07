; ## Directives #######################
		bits		64
		global		main

; ## Macros ###########################
%macro	prelude 0
		push		rbp
		mov			rbp, rsp
%endmacro

%macro	epilogue 0
		mov			rsp, rbp
		pop			rbp
%endmacro

%macro	exit 0
		mov			rax, 60
		mov			rdi, 0
		syscall
%endmacro

%macro	putStr 2
		mov			rax, 1		; syscall			(write)
		mov			rdi, 1		; file descriptor	(stdout)
		mov			rsi, %1		; first  arg
		mov			rdx, %2		; second arg
		syscall
%endmacro

%macro	putLn 2
		putStr		%1, %2
		mov			rax, 1
		mov			rdi, 1
		mov			rsi, NL
		mov			rdx, 1
		syscall
%endmacro

; ## Constants ########################
		section		.data
msg :	db			"Hello!", 0
len :	equ			$-msg-1
NL  :	db			0xa

; ## Variables ########################
		section		.bss

; ## Code #############################
		section		.text
main:
		prelude
		
		putLn		msg, len

		epilogue
		exit
