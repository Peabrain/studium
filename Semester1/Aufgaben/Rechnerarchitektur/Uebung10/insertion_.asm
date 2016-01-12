; Andreas Timmermann und Shima Shahadifar, Tutorium 02 bei Christoph Van Heteren-Frese

section .text

; veröffentlichen der operatoren, des ergebnis und funktionseinsprünge

global insertion

insertion:; rdi buffer, rsi elementnum
	dec	rsi
	dec	rsi
	mov	rax,1
.loop2:
	push rax
	mov	bl,[rdi + rax]
.loop1:
	mov bh,[rdi + rax - 1]
	cmp bl,bh
	jg	.nol
	mov [rdi + rax],bh
	dec rax
	jne .loop1
.nol:
	mov	[rdi + rax],bl
	pop	rax
	inc	rax
	dec	rsi
	jne .loop2
	ret
