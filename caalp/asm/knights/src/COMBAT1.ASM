;COMBAT1.ASM - Basic turn-based combat system
;First combat system - player vs one monster, turn-based
; COMBAT1.ASM - Basic turn-based combat
ASSUME CS:CODE, DS:DATA

DATA SEGMENT
    PLAYER_HP DW 100
    PLAYER_MAX_HP DW 100
    PLAYER_ATK DW 10
    PLAYER_DEF DW 5

    MONSTER_HP DW 50
    MONSTER_MAX_HP DW 50
    MONSTER_ATK DW 8
    MONSTER_DEF DW 2

    MSG_ATTACK DB 'You attack!$'
    MSG_MONSTER_ATTACK DB 'Monster attacks!$'
    MSG_VICTORY DB 'VICTORY!$'
    MSG_DEFEAT DB 'GAME OVER!$'
    MSG_DAMAGE DB 'Damage: $'

    TEMP_DAMAGE DW 0
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX

COMBAT_LOOP:
    ; Clear screen
    MOV AH, 00H
    MOV AL, 03H
    INT 10H

    ; Show HP bars
    CALL DRAW_HP_BARS

    ; Player turn
    CALL PLAYER_ATTACK

    ; Check if monster dead
    MOV AX, [MONSTER_HP]
    CMP AX, 0
    JLE VICTORY

    ; Wait for key
    MOV AH, 00H
    INT 16H

    ; Monster turn
    CALL MONSTER_ATTACK_TURN

    ; Check if player dead
    MOV AX, [PLAYER_HP]
    CMP AX, 0
    JLE DEFEAT

    ; Wait for key
    MOV AH, 00H
    INT 16H

    JMP COMBAT_LOOP

VICTORY:
    LEA DX, MSG_VICTORY
    MOV AH, 09H
    INT 21H
    JMP EXIT_COMBAT

DEFEAT:
    LEA DX, MSG_DEFEAT
    MOV AH, 09H
    INT 21H

EXIT_COMBAT:
    MOV AH, 00H
    INT 16H
    HLT

DRAW_HP_BARS PROC
    ; Display player HP
    MOV DL, 'P'
    MOV AH, 02H
    INT 21H
    MOV DL, 'L'
    INT 21H
    MOV DL, 'A'
    INT 21H
    MOV DL, 'Y'
    INT 21H
    MOV DL, 'E'
    INT 21H
    MOV DL, 'R'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, 'H'
    INT 21H
    MOV DL, 'P'
    INT 21H
    MOV DL, ':'
    INT 21H
    MOV DL, ' '
    INT 21H

    MOV AX, [PLAYER_HP]
    CALL PRINT_NUMBER

    MOV DL, '/'
    MOV AH, 02H
    INT 21H

    MOV AX, [PLAYER_MAX_HP]
    CALL PRINT_NUMBER

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; Display monster HP
    MOV DL, 'M'
    INT 21H
    MOV DL, 'O'
    INT 21H
    MOV DL, 'N'
    INT 21H
    MOV DL, 'S'
    INT 21H
    MOV DL, 'T'
    INT 21H
    MOV DL, 'E'
    INT 21H
    MOV DL, 'R'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, 'H'
    INT 21H
    MOV DL, 'P'
    INT 21H
    MOV DL, ':'
    INT 21H
    MOV DL, ' '
    INT 21H

    MOV AX, [MONSTER_HP]
    CALL PRINT_NUMBER

    MOV DL, '/'
    MOV AH, 02H
    INT 21H

    MOV AX, [MONSTER_MAX_HP]
    CALL PRINT_NUMBER

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    RET
DRAW_HP_BARS ENDP

PLAYER_ATTACK PROC
    LEA DX, MSG_ATTACK
    MOV AH, 09H
    INT 21H

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; Calculate damage
    MOV AX, [PLAYER_ATK]
    MOV BX, [MONSTER_DEF]
    SUB AX, BX
    CMP AX, 1
    JGE DMG_OK
    MOV AX, 1
DMG_OK:
    MOV [TEMP_DAMAGE], AX

    ; Apply damage
    SUB [MONSTER_HP], AX

    ; Show damage
    LEA DX, MSG_DAMAGE
    MOV AH, 09H
    INT 21H

    MOV AX, [TEMP_DAMAGE]
    CALL PRINT_NUMBER

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    RET
PLAYER_ATTACK ENDP

MONSTER_ATTACK_TURN PROC
    LEA DX, MSG_MONSTER_ATTACK
    MOV AH, 09H
    INT 21H

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; Calculate damage
    MOV AX, [MONSTER_ATK]
    MOV BX, [PLAYER_DEF]
    SUB AX, BX
    CMP AX, 1
    JGE MDMG_OK
    MOV AX, 1
MDMG_OK:
    MOV [TEMP_DAMAGE], AX

    ; Apply damage
    SUB [PLAYER_HP], AX

    ; Show damage
    LEA DX, MSG_DAMAGE
    MOV AH, 09H
    INT 21H

    MOV AX, [TEMP_DAMAGE]
    CALL PRINT_NUMBER

    ; Newline
    MOV DL, 0DH
    MOV AH, 02H
    INT 21H
    MOV DL, 0AH
    INT 21H

    RET
MONSTER_ATTACK_TURN ENDP

PRINT_NUMBER PROC
    ; Print number in AX
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    XOR CX, CX
    MOV BX, 10
DIVIDE_LOOP:
    XOR DX, DX
    DIV BX
    PUSH DX
    INC CX
    CMP AX, 0
    JNE DIVIDE_LOOP

PRINT_LOOP:
    POP DX
    ADD DL, '0'
    MOV AH, 02H
    INT 21H
    LOOP PRINT_LOOP

    POP DX
    POP CX
    POP BX
    POP AX
    RET
PRINT_NUMBER ENDP

CODE ENDS
END START
