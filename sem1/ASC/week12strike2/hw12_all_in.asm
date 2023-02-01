bits 32

global start        

extern exit, fscanf , printf, fopen
import exit msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll

segment data use32 class=data
read_mode db "r",0
file_name db "numbers.txt", 0
file_ptr dd 0
int_format db "%d ", 0
nr dd 0

s times 26 dd 0
slen dd 0

p times 26 dd 0
plen dd 0
n times 26 dd 0
nlen dd 0

tab db "   ", 0


segment code use32 class=code
    
    open_file:
        push read_mode
        push file_name
        call [fopen]
        add esp, 4*2
        mov [file_ptr], eax
        ret 

    read:
        mov ebx, 0
        mov esi, s
        .loop:
            push nr
            push int_format
            push dword [file_ptr]
            call [fscanf]
            add esp, 4*3
            push eax
            ; push dword [nr]
            ; push int_format
            ; call [printf]
            ; add esp, 4*2
            add dword [slen], 1

            mov edx, [nr]
            mov [esi+ebx*4], edx
            inc ebx


            pop eax
            cmp eax, 0
        jg .loop
        dec dword [slen]
        ret
    
    check_even:
      mov eax, [esp+4]
      and eax, 1
      ret 
    
    print_tab:
      push tab
      call [printf]
      add esp, 4*1
      ret 

    print_arr:
        ; push dword [plen]
        ; push p
      mov esi, [esp+1*4]
      mov ecx, [esp+2*4]
      cmp ecx, 0
      je .end_loop_pa
      .loop_pa:
        push ecx
        push dword [esi]
        push int_format
        call [printf]
        add esp, 4*2
        pop ecx
        add esi, 4
      loop .loop_pa
      .end_loop_pa:

      ret 

    append_arr:
      ; push dword [esi]
      ; push dword plen
      ; push p
      ; call append_arr
      ; add esp, 4*3
      mov esi, [esp+4]
      mov edx, [esp+4*2]
      mov ebx, [edx]
      add dword [edx], 1
      mov eax, [esp+4*3]
      mov [esi+ebx*4], eax

      ret

    start:
        ; 26
        ; Read from file numbers.txt a string of numbers (odd and even). 
        ; Build two strings using read numbers:
        ; P – only with even numbers
        ; N – only with odd numbers
        ; Display the strings on the screen.
        
        call open_file
        call read
        
        mov esi, s 
        mov ecx, [slen]

        .loop2:
            push dword [esi]
            call check_even
            jnz .not_even
              ;; even 
              ; push ecx
              ; push dword [esi]
              ; push int_format
              ; call [printf]
              ; add esp, 4*2
              ; pop ecx
              push ecx
              push esi 

              push dword [esi]
              push dword plen
              push p
              call append_arr
              add esp, 4*3

              pop esi
              pop ecx
            jmp .even
            .not_even:
              push ecx
              push esi

              push dword [esi]
              push nlen
              push n
              call append_arr
              add esp, 4*3

              pop esi
              pop ecx
                ;; unvevn stuff 
            .even:
            add esi, 4
        loop .loop2
        
        push dword [plen]
        push p
        call print_arr
        add esp, 2*4
        
        call print_tab

        push dword [nlen]
        push dword n
        call print_arr 
        add esp, 2*4

        ; push dword [slen]
        ; push dword s
        ; call print_arr 
        ; add esp, 2*4
        ;
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
