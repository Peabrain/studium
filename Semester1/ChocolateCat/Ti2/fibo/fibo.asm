;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text


global fib

fib:
		mov rax,0
		mov rbx,1
		cmp rdi,2
		jz endz
		jbe end
		call fibr
	end:
		mov rax,rbx
	endz:
		ret

fibr:
		cmp rdi,1
		je recEnd
		dec rdi
		call fibr
		mov rcx,rax
		add rax,rbx
		mov rbx,rcx
	ret
	recEnd:
		mov rbx,1
		mov rax,1
	ret
