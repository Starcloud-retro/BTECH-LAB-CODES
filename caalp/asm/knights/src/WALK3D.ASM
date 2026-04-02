; WALK3D.ASM - Complete 3D walking with all features
; This is COLLISION3D.ASM with better visuals and frame delay
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

    MSG_TITLE DB 'KNIGHT QUEST - WALK3D$'
    MSG_CONTROLS DB 'ARROWS=MOVE/TURN ESC=QUIT$'

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

    ; Show title
    LEA DX, MSG_TITLE
    MOV AH, 09H
    INT 21H
    LEA DX, MSG_CONTROLS
    MOV AH, 09H
    INT 21H

    MOV AH, 00H
    INT 16H

GAME_LOOP_W:
    MOV AH, 00H
    MOV AL, 13H
    INT 10H
    MOV AX, 0A000H
    MOV ES, AX

    CALL CLEAR_SCREEN_W
    CALL DRAW_FLOOR_CEILING
    CALL RENDER_VIEW_W
    CALL DELAY_FRAME

    MOV AH, 01H
    INT 16H
    JZ GAME_LOOP_W

    MOV AH, 00H
    INT 16H

    CMP AH, 01H
    JE EXIT_W
    CMP AH, 4DH
    JE TR_W
    CMP AH, 4BH
    JE TL_W
    CMP AH, 48H
    JE MF_W
    CMP AH, 50H
    JE MB_W
    JMP GAME_LOOP_W

TR_W:
    MOV AX, [PLAYER_ANGLE]
    ADD AX, 5
    CMP AX, 360
    JL TRW_OK
    SUB AX, 360
TRW_OK:
    MOV [PLAYER_ANGLE], AX
    JMP GAME_LOOP_W

TL_W:
    MOV AX, [PLAYER_ANGLE]
    SUB AX, 5
    CMP AX, 0
    JGE TLW_OK
    ADD AX, 360
TLW_OK:
    MOV [PLAYER_ANGLE], AX
    JMP GAME_LOOP_W

MF_W:
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
    ADD AX, CX
    MOV BX, [PLAYER_Y]
    ADD BX, DX
    CALL CHECK_COLLISION_W
    CMP AL, 0
    JNE GAME_LOOP_W

    ADD [PLAYER_X], CX
    ADD [PLAYER_Y], DX
    JMP GAME_LOOP_W

MB_W:
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
    CALL CHECK_COLLISION_W
    CMP AL, 0
    JNE GAME_LOOP_W

    SUB [PLAYER_X], CX
    SUB [PLAYER_Y], DX
    JMP GAME_LOOP_W

EXIT_W:
    MOV AH, 00H
    MOV AL, 03H
    INT 10H
    HLT

CHECK_COLLISION_W PROC
    PUSH AX
    PUSH BX
    SHR AX, 8
    SHR BX, 8
    CMP AX, 0
    JL COLL_W_YES
    CMP AX, 9
    JG COLL_W_YES
    CMP BX, 0
    JL COLL_W_YES
    CMP BX, 9
    JG COLL_W_YES
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
    RET
COLL_W_YES:
    POP BX
    POP AX
    MOV AL, 1
    RET
CHECK_COLLISION_W ENDP

CLEAR_SCREEN_W PROC
    XOR DI, DI
    MOV CX, 32000
    XOR AX, AX
    REP STOSW
    RET
CLEAR_SCREEN_W ENDP

DRAW_FLOOR_CEILING PROC
    ; Draw floor (bottom half)
    MOV DI, 32000
    MOV CX, 32000
    MOV AX, 0606H
    REP STOSW
    ; Draw ceiling (top half)
    XOR DI, DI
    MOV CX, 32000
    MOV AX, 0101H
    REP STOSW
    RET
DRAW_FLOOR_CEILING ENDP

RENDER_VIEW_W PROC
    MOV BX, 0
    MOV CX, 80
RVW_LP:
    PUSH CX
    PUSH BX
    MOV AX, [PLAYER_ANGLE]
    SUB AX, 30
    ADD AX, BX
    CMP AX, 0
    JGE RVW_CHK
    ADD AX, 360
RVW_CHK:
    CMP AX, 360
    JL RVW_OK
    SUB AX, 360
RVW_OK:
    MOV SI, AX
    SHL SI, 1
    MOV DX, [COS_TABLE + SI]
    MOV DI, [SIN_TABLE + SI]
    CALL CAST_RAY_W
    POP BX
    SHL BX, 2
    CALL DRAW_WALL_W
    POP CX
    INC BX
    LOOP RVW_LP
    RET
RENDER_VIEW_W ENDP

CAST_RAY_W PROC
    PUSH BX
    MOV BX, [PLAYER_X]
    MOV SI, [PLAYER_Y]
    MOV CX, 200
CRW_LP:
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
    JGE CRW_HIT
    MOV AL, [MAP + BP]
    POP AX
    POP SI
    POP BX
    CMP AL, 1
    JE CRW_HIT
    LOOP CRW_LP
CRW_HIT:
    POP BX
    MOV [TEMP_DIST_W], CX
    RET
CAST_RAY_W ENDP

DRAW_WALL_W PROC
    MOV AX, 5000
    MOV CX, [TEMP_DIST_W]
    CMP CX, 1
    JLE DWW_MAX
    XOR DX, DX
    DIV CX
    CMP AX, 200
    JLE DWW_OK
DWW_MAX:
    MOV AX, 200
DWW_OK:
    MOV CX, AX
    MOV AX, 100
    SUB AX, CX
    SHR AX, 1
    MOV SI, AX
DWW_LP:
    PUSH CX
    MOV AX, SI
    MOV DI, 320
    MUL DI
    ADD AX, BX
    MOV DI, AX
    MOV AL, 15
    MOV ES:[DI], AL
    INC SI
    POP CX
    LOOP DWW_LP
    RET
DRAW_WALL_W ENDP

DELAY_FRAME PROC
    MOV CX, 2000
DLY_LP:
    PUSH CX
    MOV CX, 1000
DLY_INNER:
    NOP
    LOOP DLY_INNER
    POP CX
    LOOP DLY_LP
    RET
DELAY_FRAME ENDP

TEMP_DIST_W DW 0

CODE ENDS
END START
