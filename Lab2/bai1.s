.section .data
output:
    .string "22520481"
len:
    .byte . - output
.section .text
    .globl _start

_start:
    addl $47, len #Thêm kí tự \0 và trừ 1 đi độ dài ta sẽ có độ dài của chuỗi đã cho
    movl $1, %edx #độ dài của chuỗi xuất ra
    movl $len, %ecx #lưu len vào %ecx
    movl $1, %ebx  #stdout  
    movl $4, %eax # syswrite
    int $0x80 # call kernel

    
    movl $1, %eax
    int $0x80

.section .bss
    .lcomm number, 2
