;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese
;Problem 4
section .text			;zeigt an, dass hier der Code beginnt	
global gauss			;ermöglicht es das programm "gauss" von zB dem C programm aufrufen zu lassen
gauss:				;hier beginnt der Programm code für das Programm "gauss"
	mov rdx,0		;rdx wird auf Null gesetzt
	mov rbx,rdi		;der über den C wrapper eingegebene Wert der in rdi ist, wird in rbx kopiert
	cmp rbx,0		;cmp verglicht rbx mit 0, es ist die Abbruchbedingung für den loop
	loop:			;hier beginnt die Schleife
		add rdx,rbx	;rdx und rbx werden addiert, der Endwert wird in rdx gespeichert
		dec rbx		;rbx wir um eins verkleinert
		jnz loop	;hier ist das Schleifenende, assembler springt wieder zum Schleifenbeginn "loop:"
	mov rax,rdx		;rdx wird in das Rückgabe Register rax kopiert
	ret			;rax wird ausgegeben und der errechnete Wert an den C-Wrapper weitergegeben
;die Schleife wird also so lange ausgeführt bis rbx, also die eingegebene Zahl, = 0 ist.
;Damit rbx Null wird, wird am Ende der Schleife rbx jedes mal um eins verkleinert.
;Um die Gausssche Summe zu errechnen, setzte ich rdx erstmal auf Null
;und verwende es dann als das Register in dem die Summe gespeichert wird.
;Addiert wird immer in der Schleife "loop", und zwar wird rbx zu rdx addiert,
;rbx ist dabei gleichzeitig die Zahl der Abbruchbedingung.
