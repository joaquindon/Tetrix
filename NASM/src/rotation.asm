global rotate_piece

section .text

; void rotate_piece(unsigned char* matriz)
; matriz está en [esp + 4]

rotate_piece:
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx
    sub esp, 16           ; espacio para la matriz temporal (4x4 bytes)

    ; esi = temporal, edi = original
    lea esi, [esp]        ; temporal
    mov edi, [ebp + 8]    ; matriz original

    ; Copiar matriz original a temporal
    mov ecx, 16           ; 16 bytes
    mov edx, edi          ; fuente

.copy_loop:
    mov al, [edx]
    mov [esi], al
    inc edx
    inc esi
    loop .copy_loop

    ; Restaurar punteros
    lea esi, [esp]        ; temporal
    mov edx, [ebp + 8]    ; destino (original)

    xor ecx, ecx          ; ecx = i = fila

.row_loop:
    xor ebx, ebx          ; ebx = j = columna

.col_loop:
    ; Índice origen: (3 - j) * 4 + i
    mov eax, 3
    sub eax, ebx          ; eax = 3 - j
    shl eax, 2            ; eax *= 4
    add eax, ecx          ; eax = (3 - j) * 4 + i
    mov al, [esi + eax]   ; al = valor de temporal en esa posición

    ; Índice destino: i * 4 + j
    mov eax, ecx
    shl eax, 2            ; eax *= 4
    add eax, ebx          ; eax = i * 4 + j
    mov [edx + eax], al   ; escribir valor rotado

    inc ebx
    cmp ebx, 4
    jl .col_loop

    inc ecx
    cmp ecx, 4
    jl .row_loop

    ; Restaurar pila y registros
    add esp, 16
    pop ebx
    pop edi
    pop esi
    pop ebp
    ret
