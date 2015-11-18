// Rechnerarchitektur
// Übung 2
//
// Andreas Timmermann, Shima Shahadifar
// MtrNr: 4994606, 5018598
// Gruppe 2

#include <stdio.h>

unsigned int gauss(int);										// Deklaration der Assemblerfunktion

int	main()
{
	unsigned int	iZahl = 5;									// Definieren der Variable für die Zahl von der wir die Gausszahl berechnen wollen
	unsigned int	iGauss = 0;									// Definieren der Variable für die Gauszahl

	iGauss = gauss(iZahl);										// Anspringen der Assemblerfunktion mit übergabe der Zahl. Rückgabewert in iGauss

	printf("Die Gausszahl von %u ist %u.\n",iZahl,iGauss);		// Ausgabe der Gausszahl
	return 0;
}

