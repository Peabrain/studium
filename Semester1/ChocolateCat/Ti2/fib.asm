;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese
;Problem 3
section .text
global fib
fib:
	mov rdx,1		;rdx steht für x1 und wird auf 1 gesetzt
	mov rbx,0		;rbx steht für x2 und wird auf 0 gesetzt
	mov rax,0		;rax wird auf 0 gesezt im pseudocode k
	cmp rdi,0		;rdi, der Eingabewert n wird mit 0 verglichen
	jz nZero		;wenn die ZeroFlag gesetzt ist springt assembler an das Ende des Programms und gibt den Startwert von rax zurück
	loop:			;beginn de Schleife in der die fibonacciZahl berechnet wird
		mov rax,rdx	;rdx wird in rax kopiert, also k=x1
		add rax,rbx	;n rax wird das ergebnis von rax+rbx gespeichert also k=k+x2, da vorher k=x1 gleich k=x1+x2
		mov rdx,rbx	;rbx wird in rdx kopiert also x1=x2
		mov rbx,rax	;rax wird in rbx kopiert, also x2=k, im nächsten durchlauf ist x2 dann das alte k
		dec rdi		;rdi, also n wird um eins verkleinert
		jne loop	;solange n nicht gleich Null ist, wird alles ab loop bis jne loop wiederholt
	nZero:			;Adresse zu der gesprungen wird wenn n gleich Null ist im ersten durchlauf
	ret			;rax wird an den c wrapper zurückgegeben
;der loop wird so lange wiederholt, bis n gleich Null ist, ist n null wird rax, also k zurückgegeben


