global moveOneLeft
global moveOneRight

extern boardState
extern piecePos
extern piecePivotPos
extern boardColor

section .text

moveOneLeft:
    mov ecx, 0
.check_left:
    movzx eax, byte [piecePos + ecx]
    mov edx, eax
    and edx, 0x0F       ; edx = eax % 16 (columna)
    cmp edx, 0
    je .end             ; si ya está en la columna 0, no puede mover más a la izquierda

    dec eax
    cmp byte [boardState + eax], 0
    jne .end            ; si la celda a la izquierda está ocupada, no se mueve

    inc ecx
    cmp ecx, 4
    jne .check_left

    ; Mover todas las posiciones a la izquierda
    mov ecx, 0
.move_all_left:
    dec byte [piecePos + ecx]
    inc ecx
    cmp ecx, 4
    jne .move_all_left
    dec byte [piecePivotPos]
    ret

.end:
    ret

moveOneRight:
    mov ecx, 0
.check_right:
    movzx eax, byte [piecePos + ecx]
    mov edx, eax
    and edx, 0x0F
    cmp edx, 9          ; si está en la última columna (9), no se mueve
    je .end

    inc eax
    cmp byte [boardState + eax], 0
    jne .end

    inc ecx
    cmp ecx, 4
    jne .check_right

    ; Mover todas las posiciones a la derecha
    mov ecx, 0
.move_all_right:
    inc byte [piecePos + ecx]
    inc ecx
    cmp ecx, 4
    jne .move_all_right
    inc byte [piecePivotPos]
    ret

.end:
    ret
