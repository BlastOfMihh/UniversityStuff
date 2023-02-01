
factorial: ; int _stdcall factorial(int n)
    mov eax, 1
    mov ecx, [esp + 4]
    
    .repeat: 
        mul ecx
    loop .repeat ; atention, the case ecx = 0 is not treated!

    ret 4 ; in this case, 4 represents the number of bytes that need to be cleared from the stack (the parameter of the function)

