.section .data
    output:
        .string "Nhap"

.section .text
    .globl _start

_start:
    movl $3, %eax
    movl $0, %ebx
    movl $input, %ecx
    movl $6, %edx
    int $0x80

    movl $input, %eax
    mov (%eax), %bl
    mov 4(%eax), %cl
    mov %cl , (%eax)
    mov %bl, 4(%eax)

    mov 1(%eax), %bl
    mov 3(%eax), %cl
    mov %cl ,1(%eax)
    mov %bl, 3(%eax)

    movl %eax, %ecx
    movl $6, %edx
    movl $1, %ebx 
    movl $4, %eax
    int $0x80


.section .bss
    .lcomm input, 6
