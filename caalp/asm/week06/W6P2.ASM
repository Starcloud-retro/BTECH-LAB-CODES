ASSUME CS:CODE, DS:DATA
DATA SEGMENT
	 V DB 9,6,7,8
DATA ENDS
CODE SEGMENT
	 	 	 MOV AX,DATA
	 	 	 MOV DS,AX
	 	 	 MOV CH,4
	 	 	 MOV AL,0
	 	 ITER:
	 	 	 MOV BX,0
	 	 NEXT:
	 	 	 MOV AL,V[BX]
	 	 	 CMP AL,V[BX+1]
	 	 	 JNL SWAP
	 	 	 JL CON
	 	 SWAP:
	 	 	 MOV DL,V[BX]
	 	 	 MOV AL,V[BX+1]
	 	 	 MOV V[BX+1],DL
	 	 	 MOV V[BX],AL
	 	 CON:
	 	 	 INC BX
	 	 	 CMP BX,3
	 	 	 JNZ NEXT
	 	 	 DEC CH
	 	 	 CMP CH,0
	 	 	 JNZ ITER
	 	 	 MOV CL,04H
	 	 	 MOV BL,0H
	 	 DISP:
	 	 	 MOV DL,V[BX]
	 	 	 ADD DL,30H
	 	 	 INC BX
	 	 	 MOV AH,02H
	 	 	 INT 21H
	 	 	 LOOP DISP

	 	 	 MOV AH,4CH
	 	 	 INT 21H
CODE ENDS
END
