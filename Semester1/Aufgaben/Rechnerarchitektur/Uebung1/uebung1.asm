; Rechnerarchitektur
; Übung 1

; Andreas Timmermann
; MtrNr: 4994606
; Gruppe 2

Section .Data						; anlegen der Data-Section
	msg:	db 'Hello World',10		; deklarieren des labels 'msg' und anlegen des Datenstrings 'Hello World'. Am Ende noch das '\n' (new line)
	msglen: equ $-msg				; ausrechnen des Länge von msglen bis msg

Global	_start						; das Label _start als Global deklarieren
Section .text						; anlegen der Code-Section
_start:								; anlegen des Labels '_start'
	mov rax,1						; laden rax mit 1. Parameter für syscall. rax = welcher syscall soll angesprungen werden (1 = schreiben auf ein Device)
	mov rdi,1						; laden rdi mit 1.           ="=        . rdi = ausgabedevice (1 = standartausgabedevice)
	mov rsi,msg						; laden rsi mit msg.         ="=        . rsi = adresse des Buffers wo die Daten liegen, die ausgegeben werden sollte
	mov rdx,msglen					; laden rdx mit msglen       ="=        . rdx = Länge der auszugebenen Daten
	syscall							; syscall anspringen

	mov eax,60						; laden rax mit 1. Parameter für syscall. rax = welcher syscall soll angesprungen werden (60 = exit)
	xor rdi,rdi						; löschen von rdi.           ="=        . rdi = Fehlercode
	syscall							; syscall anspringen
