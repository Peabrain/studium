;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text

global insertionsort

insertionsort:
		mov rcx,1
	searchnewplace:
		mov rbx,rcx
		mov al,[rdi+rcx]
	searchpace:
		cmp rbx,0
		je through
		mov bl,[rdi+rbx-1]
		dec rbx
		cmp bl,al
		jg searchplace
	through:
		mov rax,rcx
	swapchars:
		mov cl,[rdi+rax-1]
		mov [rdi+rax],cl
		dec rax
		cmp rax,rbx
		jne swapstring
		mov [rdi+rbx],al
		inc rcx
		cmp rcx,rsi
		jne searchnewplace
		ret
