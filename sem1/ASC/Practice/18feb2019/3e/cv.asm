bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data


b db 255
a dw '12','34',0, 0abcdh
; a db 'MihIsHere12345678',0
format db " %x",0


segment code use32 class=code
; var2 dq 10

start:

    mov eax, 0
    mov ebx,0

    mov dx, 0FFFFh
    mov ax, 0FFFFh
    mov bx, 1h
    idiv bx

    ; mov ax, 7FFFh
    ; mov bl, 1h
    ; idiv bl

    ; lea dword [a], [b+1]

    ; push dword a
    ; call [printf]
    ; add esp, 4*1

    ; push dword [a]
    ; push format
    ; call [printf]
    ; add esp, 4*2



    ; mov ax, -127
    ; mov bl, -1
    ; idiv bl

    ; jmp
    ; mov byte [CS:0], 1

    ; mov byte FAR [var2], 1




    ; mov al, 255
    ; mov bl, 2
    ; imul bl

    ; mov ax, 1000
    ; mov bl, 2
    ; idiv bl

    ; mov al, 10100001b
    ; mov bl, 10100011b
    ; add al, bl

    ; lea eax, [ebx*1+10+ebp]

    ; mov eax, 200
    ; mov ebx, 254h
    ; idiv bl


    push    dword 0
    call    [exit]
