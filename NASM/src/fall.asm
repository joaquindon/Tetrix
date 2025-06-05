global moveOneDown

extern piecePos
extern boardState
extern boardColor
extern piecePivotPos
extern solidifyPiece

section .text

moveOneDown:
    mov ecx, 0
.check_down:
    movzx eax, byte [piecePos + ecx]
    add eax, 10          ; bajar una fila (ancho del tablero)
    cmp eax, 200         ; fuera del tablero verticalmente
    jae .solidify

    cmp byte [boardState + eax], 0
    jne .solidify        ; si la posición debajo está ocupada, solidifica

    inc ecx
    cmp ecx, 4
    jne .check_down

    ; Mover hacia abajo
    mov ecx, 0
.move_down:
    add byte [piecePos + ecx], 10
    inc ecx
    cmp ecx, 4
    jne .move_down
    add byte [piecePivotPos], 10
    ret

.solidify:
    call solidifyPiece
    ret
