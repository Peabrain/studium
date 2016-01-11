section .data

	msg:
		db '\"Hello, World!"\', 10
	msglen: equ $ - msg

global _start
section .text
_start:

	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, msglen
	syscall
	mov eax, 60
	XOR rdi, rdi
	syscall
