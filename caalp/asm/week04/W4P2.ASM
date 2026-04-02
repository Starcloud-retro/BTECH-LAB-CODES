assume cs:code,ds:data
data segment
        arr db 12h,13h,05h,35h,46h,76h
        cou db 06h
        max db ?
        min db ?
data ends
code segment
        mov ax,data
        mov ds,ax
        mov si,offset arr
        mov cl,cou
        mov al,[si]
        mov min,al
        mov max,al
        back: inc si
        mov al,[si]
        cmp min,al
        jl chmax
        mov min,al
        chmax: cmp max,al
        jg go
        mov max,al
        go: dec cl
        jnz back
        hlt
code ends
end
