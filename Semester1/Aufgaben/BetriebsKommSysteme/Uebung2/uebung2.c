//  Betriebs- und Kommunikationssysteme
//  Uebung 2
//	Aufgabe 2
//
//  Created by Andreas Timmermann on 31.10.15.
//	Matrikelnummer: 4994606
//	Gruppe 1

#include	<stdio.h>
#include	<stdbool.h>
#include	<ctype.h>
#include	<string.h>

#define TEXT_BUFFER_SIZE	100																			// maximale Textgroesse
#define CODE_BUFFER_SIZE	10																			// maximale Codegroesse

//==================================================================================
// Deklaration der Funktionen
//==================================================================================
bool ReadText(char *pBuffer,int iBuffersize);															// Einlesen eines Textes
void ConvertToPreCode(char *pString,int iStringsize);													// Konvertiert den Text in das vorgegebene Format
bool CheckPreCode(char *pString,int iStringsize);														// Testet einen Text auf das vorgegebene Format
void Coding(char *pString,int iStringsize,char *pChiffre,int iChiffresize,int EnDeCode);				// Ent- und verschluesselungsroutine
void MemClr(char *pBuffer,int size);
//==================================================================================
int	main()																								// main
{
	char cEingabemode = 0;																				// Definere eine Variable für den Verarbeitungsmodus

	printf("(k)lartext oder (v)erschuesselte eingabe?: ");												// Aufforderung zur Eingabe des Verarbeitungsmodus
	cEingabemode = getchar();																			// eingabe des Verarbeitungsmodus


	switch(cEingabemode)																				// Welcher Verarbeitungsmodus Verzweigung?
	{
		case 'v':																						// wenn verschluesselten Text entschluesseln
		{
			char sChiffreText[TEXT_BUFFER_SIZE + 1];													// Definiere den Textbuffer (+1, wegen der '0' am Ende)
			char sCodeText[CODE_BUFFER_SIZE + 1];														// Definiere den Codebuffer (+1, wegen der '0' am Ende)

			MemClr(sChiffreText,TEXT_BUFFER_SIZE + 1);													// Loeschen des Chiffrebuffer
			MemClr(sCodeText,CODE_BUFFER_SIZE + 1);														// Loeschen des Codebuffer

			printf("Bitte geben Sie den verschluesselten Text ein (maximal %d Zeichen): ",TEXT_BUFFER_SIZE);	// Aufforderung zur eingabe des verschluesselten Textes
			ReadText(sChiffreText,TEXT_BUFFER_SIZE +1);													// Einlesen des Textes
			if(!CheckPreCode(sChiffreText,strlen(sChiffreText)))										// Ueberpruefe den Text auf das vorgegebene Format
			{
				printf("!!! Falsches Format !!!\n");													// Fehlerhaftes Format
				break;																					// Abbruch
			}

			printf("Bitte geben Sie den Code ein (maximal %d Zeichen): ",CODE_BUFFER_SIZE);				// Aufforderung zur Eingabe des Codes
			ReadText(sCodeText,CODE_BUFFER_SIZE + 1);													// Einlesen des Codes
			if(!CheckPreCode(sCodeText,strlen(sCodeText)))												// Ueberpruefung des eingegebenen Codes
			{
				printf("!!! Falsches Format !!!\n");													// Fehlerhaftes Format
				break;																					// Abbruch
			}

			Coding(sChiffreText,strlen(sChiffreText),sCodeText,strlen(sCodeText),-1);					// Entschluesseln des Chiffres
			printf("Text (unverschluesselt)%s\n",sChiffreText);											// Ausgabe des enschluesselten Textes
		}break;																							// Ende der Verzweigung

		case 'k':																						// wenn Text verschluesselt werden soll
		{
			char sKlarText[TEXT_BUFFER_SIZE + 1];														// Definiere Textbuffer (+1, wegen der '0' am Ende)
			char sCodeText[CODE_BUFFER_SIZE + 1];														// Definiere Codebuffer (+1, wegen der '0' am Ende)

			MemClr(sKlarText,TEXT_BUFFER_SIZE + 1);														// Loeschen des Textbuffer
			MemClr(sCodeText,CODE_BUFFER_SIZE + 1);														// Loeschen des Codebuffer

			printf("Bitte geben Sie den Klartext ein (maximal %d Zeichen): ",TEXT_BUFFER_SIZE);			// Aufforderung zur Eingabe des Textes
			ReadText(sKlarText,TEXT_BUFFER_SIZE +1);													// Eingabe des Textes

			printf("Bitte geben Sie den Code ein (maximal %d Zeichen): ",CODE_BUFFER_SIZE);				// Aufforderung zur Eingabe des Codes
			ReadText(sCodeText,CODE_BUFFER_SIZE + 1);													// Einlesen des Codes
			if(!CheckPreCode(sCodeText,strlen(sCodeText)))												// Ueberpruefung des Codes
			{
				printf("!!! Falsches Format !!!\n");													// Fehlerhaftes Format
				break;																					// Abbruch
			}

			ConvertToPreCode(sKlarText,strlen(sKlarText));												// Umwandlung des Textes in das vorgegebene Format 
			printf("Text (konvertiert)%s\n",sKlarText);													// Ausgabe des Textes im vorgegebenen Format

			Coding(sKlarText,strlen(sKlarText),sCodeText,strlen(sCodeText),1);							// Verschluesselung des Textes
			printf("Text (verschluesselt)%s\n",sKlarText);												// Ausgabe des Textes
		}break;																							// Ende der Verzweigung
		default: printf("Fehlerhafte Eingabe!!!\n");break;												// Fehlerhafter Eingabemode
	}
	

	return 0;																							// Programmende
}
//==================================================================================
// Einlesen des Textes in den pBuffer
//==================================================================================
bool ReadText(char *pBuffer,int iBuffersize)
{
	freopen("/dev/tty", "rw", stdin);																	// Reopen der stdin (behebt einen kleinen Defekt mit dem '\n')
	if(fgets(pBuffer,iBuffersize,stdin) != NULL)														// Einlesen von der stdin in den Buffer
	{
		pBuffer[strlen(pBuffer) - 1] = 0;																// ueberschreiben des '\n' mit 0 am Ende des eingebenen Textes
		printf("eingelesener Text: %s\n",pBuffer);														// Ausgabe des Textes
		return true;																					// Beendigung mit true
	}
	return false;																						// Beendigung mit false
}
//==================================================================================
// Konvertiert einen Text in das vorgegebene Format
//==================================================================================
void ConvertToPreCode(char *pString,int iStringsize)
{
	int i,j = 0;																						// Definiere 2 Laufvariablen	
	for(i = 0;i < iStringsize;++i)																		// eine Schleife von i = 0 bis iStringsize
	{
		char a = pString[i];																			// hole das Zeichen an der Stelle i
		a = toupper(a);																					// Wandle das Zeichen in einen Grossbuchstaben, wenn noetig
		if((a >= 'A' && a <='Z') || (a >= '0' && a <='9'))												// Abfrage ob es ein Buchstabe oder eine Zahl ist,
			pString[j++] = a;																			// dann Schreibe diesen an die Stelle j und erhoehe j um 1
	}
	pString[j] = 0;																						// Schreibe am Ende des neuen Textes eine 0
}
//==================================================================================
// Ueberpruefung eines Textes auf das vorgegebene Format
//==================================================================================
bool CheckPreCode(char *pString,int iStringsize)
{
	int i;																								// Definiere eine Laufvariable
	for(i = 0;i < iStringsize;++i)																		// Schleife von i = 0 bis iStringsize
	{
		char a;																							// Definiere einen Char
		a = pString[i];																					// hole den Char an der Stelle i
		if(!((a >= 'A' && a <='Z') || (a >= '0' && a <='9')))											// Abfrage ob es weder in Buchstabe noch eine Zahl ist,
		{
			printf("Fehler (%d): (%c)\n",i,a);															// Fehlerausgabe
			return false;																				// Abbruch mit false
		}
	}
	return true;																						// Ruecksprung mit true
}
//==================================================================================
char ConvertChar(char cIn)
{
	if(cIn >= 'A' && cIn <='Z')																			// Ist das Zeichen ein Buchstabe
		cIn -= 'A';																						// subtraiere 'A'
	else																								// oder
	if(cIn >= '0' && cIn <='9')																			// Ist das Zeichen eine Zahl
		cIn -= '0' - 26;																				// subtraiere ('0' - 26)
	return cIn;
}
//==================================================================================
// Konvertieren eines Textes in das vorgegebene Format
//==================================================================================
void ConvertToFormat(char *pTmp,char *pNewTmp,int iSize)
{
	int i;																								// Definiere eine Laufvariable
	for(i = 0;i < iSize;++i)																			// Schleife von i = 0 bis iSize
	{
		unsigned char a;																				// Definiere eine Temporaere Variable
		a = ConvertChar(pTmp[i]);																		// konvertiere das Zeichen an der Stelle i
		pNewTmp[i] = a;																					// schreibe das neue Zeichen in pNewTemp an der Stelle i
	}
}
//==================================================================================
// Verschluessele und Entschluessele
// EnDeCode = 1 Verschluesseln
// EnDeCode = -1 Entschluesseln
//==================================================================================
void Coding(char *pString,int iStringsize,char *pCode,int iCodesize,int EnDeCode)
{
	char sTmpCode[CODE_BUFFER_SIZE + 1];																// Definiere einen +1, wegen der '0' am Ende
	int i;																								// Laufvariable

	ConvertToFormat(pCode,sTmpCode,iCodesize);															// Konvertiere den Code in das vorgegebene Format

	for(i = 0;i < iStringsize;++i)																		// Schleife von 0 bis zum Ende der Zeichenkette
	{
		unsigned char a;
		int a_,b_;

		a = pString[i];																					// holen des Zeichens an der Stelle i
		a_ = ConvertChar(pString[i]);																	// konvertiere das Zeichen an der Stelle i
		b_ = sTmpCode[(i % iCodesize)];																	// Holen des bereits umgewandelten Code-Zeichens an der Stelle (i mod Codesize)
		a_ = (a_ + EnDeCode * b_ + 36) % 36;															// Verschluesseln bzw Entschluesseln des aktuellen Zeichens
		if(a_ < 26)																						// Umwandlung des Zeichens ins Lesbar
			a = a_ + 'A';																				// -"-
		else
			a = (a_ - 26) + '0';
		pString[i] = a;																					// Schreiben des neuen Zeichens
	}
}
//==================================================================================
// Loeschen eines Buffers
//==================================================================================
void MemClr(char *pBuffer,int size)
{
	int i;
	for(i = 0;i < size;i++) pBuffer[i] = 0;
}
//==================================================================================

