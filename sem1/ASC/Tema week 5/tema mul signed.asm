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
    
    a dw 2
    b db 1
    c dw 2
    d dd 4
    x dq 8

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;; (a*a+b/c-1)/(b+c)+d-x; 
        ; a-word
        ; b-byte
        ; c-word
        ; d-doubleword
        ; x-qword
        
        mov EAX, 0
        mov AX, [a]
        cwd
        mul EAX
        mov EBX, EAX ; EBX = the result
        ;; EBX=a * a
        mov EAX, 0
        mov AL, [b]
        cbw
        cwd 
        mov CX, [c]
        cwd 
        div ECX
        add EBX, EAX  
        sub EBX, 1
        ;; first param 
        mov EAX, 0
        mov AL, [b]
        cbw 
        cwd
        ;;add AX, [c]
        mov EDX, EAX
        mov AX, [c]
        cwd 
        sub EDX, EAX 
        mov EAX, EBX ; result in EAX 
        div EDX 
        cdq
        add EAX, [d]
        adc EDX, 0
        
        sub EAX, [x]
        sbb EDX, [x+4]
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        
        
        
        
        
        
        
        
        
        
        
        
        