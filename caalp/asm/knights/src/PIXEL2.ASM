; PIXEL2.ASM - Draw horizontal line using loops
ASSUME CS:CODE, DS:DATA

DATA SEGMENT
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX

    ; Enter graphics mode
    MOV AH, 00H
    MOV AL, 13H
    INT 10H

    ; Setup video memory
    MOV AX, 0A000H
    MOV ES, AX

    ; Draw 10 red pixels in a row
    MOV DI, 32160       ; Start at center
    MOV AL, 4           ; Red color
    MOV CX, 10          ; Counter = 10 pixels

DRAW_LINE:
    MOV ES:[DI], AL     ; Draw current pixel
    ADD DI, 321              ; Move to next pixel (right)
    LOOP DRAW_LINE      ; Repeat CX times (CX decrements automatically)

    ; Wait and exit
    MOV AH, 00H
    INT 16H

    ; Return to text mode
    MOV AH, 00H
    MOV AL, 03H
    INT 10H

    HLT

CODE ENDS
END START
