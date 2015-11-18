; Rechnerarchitektur
; Übung 2
;
; Andreas Timmermann, Shima Shahadifar
; MtrNr: 4994606, 5018598
; Gruppe 2

section .text			; Codesegment
global gauss			; die Funktion 'gauss' global setzen
gauss:
	mov	rax,rdi			; laden des Übergabewertes in rax
	mul	rdi				; rax *= rdi
	add	rax,rdi			; rax += rdi
	shr	rax,1			; rax >> 1
	ret
