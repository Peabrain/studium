;Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

section .text


global fib

fib:
		mov rax,0	
		mov rbx,1
		cmp rdi,0
		je endz
		cmp rdi,2
		jbe end
		call fibr
	end:
		mov rax,rbx
	endz:
		ret
;das Hauptprogramm fib überprüft ob n kleiner gleich 2 ist, also ob die gesuchte fibonaccizahl 0,1,2 ist
;als erstes wird überprüft ob n gleich Null ist, in diesem Fall springt das Programm zur Adresse "endz" was, das Ende des Programmes ist und gibt 0 aus, da rax anfangs auf 0 gesetzt wurde
;ist n gleich 1 oder 2 ist die Auszugebende fibonaccizahl 1 dafür setzte ich rbx am anfang des Hauptprogrammes auf 1;
;weil rbx nach rax als ausgabewert festgelegt ist, ist rbx auch der Ausgabewert vom Unterprogramm, das hinter dem Hauptprogramm steht
;die adresse "end" steht vor dem mov befehl, bei dem rax=rbx , für den Fall, dass n=1 oder n=2 wird der ursprüngliche rbx wert ausgegeben, ansonsten der vom Unterprogramm ausgegebene
;ist n>2, wird im Hauptprogramm, der call ausgeführt, der das Unterprogramm aufruft, dass die n-te fibo Zahl rekursiv berechnet

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

;"fibr"ist das Unterprogramm, das vom Hauptprogramm zur Berechnung von fiboZahlen aufgerufen wird
;die Abbruchbedingung, also der rekursionsanker hier, ist, dass n=1 ist, in dem fall springt das programm an das zweite ende und rbx und rax werden auf 1 gesetzt
;ansonsten wird rdi immer um eins verkleinert und das Programm ruft sich selber mithilfe eines calls neu aufgerufen und gibt den errechneten Wert in rbx zurück
;dadurch ergibt sich eine Verschachtelung mithilfe derer die nte Fibonacci Zahl errechnet wird, ausgehend von der 1. und 2. Fibonaccizahl, die beide den Wert 1 haben, dabei wird der alte Wert von n in rcx gerettet und n mit n-1 addiert, am ende wird der wert von n+1 in rax gespeichert und der wert von n wird am ende in rbx gespeichert und ausgegeben

