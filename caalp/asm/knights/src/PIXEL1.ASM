ASSUME CS:CODE, DS:DATA

DATA SEGMENT
DATA ENDS

CODE SEGMENT
START:
        MOV AX,DATA
        MOV DS,AX

        ;SWITCH TO MODE 13H
        MOV AH,00H ;BIOS FUNCTION:SET VIDEO MODE
        MOV AL,13H ;MODE 13H=320X320,256 COLOURS
        INT 10H ;CALL BIOS

        ;POINT ES TO VIDEO MEMORY
        MOV AX,0A000H
        MOV ES,AX

        ;CALCULATE CENTER POSITION
        ;CENTER = (160,100)
        ;OFFSET = (100 X 320) + 160 = 32160
        MOV DI,32160 ;DI=OFFSET FOR CENTER PIXEL

        ; Draw 5x5 red square (easier to see)
        MOV AL, 4           ; Color 4 = Red
        MOV CX, 5           ; 5 rows
        DRAW_ROW:
        PUSH CX
        PUSH DI
        MOV CX, 5           ; 5 pixels per row
        DRAW_COL:
        MOV ES:[DI], AL
        INC DI
        LOOP DRAW_COL
        POP DI
        ADD DI, 320         ; Next row
        POP CX
        LOOP DRAW_ROW

        ;WAIT FOR KEYPRESS
        MOV AH,00H
        INT 16H ;CALL KEYBOARD INTERRUPT

        ;RETURN TO TEXT MODE
        MOV AH,00H
        MOV AL,03H
        INT 10H

        HLT

CODE ENDS
END START
