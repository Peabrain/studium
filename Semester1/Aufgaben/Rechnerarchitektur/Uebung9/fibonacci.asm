extern	printf
extern	atoi

global main

section .data
	int_store:	db "%lu",10, 0
	str_store:	db "%s",10, 0

section .text

main:
	cmp	rdi,2
	jne	.end
	push	rsi
	mov		rdi,[rsi + 8]
	call 	atoi
	mov	rsi,rax
	mov	rdi,int_store
	call printf_int
	pop	rsi
	mov	rdi,rax
	call	fibonacci

	mov	rsi,rax
	mov	rdi,int_store
	call printf_int	
.end:
	ret

fibonacci:
	cmp rdi,2
	je .start1
	dec	rdi
	call fibonacci
	mov	rcx,rax
	add	rax,rbx
	mov	rbx,rcx
	ret
.start1:
	mov	rbx,1
	mov	rax,1
	ret

printf_int:
	push rbp		; bisschen was auf den stack retten
	push rax
	mov	rax,0		; keine xmm register
    call printf		; Call C funktion printf
	pop rax			; wieder sachen aus dem stack holen
	pop	rbp
	ret

printf_string:
	push rbp
	mov	rax,0
	call printf
	pop	rbp
	ret
