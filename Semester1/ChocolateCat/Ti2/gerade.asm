section .text				; start Programm-Section
global ist_zahl_gerade		; setze die Funktion "ist_zahl_gerade" global

ist_zahl_gerade:			; Label "ist_zahl_gerade
	and rdi,1				; rdi = rdi ^ 1 (wenn Zahl gerade => rdi = 0, ansonsten rdi = 1)
	mov rax,rdi				; schreibe rdi in rax (Rückgabewert)
	ret						; Sprung zurück
