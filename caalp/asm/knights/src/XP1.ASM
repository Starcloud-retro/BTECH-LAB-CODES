XP1.ASM - XP and leveling system
Add XP gain, level up checks, stat growth
; XP1.ASM - XP and leveling system
ASSUME CS:CODE, DS:DATA

DATA SEGMENT
    PLAYER_LEVEL DW 1
    PLAYER_XP DW 0
    PLAYER_XP_NEXT DW 100

    PLAYER_HP DW 50
    PLAYER_MAX_HP DW 50
    PLAYER_ATK DW 5
    PLAYER_DEF DW 2

    XP_GAINED DW 50

    MSG_LEVEL_UP DB 'LEVEL UP!$'
    MSG_XP_GAIN DB 'Gained XP: $'
    MSG_STATS DB 'HP: $'
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX

    ; Simulate XP gain
    LEA DX, MSG_XP_GAIN
    MOV AH, 09H
    INT 21H

    MOV AX, [XP_GAINED]
    CALL PRINT_NUMBER

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; Add XP
    MOV AX, [XP_GAINED]
    ADD [PLAYER_XP], AX

    ; Check level up
    CALL CHECK_LEVEL_UP

    ; Show stats
    CALL SHOW_STATS

    MOV AH, 00H
    INT 16H
    HLT

CHECK_LEVEL_UP PROC
    MOV AX, [PLAYER_XP]
    CMP AX, [PLAYER_XP_NEXT]
    JL NO_LEVEL_UP

    ; Level up!
    INC WORD PTR [PLAYER_LEVEL]

    ; Subtract XP
    MOV AX, [PLAYER_XP_NEXT]
    SUB [PLAYER_XP], AX

    ; Calculate next XP (Level² × 100)
    MOV AX, [PLAYER_LEVEL]
    MUL AX
    MOV BX, 100
    MUL BX
    MOV [PLAYER_XP_NEXT], AX

    ; Increase stats
    ; MAX HP = 50 + (Level × 5)
    MOV AX, [PLAYER_LEVEL]
    MOV BX, 5
    MUL BX
    ADD AX, 50
    MOV [PLAYER_MAX_HP], AX
    MOV [PLAYER_HP], AX

    ; ATK = 5 + (Level × 2)
    MOV AX, [PLAYER_LEVEL]
    MOV BX, 2
    MUL BX
    ADD AX, 5
    MOV [PLAYER_ATK], AX

    ; DEF = 2 + Level
    MOV AX, [PLAYER_LEVEL]
    ADD AX, 2
    MOV [PLAYER_DEF], AX

    ; Show level up message
    LEA DX, MSG_LEVEL_UP
    MOV AH, 09H
    INT 21H

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

NO_LEVEL_UP:
    RET
CHECK_LEVEL_UP ENDP

SHOW_STATS PROC
    ; Show level
    MOV DL, 'L'
    MOV AH, 02H
    INT 21H
    MOV DL, 'V'
    INT 21H
    MOV DL, 'L'
    INT 21H
    MOV DL, ':'
    INT 21H
    MOV DL, ' '
    INT 21H

    MOV AX, [PLAYER_LEVEL]
    CALL PRINT_NUMBER

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; Show HP
    LEA DX, MSG_STATS
    MOV AH, 09H
    INT 21H

    MOV AX, [PLAYER_MAX_HP]
    CALL PRINT_NUMBER

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    RET
SHOW_STATS ENDP

PRINT_NUMBER PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    XOR CX, CX
    MOV BX, 10
PN_DIV:
    XOR DX, DX
    DIV BX
    PUSH DX
    INC CX
    CMP AX, 0
    JNE PN_DIV
PN_PRINT:
    POP DX
    ADD DL, '0'
    MOV AH, 02H
    INT 21H
    LOOP PN_PRINT
    POP DX
    POP CX
    POP BX
    POP AX
    RET
PRINT_NUMBER ENDP

CODE ENDS
END START
