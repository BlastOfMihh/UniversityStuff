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
    a db 10
    b db 10
    c db 10
    d dw 10
    res db 0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
      
        mov AL, 50
        
        sbb AL, [b]
        sbb AL, [c] ;; 50-b-c
        
        mov BL, 2
        mul BL  ;; (50-b-c)*2
        
        mov byte [res], AL
        mov AL, [a]
        mul byte [a]
        add AL, [res]
        add AX, [d]
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
