.section .text
.global _start

.macro exit_program, status
  mov r0, #\status        @ Load the exit status code
  mov r7, #1              @ syscall number for sys_exit
  svc #0                  @ invoke syscall
.endm

_start:
  mov r0, #1                @ File descriptor 1: stdout
  ldr r1, =message          @ Load address of the message
  ldr r2, =len              @ Load length of the message
  mov r7, #4                @ syscall number for sys_write
  svc #0                    @ invoke syscall

  exit_program 0            @ Exit the program with status code 0

message:
  .ascii "Hello, World!\n"

len = . - message           @ Calculate the length of the message

