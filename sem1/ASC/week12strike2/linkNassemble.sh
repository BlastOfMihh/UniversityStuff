#!/bin/bash
#!/bin/bash


nasm -fobj hw12.asm; 
nasm -fobj even.asm ; 

alink hw12.obj even.obj -oPE -subsys console -entry start
