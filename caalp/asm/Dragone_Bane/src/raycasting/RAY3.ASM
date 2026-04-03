; RAY3.ASM - Full screen 3D raycasting
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

    ; Simplified sin/cos tables (only 8 directions for now)
    COS_TABLE DW 256, 181, 0, -181, -256, -181, 0, 181
    SIN_TABLE DW 0, 181, 256, 181, 0, -181, -256, -181

    CURRENT_ANGLE DB 0
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

    ; Clear screen
    XOR DI, DI
    MOV CX, 32000
    XOR AL, AL
    REP STOSW

    ; Draw 3D view
    CALL RENDER_3D

    MOV AH, 00H
    INT 16H
    MOV AH, 00H
    MOV AL, 03H
    INT 10H
    HLT

RENDER_3D PROC
    ; Cast 80 rays (every 4 pixels)
    MOV CX, 80
    MOV BX, 0
RENDER_COLUMN:
    PUSH CX
    PUSH BX

    ; Calculate ray angle (FOV = 60 degrees)
    ; For simplicity, using straight ahead only
    MOV SI, 0
    MOV AX, [COS_TABLE + SI]
    MOV DX, [SIN_TABLE + SI]

    ; Cast ray
    CALL CAST_RAY_3D

    ; Draw wall slice
    POP BX
    CALL DRAW_WALL_SLICE

    POP CX
    ADD BX, 4
    LOOP RENDER_COLUMN
    RET
RENDER_3D ENDP

CAST_RAY_3D PROC
    ; Ray from player position
    PUSH BX
    MOV BX, [PLAYER_X]
    MOV SI, [PLAYER_Y]
    MOV CX, 200
RAY_LOOP_3D:
    ADD BX, AX
    ADD SI, DX
    PUSH BX
    PUSH SI
    MOV DI, BX
    SHR DI, 8
    PUSH AX
    MOV AX, SI
    SHR AX, 8
    ; Check map
    PUSH BX
    MOV BX, 10
    MUL BX
    ADD AX, DI
    MOV DI, AX
    POP BX
    CMP DI, 100
    JGE RAY_HIT_3D
    MOV DH, [MAP + DI]
    POP AX
    POP SI
    POP BX
    CMP DH, 1
    JE RAY_HIT_3D
    LOOP RAY_LOOP_3D
RAY_HIT_3D:
    POP BX
    ; Distance in CX
    MOV [HIT_DIST], CX
    RET
CAST_RAY_3D ENDP

DRAW_WALL_SLICE PROC
    ; BX = screen X
    ; Calculate wall height from distance
    MOV AX, 2000
    MOV CX, [HIT_DIST]
    CMP CX, 0
    JE SKIP_SLICE
    XOR DX, DX
    DIV CX
    ; AX = wall height
    CMP AX, 200
    JL HEIGHT_OK
    MOV AX, 200
HEIGHT_OK:
    MOV CX, AX
    ; Center on screen
    MOV AX, 100
    SUB AX, CX
    SHR AX, 1
    MOV SI, AX
    ; Draw vertical line
DRAW_SLICE_LOOP:
    PUSH CX
    MOV AX, SI
    MOV DI, 320
    MUL DI
    ADD AX, BX
    MOV DI, AX
    MOV AL, 7
    MOV ES:[DI], AL
    INC SI
    POP CX
    LOOP DRAW_SLICE_LOOP
SKIP_SLICE:
    RET
DRAW_WALL_SLICE ENDP

HIT_DIST DW 0

CODE ENDS
END START
