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
    
    a db 8
    b dw 16
    c dd 32
    d dq 64
    
    ;; a - byte, b - word, c - double word, d - qword 
    
; our code starts here
segment code use32 class=code
    start:
        ;; (c-d-a)+(b+b)-(c+a) 
        ;; signed guys signed
        
        ;; convert c in quad word 
        mov EAX, [c]
        cdq
        sub EAX, dword [d]
        sbb EDX, dword [d+4]
        mov EBX, EAX
        mov ECX, EDX ; save in ECX,EBX=EDX,EAX
        
        
        mov AL, [a]
        cbw
        cwde
        cdq 
        
        sub EBX, EAX
        sbb ECX, EDX 
        
        mov EAX, 0
        mov AX, [b]
        cwd 
        mov EDX, EAX
        add EAX, EDX
        cdq
        
        sub EBX, EAX
        sbb ECX, EDX 
        
        mov EDX, [c]
        mov AL, [a]
        cbw
        cWd
        add EAX, EDX
        ;mov EDX, 0
        cdq
        ADC EDX, 0
        
        sub EBX, EAX
        sbb ECX, EDX 
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        
        
        
        
        
        
        
        
        