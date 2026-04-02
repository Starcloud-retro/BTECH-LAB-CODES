ASSUME CS:CODE,DS:DATA
DATA SEGMENT
        ARR DB 13H,56H,67H,08H,0A5H
DATA ENDS
CODE SEGMENT
        MOV AX,DATA
        MOV DS,AX
        MOV SI, OFFSET ARR
        MOV CL,04H
        MOV AL, [SI]
        INC SI

  BACK: MOV BL,[SI]
        CMP AL,BL
        JA GO
        XCHG AL,BL
        GO: INC SI
        DEC CL
        JNZ BACK
        MOV[SI],AL
        INT 03H
CODE ENDS
END
