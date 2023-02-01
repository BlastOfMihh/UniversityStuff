bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; tell nasm that exit exists even if we won't be defining it
extern fopen               ; tell nasm that exit exists even if we won't be defining it
import fopen msvcrt.dll    
extern fscanf
import fscanf msvcrt.dll  
extern fprintf
import fprintf msvcrt.dll                   
extern printfj
import printf msvcrt.dll                   
 
 
;extern is_even
%include "even.asm"
 
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    file dw 0
    file_name db "numbers.txt",0
    int_format db "%d",0
    nr dw 0
    
    plen dw 0
    nlen dw 0
    
    p resb 109
    n resb 109
    
    mihh db "mihnea is here"

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ; 26
        ;Read from file numbers.txt a string of numbers (odd and even). Build two strings using readen numbers:
        ;P – only with even numbers
        ;N – only with odd numbers
        ;Display the strings on the screen.
        
        push dword mihh
        call [printf]
        
        
        push dword file_name
        call [fopen]
        mov [file], eax
        add esp, 4*1
        
        .loop:
            ; fscanf file, "%d", var 
            push dword nr 
            push dword int_format
            push dword [file]
            call [fscanf]
            add esp, 4*3
            
            ; even, uneven
            push dword [nr]
            call [is_even]
            add esp, 1*4
            
            cmp eax, 0
            jz .even
                mov ecx, [nlen]
                add dword [nlen], 1
                mov edx, [nr]
                mov [p+ecx], edx 
            jmp .uneven 
            .even :
                ; pass 
                mov ecx, [plen]
                add dword [plen], 1
            .uneven:
            cmp eax, 0
        jle .loop
        
                
        mov ecx, [nlen]
        mov dword [n+ecx], 0
        
        mov ecx, [plen]
        mov dword [p+ecx], 0
        
        push dword p
        call [printf]
        add esp, 4
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        
        
        
        
        
        
        
        
        
        
        
        
        
