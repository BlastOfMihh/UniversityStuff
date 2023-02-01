bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    
import printf msvcrt.dll


; our data is declared here (the variables needed by our program)
segment data use32 class=data

pwr dd 1
factorial_str db "here I am"
ret_adrs resd 1
exp resd 1
    
; our code starts here
segment code use32 class=code
    
    factorial:
        pop dword [ret_adrs]
        pop dword [exp]
        mov ecx, [exp]
        mov eax, 1
        .loop:
            mul cx 
        loop .loop 
        jmp [ret_adrs]
    
    start:
        ; ...
        
        push dword 5
        call factorial
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
