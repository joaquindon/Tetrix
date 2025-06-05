section .bss
    global boardState
    global piecePos
    global piecePivotPos
    global boardColor

boardState: resb 200          ; 10*20 = 200 bytes
piecePos:   resb 4
piecePivotPos: resb 1
boardColor: resb 1
