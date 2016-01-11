section .bss
stack: resq 64 ;reservieren von 64 dataquad-Registern(64*8Byte)
sp1: resq 1 ;dataquad reserviert ein 8-Byte Register,stackpointer = sp1

section .text

global init		
global top
global push
global pop
global isEmpty

init: 	mov rax,0	
		mov [sp1],rax
		ret
;init setzt den stackpointer auf Null, sodass der Stack 'leer' ist
;die noch in den Registern stehenden alten Werte sind unwichtig, da sie falls etwas in den STack kommt durch push überschrieben wird

top:	mov rdx,[sp1]
		dec rdx
		mov rax,[stack + rdx *8]	;holt den wert aus der adresse stack + rdx quadwörtern,der wert aus i=sp1
		ret
;top holt den inhalt des stackpointers, verkleinert diesen um 1 und holt den Wert des Registers an dieser Adresse raus, um diesen auszugeben

pop:	mov rdx,[sp1]
		dec rdx
		mov rax,[stack + rdx *8]	; hol den wert aus der adresse stack + rdx quadwörtern,der wert aus i=sp1
		mov [sp1],rdx
		ret
;pop gibt das erste/vorderste Element des Stacks aus und löscht dieses
	
push:	mov rdx,[sp1]
		mov [stack + rdx *8],rdi
		inc rdx
		mov [sp1],rdx
		ret
;push erweitert den Stack um ein Element
		
isEmpty:mov rdx,[sp1]
		cmp rdx,0
		mov rax,1
		jz empty
		mov rax,0
		empty:
		ret 
;isEmpty überprüft ob der Stackpointer größer als 0 ist und gibt wenn dies wahr ist 1 aus, ansonsten 0
		
