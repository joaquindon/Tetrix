global checkCollision

extern piecePos
extern boardState
extern boardColor
extern solidifyPiece

section .text

checkCollision:
    mov ecx, 0
.loop:
    movzx eax, byte [piecePos + ecx]
    add eax, 10          ; bajar una fila
    cmp eax, 200
    jae .collide         ; si pasa límite, colisión

    mov bl, [boardState + eax]
    cmp bl, 0
    jne .collide         ; si la celda está ocupada, colisión

    inc ecx
    cmp ecx, 4
    jne .loop

    ret                  ; no hay colisión

.collide:
    call solidifyPiece
    ret
