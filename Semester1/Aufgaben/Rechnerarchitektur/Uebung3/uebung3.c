// Rechnerarchitektur
// Übung 3
//
// Andreas Timmermann, Shima Shahadifar
// MtrNr: 4994606, 5018598
// Gruppe 2

#include <stdio.h>
#include <time.h>

#define	BENCHMARK_NUM	10000000						// Benchmark Fibonacci Durchläufe

long int fibonacci(long int,long int,int);								// Deklaration der Assemblerfunktion

long int fibonacci_c(long int iF1,long int iF2,int iN)					// Fibonacci C Funktion
{
	int i;
	long int a = 0;
	for(i = 0;i < iN;++i)
	{
		a = iF2;
		iF2 = iF1 + iF2;
		iF1 = a;
	}
	return a;
}
int	main()
{
	clock_t start_t, end_t;											// Timervariablen definieren
	double total_t;

	int i;															// Einige Variablen definieren
	unsigned int	iN = 50;
	long int	iF1 = 0,iF2 = 1;
	long int	iRet = 0,iRet_a = 0;

	if(iN != -1)														// Abfragen, ob die Länge der Fibonaccirekursion größer als 0 ist
	{																	// wenn ja, dann ...
		iRet = fibonacci_c(iF1,iF2,iN);									// C Funktion anspringen um die Fibonaccizahl zu berechnen
		iRet_a = fibonacci(iF1,iF2,iN);									// Assemblerroutine anspringen um die Fibonaccizahl zu berechnen

		printf("Die Fibonaccizahl von %lu und %lu mit %u Schritten ist %lu (%lu).\n",iF1,iF2,iN,iRet,iRet_a);		// Ausgabe der Fibonaccizahl

		printf("Benchmark\n");
		printf("=========\n");
		start_t = clock();												// ersten Timer nehmen
		for(i = 0;i < BENCHMARK_NUM;i++) iRet = fibonacci_c(iF1,iF2,iN);// Benchmark mit der C Funktion durchführen
		end_t = clock();												// zweite Zeit nehmen
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;			// Differenz der Zeiten berechnen
		printf("CPU-Zeit: %f, Fibonacci-Berechnung in C\n", total_t);	// Ausgabe

		double o;
		start_t = clock();												// Das Selbe nochmal für die Assemblerroutine
		for(i = 0;i < BENCHMARK_NUM;i++) iRet = fibonacci(iF1,iF2,iN);
		end_t = clock();
		o = total_t;													// Kurz noch die Zeit der C Funktion zwischenspeichern
		total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		printf("CPU-Zeit: %f, Fibonacci-Berechnung in Assembler\n", total_t);
		printf("Das Assemblerprogramm ist %f mal schneller, als das C Programm\n",o/total_t);	// und noch den Geschwindigkeitsfaktor ausgeben
	}
	else
		printf("Fehlerhafte Durchgangsanzahl.\n");						// ein Fehler ist aufgetreten.

	return 0;
}

