;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese
;Problem 3
section .text
global quadsqrt
quadsqrt: 	
	mov rsi,rdi 	;rsi entspricht a, rdi entspricht value, hier 1.Zeile PseudoCode a=value
	mov r15,0	;r15 entspricht b, 2.Zeile PseudoCode b=0
loop:			;Adresse, die auch dem Start der While-Schleife entspricht
	mov rbx,rsi	;damit rsi, also a unverändert bleibt, wird rsi in rbx verschoben
	sub rbx,r15	;entspricht a-b ergebnis wird in a(rbx)gespeichert
	cmp rbx,0	;rbx, also das ergebnis von a-b wird mit null verglichen
	ja grNullBetrag ;falls rbx größer als Null ist soll zur angegebenen Adresse gesprungen werden
	neg rbx		;in allen anderen Fällen bedeutet das, dass rbx negativ ist und daher negiert werden muss um den Betrag zu erhalten
grNullBetrag:		;hier springt assembler hin, wenn rbx von anfang an positiv oder 0 ist
	cmp rbx,1	;hier wird der Betrag von a-b mit 1 verglichen, die Bedingung der while schleife
	jbe end		;ist a-b kleiner oder gleich eins, soll zum ende des Programms gesprungen werden, mit der adresse "end"
	add rsi,r15	;ansonsten ist die Bedingung der While-Schleife wahr, also a=a+b -  entspricht dieser Zeile
	mov rax,rsi	;rsi wird in rax kopiert, damit später rsi(a) hier schon (a+b) durch 2 geteilt werden kann
	mov rdx,0	;rdx wird zur sicherheit auf Null gesetzt
	mov rbx,2	;rbx wird eine 2 zugewiesen, damit nachher durch 2 geteilt wird
	idiv rbx	;hier wird dann (a+b)/2, das ergebnis wird in rax gespeichert
	mov rsi,rax	;a=rbx gesetzt, bekommt also den neuen wert zugewiesen
	mov rax,rdi	;hier wird wieder die div-Funktion vorbereitet, in rax wird der value bewegt
	mov rdx,0	;rdx wird wieder sicherheitshalber auf Null gesetzt
	idiv rsi	;hier wird durch rsi, also a geteilt, und zwar der Wert der in rax steht, also value -> value/a
	mov r15,rax	;der neue Wert der grade berechnet wurde wird b zugewiesen -> b=value/a
	jmp loop	;es soll immer zu der adresse loop gesprungen werden, hier endet die while schleife
end:			
	mov rax,rsi	;rsi, also a wird nach rax kopiert, in das Ausgaberegister
	cmp rsi,r15	;rsi(a) wird mit r15(b) verglichen, r15 ist der Vergleichswert
	jbe rsikleinergleich	;wenn rsi(a)kleiner oder gleich b ist, wird an die angegebene adresse gesprungen
	mov rax,r15	;ist r15(b) allerdings kleiner als rsi(a), wird r15 nach rax bewegt, so dass der Ausgabewert geändert wird
rsikleinergleich:
	ret
