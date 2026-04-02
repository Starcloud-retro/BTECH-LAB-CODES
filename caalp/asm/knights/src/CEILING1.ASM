; ============================================
; CEILING1.ASM - Ceiling rendering
; ============================================
; Same as FLOOR but for rows 0-99

RENDER_CEILING PROC
    MOV BX, 0
    MOV CX, 80
RC_COL:
    PUSH CX
    PUSH BX

    MOV SI, 0
RC_ROW:
    PUSH SI

    MOV AL, 1
    CMP SI, 50
    JL NEAR_CEIL
    MOV AL, 8
NEAR_CEIL:

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
    CMP SI, 100
    JL RC_ROW

    POP BX
    INC BX
    POP CX
    LOOP RC_COL
    RET
RENDER_CEILING ENDP
