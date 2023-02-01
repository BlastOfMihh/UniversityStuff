bits 32


segment data use32 class=data

segment code use32 class=code

global check_even
check_even:
    mov eax, [esp+4]
    and eax, 1
    ret 
