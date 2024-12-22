.section .data
output:
    .string "Date (DDMMYYYY):"
output1:
    .string "Date (YYYYDDMM):"

.section .text
    .globl _start

_start:
    movl $16, %edx
    movl $output, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80

    movl $3, %eax
    movl $0, %ebx
    movl $number, %ecx
    movl $8, %edx
    int $0x80

    movl $8, %edx
    movl $number, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80

   

    movl $16, %edx
    movl $output1, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80

    movl $number, %eax
    leal 4(%eax), %ecx
    movl $1, %ebx
    movl $4, %eax
    movl $4, %edx
    int $0x80

     movl $number, %eax
    leal (%eax), %ecx
    movl $1, %ebx
    movl $4, %eax
    movl $4, %edx
    int $0x80

.section .bss
    .lcomm number, 8
