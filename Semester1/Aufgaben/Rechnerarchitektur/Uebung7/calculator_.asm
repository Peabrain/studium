; Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text

; veröffentlichen der operatoren, des ergebnis und funktionseinsprünge

global operator
global operation
global result
global calculate

calculate:
	mov 	rcx,rdi
	xor		rdx,rdx
	movsd	xmm0,[operator]
loop:
	mov		al,[operation + rdx]
	inc		rdx
	cmp		al,'+'
	jne 	noadd
	addsd	xmm0,[operator + rdx * 8]
	jmp		nosub
noadd:
	subsd	xmm0,[operator + rdx * 8]
nosub:
	dec		rcx
	jnz		loop
	movsd	[result],xmm0
	ret

section	.bss
operator:	resq 16
operation:	resb 16
result:		resq 1
