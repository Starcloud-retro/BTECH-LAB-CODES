; COLLISION3D.ASM - Add wall collision to movement
; (This builds on MOVE1.ASM - adds collision checking before moving)
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
    MOVE_SPEED DW 50

    SIN_TABLE DW 0,4,9,13,18,22,27,31,36,40,
           DW 44,49,53,58,62,66,71,75,79,83,
           DW 88,92,96,100,104,108,112,116,120,124,
           DW 128,132,136,139,143,147,150,154,158,161,
           DW 165,168,171,175,178,181,184,187,190,193,
           DW 196,199,202,204,207,210,212,215,217,219,
           DW 222,224,226,228,230,232,234,236,237,239,
           DW 241,242,243,245,246,247,248,249,250,251,
           DW 252,253,254,254,255,255,255,256,256,256,
           DW 256,256,256,256,255,255,255,254,254,253,
           DW 252,251,250,249,248,247,246,245,243,242,
           DW 241,239,237,236,234,232,230,228,226,224,
           DW 222,219,217,215,212,210,207,204,202,199,
           DW 196,193,190,187,184,181,178,175,171,168,
           DW 165,161,158,154,150,147,143,139,136,132,
           DW 128,124,120,116,112,108,104,100,96,92,
           DW 88,83,79,75,71,66,62,58,53,49,
           DW 44,40,36,31,27,22,18,13,9,4,
           DW 0,-4,-9,-13,-18,-22,-27,-31,-36,-40,
           DW -44,-49,-53,-58,-62,-66,-71,-75,-79,-83,
           DW -88,-92,-96,-100,-104,-108,-112,-116,-120,-124,
           DW -128,-132,-136,-139,-143,-147,-150,-154,-158,-161,
           DW -165,-168,-171,-175,-178,-181,-184,-187,-190,-193,
           DW -196,-199,-202,-204,-207,-210,-212,-215,-217,-219,
           DW -222,-224,-226,-228,-230,-232,-234,-236,-237,-239,
           DW -241,-242,-243,-245,-246,-247,-248,-249,-250,-251,
           DW -252,-253,-254,-254,-255,-255,-255,-256,-256,-256,
           DW -256,-256,-256,-256,-255,-255,-255,-254,-254,-253,
           DW -252,-251,-250,-249,-248,-247,-246,-245,-243,-242,
           DW -241,-239,-237,-236,-234,-232,-230,-228,-226,-224,
           DW -222,-219,-217,-215,-212,-210,-207,-204,-202,-199,
           DW -196,-193,-190,-187,-184,-181,-178,-175,-171,-168,
           DW -165,-161,-158,-154,-150,-147,-143,-139,-136,-132,
           DW -128,-124,-120,-116,-112,-108,-104,-100,-96,-92,
           DW -88,-83,-79,-75,-71,-66,-62,-58,-53,-49,
           DW -44,-40,-36,-31,-27,-22,-18,-13,-9,-4
    COS_TABLE DW 256,256,256,256,255,255,255,254,254,253,
           DW 252,251,250,249,248,247,246,245,243,242,
           DW 241,239,237,236,234,232,230,228,226,224,
           DW 222,219,217,215,212,210,207,204,202,199,
           DW 196,193,190,187,184,181,178,175,171,168,
           DW 165,161,158,154,150,147,143,139,136,132,
           DW 128,124,120,116,112,108,104,100,96,92,
           DW 88,83,79,75,71,66,62,58,53,49,
           DW 44,40,36,31,27,22,18,13,9,4,
           DW 0,-4,-9,-13,-18,-22,-27,-31,-36,-40,
           DW -44,-49,-53,-58,-62,-66,-71,-75,-79,-83,
           DW -88,-92,-96,-100,-104,-108,-112,-116,-120,-124,
           DW -128,-132,-136,-139,-143,-147,-150,-154,-158,-161,
           DW -165,-168,-171,-175,-178,-181,-184,-187,-190,-193,
           DW -196,-199,-202,-204,-207,-210,-212,-215,-217,-219,
           DW -222,-224,-226,-228,-230,-232,-234,-236,-237,-239,
           DW -241,-242,-243,-245,-246,-247,-248,-249,-250,-251,
           DW -252,-253,-254,-254,-255,-255,-255,-256,-256,-256,
           DW -256,-256,-256,-256,-255,-255,-255,-254,-254,-253,
           DW -252,-251,-250,-249,-248,-247,-246,-245,-243,-242,
           DW -241,-239,-237,-236,-234,-232,-230,-228,-226,-224,
           DW -222,-219,-217,-215,-212,-210,-207,-204,-202,-199,
           DW -196,-193,-190,-187,-184,-181,-178,-175,-171,-168,
           DW -165,-161,-158,-154,-150,-147,-143,-139,-136,-132,
           DW -128,-124,-120,-116,-112,-108,-104,-100,-96,-92,
           DW -88,-83,-79,-75,-71,-66,-62,-58,-53,-49,
           DW -44,-40,-36,-31,-27,-22,-18,-13,-9,-4,
           DW 0,4,9,13,18,22,27,31,36,40,
           DW 44,49,53,58,62,66,71,75,79,83,
           DW 88,92,96,100,104,108,112,116,120,124,
           DW 128,132,136,139,143,147,150,154,158,161,
           DW 165,168,171,175,178,181,184,187,190,193,
           DW 196,199,202,204,207,210,212,215,217,219,
           DW 222,224,226,228,230,232,234,236,237,239,
           DW 241,242,243,245,246,247,248,249,250,251,
           DW 252,253,254,254,255,255,255,256,256,256
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX

GAME_LOOP_C:
    MOV AH, 00H
    MOV AL, 13H
    INT 10H
    MOV AX, 0A000H
    MOV ES, AX

    CALL CLEAR_SCREEN_C
    CALL RENDER_VIEW_C

    MOV AH, 01H
    INT 16H
    JZ GAME_LOOP_C

    MOV AH, 00H
    INT 16H

    CMP AH, 01H
    JE EXIT_C
    CMP AH, 4DH
    JE TR_C
    CMP AH, 4BH
    JE TL_C
    CMP AH, 48H
    JE MF_C
    CMP AH, 50H
    JE MB_C
    JMP GAME_LOOP_C

TR_C:
    MOV AX, [PLAYER_ANGLE]
    ADD AX, 5
    CMP AX, 360
    JL TRC_OK
    SUB AX, 360
TRC_OK:
    MOV [PLAYER_ANGLE], AX
    JMP GAME_LOOP_C

TL_C:
    MOV AX, [PLAYER_ANGLE]
    SUB AX, 5
    CMP AX, 0
    JGE TLC_OK
    ADD AX, 360
TLC_OK:
    MOV [PLAYER_ANGLE], AX
    JMP GAME_LOOP_C

MF_C:
    ; Calculate new position
    MOV AX, [PLAYER_ANGLE]
    MOV SI, AX
    SHL SI, 1
    MOV AX, [COS_TABLE + SI]
    MOV BX, [SIN_TABLE + SI]
    IMUL [MOVE_SPEED]
    SAR AX, 8
    MOV CX, AX
    MOV AX, BX
    IMUL [MOVE_SPEED]
    SAR AX, 8
    MOV DX, AX

    ; Check collision
    MOV AX, [PLAYER_X]
    ADD AX, CX
    MOV BX, [PLAYER_Y]
    ADD BX, DX
    CALL CHECK_COLLISION
    CMP AL, 0
    JNE GAME_LOOP_C

    ; No collision - move
    ADD [PLAYER_X], CX
    ADD [PLAYER_Y], DX
    JMP GAME_LOOP_C

MB_C:
    MOV AX, [PLAYER_ANGLE]
    MOV SI, AX
    SHL SI, 1
    MOV AX, [COS_TABLE + SI]
    MOV BX, [SIN_TABLE + SI]
    IMUL [MOVE_SPEED]
    SAR AX, 8
    MOV CX, AX
    MOV AX, BX
    IMUL [MOVE_SPEED]
    SAR AX, 8
    MOV DX, AX

    MOV AX, [PLAYER_X]
    SUB AX, CX
    MOV BX, [PLAYER_Y]
    SUB BX, DX
    CALL CHECK_COLLISION
    CMP AL, 0
    JNE GAME_LOOP_C

    SUB [PLAYER_X], CX
    SUB [PLAYER_Y], DX
    JMP GAME_LOOP_C

EXIT_C:
    MOV AH, 00H
    MOV AL, 03H
    INT 10H
    HLT

CHECK_COLLISION PROC
    ; AX = new X, BX = new Y
    ; Returns AL = 1 if collision, 0 if clear
    PUSH AX
    PUSH BX
    SHR AX, 8
    SHR BX, 8
    ; Check bounds
    CMP AX, 0
    JL COLLISION_YES
    CMP AX, 9
    JG COLLISION_YES
    CMP BX, 0
    JL COLLISION_YES
    CMP BX, 9
    JG COLLISION_YES
    ; Check map
    PUSH AX
    MOV AX, BX
    MOV BX, 10
    MUL BX
    POP BX
    ADD AX, BX
    MOV SI, AX
    MOV AL, [MAP + SI]
    POP BX
    POP BX
    ; AL already has map value (1 = wall)
    RET
COLLISION_YES:
    POP BX
    POP AX
    MOV AL, 1
    RET
CHECK_COLLISION ENDP

CLEAR_SCREEN_C PROC
    XOR DI, DI
    MOV CX, 32000
    XOR AX, AX
    REP STOSW
    RET
CLEAR_SCREEN_C ENDP

RENDER_VIEW_C PROC
    MOV BX, 0
    MOV CX, 80
RVC_LOOP:
    PUSH CX
    PUSH BX
    MOV AX, [PLAYER_ANGLE]
    SUB AX, 30
    ADD AX, BX
    CMP AX, 0
    JGE RVC_CHK
    ADD AX, 360
RVC_CHK:
    CMP AX, 360
    JL RVC_OK
    SUB AX, 360
RVC_OK:
    MOV SI, AX
    SHL SI, 1
    MOV DX, [COS_TABLE + SI]
    MOV DI, [SIN_TABLE + SI]
    CALL CAST_RAY_C
    POP BX
    SHL BX, 2
    CALL DRAW_WALL_C
    POP CX
    INC BX
    LOOP RVC_LOOP
    RET
RENDER_VIEW_C ENDP

CAST_RAY_C PROC
    PUSH BX
    MOV BX, [PLAYER_X]
    MOV SI, [PLAYER_Y]
    MOV CX, 200
CRC_LP:
    ADD BX, DX
    ADD SI, DI
    PUSH BX
    PUSH SI
    PUSH AX
    MOV AX, BX
    SHR AX, 8
    MOV BP, AX
    MOV AX, SI
    SHR AX, 8
    PUSH BX
    MOV BX, 10
    MUL BX
    ADD AX, BP
    MOV BP, AX
    POP BX
    CMP BP, 100
    JGE CRC_HIT
    MOV AL, [MAP + BP]
    POP AX
    POP SI
    POP BX
    CMP AL, 1
    JE CRC_HIT
    LOOP CRC_LP
CRC_HIT:
    POP BX
    MOV [TEMP_DIST_C], CX
    RET
CAST_RAY_C ENDP

DRAW_WALL_C PROC
    MOV AX, 5000
    MOV CX, [TEMP_DIST_C]
    CMP CX, 1
    JLE DWC_MAX
    XOR DX, DX
    DIV CX
    CMP AX, 200
    JLE DWC_OK
DWC_MAX:
    MOV AX, 200
DWC_OK:
    MOV CX, AX
    MOV AX, 100
    SUB AX, CX
    SHR AX, 1
    MOV SI, AX
DWC_LP:
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
    LOOP DWC_LP
    RET
DRAW_WALL_C ENDP

TEMP_DIST_C DW 0

CODE ENDS
END START
