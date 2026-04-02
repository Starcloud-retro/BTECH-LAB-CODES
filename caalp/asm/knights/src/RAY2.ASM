; RAY2.ASM - DDA (Digital Differential Analyzer) raycasting
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

    PLAYER_X DW 1536
    PLAYER_Y DW 1536
    PLAYER_ANGLE DW 0

    ; Ray hit info
    HIT_DIST DW 0
    HIT_SIDE DB 0

    ; Direction vectors (will be calculated)
    DIR_X DW 256
    DIR_Y DW 0
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
    CALL CAST_DDA_RAY
    CALL DRAW_RAY_RESULT

    MOV AH, 00H
    INT 16H
    MOV AH, 00H
    MOV AL, 03H
    INT 10H
    HLT

DRAW_MAP PROC
    MOV SI, 0
    MOV BX, 0
MAP_ROW_2:
    MOV CX, 0
MAP_COL_2:
    MOV AL, [MAP + SI]
    CMP AL, 1
    JE DRAW_WALL_2
    MOV AL, 0
    JMP DRAW_TILE_2
DRAW_WALL_2:
    MOV AL, 7
DRAW_TILE_2:
    PUSH SI
    PUSH BX
    PUSH CX
    MOV DH, 20
TILE_ROW_2:
    PUSH DH
    PUSH BX
    PUSH CX
    MOV DH, 20
TILE_COL_2:
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
    JNZ TILE_COL_2
    POP CX
    POP BX
    INC BX
    POP DH
    DEC DH
    JNZ TILE_ROW_2
    POP CX
    POP BX
    POP SI
    INC SI
    ADD CX, 20
    CMP CX, 200
    JL MAP_COL_2
    ADD BX, 20
    CMP BX, 200
    JL MAP_ROW_2
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
    MOV DH, 4
PLAYER_ROW_2:
    PUSH DH
    PUSH BX
    PUSH CX
    MOV DH, 4
PLAYER_COL_2:
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
    JNZ PLAYER_COL_2
    POP CX
    POP BX
    INC BX
    POP DH
    DEC DH
    JNZ PLAYER_ROW_2
    RET
DRAW_PLAYER ENDP

CAST_DDA_RAY PROC
    ; Simple DDA - step until hit wall
    MOV AX, [PLAYER_X]
    MOV BX, [PLAYER_Y]
    MOV CX, 0
DDA_LOOP:
    ADD AX, [DIR_X]
    ADD BX, [DIR_Y]
    INC CX
    PUSH AX
    PUSH BX
    MOV SI, AX
    SHR SI, 8
    MOV DI, BX
    SHR DI, 8
    ; Check bounds
    CMP SI, 0
    JL DDA_HIT
    CMP SI, 9
    JG DDA_HIT
    CMP DI, 0
    JL DDA_HIT
    CMP DI, 9
    JG DDA_HIT
    ; Check map
    PUSH AX
    MOV AX, DI
    MOV BX, 10
    MUL BX
    ADD AX, SI
    MOV SI, AX
    POP AX
    MOV DL, [MAP + SI]
    POP BX
    POP AX
    CMP DL, 1
    JE DDA_HIT
    CMP CX, 500
    JL DDA_LOOP
DDA_HIT:
    MOV [HIT_DIST], CX
    RET
CAST_DDA_RAY ENDP

DRAW_RAY_RESULT PROC
    ; Draw line from player to hit point
    MOV AX, [PLAYER_X]
    MOV BX, [PLAYER_Y]
    MOV CX, [HIT_DIST]
DRAW_RAY_LINE:
    PUSH CX
    PUSH AX
    PUSH BX
    PUSH AX
    MOV AX, BX
    SHR AX, 8
    MOV BX, 20
    MUL BX
    MOV BX, AX
    POP AX
    SHR AX, 8
    PUSH CX
    MOV CX, 20
    MUL CX
    POP CX
    MOV DI, BX
    PUSH AX
    MOV AX, DI
    MOV DI, 320
    MUL DI
    POP DI
    ADD AX, DI
    MOV DI, AX
    MOV AL, 12
    MOV ES:[DI], AL
    POP BX
    POP AX
    ADD AX, [DIR_X]
    ADD BX, [DIR_Y]
    POP CX
    LOOP DRAW_RAY_LINE
    RET
DRAW_RAY_RESULT ENDP

CODE ENDS
END START
