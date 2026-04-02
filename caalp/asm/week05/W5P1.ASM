assume ds:data,es:extra,cs:code
code segment
        mov ax,data
        mov ds,ax
        mov ax,extra
        mov es,ax
        mov si,offset str1
        mov di,offset str2
        mov cl,0bh
        cld
        rep movsb
        hlt
code ends
data segment
        str1 db "geethanjali"
data ends
extra segment
        str2 db 0bh dup(0)
extra ends
end
