.section .data
    output:
        .string "Giam dan"
    outpu1:
        .string "Khong giam dan"

.section .text
    .globl _start

_start:
    movl $3, %eax
    movl $0, %ebx
    movl $input, %ecx
    movl $6, %edx
    int $0x80

    movl $0, %ecx
    movl $input, %eax

.loop:
    movb (%eax, %ecx), %bl
    incl %ecx
    movb (%eax, %ecx), %dl
    cmp %bl, %dl
    jge .exit
    
    cmpl $6, %ecx
    jl .loop
    jmp .exit2
.exit:
    movl $outpu1, %ecx
    movl $14, %edx
    movl $1, %ebx 
    movl $4, %eax
    int $0x80
    jmp .exit3

.exit2:
    movl $output, %ecx
    movl $8, %edx
    movl $1, %ebx 
    movl $4, %eax
    int $0x80
    
.exit3:
    movl $1, %eax
    int $0x80


.section .bss
    .lcomm input, 6
