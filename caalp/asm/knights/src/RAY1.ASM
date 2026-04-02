; RAY1.ASM - Single ray visualization (top-down view)
ASSUME CS:CODE, DS:DATA

DATA SEGMENT
    ; 10x10 map (1=wall, 0=empty)
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

    PLAYER_X DW 1280
    PLAYER_Y DW 1280
    RAY_DX DW 256
    RAY_DY DW 0
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

    CALL DRAW_MAP
    CALL DRAW_PLAYER
    CALL CAST_RAY

    MOV AH, 00H
    INT 16H
    MOV AH, 00H
    MOV AL, 03H
    INT 10H
    HLT

DRAW_MAP PROC
    MOV SI, 0
    MOV BX, 0
MAP_ROW:
    MOV CX, 0
MAP_COL:
    MOV AL, [MAP + SI]
    CMP AL, 1
    JE DRAW_WALL_TILE
    MOV AL, 0
    JMP DRAW_TILE
DRAW_WALL_TILE:
    MOV AL, 7
DRAW_TILE:
    PUSH SI
    PUSH BX
    PUSH CX
    MOV DH, 20
TILE_ROW:
    PUSH DH
    PUSH BX
    PUSH CX
    MOV DH, 20
TILE_COL:
    PUSH AX
    MOV AX, BX
    MOV DI, 320
    MUL DI
    ADD AX, CX
    MOV DI, AX
    POP AX
    MOV ES:[DI], AL
    INC CX
    DEC DH
    JNZ TILE_COL
    POP CX
    POP BX
    INC BX
    POP DH
    DEC DH
    JNZ TILE_ROW
    POP CX
    POP BX
    POP SI
    INC SI
    ADD CX, 20
    CMP CX, 200
    JL MAP_COL
    ADD BX, 20
    CMP BX, 200
    JL MAP_ROW
    RET
DRAW_MAP ENDP

DRAW_PLAYER PROC
    MOV AX, [PLAYER_X]
    SHR AX, 8
    MOV BX, 20
    MUL BX
    MOV CX, AX
    MOV AX, [PLAYER_Y]
    SHR AX, 8
    MOV BX, 20
    MUL BX
    MOV BX, AX
    MOV DH, 3
PLAYER_ROW:
    PUSH DH
    PUSH BX
    PUSH CX
    MOV DH, 3
PLAYER_COL:
    PUSH AX
    MOV AX, BX
    MOV DI, 320
    MUL DI
    ADD AX, CX
    MOV DI, AX
    POP AX
    MOV AL, 4
    MOV ES:[DI], AL
    INC CX
    DEC DH
    JNZ PLAYER_COL
    POP CX
    POP BX
    INC BX
    POP DH
    DEC DH
    JNZ PLAYER_ROW
    RET
DRAW_PLAYER ENDP

CAST_RAY PROC
    MOV AX, [PLAYER_X]
    MOV BX, [PLAYER_Y]
    MOV CX, 256
RAY_STEP:
    ADD AX, [RAY_DX]
    ADD BX, [RAY_DY]
    MOV SI, AX
    SHR SI, 8
    MOV DI, BX
    SHR DI, 8
    PUSH AX
    PUSH BX
    MOV AX, DI
    MOV BX, 10
    MUL BX
    ADD AX, SI
    MOV SI, AX
    MOV AL, [MAP + SI]
    CMP AL, 1
    POP BX
    POP AX
    JE RAY_HIT
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH AX
    MOV AX, BX
    SHR AX, 8
    MOV BX, 20
    MUL BX
    MOV BX, AX
    POP AX
    SHR AX, 8
    MOV CX, 20
    MUL CX
    MOV CX, AX
    MOV AX, BX
    MOV DI, 320
    MUL DI
    ADD AX, CX
    MOV DI, AX
    MOV AL, 4
    MOV ES:[DI], AL
    POP CX
    POP BX
    POP AX
    LOOP RAY_STEP
RAY_HIT:
    RET
CAST_RAY ENDP

CODE ENDS
END START
