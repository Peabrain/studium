; Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text

; veröffentlichen der operatoren, des ergebnis und funktionseinsprünge

global bubblesort

buublesort:; rdi buffer, rsi elementnum
	mov	rcx,0
	mov	eax,[rdi + rcx * 4]
.loop1:
	mov	ebx,[rdi + 4 + rcx * 4]
	cmp eax,ebx
	jge	.loop
	mov	ebx,[rdi + rcx * 4]
	mov	eax,[rdi + 4 + rcx * 4]
	mov	eax,ebx
.loop:
	inc	rcx
	cmp	rcx,rsi
	jne .loop1
	ret
