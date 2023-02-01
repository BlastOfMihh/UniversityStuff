bits 32

global start        



extern exit, printf

import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data

arr_len: dd 3
arr:    dd 1234A678h, 1785634h, 1A4D3C2Bh
new_arr:     times 100 dw 0

int_format db "%x ", 0

segment code use32 class=code

build_elem:
    mov al,    byte [esi+4]
    mov ah,    byte [esi+12]
    mov [edi], word ax
    ret

build_new:
    mov esi, arr 
    mov edi, new_arr
    mov ecx, [arr_len]
    .loop:
        call build_elem
        add esi, 4*4
        add edi, 2*4
    loop .loop
    ret



print_warr:
    mov esi, [esp+4]
    mov ecx, [arr_len]

    .loop_print_arr:
        push ecx
        
        push word 0
        push word [esi]
        push dword int_format
        call [printf]
        add esp, 4*2
        
        pop ecx
        add esi, 2
        
    loop .loop_print_arr
    ret

start:

    call build_new
    add esp, 0

    push new_arr
    call print_warr
    add esp, 4*1


    push    dword 0
    call    [exit]
