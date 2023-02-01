;bits 32                         
;segment code use32 public code
;global is_even

is_even: 
    pop eax
    and eax, 1
    cmp eax, 0
    je .even
        mov eax, 0
    jmp .uneven
    .even:
        mov eax, 1
    .uneven:
    add esp, 4
    ret 4
