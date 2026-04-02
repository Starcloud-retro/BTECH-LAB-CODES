; ============================================
; GRAPHICS.ASM - Enter Mode 13h and draw pixel
; ============================================
; This program teaches:
; 1. How to switch to graphics mode
; 2. How to access video memory
; 3. How to plot a pixel
; 4. How to wait for keypress
; 5. How to return to text mode
; ============================================

.model small
.stack 100h

.code
main:
    ; ==========================================
    ; STEP 1: Switch to Mode 13h (320x200, 256 colors)
    ; ==========================================
    ; INT 10h is the VIDEO BIOS interrupt
    ; AH=00h means "Set Video Mode"
    ; AL=13h is Mode 13h (our graphics mode)
    ; ==========================================
    mov ah, 00h        ; Function: Set video mode
    mov al, 13h        ; Mode 13h = 320x200, 256 colors
    int 10h            ; Call BIOS video interrupt

    ; WHY Mode 13h?
    ; - Each pixel = 1 byte (0-255 color values)
    ; - Video memory starts at 0A000h:0000h
    ; - Easy to calculate: address = 0A000h + (y*320) + x

    ; ==========================================
    ; STEP 2: Set up ES register to point to video RAM
    ; ==========================================
    ; Video memory in Mode 13h is at segment 0A000h
    ; We use ES (Extra Segment) to access it
    ; ==========================================
    mov ax, 0A000h     ; Video RAM segment address
    mov es, ax         ; ES now points to video memory

    ; ==========================================
    ; STEP 3: Calculate position for center pixel
    ; ==========================================
    ; Screen is 320x200, so center is (160, 100)
    ; Formula: offset = (y * 320) + x
    ; offset = (100 * 320) + 160 = 32160
    ; ==========================================
    mov di, 32160      ; DI = offset for pixel at (160, 100)

    ; ==========================================
    ; STEP 4: Choose color and plot pixel
    ; ==========================================
    ; Color values in Mode 13h:
    ; 0=black, 15=white, 4=red, 2=green, 1=blue
    ; 14=yellow, 5=magenta, 3=cyan, etc.
    ; ==========================================
    mov al, 4          ; Color 4 = RED
    mov es:[di], al    ; Write color to video memory

    ; WHAT JUST HAPPENED?
    ; You directly wrote to video RAM!
    ; The byte at 0A000h:32160 controls the pixel at (160,100)
    ; Changing that byte changes the pixel color instantly

    ; ==========================================
    ; STEP 5: Wait for any keypress
    ; ==========================================
    mov ah, 00h        ; Function: Wait for keypress
    int 16h            ; Keyboard interrupt

    ; ==========================================
    ; STEP 6: Return to text mode
    ; ==========================================
    mov ah, 00h        ; Function: Set video mode
    mov al, 03h        ; Mode 03h = standard text mode
    int 10h            ; Call BIOS

    ; ==========================================
    ; STEP 7: Exit to DOS
    ; ==========================================
    mov ah, 4Ch        ; DOS terminate program
    int 21h            ; Call DOS interrupt

end main
