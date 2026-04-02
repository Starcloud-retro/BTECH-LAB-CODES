ASSUME CS:CODE,DS:DATA
DATA SEGMENT
        COU DB 0AH
        ARRNUM DB 0AH DUP(0)
DATA ENDS
CODE SEGMENT       
        MOV AX,DATA
        MOV DS,AX
        MOV SI, OFFSET ARRNUM
        MOV AL,00H
  BACK: MOV [SI],AL
        DEC CL
        JZ GO
        INC AL
        INC SI
        JMP BACK
  GO:HLT
CODE ENDS
END


