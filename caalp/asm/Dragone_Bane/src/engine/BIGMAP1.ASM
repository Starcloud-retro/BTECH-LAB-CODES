; ============================================
; BIGMAP1.ASM - 20×20 dungeon
; ============================================
; Change MAP definition to:

DATA SEGMENT
    MAP DB 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,1,1,1,0,0,0,0,0,2,2,2,0,0,0,0,1
        DB 1,0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1
        DB 1,0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,3,3,0,3,3,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        DB 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1

    PLAYER_X DW 2560
    PLAYER_Y DW 2560
DATA ENDS

; In raycasting, change bounds check from 100 to 400 (20×20)
; In collision check, change 9 to 19


; ============================================
; MINIMAP1.ASM - Minimap overlay
; ============================================
; Add at end of rendering

DRAW_MINIMAP PROC
    ; Draw at top-right (280,10) as 40×40 pixel minimap
    MOV SI, 0
    MOV BX, 10
MM_ROW:
    MOV CX, 280
MM_COL:
    ; Get map tile
    MOV AX, SI
    MOV DX, 20
    DIV DX
    ; AX = tile_y, DX = tile_x
    PUSH AX
    MOV AX, SI
    MOV BX, 20
    XOR DX, DX
    DIV BX
    PUSH DX
    MOV BX, 20
    MUL BX
    POP DX
    ADD AX, DX
    MOV DI, AX
    POP AX

    ; Check if within bounds
    CMP DI, 400
    JGE MM_SKIP

    ; Get map color
    MOV AL, [MAP + DI]
    CMP AL, 0
    JE MM_EMPTY
    MOV AL, 15
    JMP MM_DRAW
MM_EMPTY:
    MOV AL, 0
MM_DRAW:

    ; Draw 2×2 pixel block
    PUSH SI
    PUSH BX
    PUSH CX

    MOV SI, BX
    MOV DI, 2
MM_BLOCK_Y:
    PUSH DI
    PUSH CX
    MOV DI, 2
MM_BLOCK_X:
    PUSH AX
    MOV AX, SI
    PUSH DX
    MOV DX, 320
    MUL DX
    POP DX
    ADD AX, CX
    MOV DI, AX
    POP AX
    MOV ES:[DI], AL
    INC CX
    DEC DI
    JNZ MM_BLOCK_X
    POP CX
    INC SI
    POP DI
    DEC DI
    JNZ MM_BLOCK_Y

    POP CX
    POP BX
    POP SI

MM_SKIP:
    ADD CX, 2
    INC SI
    CMP CX, 320
    JL MM_COL
    ADD BX, 2
    CMP BX, 50
    JL MM_ROW

    ; Draw player position
    MOV AX, [PLAYER_X]
    SHR AX, 8
    SHL AX, 1
    ADD AX, 280
    MOV CX, AX

    MOV AX, [PLAYER_Y]
    SHR AX, 8
    SHL AX, 1
    ADD AX, 10
    MOV BX, AX

    ; Draw 2×2 red dot for player
    MOV DI, 2
MM_PLAYER_Y:
    PUSH DI
    PUSH CX
    MOV DI, 2
MM_PLAYER_X:
    PUSH AX
    MOV AX, BX
    PUSH DX
    MOV DX, 320
    MUL DX
    POP DX
    ADD AX, CX
    MOV DI, AX
    MOV AL, 4
    MOV ES:[DI], AL
    POP AX
    INC CX
    DEC DI
    JNZ MM_PLAYER_X
    POP CX
    INC BX
    POP DI
    DEC DI
    JNZ MM_PLAYER_Y

    RET
DRAW_MINIMAP ENDP
