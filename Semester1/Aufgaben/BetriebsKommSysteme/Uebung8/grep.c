#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN            16384
int main(int argv, char **argc)
{
	FILE *f = NULL;
	switch(argv)
	{
		case 3: f = fopen(argc[2],"r");break;
		case 2: f = stdin;break;
	}

	if(f != NULL)
	{
		char    pLine[LINE_LEN];
		while (fgets(pLine, LINE_LEN, f))
		{
			if(strstr(pLine,argc[1]))
				fprintf(stdout,"%s",pLine);
		}
		if(argv == 3) fclose(f);
	}
	return 0;
}
