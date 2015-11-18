; Rechnerarchitektur
; Übung 4
;
; Andreas Timmermann, Shima Shahadifar
; MtrNr: 4994606, 5018598
; Gruppe 2

extern	printf
;====================================	
section .text			; Codesegment
global collatz			; die Funktion 'collatz' global setzen
;====================================	
collatz:
;<--- some printings ---->
	push rdi
	mov rdi,str_store
	mov rsi,string1
	call printf_string
	pop rdi
;<--- end printings ---->
	mov	rax,0
lo1:
	cmp	rdi,1
	jle	ende
	inc	rax
;<--- some printings ---->
	push rdi
	mov	rsi,rdi		; put "a" from store into register
	mov	rdi,int_store
	call printf_int
	pop rdi
;<--- end printings ---->
	mov	rbx,rdi
	and	rbx,1
	jne	i1
	shr	rdi,1
	jmp i2
i1:
	mov	rbx,rdi
	add	rdi,rdi
	add	rdi,rbx
	inc	rdi
i2:
	jmp	lo1
ende:
;<--- some printings ---->
	push rax
	mov	rsi,rdi
	mov	rdi,int2_store
	call printf_int

	mov rdi,str_store
	mov rsi,nline
	call printf_string
	pop rax
;<--- end printings ---->
	ret
;====================================	
printstart:
	push rax
	push rdi
	mov rax,1
	mov rdi,1
	syscall
	pop	rdi
	pop	rax
	ret
;====================================	
printf_int:
	push rbp		; bisschen was auf den stack retten
	push rax
	mov	rax,0		; keine xmm register
    call printf		; Call C funktion printf
	pop rax			; wieder sachen aus dem stack holen
	pop	rbp
	ret
;====================================	
printf_string:
	push rbp
	mov	rax,0
	call printf
	pop	rbp
	ret
;====================================	
section .data	; Datasegment
string1:		db "collatz in asm",10,"==============",10,0
string1len: 	equ $-string1
int_store: 		db "%lu,", 0
int2_store: 	db "%lu", 0
str_store: 		db "%s", 0
nline:			db 10, 0
nlinelen:	 	equ $-nline
;====================================	
