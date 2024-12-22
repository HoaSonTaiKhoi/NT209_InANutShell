.section .data
input: .string ""

.section .text
    .globl _start

_start: 
movl $3, %eax
movl $0, %ebx
movl $input, %ecx
movl $2, %edx
int $0x80

movl $input, %edx
movb 1(%edx), %cl
subb $48, %cl
orb $254, %cl
notb %cl
addb $48, %cl
movb %cl, 1(%edx)

movl $4, %eax
movl $1, %ebx
leal 1(%edx), %ecx
movl $1, %edx
int $0x80

movl $1, %eax
int $0x80
