data segment

buffer@io                db      0

; Marker

markerCol@io             dw      0
markerRow@io             dw      0

mouseEnabled@io          db      0
mousePrevLeft@io         db      0

rawMouseX@io             dw      0
rawMouseY@io             dw      0

data ends

code segment

initMouse@io PROC
        mov byte ptr [mouseEnabled@io], 0
        mov byte ptr [mousePrevLeft@io], 0

        mov ax, 0h
        int 33h

        cmp ax, 0
        je exit@initMouse

        mov byte ptr [mouseEnabled@io], 1

        ; Ask mouse driver to show cursor (some VESA modes may still hide it).
        mov ax, 01h
        int 33h

exit@initMouse:
        ret
initMouse@io ENDP


mapMouseToSquare@io PROC
        ; Scale coordinates if driver reports doubled ranges in graphics mode.
        mov ax, [rawMouseX@io]
        cmp ax, 1024d
        jb x@scaled
        shr ax, 1
x@scaled:
        mov cx, ax

        mov ax, [rawMouseY@io]
        cmp ax, 768d
        jb y@scaled
        shr ax, 1
y@scaled:
        mov dx, ax

        ; minX = marginX * cubeSize
        mov ax, [marginX@graphics]
        mov bx, [cubeSize@graphics]
        mul bx
        mov bp, ax

        ; maxX = minX + cubeSize * 8
        mov ax, [cubeSize@graphics]
        add ax, ax
        add ax, ax
        add ax, ax
        add ax, bp

        cmp cx, bp
        jb invalid@mapMouse
        cmp cx, ax
        jae invalid@mapMouse

        ; col = (x - minX) / cubeSize
        sub cx, bp
        mov ax, cx
        xor dx, dx
        mov bx, [cubeSize@graphics]
        div bx
        mov di, ax

        ; minY = marginY * cubeSize
        mov ax, [marginY@graphics]
        mov bx, [cubeSize@graphics]
        mul bx
        mov bp, ax

        ; maxY = minY + cubeSize * 8
        mov ax, [cubeSize@graphics]
        add ax, ax
        add ax, ax
        add ax, ax
        add ax, bp

        mov cx, [rawMouseY@io]
        cmp cx, 768d
        jb y2@scaled
        shr cx, 1
y2@scaled:

        cmp cx, bp
        jb invalid@mapMouse
        cmp cx, ax
        jae invalid@mapMouse

        ; row = (y - minY) / cubeSize
        sub cx, bp
        mov ax, cx
        xor dx, dx
        mov bx, [cubeSize@graphics]
        div bx
        mov si, ax

        clc
        ret

invalid@mapMouse:
        stc
        ret
mapMouseToSquare@io ENDP


updateMarker@io PROC
        ; input: SI=row, DI=col
        cmp si, [markerRow@io]
        jne redraw@updateMarker
        cmp di, [markerCol@io]
        jne redraw@updateMarker
        ret

redraw@updateMarker:
        push si
        push di

        mov si, [markerRow@io]
        mov di, [markerCol@io]
        call getColor@graphics
        call markCube@graphics

        pop di
        pop si

        mov al, [markColor@graphics]
        call markCube@graphics

        mov [markerCol@io], di
        mov [markerRow@io], si
        ret
updateMarker@io ENDP


getData@io PROC
poll@getData:
        mov ah, 01h
        int 16h
        jnz key@getData

        cmp byte ptr [mouseEnabled@io], 0
        je poll@getData

        mov ax, 03h
        int 33h

        mov [rawMouseX@io], cx
        mov [rawMouseY@io], dx

        call mapMouseToSquare@io
        jc noHover@getData

        call updateMarker@io

noHover@getData:
        test bl, 1
        jz released@getData

        cmp byte ptr [mousePrevLeft@io], 0
        jne poll@getData

        mov byte ptr [mousePrevLeft@io], 1

        ; Return marker location as selection.
        mov si, [markerRow@io]
        mov di, [markerCol@io]
        ret

released@getData:
        mov byte ptr [mousePrevLeft@io], 0
        jmp poll@getData

key@getData:
        mov byte ptr [mousePrevLeft@io], 0

        mov ah, 0h
        int 16h

        cmp ah, 20h
        ja undefinedKey@getData

        xor bh, bh
        mov bl, ah
        shl bx, 1

        jmp word ptr cs:[binds@io + bx]

undefinedKey@getData:
        jmp poll@getData

getData@io ENDP


userAction PROC
quit@userAction:
        mov dx, offset byUser@error
        jmp exit_msg

submit@userAction:
        ret

markerUp@userAction:
        mov si, [markerRow@io]
        mov di, [markerCol@io]

        cmp si, 0d
        je exit@markerUp

decRow@markerUp:
        call getColor@graphics
        call markCube@graphics

        dec si
        mov al, [markColor@graphics]
        call markCube@graphics

        mov [markerCol@io], di
        mov [markerRow@io], si

exit@markerUp:
        jmp getData@io

markerDown@userAction:
        mov si, [markerRow@io]
        mov di, [markerCol@io]

        cmp si, 7d
        je exit@markerDown

incRow@markerDown:
        call getColor@graphics
        call markCube@graphics

        inc si
        mov al, [markColor@graphics]
        call markCube@graphics

        mov [markerCol@io], di
        mov [markerRow@io], si

exit@markerDown:
        jmp getData@io

markerRight@userAction:
        mov si, [markerRow@io]
        mov di, [markerCol@io]

        cmp di, 7d
        je incRow@markerRight

incCol@markerRight:
        call getColor@graphics
        call markCube@graphics

        inc di
        mov al, [markColor@graphics]
        call markCube@graphics

        mov [markerCol@io], di
        jmp exit@markerRight

incRow@markerRight:
        cmp si, 7d
        je exit@markerRight

        call getColor@graphics
        call markCube@graphics

        inc si
        xor di, di
        mov al, [markColor@graphics]
        call markCube@graphics

        mov [markerCol@io], di
        mov [markerRow@io], si
        jmp exit@markerRight

exit@markerRight:
        jmp getData@io

markerLeft@userAction:
        mov si, [markerRow@io]
        mov di, [markerCol@io]

        cmp di, 0d
        je decRow@markerLeft

decCol@markerLeft:
        call getColor@graphics
        call markCube@graphics

        dec di
        mov al, [markColor@graphics]
        call markCube@graphics

        mov [markerCol@io], di
        jmp exit@markerLeft

decRow@markerLeft:
        cmp si, 0d
        je exit@markerLeft

        call getColor@graphics
        call markCube@graphics

        dec si
        mov di, 7d
        mov al, [markColor@graphics]
        call markCube@graphics

        mov [markerCol@io], di
        mov [markerRow@io], si
        jmp exit@markerLeft

exit@markerLeft:
        jmp getData@io

userAction ENDP

binds@io:
        dw offset undefinedKey@getData          ; UNDEFINED
        dw offset quit@userAction               ; Esc[1d]
        dw 15d dup(offset undefinedKey@getData) ; UNDEFINED
        dw offset markerUp@userAction           ; W[17d]
        dw 10d dup(offset undefinedKey@getData) ; UNDEFINED
        dw offset submit@userAction             ; Enter[28d]
        dw offset undefinedKey@getData          ; UNDEFINED
        dw offset markerLeft@userAction         ; A[30d]
        dw offset markerDown@userAction         ; S[31d]
        dw offset markerRight@userAction        ; D[32d]

code ends
