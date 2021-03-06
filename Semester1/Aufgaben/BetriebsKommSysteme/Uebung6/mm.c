#include "mm.h"
#include <stdio.h>

// Groesse des Speichers, den die Speicherverwaltung verwalten soll
#define memorySize 10240

// Zustand von einem Speicherblock
enum memBlockState{not_allocated=0, allocated=1};
// Zur spaeteren Ausgabe..
char boolStr[2][6] = {{"FALSE"},{"TRUE"}};

// Ein Speicherblock
typedef struct _memoryblock {
	void* data;			// Zeiger auf die Daten
	int dataSize;			// Laenge des Blocks
	enum memBlockState state;	// Wird der Block benutzt?
	struct _memoryblock * nextMemBlock; // Zeiger auf naechsten Speicherblock
} memoryBlock;

#define memoryBlockHeaderSize sizeof(memoryBlock)

// Definition von "privaten" funktionen
void mergeFreeBlocks();
memoryBlock* splitBlock(memoryBlock* block, int byteCount);

// Erster Speicherblock in der Liste
memoryBlock* head;
// Unser Speicher, den wir fuer die Daten und deren Verwaltung benutzen koennen
char memory[memorySize];

// Ist unsere Speicherverwaltung initialisiert und bereit benutzt zu werden?
int b_initialized = 0;

// Initialisiere die Datenstruktur(en) fuer unsere Speicherverwaltung
void initialize()
{
	if(!b_initialized)
	{
		head = (memoryBlock*)memory;
		// Initialisiere head in unserem Speicher <memory>
		// Unser gesamter Speicher <memory> soll als ein memoryBlock interpretiert werden
		// Wir muessen beachten, dass der memoryBlock head auch im Speicher <memory>
		// abgespeichert wird und somit der head auch Speicher der Groesse
		// memoryBlockHeaderSize zur Verwaltung benoetigt.
		// Anfangs ist der restliche Speicher verfuegbar und wird dem head als data zugeordnet.
		// Data beginnt somit nicht am Anfang von <memory>.
		head->data = head + memoryBlockHeaderSize;
		head->dataSize = memorySize - memoryBlockHeaderSize;
		head->state = not_allocated;
		head->nextMemBlock = 0;

		b_initialized = 1;
		// TODO INITIALISIERUNG VON HEAD
	}
}

// Liefert den ingesamt freien Speicherplatz zurueck
int get_free_space()
{
	if(!b_initialized)
    {
		return -1;
    }
	int count = 0;
	memoryBlock *block = head;
	while(block != NULL)
	{
		if(block->state == not_allocated)
		{
			count = count + block->dataSize;
		}
		block = block->nextMemBlock;
	}
	return(count);
}

// Versucht einen Speicherbereich mit <byteCount> vielen Bytes zu reservieren
// Falls dies nicht gelingt wird ein NULL (0) Pointer zurueckgeliefert
void* my_malloc(int byteCount)
{
	if(!b_initialized)
	{
		initialize();
	}
	// Wenn der insgesamt verfuegbare Speicherplatz kleiner ist
	// als der angeforderte, koennen wir gleich aufhoeren!
	if(byteCount > get_free_space())
	{
		return(NULL);
	}
	memoryBlock *block = head;
	// TODO
	// SUCHE NACH EINEM GEEIGNETEN FREIEN SPEICHERBLOCK, MIT MEHR ALS <byteCount>
	// VIELEN BYTES
	//

	do
	{
		if(block->state == not_allocated && block->dataSize >= byteCount + memoryBlockHeaderSize) break;
		block = block->nextMemBlock;
	}
	while(block != 0);

	// FALLS ES KEIN PASSENDES ELEMENT GIBT, GEBEN WIR NULL ZURUECK.
	if(block == 0) return 0;

	// Der Knoten block hat genuegend Speicherplatz

	// UNTERTEILUNG DIESES BLOCKS, SO DASS NICHT UNNOETIG VIEL SPEICHERPLATZ VERBRAUCHT WIRD
	// UND MARKIERE DIESEN BLOCK
	block = splitBlock(block,byteCount);
	block->state = allocated;

	// RUECKGABE DES ZEIGERS AUF DEN ZU BENUTZENDEN SPEICHERBEREICH
	return block->data;
}

// Sofern moeglich teilt die Funktion splitBlock einen Block in 2 Bloecke,
// so dass einer der beiden Bloecke <byteCount> viel Speicherplatz enthaelt.
// Die Funktion liefert denjenigen Block zurueck, der <byteCount> viel Speicherplatz
// bereitstellt und passt die verkette Liste an.
memoryBlock* splitBlock(memoryBlock* block, int byteCount)
{
	// Hinweis: Es ist sinnvoll, wenn <block> die Laenge byteCount hat und
	// der Nachfolger von <block> die Restlaenge umfasst.

	// TODO
	// IMPLEMENTIEREN

	struct _memoryblock * nextMemBlock = 0;

	// BERECHNE DIE GROESSE DES NEUEN UND ALTEN BLOCKS
	if(byteCount + memoryBlockHeaderSize <= block->dataSize)
	{
		nextMemBlock = block->data + byteCount;
		nextMemBlock->data = nextMemBlock + memoryBlockHeaderSize;
		nextMemBlock->dataSize = block->dataSize - (byteCount + memoryBlockHeaderSize);
		nextMemBlock->nextMemBlock = block->nextMemBlock;
		nextMemBlock->state = not_allocated;
		block->nextMemBlock = nextMemBlock;
		block->dataSize = byteCount;
	}


	// FALLS EIN WEITERER SPEICHERBLOCK IN DEN ALTEN PASST,
	// ERZEUGEN WIR EINEN NEUEN BLOCK, AENHLICH ZU HEAD AM ANFANG

	// LEGE DEN NEUEN BLOCK ALS NACHFOLGER VOM ALTEN BLOCK FEST

	// PASSE DIE LAENGE VOM ALTEN BLOCK AN

	return block;
}


// my_free versucht den Speicherbereich, auf den <p> verweist, wieder freizugeben.
// Sofern <p> in unserem Speicher gefunden wird, muessen benachbarte, freie Speicherbloecke
// miteinander verschmolzen werden.
void my_free(void* p)
{
	if(!b_initialized)
	{
		return;
	}

	// TODO
	// SUCHE NACH DEM BLOCK MIT ZEIGER <p>
	if(!p) return;

	memoryBlock *last = 0;
	memoryBlock *block = head;
	// TODO
	// SUCHE NACH EINEM GEEIGNETEN FREIEN SPEICHERBLOCK, MIT MEHR ALS <byteCount>
	// VIELEN BYTES
	//

	do
	{
		if(block->data == p) break;
		last = block;
		block = block->nextMemBlock;
	}
	while(block != 0);

	if(block == 0) return;

	// FALLS KEINER GEFUNDEN WURDE, GEBE EINE MELDUNG AUS.

	// FREIGEBEN VON DEM ENTSPRECHENDEN SPEICHERBLOCK

	block->state = not_allocated;

	// FREIE SPEICHERBLOECKE MITEINANDER VERSCHMELZEN
	mergeFreeBlocks();
}

// Diese Funktion verschmilzt benachbarte, nicht benutzte Speicherbloecke
void mergeFreeBlocks()
{
	// TODO
	// BEGINNE AM ANFANG DER LISTE
	// WENN DER AKTUELLE UND DER BENACHBARTE BLOCK FREI SIND,
	// DANN VERSCHMELZE DIESE INDEM DIE DATENLAENGE UND DER NACHFOLGER
	// VOM AKTUELLEN BLOCK ANGEPASST WERDEN.
	// IMPLEMENTIEREN
	memoryBlock *block = head;
	do
	{
		if(block->nextMemBlock != 0 && block->state == not_allocated && block->nextMemBlock->state == not_allocated)
		{
			block->dataSize += block->nextMemBlock->dataSize + memoryBlockHeaderSize;
			block->nextMemBlock = block->nextMemBlock->nextMemBlock;
		}
		else
		{
			block = block->nextMemBlock;
		}
	}
	while(block != 0);
}

// Diese Funktion gibt eine Uebersicht ueber die vorhandenen Speicherbloecke aus
void status()
{
	if(!b_initialized)
	{
		initialize();
	}
	memoryBlock *block = head;
	int count = 0;
	printf("Uebersicht des Speichers: %d / %d Speicher frei\n", get_free_space(), memorySize);
	printf("------------------------------------------------\n");
	printf("#  at\t\t allocated\t space\t data\t\t\tnext block\n");
	while(block != NULL)
	{

		printf("%d  %p\t %s \t\t %d\t [%p,%p]\t%p\n", ++count, block, boolStr[block->state], block->dataSize, (block->data), ((char*)block->data + block->dataSize-1), (block->nextMemBlock));
		block = block->nextMemBlock;
	}
	printf("\n\n");
}

