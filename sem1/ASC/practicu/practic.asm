bits 32 ; assembling for the 32 bits architecture

global start        

extern exit             
import exit msvcrt.dll    

extern scanf
import scanf msvcrt.dll

extern fopen
import fopen msvcrt.dll


extern printf 
import printf msvcrt.dll


extern fprintf 
import fprintf msvcrt.dll


  
segment data use32 class=data
    
write_mode db "w",0

file_name resb 104
file_descr dd 0

hexa_format db "file descriptor: %x",0
int_format db "%d ", 0
str_format db "%s",0

segment code use32 class=code
    start:
        ; Sa se deschida fisierul si sa se printeze pe ecran descriptorul de fisier in baza 16 iar apoi sa se scrie cifrele impare (in baza 10) din descriptorul de fisier in fisierul creat.    
        
        push file_name
        push str_format
        call [scanf]; scanf %s str 
        add esp, 4*2
        
        push write_mode 
        push file_name
        call [fopen] ; fopen(name, mode )
        add esp, 4*2
        
        mov [file_descr], eax
        
        
        push file_descr
        push hexa_format
        call [printf]
        
        ;; revolza cifrele
        
        
        
        mov eax, [file_descr]

        .loop:
            
            mov ebx, 10
            mov edx, 0
            div dword ebx
            
            mov ebx, 1
            and ebx, edx
            jz .even            
                push eax
                
                push edx
                push int_format
                push dword [file_descr]
                call [fprintf]
                add esp, 4*3
                
                pop eax
            .even:
            
            cmp eax, 0
            jnz .loop
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
