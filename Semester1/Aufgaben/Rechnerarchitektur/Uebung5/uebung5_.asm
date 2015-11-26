; Rechnerarchitektur
; Übung 5
;
; Andreas Timmermann, Shima Shahadifar
; MtrNr: 4994606, 5018598
; Gruppe 2

;====================================	
section .text			; Codesegment
global square			; die Funktion 'square' global setzen
;====================================	
square:
	mov	rbx,rdi			; rax = value
	mov	rax,0			; rbx = 0
loop:
	mov	rcx,rbx			; rcx = b
	sub	rcx,rax			; b - a
	jge weiter
	neg rcx
weiter:
	cmp rcx,1
	jle	end
	add	rbx,rax
	shr rbx,1
	mov rax,rdi
	xor	rdx,rdx
	idiv rbx
	jmp loop
end:
	cmp rax,rbx
	jg	lower
	mov	rax,rbx
lower:
	ret
;====================================	

