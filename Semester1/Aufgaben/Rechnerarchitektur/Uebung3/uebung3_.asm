; Rechnerarchitektur
; Übung 3
;
; Andreas Timmermann, Shima Shahadifar
; MtrNr: 4994606, 5018598
; Gruppe 2

section .text			; Codesegment
global fibonacci		; die Funktion 'fibonacci' global setzen
fibonacci:
	mov	rax,rdi			; holen des 1. parameters
	mov	rbx,rsi			; holen des 2. parameter
	cmp	rdx,0
	je	end
loop1:
	mov	rcx,rax			; nächten Wert berechnen
	add	rax,rbx
	mov	rbx,rcx
	dec	rdx				; --n
	jne	loop1			; loop
end:
	ret
