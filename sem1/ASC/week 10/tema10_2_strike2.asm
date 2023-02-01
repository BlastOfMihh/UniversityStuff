bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, printf, fprintf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fprintf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

file_name db "file.out", 0
format db "w", 0

test_str db "test",0

backslash_str db "\n"

file_prt dd -1

scanf_format dd "%s", 0
read_word dd -1

print_it db 0

precentS db "%s",0

    
; our code starts here
segment code use32 class=code
    start:
        ; ...

        push dword format 
        push dword file_name 
        call [fopen]
        add esp, 4*2
        mov [file_prt], eax
        
        .loop:
            mov ecx, 1
            
            ;scanf
            push read_word
            push scanf_format
            call [scanf]
            add esp, 4*2
            ; check if we have "$" inside read_word
            
            cmp byte [read_word], "$"
            je .exit_loop
            
            
            ; check if we have an uppercase inside read_word
            ;pushad
            mov ecx, 32 
            mov esi, read_word
            .loop2:
                cmp [esi], byte 0
                je .exit_loop2
                cmp [esi], byte 'Z'
                jle .is_uppercase
                inc esi 
            loop .loop2
            .exit_loop2:
            
            mov [print_it], byte 0
            jmp .not_uppercase
            .is_uppercase:
                mov [print_it], byte 1
            .not_uppercase:
            ;popad
            
            cmp [print_it], byte 1
            ;jne .dont_print
                ; fprintf
                
                push dword read_word 
               ; push dword precentS
                push dword [file_prt]
                call [fprintf]
                add esp, 4*2
            ;.dont_print:
        loop .loop
        
        .exit_loop :
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
