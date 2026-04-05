; ============================================
; SHADE1.ASM - Add distance shading
; ============================================
; (Same as TEXTURE2 but add this to DRAW_TYPED_WALL before drawing pixel)

APPLY_SHADING PROC
    ; Darken color based on TEMP_DIST_T2
    MOV CX, [TEMP_DIST_T2]
    CMP CX, 50
    JG FAR_WALL
    ; Close - no darkening
    RET
FAR_WALL:
    ; Darken: subtract 2 from color value
    CMP AL, 2
    JLE DARKEST
    SUB AL, 2
DARKEST:
    RET
APPLY_SHADING ENDP

; Call this before: MOV ES:[DI], AL
