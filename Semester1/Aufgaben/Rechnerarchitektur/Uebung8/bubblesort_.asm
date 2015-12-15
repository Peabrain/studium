; Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text

; veröffentlichen der operatoren, des ergebnis und funktionseinsprünge

global bubblesort

bubblesort:; rdi buffer, rsi elementnum
	dec	rsi
	mov	rcx,rsi
.loop2:
	mov	rdx,0
	mov	rsi,rcx
	mov	eax,[rdi + rsi * 4]
.loop1:
	mov	eax,[rdi + rsi * 4]
	mov	ebx,[rdi - 4 + rsi * 4]
	cmp eax,ebx
	jge	.loop
	mov	[rdi + rsi * 4],ebx
	mov	[rdi - 4 + rsi * 4],eax
	mov	eax,ebx
	or	rdx,1
.loop:
	dec	rsi
	jne .loop1
	dec	rcx
	add	rdi,4
	and	rdx,1
	jne	.loop2
	ret
