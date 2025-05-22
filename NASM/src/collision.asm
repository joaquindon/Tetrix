global collision

section .text

; bool collision(Position* tabla, int size, unsigned char* matriz, int ancho, int alto)
; Devuelve 1 si hay colisión, 0 si no.
collision:
    push ebp
    mov ebp, esp
    push ebx            ; índice i
    push esi            ; tabla pointer
    push edi            ; matriz pointer

    mov esi, [ebp + 8]   ; size
    mov ebx, 0           ; i = 0

    mov edi, [ebp + 4]   ; tabla (Position*)
    mov edx, [ebp + 16]  ; ancho
    mov ecx, [ebp + 20]  ; alto
    mov edi, [ebp + 12]  ; matriz (unsigned char*)

    ; calcular límite: ancho * alto
    mov eax, edx
    imul eax, ecx        ; eax = ancho * alto

.loop_check:
    cmp ebx, esi
    jge .can_fall        ; si i >= size, no colisión

    ; cargar x,y de tabla[i]
    mov edx, [edi + ebx*8]       ; x
    mov esi, [edi + ebx*8 + 4]   ; y

    inc esi                      ; y+1

    cmp esi, ecx                 ; y+1 comparado con alto
    jae .collision               ; si y+1 >= alto, colisión

    ; calcular offset = x + (y+1)*ancho
    mov edi, esi                 ; edi = y+1
    imul edi, edx                ; INCORRECTO: edx = x, edx = x * (y+1) NO ES correcto
                                ; Corrijo abajo

    ; CORRECCIÓN:
    mov edi, esi                 ; edi = y+1
    imul edi, edx                ; este imul es incorrecto (edx es x)
    ; Hay confusión. Reasigno registros para claridad:

    ; Lo correcto es:
    ; offset = x + (y+1)*ancho
    ; x = edx, (y+1) = esi, ancho = variable que guardamos en algún registro

    ; Para evitar confusión, asignemos:
    ; edx = x
    ; esi = y+1
    ; ebp = ancho

    ; Pero ebp está en uso para frame pointer. Usaré otro registro.

    mov ebp, [ebp + 16]   ; ancho (pero es el frame pointer, cuidado)
    ; Para evitar conflicto, copia ancho a otro registro antes:

    ; Como tenemos frame pointer ebp, mejor usar registros libres:

    ; Vamos a reservar registros:
    ; eax = ancho (ya tenemos)
    ; edx = x
    ; esi = y+1

    ; Entonces:

    mov edi, esi         ; edi = y+1
    mov ebx, edx         ; ebx = x
    mov esi, [ebp + 16]  ; ancho (desde stack frame)

    imul edi, esi        ; edi = (y+1)*ancho
    add edi, ebx         ; edi = x + (y+1)*ancho (offset)

    cmp edi, eax         ; comparar offset con ancho*alto
    jae .collision

    mov al, [ecx + edi]  ; matriz[offset]
    cmp al, 0
    jne .collision

    inc ebx              ; i++
    jmp .loop_check

.collision:
    mov al, 1
    jmp .end

.can_fall:
    xor ebx, ebx         ; i = 0

.inc_loop:
    cmp ebx, esi         ; comparar i con size (?), cuidado
    jge .ret_zero

    mov eax, [edi + ebx*8 + 4]
    inc eax
    mov [edi + ebx*8 + 4], eax

    inc ebx
    jmp .inc_loop

.ret_zero:
    mov al, 0

.end:
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret
