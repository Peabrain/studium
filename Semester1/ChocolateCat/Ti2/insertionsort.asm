;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text

global insertionsort

insertionsort:
		mov rax,1
		mov rcx,1
		mov rbx,1
		dec rsi
		cmp rcx,1
		je sameElem
	newElem:
			cmp rcx,rbx
			je rightpos
			mov r15,[rdi+rcx]
		swap1:
			mov r13,[rdi+rcx-1]
			mov [rdi+rcx],r13
			dec rcx
			cmp rcx,rbx
			jne swap1
			mov [rdi+rbx],r15
		rightpos:
			inc rcx
			mov rax,rcx
			mov rbx,rcx
		sameElem:
				mov r12,[rdi+rax]
				mov r11,[rdi+rax-1]
				cmp r11,r12
				jge a
				dec rbx
			a:
				dec rax
				cmp rcx,rsi
				jne sameElem
				ret

