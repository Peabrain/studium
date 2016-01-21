#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myFileinfo
{
	char *mem;
	int len;
	int isCrcFile;
}myFileinfo;

unsigned short encSeq(char *seq,int iSeqLen,int iCode);
myFileinfo loadfile(char *name);
int savefile(char *name,myFileinfo inf);

int main(int argv, char **argc)
{
	unsigned int iCode = 0xa001;	// polynom umgedreht
	myFileinfo info;
	
	if(argv == 2)
	{
		info = loadfile(argc[1]);
		if(info.mem)
		{
			unsigned short check = 0;
			if(info.isCrcFile)
			{
				check = (char)info.mem[info.len-2] | ((char)info.mem[info.len-1] << 8);
				info.mem[info.len-2] = 0;
				info.mem[info.len-1] = 0;
			}
			else
				info.len += 2;
			unsigned short crc = encSeq(info.mem,info.len * 8,iCode);
			if(!info.isCrcFile)
			{
				info.mem[info.len-2] = (char)crc;
				info.mem[info.len-1] = (char)(crc >> 8);
				printf("CRC16: %04x\n",crc);
				savefile(argc[1],info);
			}
			else
			{
				printf("CheckCRC: %04x, %04x\n",crc,check);
			}	
			free(info.mem);
		}
	}
	else
	{
	}
}
unsigned short encSeq(char *seq,int iSeqLen,int iCode)
{
	unsigned short code = (unsigned short)(iCode & 0xffff);
	unsigned short toCode = (unsigned char)seq[0] | ((unsigned char)seq[1] << 8);
	int pos = 16,count = 0;
	
	while(1)
	{
		unsigned short z = (toCode & 0x0001);
		toCode >>= 1;
		if(seq[pos / 8] & (1 << (pos & 7)))
			toCode |= 0x8000;
		pos++;
		if(z)
		{
			toCode ^= code;
			count++;
		}
		if(pos == iSeqLen) break;
	}
	return toCode;
}
myFileinfo loadfile(char *name)
{
	myFileinfo inf;
	inf.mem = 0;
	inf.len = 0;
	inf.isCrcFile = 0;
	FILE *f = fopen(name,"r");
	if(f != NULL)
	{
		fseek(f, 0L, SEEK_END);
		inf.len = ftell(f);
		fseek(f, 0L, SEEK_SET);
		
		int addi = 2;
		int strl = strlen(name);
		if(strcmp(&name[strl-4],".crc") == 0)
		{
			inf.isCrcFile = 1;
			addi = 0;
		}
		inf.mem = (char*)malloc(inf.len + addi);
		memset(inf.mem,0,inf.len + addi);		
		fread(inf.mem,1,inf.len,f);
		fclose(f);
		printf("load file: %s\n",name);
	}
	return inf;
}
int savefile(char *name,myFileinfo inf)
{
	char name2[1024];
	sprintf(name2,"%s.crc",name);
	FILE *f = fopen(name2,"wb");
	if(f != NULL)
	{
		fwrite(inf.mem,1,inf.len,f);
		fclose(f);
		return 0;
	}
	return -1;
}
