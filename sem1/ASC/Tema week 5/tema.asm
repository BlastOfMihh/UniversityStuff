bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    c dd 10
    a db 8
    b dw 9
    ; d dq 11
    d dq 18446744073709551612
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; Cerinta:  (c-b+a)-(d+a) 
        ; c - double word
        ; a - byte, b - word,
        ; d - qword
        
        mov EAX, [c]
        
        movzx EBX, word [b]
        sub EAX, EBX
        ;mov EBX, 0
        movzx EBX, byte [a]
        add EAX, EBX ; +=a
        
        ;; we represent d on ECX and EDX
        mov ECX, [d+4]
        mov EDX, [d]
        ;; do the subtraction
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        
        
        
        
        
        
        
        
        