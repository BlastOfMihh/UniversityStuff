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

    
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
        ;;Given the byte A and the word B, compute the doubleword C as follows:
        ;; the bits 0-7 of C have the value 1                   ;
        ;; the bits 8-11 of C are the same as the bits 4-7 of A ;
        ;; the bits 12-19 are the same as the bits 2-9 of B     ;
        ;; the bits 20-23 are the same as the bits 0-3 of A     ;
        ;; the bits 24-31 are the same as the high byte of B    ;

    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
