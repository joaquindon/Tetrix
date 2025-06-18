global MoveRight
global MoveLeft
global UpdateBoardASM

section .text

; void MoveRight(int* board, int* indX)
; board en RDI, indX en RSI

MoveRight:
    push rbp
    mov rbp, rsp

    xor r9d, r9d          ; aux = 0
    xor r10d, r10d        ; i = 0

.loop_i_right:
    cmp r10d, 20
    jge .check_aux_right

    xor r11d, r11d        ; j = 0
.loop_j_right:
    cmp r11d, 9
    jg .next_i_right

    mov r12, r10
    imul r12, 10
    add r12, r11
    shl r12, 2

    mov eax, [rdi + r12]
    cmp eax, -1
    jne .next_j_right

    mov r14, r10
    imul r14, 10
    add r14, r11
    add r14, 1
    shl r14, 2

    mov edx, [rdi + r14]
    cmp edx, 0
    jg .next_j_right

    inc r9d

.next_j_right:
    inc r11d
    jmp .loop_j_right

.next_i_right:
    inc r10d
    jmp .loop_i_right

.check_aux_right:
    cmp r9d, 4
    jne .done_right

    add dword [rsi], 1

    xor r10d, r10d
.loop_move_i_right:
    cmp r10d, 20
    jge .done_right

    mov r11d, 9
.loop_move_j_right:
    cmp r11d, -1
    jl .next_move_i_right

    mov r12, r10
    imul r12, 10
    add r12, r11
    shl r12, 2

    mov eax, [rdi + r12]
    cmp eax, -1
    jne .next_move_j_right

    mov r14, r10
    imul r14, 10
    add r14, r11
    add r14, 1
    shl r14, 2

    mov dword [rdi + r12], 0
    mov dword [rdi + r14], -1

.next_move_j_right:
    dec r11d
    jmp .loop_move_j_right

.next_move_i_right:
    inc r10d
    jmp .loop_move_i_right

.done_right:
    pop rbp
    ret

; void MoveLeft(int* board, int* indX)
; board en RDI, indX en RSI

MoveLeft:
    push rbp
    mov rbp, rsp

    xor r9d, r9d
    xor r10d, r10d

.loop_i_left:
    cmp r10d, 20
    jge .check_aux_left

    mov r11d, 1
.loop_j_left:
    cmp r11d, 9
    jg .next_i_left

    mov r12, r10
    imul r12, 10
    add r12, r11
    shl r12, 2

    mov eax, [rdi + r12]
    cmp eax, -1
    jne .next_j_left

    mov r14, r10
    imul r14, 10
    add r14, r11
    sub r14, 1
    shl r14, 2

    mov edx, [rdi + r14]
    cmp edx, 0
    jg .next_j_left

    inc r9d

.next_j_left:
    inc r11d
    jmp .loop_j_left

.next_i_left:
    inc r10d
    jmp .loop_i_left

.check_aux_left:
    cmp r9d, 4
    jne .done_left

    sub dword [rsi], 1

    xor r10d, r10d
.loop_move_i_left:
    cmp r10d, 20
    jge .done_left

    xor r11d, r11d
.loop_move_j_left:
    cmp r11d, 9
    jg .next_move_i_left

    mov r12, r10
    imul r12, 10
    add r12, r11
    shl r12, 2

    mov eax, [rdi + r12]
    cmp eax, -1
    jne .next_move_j_left

    mov r14, r10
    imul r14, 10
    add r14, r11
    sub r14, 1
    shl r14, 2

    mov dword [rdi + r12], 0
    mov dword [rdi + r14], -1

.next_move_j_left:
    inc r11d
    jmp .loop_move_j_left

.next_move_i_left:
    inc r10d
    jmp .loop_move_i_left

.done_left:
    pop rbp
    ret

; bool UpdateBoardASM(int* board, int* timer, int timerLimit, int* indY, int indColorNewPart)

UpdateBoardASM:
    push rbp
    mov rbp, rsp

    mov eax, [rsi]
    cmp eax, edx
    jl .notReady

    xor r9d, r9d
    mov r10d, 18

.loop_i:
    cmp r10d, -1
    jl .check_aux

    xor r11d, r11d
.loop_j:
    cmp r11d, 9
    jg .next_i

    mov r12, r10
    imul r12, 10
    add r12, r11
    shl r12, 2

    mov eax, [rdi + r12]
    cmp eax, -1
    jne .next_j

    mov r14, r10
    add r14, 1
    imul r14, 10
    add r14, r11
    shl r14, 2

    mov edx, [rdi + r14]
    cmp edx, 0
    jg .next_j

    inc r9d

.next_j:
    inc r11d
    jmp .loop_j

.next_i:
    dec r10d
    jmp .loop_i

.check_aux:
    cmp r9d, 4
    jne .fix_to_ground

    add dword [rcx], 1
    mov r10d, 18

.loop_move_i:
    cmp r10d, -1
    jl .reset_timer

    xor r11d, r11d
.loop_move_j:
    cmp r11d, 9
    jg .move_next_i

    mov r12, r10
    imul r12, 10
    add r12, r11
    shl r12, 2

    mov eax, [rdi + r12]
    cmp eax, -1
    jne .move_next_j

    mov r14, r10
    add r14, 1
    imul r14, 10
    add r14, r11
    shl r14, 2

    mov dword [rdi + r12], 0
    mov dword [rdi + r14], -1

.move_next_j:
    inc r11d
    jmp .loop_move_j

.move_next_i:
    dec r10d
    jmp .loop_move_i

.fix_to_ground:
    mov r10d, 19
.loop_fix_i:
    cmp r10d, -1
    jl .reset_timer_ground

    xor r11d, r11d
.loop_fix_j:
    cmp r11d, 9
    jg .fix_next_i

    mov r12, r10
    imul r12, 10
    add r12, r11
    shl r12, 2

    mov eax, [rdi + r12]
    cmp eax, -1
    jne .fix_next_j

    mov dword [rdi + r12], r8d

.fix_next_j:
    inc r11d
    jmp .loop_fix_j

.fix_next_i:
    dec r10d
    jmp .loop_fix_i

.reset_timer_ground:
    mov eax, 1
    mov dword [rsi], 0
    jmp .done

.reset_timer:
    mov eax, 0
    mov dword [rsi], 0
    jmp .done

.notReady:
    mov eax, 0
    jmp .done

.done:
    pop rbp
    ret
