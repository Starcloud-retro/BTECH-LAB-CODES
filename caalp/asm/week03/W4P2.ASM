ASSUME CS:CODE, DS:DATA
DATA SEGMENT
        NUM1 DB "ENTER THE NUMBER:$"
        TEMP DB ?
        FIBARR DB 10 DUP(0)
DATA ENDS
CODE SEGMENT
                MOV AX,DATA
                MOV DS,AX
                MOV SI,OFFSET FIBARR
                LEA DX,NUM1
                MOV AH,09H
                INT 21H

                MOV AH,01H
                INT 21H

                SUB AL,30H
                MOV CL,AL

                MOV AL,00
                MOV [SI],AL
                ADD AL,30H
                MOV DL,AL
                MOV AH,02H
                INT 21H

                MOV AL,01H
                MOV [SI+1],AL

                ADD AL,30H
                MOV DL,AL
                MOV AH,02H
                INT 21H

        LBL1:   MOV AL,[SI]
        ADD AL,[SI+1]
        MOV [SI+2],AL
        ADD AL,30H
        MOV DL,AL
        MOV AH,02H
        INT 21H
        INC SI

        LOOP LBL1
        MOV AH,4CH
        INT 21H
CODE ENDS
END
