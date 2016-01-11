section .text
global test
test:
	mov rsi,0
	whilekgr1:
		cmp rdi,1
		jbe end
		inc rsi
		mov rbx,2
		mov rdx,0
		mov rax,rdi
		div rbx
		cmp rdx,0
		jne kuneven
		mov rdi,rax
		jmp whilekgr1
		kuneven:
			mov rax,3
			mul rdi
			mov rdi,rax
			inc rdi
		jmp whilekgr1
	end:
	ret
		
