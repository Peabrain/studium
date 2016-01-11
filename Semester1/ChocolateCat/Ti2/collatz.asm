;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese
;Problem 3
section .text
global collatz
collatz:
	mov rsi,0	;rsi steht hier für den Index i und wird auf Null gesetzt
	whilekgr1:	;Adresszeile, mithilfe derer das while k>1 uas dem Pseudo-Code simuliert wird
		cmp rdi,1	;rdi wird mit 1 verglichen, rdi entspricht k,hier gesetzte Flags werden nur für die nächste Zeile benötigt
		jbe end		;falls rdi >=1 ist springt assembler zur adresse "end" kurz vorm Ende des Programms
		inc rsi		;der Index i bzw, das Register rsi wird um eins erhöht
		mov rbx,2	;rbx wird für den folgenden div-Befehl als Teiler benötigt, hier 2 um gerade/ungerade zu überprüfen
		mov rdx,0	;rdx speichert für den folgenden div-Befehl den Rest, zur Sicherheit auf Null setzen
		mov rax,rdi	;der div Befhel speichert das Ergbnis in rax, und berechnet es indem rax=rax/rbx rest rdx
		div rbx		;der in rax gespeicherte wert wird durch rbx geteilt, rdi also k bleibt unverändert
		cmp rdx,0	;hier wird überprüft ob der Rest aus der Division Null ist, also rdi gerade ist
		jne kuneven	;ist rdi ungerade, also rdx nicht gleich 0, springt assembler zur adresse "kuneven"
		mov rdi,rax	;ist rdi, allerdings gerade(rdx=0),soll k=k/2, da das bereits berechnet wurde,muss rax in rdi kopiert werden
		jmp whilekgr1	;sobald ds Programm hier ankommt, soll es an die angegebene Adresse springen
		kuneven:	;sozusagen das else aus dem Pseudo-Code, die Adresszeile für den jne ob k gerade/ungerade
			mov rax,3	;rax wird auf 3 gesetzt,weil if k ungerade then k= k*3+1
			mul rdi		;rdi wird mit dem in rax stehenden wert multipliziert, ergebnis steht in rax
			mov rdi,rax	;das ergebnis der multiplikation wird aus rax in rdi(k)kopiert
			inc rdi		;k bzw rdi wird um eins vergrößert
		jmp whilekgr1		;hier wird wieder zur angegebenen Adresse gesprungen
	end:		
	mov rax,rsi	;da rax das Ausgabe register ist, und i ausgegeben werden soll, wird rsi in rax verschoben
	ret
		
