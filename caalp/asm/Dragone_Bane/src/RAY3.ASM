; ===== FINAL STEP5 - STABLE RAYCAST + TEXTURE =====

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

; simple 8x8 texture
TEXTURE DB 7,8,7,8,7,8,7,8
        DB 8,7,8,7,8,7,8,7
        DB 7,8,7,8,7,8,7,8
        DB 8,7,8,7,8,7,8,7
        DB 7,8,7,8,7,8,7,8
        DB 8,7,8,7,8,7,8,7
        DB 7,8,7,8,7,8,7,8
        DB 8,7,8,7,8,7,8,7

PX DW 1280
PY DW 1280
DIR DB 0

RX DW 0
RY DW 0
DIST DW 0
COL DW 0
TEX_X DB 0

DATA ENDS

CODE SEGMENT

START:
    MOV AX, DATA
    MOV DS, AX

    MOV AX, 0013H
    INT 10H

    MOV AX, 0A000H
    MOV ES, AX

MAIN_LOOP:

    ; clear screen
    XOR DI, DI
    MOV CX, 32000
    XOR AX, AX
    REP STOSW

    CALL RENDER
    CALL INPUT

    JMP MAIN_LOOP

; ======================
; INPUT
; ======================

INPUT PROC
    MOV AH,01H
    INT 16H
    JZ NO_KEY

    MOV AH,00H
    INT 16H

    CMP AH,01H
    JE EXIT

    CMP AH,4BH
    JE LEFT

    CMP AH,4DH
    JE RIGHT

    CMP AH,48H
    JE FORWARD

    CMP AH,50H
    JE BACK

NO_KEY:
    RET

LEFT:
    DEC BYTE PTR [DIR]
    AND BYTE PTR [DIR],3
    RET

RIGHT:
    INC BYTE PTR [DIR]
    AND BYTE PTR [DIR],3
    RET

FORWARD:
    CALL MOVE_F
    RET

BACK:
    CALL MOVE_B
    RET

EXIT:
    MOV AX,0003H
    INT 10H
    MOV AH,4CH
    INT 21H

INPUT ENDP

; ======================
; MOVEMENT
; ======================

MOVE_F PROC
    MOV AL,[DIR]
    CMP AL,0
    JE MF_E
    CMP AL,1
    JE MF_S
    CMP AL,2
    JE MF_W
    JMP MF_N

MF_E: ADD [PX],64  ; reduced step
      RET
MF_S: ADD [PY],64
      RET
MF_W: SUB [PX],64
      RET
MF_N: SUB [PY],64
      RET
MOVE_F ENDP

MOVE_B PROC
    MOV AL,[DIR]
    CMP AL,0
    JE MB_E
    CMP AL,1
    JE MB_S
    CMP AL,2
    JE MB_W
    JMP MB_N

MB_E: SUB [PX],64
      RET
MB_S: SUB [PY],64
      RET
MB_W: ADD [PX],64
      RET
MB_N: ADD [PY],64
      RET
MOVE_B ENDP

; ======================
; RENDER
; ======================

RENDER PROC
    MOV WORD PTR [COL],0

R_LOOP:
    MOV AX,[COL]
    SUB AX,40
    MOV BX,AX

    CALL CAST
    CALL DRAW

    INC WORD PTR [COL]
    CMP WORD PTR [COL],80
    JL R_LOOP

    RET
RENDER ENDP

; ======================
; CAST
; ======================

CAST PROC
    MOV AX,[PX]
    MOV [RX],AX
    MOV AX,[PY]
    MOV [RY],AX

    MOV CX,80

C_LOOP:

    MOV AL,[DIR]
    CMP AL,0
    JE CE
    CMP AL,1
    JE CS
    CMP AL,2
    JE CW
    JMP CN

CE:
    ADD [RX],64
    MOV AX,BX
    SHL AX,1
    ADD [RY],AX
    JMP CHECK

CS:
    ADD [RY],64
    MOV AX,BX
    SHL AX,1
    ADD [RX],AX
    JMP CHECK

CW:
    SUB [RX],64
    MOV AX,BX
    SHL AX,1
    SUB [RY],AX
    JMP CHECK

CN:
    SUB [RY],64
    MOV AX,BX
    SHL AX,1
    SUB [RX],AX

CHECK:
    PUSH CX
    CALL MAP_CHECK
    POP CX

    CMP AL,1
    JE HIT

    LOOP C_LOOP

HIT:
    MOV AX,80
    SUB AX,CX
    MOV [DIST],AX

    MOV AX,[RX]
    AND AL,7
    MOV [TEX_X],AL

    RET
CAST ENDP

; ======================
; MAP CHECK
; ======================

MAP_CHECK PROC
    MOV AX,[RX]
    SHR AX,8

    MOV BX,[RY]
    SHR BX,8

    CMP AX,0
    JL WALL
    CMP AX,9
    JG WALL
    CMP BX,0
    JL WALL
    CMP BX,9
    JG WALL

    MOV DX,10
    MUL DX
    ADD AX,BX

    LEA SI,MAP
    ADD SI,AX
    MOV AL,[SI]
    RET

WALL:
    MOV AL,1
    RET
MAP_CHECK ENDP

; ======================
; DRAW WITH TEXTURE
; ======================

DRAW PROC

    MOV AX,[DIST]
    CMP AX,1
    JG OK1
    MOV AX,1
OK1:

    MOV BX,AX
    MOV AX,2000
    XOR DX,DX
    DIV BX

    CMP AX,200
    JLE OK2
    MOV AX,200
OK2:

    MOV CX,AX

    MOV AX,100
    SUB AX,CX
    SHR AX,1
    MOV DI,AX

    MOV AX,[COL]
    SHL AX,2
    MOV BX,AX

    MOV DL,[TEX_X]

DRAW_LOOP:

    PUSH CX

    MOV AX,DI
    AND AX,7
    SHL AX,3
    ADD AL,DL
    MOV SI,AX

    LEA AX,TEXTURE
    ADD SI,AX
    MOV AL,[SI]

    MOV AX,DI
    MOV DX,320
    MUL DX
    ADD AX,BX
    MOV DI,AX

    MOV ES:[DI],AL

    INC DI
    POP CX
    LOOP DRAW_LOOP

    RET
DRAW ENDP

CODE ENDS
END START