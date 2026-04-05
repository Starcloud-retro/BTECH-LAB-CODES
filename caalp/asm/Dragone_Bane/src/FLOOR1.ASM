; ============================================
; FLOOR1.ASM - Floor rendering
; ============================================
; Add after wall rendering loop

RENDER_FLOOR PROC
    MOV BX, 0
    MOV CX, 80
RF_COL:
    PUSH CX
    PUSH BX

    ; For each row from 100 to 200 (bottom half)
    MOV SI, 100
RF_ROW:
    PUSH SI

    ; Calculate floor distance
    MOV AX, 200
    SUB AX, SI
    ; Simple floor color based on distance
    MOV AL, 6
    CMP SI, 150
    JL NEAR_FLOOR
    MOV AL, 14
NEAR_FLOOR:

    ; Draw pixel at (BX*4, SI)
    PUSH BX
    SHL BX, 2
    PUSH AX
    MOV AX, SI
    MOV DI, 320
    MUL DI
    ADD AX, BX
    MOV DI, AX
    POP AX
    MOV ES:[DI], AL
    POP BX

    POP SI
    INC SI
    CMP SI, 200
    JL RF_ROW

    POP BX
    INC BX
    POP CX
    LOOP RF_COL
    RET
RENDER_FLOOR ENDP
