; Rechnerarchitektur
; Übung 6
;
; Andreas Timmermann, Shima Shahadifar
; MtrNr: 4994606, 5018598
; Gruppe 2

;====================================
section .text			; Codesegment
global init			; die Funktion 'init' global setzen
global push			; die Funktion 'push' global setzen
global pop				; die Funktion 'pop' global setzen
global top				; die Funktion 'top' global setzen
global isEmpty			; die Funktion 'isEmpty' global setzen
;====================================
init:
	mov	rax,0
	mov	[stackpointer],rax
	ret
;====================================
push:
	mov	rdx,[stackpointer]
	mov [stackbuffer+rdx * 8],rdi
	inc rdx
	mov	[stackpointer],rdx
	ret
;====================================
pop:
	mov	rdx,[stackpointer]
	dec rdx
	mov rax,[stackbuffer+rdx * 8]
	mov	[stackpointer],rdx
	ret
;====================================
top:
	mov	rdx,[stackpointer]
	dec rdx
	mov rax,[stackbuffer+rdx * 8]
	ret
;====================================
isEmpty:
	mov	rax,[stackpointer]
	cmp rax,0
	jne	zero
	mov	rax,1
	ret
zero:
	mov	rax,0
	ret
;====================================
section .bss
stackpointer:	resq	1
stackbuffer:	resq	256

