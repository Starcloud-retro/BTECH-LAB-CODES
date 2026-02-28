org 100h

mov dx, msg
mov ah, 09h
int 21h

mov ah, 4Ch
int 21h

msg db 'Hello CAALP$', 0
