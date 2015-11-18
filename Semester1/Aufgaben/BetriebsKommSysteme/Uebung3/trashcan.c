/**
 * File: trashcan.c
 * TI 2 - Betriebs- und Kommunikationssysteme
 * Freie Universitaet Berlin
 Andreas Timmermann
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE			9
#define PATHSIZE		256
#define TRASHFOLDER	".ti3_trash"

#define	SRC_MISSING		0x01
#define	DST_MISSING		0x02

char copy_buffer[BUFSIZE];


/* 'copy' kopiert den Dateiinhalt einer Datei namens
 * "source". Eine Kopie target wird nur erzeugt, wenn
 * eine Datei "target" noch nicht existiert.
 * Die Zugriffsrechte werden nicht kopiert, sondern
 * auf "rwx --- ---" gesetzt.
 */
int copy(char *source, char *target)
{
	printf("kopiere %s nach %s\n",source,target);
	int i;
	int i1;
	int len = 0;
	if(source)																				// wenn der sourcepointer leer ist, dann abbruch
	{
		if(target)																			// wenn der targetpointer leer ist, dann abbruch
		{
			i = open(source,O_RDONLY);														// oeffnen des sourcefiles
			if(i != -1)
			{
				int o = 0; 
				i1 = open(target, O_WRONLY | O_CREAT,S_IRWXU);								// oeffnen des targetfiles
				if(i1 != -1)
				{
					int len1 = BUFSIZE;														// hole solange etwas aus dem sourcefile und ...
					while(len1 == BUFSIZE)													// ... schreibe es ins targetfile, wie len1 = BUFSIZE.
					{																		// len1 != BUFSIZE, dann wurde der letzte block gelesen.
						int j;
						len1 = read(i,copy_buffer,BUFSIZE);
						len1 = write(i1,copy_buffer,len1);
						len += len1;
						for(j = 0;j < len1;++j) printf("%c",copy_buffer[j]);
					}
					o = 1;
					close(i1);															// schliesse das targetfile
				}
				close(i);																// schliesse das sourcefile
				if(o == 1)																// alles gut kopiert?
				{
					if(remove(source) < 0)												// versuche das sourcefile zu loeschen
						return -1;
				}
			}
		}
	}
	return 0;
}


char parse_command(char *command)
{
	return command[1];
}


/* erzeugt einen Ordner foldername */
int setup_trashcan(char *foldername)
{
	if(mkdir(foldername,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)					// erzeuge ein verzeichnes
      printf("%s existiert bereits\n",foldername);
   else
      printf("%s angelegt\n",foldername);
	return 0;
}
/* ueberpriefe ob srcfile und dstfile existieren */
int check_SrcDst(char *src, char *dst)
{
	int ret = 0,i;
	if(src)
	{
		i = open(src,O_RDONLY);
		if(i != -1)
			close(i);
		else
			ret |= SRC_MISSING;
	}

	if(dst)
	{
		i = open(dst,O_RDONLY);
		if(i != -1)
			close(i);
		else
			ret |= DST_MISSING;
	}
			
	return ret;
}
/* pseudoroutine fuer das kopieren von src nach dst */
int putget_file(char *src, char *dst)
{
	int f;
	printf("file: %s to %s\n",src,dst);

	f = check_SrcDst(src,dst);
	if(!(f & SRC_MISSING) && (f & DST_MISSING))
	{
		printf("File %s kann nach %s verschoben werden.\n",src,dst);
		if(copy(src, dst) == -1)
			return -3;
	}
	else
	{
		if(f & SRC_MISSING)
			return -1;
		if(!(f & DST_MISSING))
			return -2;
	}

	return 0;
}
/* führt trashcan -p[ut] filename aus */
int put_file(char *foldername, char *filename)
{
	char src[PATHSIZE];
	char dst[PATHSIZE];
	sprintf(src,"./%s",filename);
	sprintf(dst,"%s/%s",foldername,filename);
	return putget_file(src,dst);
}


/* führt trashcan -g[et] filename aus */
int get_file(char *foldername, char *filename)
{
	char src[PATHSIZE];
	char dst[PATHSIZE];
	sprintf(src,"%s/%s",foldername,filename);
	sprintf(dst,"./%s",filename);
	return putget_file(src,dst);
}

/* führt trashcan -r[emove] filename aus */
int remove_file(char *foldername, char *filename)
{
	int f;
	char src[PATHSIZE];
	sprintf(src,"%s/%s",foldername,filename);
	f = check_SrcDst(src, 0);
	printf("%s\n",src);
	if(!(f & SRC_MISSING))
	{
		if(remove(src) < 0)
			return -1;		
		printf("file: %s remove from %s\n",filename,foldername);
	}
	else
		return -1;
	return 0;
}


int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("...not enough arguments!\n");
		return EXIT_FAILURE;
	} else {
		setup_trashcan(TRASHFOLDER);
		char command = parse_command(argv[1]);
		switch (command) {
			case 'p':
				if (argc != 3) {
					printf("...not enough arguments!\n");
					return EXIT_FAILURE;
				}
				int p_error = put_file(TRASHFOLDER, argv[2]);
				switch (p_error) {
					case -1:
						printf("...source file not found!\n");
						break;
					case -2:
						printf("...trash file was not created!\n");
						break;
					case -3:
						printf("...source file could not be removed!\n");
					default:
						break;
				}
				break;
			case 'g':
				if (argc != 3) {
					printf("...not enough arguments!\n");
					return EXIT_FAILURE;
				}
				int g_error = get_file(TRASHFOLDER, argv[2]);
				switch (g_error) {
					case -1:
						printf("...trash file not found!\n");
						break;
					case -2:
						printf("...restore file was not created!\n");
						break;
					case -3:
						printf("...trash file could not be removed!\n");
					default:
						break;
				}
				break;
			case 'r':
				if (argc != 3) {
					printf("...not enough arguments!\n");
					return EXIT_FAILURE;
				}
				int r_error = remove_file(TRASHFOLDER, argv[2]);
				if (r_error)
					printf("...trash file could not be removed!\n");
				break;
			default :
				printf("...unknown command!\n");
				return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
