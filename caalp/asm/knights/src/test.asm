; Test program - displays a message
.model small
.stack 100h
.data
    msg db 'Setup works! Press any key...$'
.code
main:
    mov ax, @data
    mov ds, ax
    
    ; Display message
    mov ah, 09h
    lea dx, msg
    int 21h
    
    ; Wait for keypress
    mov ah, 01h
    int 21h
    
    ; Exit
    mov ah, 4ch
    int 21h
end main
