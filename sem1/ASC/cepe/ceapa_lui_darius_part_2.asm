bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, printf, fprintf, scanf, fscanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fprintf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fscanf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

file_name db "file.txt", 0
read_format db "r", 0
int_format db "%d", 0
print_int_format db "%d  ",0
scanf_format dd "%s", 0

test_str db "test",0

backslash_str db "\n"

file_prt dd -1

number dd -1

print_it db 0

fq times 10 db 0
aux dd 0
best_fq dd 0

; A text file is given. Read the content of the file, determine the digit with the highest frequency and display the digit along with its frequency on the screen. The name of text file is defined in the data segment.

    
; our code starts here
segment code use32 class=code
    start:
        ; ...

        push dword read_format 
        push dword file_name 
        call [fopen]
        add esp, 4*2
        mov [file_prt], eax
        
        .loop:
            ;scanf
            push number
            push int_format
            push dword [file_prt]
            call [fscanf]
            add esp, 4*2
            
            cmp dword [number], 10 
            cmp eax, 0
            jle .exit_loop
            
            mov edx,0
            mov eax, [number]
            mov edi, fq
            mov ebx, 10
            .loop_nr:
                div dword ebx
                ; edx=ebx%10
                inc byte [edi+edx*1]
                cmp eax, 0
                mov edx, 0
                jnz .loop_nr
           ; push dword [number]
            ;push dword print_int_format
            ;call [printf]
            ;add esp, 4*2
        jmp .loop
        .exit_loop :
        
        mov dword [best_fq], fq
        mov esi, fq
        mov ecx, 10
        .loop_fq:
            mov bl, [esi]
            mov edi, [best_fq]
            cmp byte [edi], bl 
            jnle .end_if
                mov [best_fq],esi 
            .end_if:
            inc esi 
        loop .loop_fq
        
        
        mov ebx, [best_fq]
        push dword [ebx]
        push dword print_int_format ;; printring it's frequency 
        call [printf]
        add esp, 4*2
        
        sub dword [best_fq], fq 
        push dword [best_fq]
        push dword print_int_format
        call [printf]
        add esp, 4*2 ;; printing the most common digit 
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
