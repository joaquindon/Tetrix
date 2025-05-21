global rotate_piece

section .text

; void rotate_piece(unsigned char* matriz)
rotate_piece:
    ; Guardar registros que vamos a usar
    push rsi
    push rdx
    push rcx

    ; Reservar espacio en la pila para una matriz temporal de 16 bytes
    sub rsp, 16           ; Ahora [rsp] apunta a espacio libre
    lea rsi, [rsp]        ; rsi = puntero a la matriz temporal

    ; Copiar la matriz original (rdi) a la temporal (rsi)
    mov rcx, 16           ; contador = 16 bytes
    mov rdx, rdi          ; rdx = fuente (matriz original)
.copy_loop:
    mov al, [rdx]         ; leer byte de matriz original
    mov [rsi], al         ; escribir en matriz temporal
    inc rdx
    inc rsi
    loop .copy_loop

    ; Restaurar punteros
    lea rsi, [rsp]        ; rsi = puntero a la temporal
    mov rdx, rdi          ; rdx = puntero a la matriz destino (original)

    ; Rotar la matriz: dst[i][j] = src[3 - j][i]
    ; Convertimos coordenadas 2D a 1D: offset = fila * 4 + columna

    xor r8, r8            ; r8 = fila (i) = 0
.row_loop:
    xor r9, r9            ; r9 = columna (j) = 0
.col_loop:
    ; Calcular índice en la matriz original: (3 - j) * 4 + i
    mov r10, 3
    sub r10, r9           ; r10 = 3 - j
    mov r11, r8           ; r11 = i

    mov rax, r10
    shl rax, 2            ; rax = (3 - j) * 4
    add rax, r11          ; rax += i = índice origen

    ; Leer valor desde la temporal
    mov al, [rsi + rax]

    ; Calcular índice de destino: i * 4 + j
    mov rbx, r8
    shl rbx, 2            ; rbx = i * 4
    add rbx, r9           ; rbx += j = índice destino

    ; Escribir valor rotado en matriz destino
    mov [rdx + rbx], al

    ; Siguiente columna
    inc r9
    cmp r9, 4
    jl .col_loop

    ; Siguiente fila
    inc r8
    cmp r8, 4
    jl .row_loop

    ; Liberar espacio temporal y restaurar registros
    add rsp, 16           ; liberar 16 bytes de la pila
    pop rcx
    pop rdx
    pop rsi
    ret                   ; volver al caller