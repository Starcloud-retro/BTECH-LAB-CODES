; KNIGHT1.ASM - Display 16x16 knight sprite
ASSUME CS:CODE, DS:DATA

DATA SEGMENT
    KNIGHT DB 0,0,0,7,7,7,7,7,7,7,7,7,7,0,0,0
           DB 0,0,7,7,7,7,7,7,7,7,7,7,7,7,0,0
           DB 0,7,7,6,6,6,6,6,6,6,6,6,6,7,7,0
           DB 7,7,6,6,6,6,6,6,6,6,6,6,6,6,7,7
           DB 7,7,6,0,6,6,6,6,6,6,6,0,6,6,7,7
           DB 7,7,6,6,6,6,6,6,6,6,6,6,6,6,7,7
           DB 0,7,7,6,6,4,4,4,4,4,4,6,6,7,7,0
           DB 0,0,7,7,6,6,6,6,6,6,6,6,7,7,0,0
           DB 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
           DB 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
           DB 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
           DB 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
           DB 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
           DB 0,7,7,0,0,7,7,7,7,7,7,0,0,7,7,0
           DB 0,7,7,0,0,7,7,0,0,7,7,0,0,7,7,0
           DB 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

    KNIGHT_X DW 152
    KNIGHT_Y DW 92
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX

    MOV AH, 00H
    MOV AL, 13H
    INT 10H

    MOV AX, 0A000H
    MOV ES, AX

    MOV AX, [KNIGHT_Y]
    MOV BX, 320
    MUL BX
    ADD AX, [KNIGHT_X]
    MOV DI, AX

    LEA SI, KNIGHT
    MOV BX, 16
DRAW_KNIGHT_ROW:
    PUSH BX
    PUSH DI
    MOV CX, 16
DRAW_KNIGHT_COL:
    LODSB
    CMP AL, 0
    JE SKIP_TRANSPARENT
    MOV ES:[DI], AL
SKIP_TRANSPARENT:
    INC DI
    LOOP DRAW_KNIGHT_COL

    POP DI
    ADD DI, 320
    POP BX
    DEC BX
    JNZ DRAW_KNIGHT_ROW

    MOV AH, 00H
    INT 16H

    MOV AH, 00H
    MOV AL, 03H
    INT 10H

    HLT
CODE ENDS
END START
