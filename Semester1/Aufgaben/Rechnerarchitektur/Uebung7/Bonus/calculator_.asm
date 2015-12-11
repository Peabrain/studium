; Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section	.data
scanstring:	db	"%lf",0

section .text

; veröffentlichen der operatoren, des ergebnis und funktionseinsprünge

global	formel
global	result
global	calculate

extern sscanf

calculate:
		call	convert_formel
		mov		eax,0
		mov		[nextFreeState],eax
		mov		rdi,formel_2
		call	process
		ret
convert_formel:
		mov		rdi,formel
		call	getStrLen
		mov		rsi,0
		mov		rbx,rsi
.loop:	mov		dl,[rdi + rsi]
		mov		[rdi + rbx],dl
		cmp		dl,' '
		je		.weiter
		inc		rbx
.weiter:
		inc		rsi
		cmp		rsi,rax
		jne		.loop
		mov		dl,0
		mov		[rdi + rbx],dl

		call	getStrLen
		mov		rsi,formel_2
		mov		rcx,0
		mov		rbx,rcx
.loop1:
		mov		dl,[rdi + rcx]
		mov		[rsi + rbx],dl
		cmp		dl,'-'
		jne		.nominus
		mov		dl,[rsi + rbx - 1]
		cmp		dl,'*'
		jne		.nomul
		mov		dl,'-'
		mov		[rsi + rbx],dl
		jmp		.nominus
.nomul:
		cmp		dl,'+'
		je		.nominus
		mov		dl,'+'
		mov		[rsi + rbx],dl
		inc		rbx
		mov		dl,'-'
		mov		[rsi + rbx],dl
.nominus:
		inc		rcx
		inc		rbx
		cmp		rcx,rax
		jne		.loop1
		mov		dl,0
		mov		[rsi + rbx],dl
		
		
		ret

;char formel_2[1024];
;int len = strlen(formel);
;int j = 0;
;for(i = 0;i < len;i++)
;{
;	formel_2[j] = formel[i];
;	if(formel[i] != ' ') j++;
;}
;formel_2[j] = 0;
;printf("%i, %s\n",j,formel_2);
;len = strlen(formel_2);
;j = 0;
;for(i = 0;i < len;i++,j++)
;{
;	formel[j] = formel_2[i];
;	if(formel_2[i] == '-' && formel_2[i-1] != '*' && formel_2[i-1] != '+') { formel[j++] = '+';formel[j] = '-';}
;	else
;	if(formel_2[i] == '-' && formel_2[i-1] == '*') { formel[j] = '-';}
;}

process:
		call	translate_asm
		mov		rdi,0
		mov		rax,0
		movq	xmm0,rax
		movq	xmm1,rax
		push 	rdi
		call	processing
		pop 	rdi
		movsd	[result],xmm1
		ret
	
processing: ; stateIdx = rdi
		push 	rax
		mov		bl,al
		mov 	al,[List_operation + edi]
		cmp 	al,0
		jne 	.nozero
		movsd	xmm1,[List_value + edi * 8]
		jmp 	.return
.nozero:
		push	rdi
		mov 	edi,[List_left + edi * 4]
		call 	processing
		pop		rdi
		movq	rcx,xmm1
		push	rcx
		push	rdi
		mov 	edi,[List_right + rdi * 4]
		call	processing
		movq	xmm0,xmm1
		pop		rdi
		pop		rcx
		movq	xmm1,rcx

		cmp 	al,'*'
		jne 	.nomul
		mulsd 	xmm1,xmm0
		jmp 	.return
.nomul:
		cmp 	al,'+'
		jne 	.noplus
		addsd 	xmm1,xmm0
		jmp 	.return
.noplus:
.return:	
		pop 	rax
		ret
	
getStrLen: ; rdi formel
		push	rdi
		push	rbx
		mov		rax,0
.loop:	mov		bl,[rdi + rax]
		cmp		bl,0
		je		.end
		inc		rax
		jmp		.loop
.end:	
		pop		rbx
		pop		rdi
		ret
getNextOp:	;rdi formel
			;rax pos
			;rbx prio
			;rcx len
		push	rcx
		push	rdi
		push	rbx
		push	rdx
		push	rsi
		call 	getStrLen
		mov		rcx,rax		; strlen
		mov		rax,-1		; pos
		mov		rsi,1
		mov		rbx,100		; prio
.loop:	mov		dl,[rdi + rsi]
		cmp		dl,'+'
		je		.plusminus
		cmp		dl,'*'
		jne		.next
		cmp		rbx,1
		jle		.next
		mov		rbx,1
		mov		rax,rsi
		jmp 	.next
.plusminus:
		cmp		rbx,0
		jle		.next
		mov		rbx,0
		mov		rax,rsi
.next:
		inc		rsi
		cmp		rsi,rcx
		jl		.loop
		pop		rsi
		pop		rdx
		pop		rbx
		pop		rdi
		pop		rcx
		ret
;	int pos = -1,i;
;	int prio = 100;
;	int len = strlen(formel);
;	for(i = 1;i < len;i++)
;	{
;		char op = formel[i];
;		switch(op)
;		{
;			case '+': // prio 0
;			case '-':
;			{
;				if(prio > 0)
;				{
;					pos = i;
;					prio = 0;
;				}
;			}break;
;			case '*': // prio 1
;			{
;				if(prio > 1)
;				{
;					pos = i;
;				}
;			}break;
;		}
;	}
;	return pos;

translate_asm: ; rdi formel
		push	rdi
		push	rax
		push	rbx
		call	getNextOp	; rax return pos
		cmp		rax,-1
		je		.getvalue
		mov		ebx,[nextFreeState]
		mov		dl,[rdi + rax]
		mov		[List_operation + ebx],dl
		xor		dl,dl
		mov		[rdi + rax],dl
		inc		ebx
		mov		[nextFreeState],ebx
		dec		ebx
		mov		ecx,[nextFreeState]
		mov		[List_left + ebx * 4],ecx
		call	translate_asm

		mov		ecx,[nextFreeState]
		mov		[List_right + ebx * 4],ecx		
		add		rdi,rax
		inc		rdi
		call	translate_asm
		jmp		.end
.getvalue:
		call	convert
		mov		rax,[result]
		mov		ecx,[nextFreeState]
		mov		dl,0
		mov		[List_operation + ecx],dl
		mov		[List_value + ecx * 8],rax
		inc		ecx
		mov		[nextFreeState],ecx
.end:
		pop		rbx
		pop		rax
		pop		rdi
		ret
convert:
		push	rdi
		push	rsi
		push	rax
		mov		rsi, scanstring
		mov		rdx, result
		mov		al, 0 ; number of arguments in SSE
		call	sscanf
		pop		rax
		pop		rsi
		pop		rdi
		ret
;void translate(char *formel)
;{
;	int i;
;	int	pos = getNextOp(formel);
;	if(pos != -1)
;	{
;		int thisn = nextFreeState;
;		List_operation[thisn] = formel[pos];
;		formel[pos] = 0;
;		nextFreeState++;

;		List_left[thisn] = nextFreeState;
;		translate(formel);
;		List_right[thisn] = nextFreeState;
;		translate(formel + pos + 1);
;	}
;	else
;	{
;		convert(formel);
;		printf("%s\n",formel);
;		List_operation[nextFreeState] = 0;
;		List_value[nextFreeState] = result;
;		nextFreeState++;
;	}
;}

section	.bss
result:		resq 1

List_operation:	resb 	256
List_left:		resd	256
List_right:		resd	256
List_value:		resq	256
nextFreeState:	resd	1
formel:			resb	1024
formel_2:		resb	1024
