section .text
global collision

; bool collision(Position* tabla, int size, unsigned char* matriz, int ancho, int alto)
; argumentos:
; rdi = tabla (Position*)
; rsi = size (int)
; rdx = matriz (unsigned char*)
; rcx = ancho (int)
; r8  = alto (int)

collision:
    push rbx
    push r9
    push r10
    push r11

    mov rbx, 0           ; índice i = 0

.check_loop:
    cmp rbx, rsi         ; si i >= size
    jge .can_fall

    ; cargar x e y de tabla[i]
    mov eax, dword [rdi + rbx*8]       ; x = tabla[i].x
    mov edx, dword [rdi + rbx*8 + 4]   ; y = tabla[i].y

    ; verificar límite inferior (y+1 >= alto)
    mov edi, edx
    inc edi
    cmp edi, r8d
    jae .collision       ; colisión si fuera del borde

    ; calcular offset matriz: (y+1)*ancho + x
    mov esi, edi         ; y+1
    imul esi, ecx        ; * ancho
    add esi, eax         ; + x

    mov al, [rdx + rsi]  ; cargar matriz[offset]
    cmp al, 0
    jne .collision       ; colisión si != 0

    inc rbx
    jmp .check_loop

.collision:
    mov al, 1
    jmp .end

.can_fall:
    mov rbx, 0

.inc_loop:
    cmp rbx, rsi
    jge .ret_zero

    mov eax, dword [rdi + rbx*8 + 4]
    inc eax
    mov dword [rdi + rbx*8 + 4], eax

    inc rbx
    jmp .inc_loop

.ret_zero:
    mov al, 0

.end:
    pop r11
    pop r10
    pop r9
    pop rbx
    ret
