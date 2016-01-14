;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text

global insertionsort

insertionsort:
		dec rsi
		mov r11,1
	searchnewplace:
		mov r12,r11
		mov al,[rdi+r11]
	searchplace:
		mov bl,[rdi+r12-1]
		cmp bl,al
		jl through
		dec r12
		jnz searchplace
	through:
		mov r13,r11
	swapchars:
		mov cl,[rdi+r13-1]
		mov [rdi+r13],cl
		dec r13
		cmp r13,r12
		jge swapchars
		mov [rdi+r12],al
test:	inc r11
		cmp r11,rsi
		jne searchnewplace
		ret
