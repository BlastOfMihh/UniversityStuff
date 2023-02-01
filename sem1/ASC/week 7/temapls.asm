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

s db 18, 6, 3, 1
cnt equ $-s 
;d db 0, 0, 0
d times (cnt-1) db 0 ;, 0, 0
  
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;; problema 32 
        
        mov EBX, 0
        mov EAX, 0
        
        
        mov ecx, cnt-1 
       ; dec ecx 
        mov esi, s
        mov edi, d
        jecxz final
            wh:
               ; D(i) = S(i) / S(i+1).
               
               mov al, [esi] 
               inc esi
               mov bl, [esi]
               div bl 
               mov [edi], al 
               
               inc edi 
                
               mov EAX, 0
            loop wh
        final:
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
