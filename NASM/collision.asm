; check_collision.asm
; int check_collision(unsigned char* forma, int x, int y, unsigned char* tablero, int ancho)

global check_collision

section .text

check_collision:
    push rbx
    push r9
    push r10
    push r11

    xor rax, rax        ; rax = valor de retorno, por defecto 0 (sin colisión)

    xor r9, r9          ; i = fila (0..3)
.row_loop:
    xor r10, r10        ; j = columna (0..3)
.col_loop:
    ; offset = i * 4 + j
    mov r11, r9
    shl r11, 2          ; r11 = i * 4
    add r11, r10        ; r11 = i*4 + j

    movzx bl, byte [rdi + r11] ; bl = forma[i][j]
    cmp bl, 0
    je .next_col        ; si no hay bloque, ignorar

    ; calcular coordenadas en el tablero: tx = x + j, ty = y + i
    mov eax, esi        ; r11d = x (movemos el valor de x a eax para la suma)
    add eax, r10        ; eax = x + j

    mov ebx, edx        ; rbx = y
    add ebx, r9         ; ebx = y + i

    ; verificar bordes: si x+j < 0 o >= ancho, colisión
    cmp eax, 0
    jl .colision

    cmp eax, r8d        ; r8d es el ancho, lo usamos aquí
    jge .colision

    ; offset tablero = (y + i) * ancho + (x + j)
    imul ebx, r8d       ; (y+i) * ancho
    add ebx, eax        ; + (x+j)

    ; verificar si ese lugar del tablero está ocupado
    cmp byte [rcx + rbx], 0
    jne .colision

.next_col:
    inc r10
    cmp r10, 4
    jl .col_loop

    inc r9
    cmp r9, 4
    jl .row_loop

    ; sin colisión
    xor rax, rax
    jmp .done

.colision:
    mov rax, 1          ; hay colisión

.done:
    pop r11
    pop r10
    pop r9
    pop rbx
    ret
