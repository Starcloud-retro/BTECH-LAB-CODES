assume cs:code,ds:data,es:data
data segment
str1 db "mpmclab$"
count equ ($-str1)
str2 db 8 dup(0)
data ends
code segment
mov ax,data
mov ds,ax
mov es,ax
mov cx,count-1
lea si,str1
lea di,str2
add si,count-2
l1: std
lodsb
cld
stosb
loop l1
mov al,24h
stosb
mov ah,09h
lea dx,str2
int 21h
int 3h
code ends
End
