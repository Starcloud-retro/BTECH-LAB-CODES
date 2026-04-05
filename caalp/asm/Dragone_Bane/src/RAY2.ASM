; RAY2_CLEAN.ASM - DDA raycasting (TASM SAFE)
ASSUME CS:CODE, DS:DATA

DATA SEGMENT
MAP DB 1,1,1,1,1,1,1,1,1,1
    DB 1,0,0,0,0,0,0,0,0,1
    DB 1,0,0,0,0,0,0,0,0,1
    DB 1,0,0,0,1,1,0,0,0,1
    DB 1,0,0,0,1,0,0,0,0,1
    DB 1,0,0,0,0,0,0,0,0,1
    DB 1,0,0,0,0,0,0,0,0,1
    DB 1,0,0,0,0,0,0,0,0,1
    DB 1,0,0,0,0,0,0,0,0,1
    DB 1,1,1,1,1,1,1,1,1,1

PLAYER_X DW 5
PLAYER_Y DW 5

DIR_X DW 0
DIR_Y DW -1

DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX

    MOV AX, 13H
    INT 10H

    MOV AX, 0A000H
    MOV ES, AX

    CALL DRAW_MAP
    CALL DRAW_PLAYER
    CALL CAST_RAY

    MOV AH,0
    INT 16H

    MOV AX,3
    INT 10H

    MOV AH,4CH
    INT 21H

; =====================

DRAW_MAP PROC
    MOV SI,0
    MOV BX,0

ROW:
    MOV CX,0

COL:
    MOV AL,[MAP+SI]

    CMP AL,1
    JE WALL
    MOV AL,0
    JMP DRAW

WALL:
    MOV AL,7

DRAW:
    MOV DX,BX
    MOV AX,DX
    MOV BX,320
    MUL BX
    ADD AX,CX
    MOV DI,AX

    MOV ES:[DI],AL

    INC CX
    INC SI
    CMP CX,100
    JL COL

    INC BX
    CMP BX,100
    JL ROW

    RET
DRAW_MAP ENDP

; =====================

DRAW_PLAYER PROC
    MOV AX,[PLAYER_Y]
    MOV BX,320
    MUL BX
    ADD AX,[PLAYER_X]
    MOV DI,AX

    MOV AL,4
    MOV ES:[DI],AL

    RET
DRAW_PLAYER ENDP

; =====================

CAST_RAY PROC
    MOV AX,[PLAYER_X]
    MOV BX,[PLAYER_Y]

    MOV CX,100   ; max steps

RAY_LOOP:

    ADD AX,[DIR_X]
    ADD BX,[DIR_Y]

    ; check bounds
    CMP AX,0
    JL END_RAY
    CMP AX,9
    JG END_RAY

    CMP BX,0
    JL END_RAY
    CMP BX,9
    JG END_RAY

    ; map index = y*10 + x
    MOV DX,BX
    MOV SI,DX
    MOV DX,10
    MUL DX
    ADD AX,SI
    MOV SI,AX

    MOV DL,[MAP+SI]
    CMP DL,1
    JE END_RAY

    ; draw ray
    MOV DX,BX
    MOV SI,DX
    MOV DX,320
    MUL DX
    ADD AX,SI
    MOV DI,AX

    MOV AL,12
    MOV ES:[DI],AL

    LOOP RAY_LOOP

END_RAY:
    RET
CAST_RAY ENDP

CODE ENDS
END START