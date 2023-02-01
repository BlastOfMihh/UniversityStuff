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

a db "nelu"
lenA equ $-a
b db "NeLUisHEREEE"
lenB equ $-b

c times(lenB) db 1



    
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
        ; Two strings of bytes A and B are given. Parse the shortest string(A) of those two and build a third string C as follows:

        ; up to the lenght of the shortest string(A), C contains the largest element of the same rank from the two strings
        
        ; then, up to the length of the longest string(B), C will be filled with 1 and 0, alternatively.
    
        
      
        mov EAX, 0
        
          
        ;; make c equal to b till lenA
        mov ecx, dword lenA
        mov ESI, b
        mov EDI, c
        jecxz skip_loop1
            _loop:
                movsb
            loop _loop
        skip_loop1:
        
        ; up to the lenght A, C contains the largest element of the same rank from the two strings
        mov ECX, dword lenA
        mov EDI, c
        mov ESI, a
        jecxz skip_loop2
            _loop2:
                cmpsb
                dec ESI ; a
                dec EDI ; c
                jl less
                    ;greater
                    mov AL, [ESI]
                jmp not_less
                less:
                    mov AL, [EDI]
                not_less:
                
                stosb ; edi
                inc esi
            loop _loop2
        skip_loop2:
        
                
        ; then, up to the length of the longest string(B), C will be filled with 1 and 0, alternatively.
        mov ECX, lenB
        sub ECX, lenA 
       ; mov EDI, c
        jecxz skip_loop2
            _loop3:
                
                mov EAX, ECX 
                and EAX, 1
                cmp EAX, 1
                je _equal
                    ;not equal 
                    ;mov [EDI], 1
                    mov AL, '1'
                jmp not_equal
                _equal : ;
                   ; mov [EDI], 0
                   mov AL, '0'
                not_equal:
                
                stosb
            loop _loop3
        skip_loop3:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        
        
        
        
        
        
        