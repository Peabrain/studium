#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN            16384
int main(int argv, char **argc)
{
	FILE *f = NULL;
	switch(argv)
	{
		case 2: f = fopen(argc[1],"r");break;
		case 1: f = stdin;break;
	}

	if(f != NULL)
	{
		int lines = 0;
		int	words = 0;
		int	bytes = 0;
		char    pLine[LINE_LEN];
		while (fgets(pLine, LINE_LEN, f))
		{
			int len = strlen(pLine);
			int i;
			bytes += len;
			if(pLine[0] > 32) words++;
			for(i = 0;i < len - 1;i++)
			{
				if(pLine[i] == ' ' && pLine[i + 1] > 32) words++;
			}
			lines++;
		}
		if(argv == 2) fclose(f);
		fprintf(stdout,"\t%i\t%i\t%i\n",lines,words,bytes);
	}
	return 0;
}
