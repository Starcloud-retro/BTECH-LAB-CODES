assume cs:code,ds:data
data segment
        cou db 09h
        str1 db "Enter the next number$"
        sum db ?
data ends
code segment
        mov ax,data
        mov ds,ax
        mov cl,cou
        mov bl,0000h
        go: mov dx,offset str1
        mov ah,09h
        int 21h
        mov ah,01h
        int 21h
        sub al,30h
        add bl,al
        dec cl
        jnz go
        mov sum,bl
        hlt
code ends
end
