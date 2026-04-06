data segment

fileHeight@bmp		dw	76d
fileWidth@bmp		dw	76d

cordX@bmp			dw	0
cordY@bmp			dw	0

errorMsg@bmp		db	'Could not open file, program terminated. ERROR.0$'

fileHandle@bmp		dw	0

rowBuffer@bmp		db	1024 dup(0)
headerBuffer@bmp	db	54 	dup(0)

data ends

code segment

drawFile@bmp PROC
	push ax
	push bx
	push cx
	push dx
	push si
	push di

	add di, [marginX@graphics]
	add si, [marginY@graphics]

	push si ; Row
	push di ; Col

	call getHandle@bmp
	call gotoData@bmp

	pop di
	pop si

	call loadBitmap@bmp
	call closeFile@bmp

	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax

	ret
drawFile@bmp ENDP



getHandle@bmp PROC
	mov ax, 3D00h
	int 21h

	call isFileError@bmp
	mov [fileHandle@bmp], ax

	ret
getHandle@bmp ENDP



closeFile@bmp PROC
	mov ah, 3Eh
	mov bx, [fileHandle@bmp]

	call isFileError@bmp

	int 21h
	ret
closeFile@bmp ENDP



gotoHeader@bmp PROC
	mov ax, 4200h
	mov bx, [fileHandle@bmp]
	xor cx, cx
	xor dx, dx

	int 21h
	call isFileError@bmp

	ret
gotoHeader@bmp ENDP



gotoData@bmp PROC
	call gotoHeader@bmp

	mov ax, 3F00h
	mov cx, 54d
	mov dx, offset headerBuffer@bmp
	int 21h
	call isFileError@bmp

	mov bx, offset headerBuffer@bmp
	mov dx, word ptr [bx+10d]
	mov cx, word ptr [bx+12d]

	mov ax, 4200h
	mov bx, [fileHandle@bmp]
	int 21h

	ret
gotoData@bmp ENDP


loadBitmap@bmp PROC	
	mov dx, [cubeSize@graphics]
	mov ax, si
	mul dx
	mov [cordY@bmp], ax

	mov dx, [cubeSize@graphics]
	mov ax, di
	mul dx
	mov [cordX@bmp], ax

	mov si, [fileHeight@bmp]
	loopY@loadBitmap:
		mov bx, [fileHandle@bmp]

		mov ah, 3Fh
		mov cx, [fileWidth@bmp]
		mov dx, offset rowBuffer@bmp
		int 21h

		mov di, [fileWidth@bmp]
		dec di
		loopX@loadBitmap:
			mov bx, offset rowBuffer@bmp
			add bx, di

			mov al, byte ptr [bx]
			cmp al, 0FFh
			je alphaColor@loopX

			mov ah, 0Ch
			xor bl, bl

			mov cx, di
			add cx, [cordX@bmp]

			mov dx, si
			add dx, [cordY@bmp]

			int 10h

			alphaColor@loopX:
				cmp di, 0
				dec di
				jne loopX@loadBitmap

		cmp si, 0
		dec si
		jne loopY@loadBitmap

	ret
loadBitmap@bmp ENDP



isFileError@bmp PROC
	jc fileError@isFileError
	ret
	
	fileError@isFileError:
		mov ah, 9h
		mov dx, offset errorMsg@bmp
		int 21h

		mov ah, 2h
		mov dl, al
		add dl, 48d
		int 21h

		mov ax, 4c00h
		int 21h
isFileError@bmp ENDP

code ends