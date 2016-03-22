; Program Description:  Add the contents of two arrays and store the result
;                       in another. If the add results in a carry, force
;                       the result to be 0. After, print the ascii representation
;                       to the console both forwards and backwards.
; Author:               Brent Wishart
; Date:                 Mar 20 2016
; OS:                   Linux MINT_VM
; IDE/Compiler:         vi/nasm

bits 32
section .data

  array_1 db 0x10, 0x30, 0xf0               ; Array 1
          db 0x20, 0x50, 0x12               ;
    .LENGTH equ ($ - array_1)               ;

  array_2 db 0xe0, 0x40, 0x22               ; Array 2
          db 0xe5, 0x40, 0x55               ;
    .LENGTH equ ($ - array_2)               ;

  array_result times array_1.LENGTH db 0x0  ; Result Array
    .LENGTH equ ($ - array_result)          ;

  array_print times 4 db 0x0                ; Array to print
    .LENGTH equ ($ - array_print)           ;
  newline db 0dh, 0ah, 0h                   ; Newline values
  tabs db 09h, 0h                           ; Tabstop values

section .bss
section .text
  global _start
_start:                           ; START
  nop                                   ;

  push eax                              ; Push EAX to the stack
  push ebx                              ; Push EBX to the stack
  push ecx                              ; Push ECX to the stack
  push esi                              ; Push ESI to the stack

  call add                              ; Add the arrays and store result_array
  mov edi, array_result                 ; Pass array_result to print_array func
  mov ecx, array_result.LENGTH          ; Pass the length too
  call print_array                      ; Print the array to the console
  call print_newline                    ; Formatting

  mov edi, array_result                 ; Parameters for both reverse_array
  mov ecx, array_result.LENGTH          ; and print_array
  call reverse_array                    ; Reverse the contents of the array
  call print_array                      ; Print the reversed array
  call print_newline                    ; Formatting

  pop esi                               ; Pop ESI from the stack
  pop ecx                               ; Pop ECX from the stack
  pop ebx                               ; Pop EBX from the stack
  pop eax                               ; Pop EAX from the stack

  mov eax, 1                            ; Exit system call value
  add eax, 0                            ; Exit return code
  int 0x80                              ; Call the kernel

;----------------------------------------
add:
; Takes:
;   Nothing
; Modifies:
;   array_result variable
;     Iterates through array_1 and array_2, adding the elements and storing
;     the result in array_result
;----------------------------------------
  mov esi, 0x0                          ; Initialize ESI to 0
  mov ecx, array_1.LENGTH               ; Set loop count to array size
  add_loop:
  mov al, [array_1 + esi]               ; Move first value to EAX
  add al, [array_2 + esi]               ; Add the other value to EAX
  jc carry                              ; Jump to carry label if result of add threw a carry
  jmp end                               ; Go to end label

  carry:
    mov al, 0x0                         ; Result of add should be zero if carry
    jmp end                             ; Go to end label

  end:
    mov [array_result + esi], al        ; Move the result of the add to result array
    add esi, 1                          ; Increment ESI to access next array element
    loop add_loop                       ; Loop
ret                                 ; End add
;----------------------------------------

;----------------------------------------
print_array:
; Takes:
;   EDI:  Address of the array to print
;   ECX:  Length of the array to print
; Modifies:
;   array_print variable
;     Iterates through the array to print, getting the ascii value at each element
;     and printing it to the console. array_print is the temporary variable that
;     stores the ascii value.
;----------------------------------------
  pushad                                ; Push registers to protect main loop
  array_loop:
    mov eax, 0h                         ; Clear the EAX register
    mov [array_print], eax              ; Clear array_print
    mov al, BYTE [ edi ]                ; Pass value from array_result to get_ascii_array
    pushad                              ; Protect the registers
    call get_ascii_array                ; Puts the ascii value at edi into array_print
    mov ecx, array_print                ; Pass address of array_print to print function
    mov edx, array_print.LENGTH         ; Pass the length too
    call print                          ; Print to console
    call print_space                    ; Formatting
    popad                               ; Restore the registers
    inc edi                             ; Add 1 to edi (size of byte)
  loop array_loop                       ; Loop
  popad                                 ; Pop registers and go back to main loop
ret                                 ; End print_array
;----------------------------------------

;----------------------------------------
get_ascii_array:
; Takes:
;   EAX:  The raw value to convert to ascii
; Modifies:
;   array_print
;     stores the ascii value
; Notes:
;   Because of the way this algorithm works, each digit is stored from the most significant
;   bit to least. As a result, the function reverse_array is used to correct it.
;----------------------------------------
  mov bl, BYTE 0ah                      ; Get ready to divide ax by 10
  mov edi, 0h                           ; Initialize position counter
  hex_to_dec:
    div bl                              ; Divide. Remainder will be in ah, result in al
    add ah, 30h                         ; add 30h to remainder to convert to ascii
    mov [array_print + edi], ah         ; Move the ascii result into the array
    mov ah, 0h                          ; clear the ah
    cmp al, 0h                          ; Check quotient to see if 0
    je to_ascii_end                     ; If it is, print the ascii number
    inc edi                             ; Increment to next position
  jmp hex_to_dec                        ; Go to the top

  to_ascii_end:
  mov edi, array_print                  ; Parameters for reverse_array
  mov ecx, array_print.LENGTH           ; Parameters for reverse_array
  call reverse_array                    ; Reverse array_print
ret                                 ; End get_ascii_array
;----------------------------------------

;----------------------------------------
reverse_array:
; Takes:
;   EDI:  Address of the array to reverse
;   ECX:  Length of the array to reverse
; Modifies:
;   [ EDI ]:
;     Reverses the contents of the array
; Notes:
;   Since this function requires two independent loops, the contents of edi and ecx are
;   stored in esi and ebp and then used to refresh edi and ecx.
;----------------------------------------
  pushad                                ; Push registers
  mov esi, edi                          ; Save the location and size of the array for
  mov ebp, ecx                          ; use in the second part of this function
  reverse_one:                        ; First Reverse Loop
    mov eax, 0h                         ; Reset EAX
    mov al, BYTE [edi]                  ; Move byte at esi to al
    push eax                            ; and push it to the stack
    inc edi                             ; Go to next position in array
    loop reverse_one                    ; Loop

  mov ecx, ebp                          ; Reset ecx and esi to their
  mov edi, esi                          ; initial values
  reverse_two:                        ; Second Loop
    pop eax                             ; Pop to EAX
    mov [edi], BYTE al                  ; Move result to position at esi
    inc edi                             ; Go to next position in array
    loop reverse_two                    ; Loop

  popad                                 ; Pop registers
ret                                 ; End reverse_array
;----------------------------------------

;----------------------------------------
print:
; Takes:
;   ECX:  Address of the array to print
;   EDX:  Length of the array to print
; Modifies:
;   Nothing, but calls the kernel
;----------------------------------------
  pushad                                ; Protect the registers
  mov eax, 0x04                         ; Write
  mov ebx, 0x01                         ; Stdout
  int 80h                               ; Interupt
  popad                                 ; Pop the registers back
ret                                 ;  End Print_newline
;----------------------------------------

;----------------------------------------
print_space:
; Takes:
;   tabs variable
; Modifies:
;   Nothing, but calls the kernel
;----------------------------------------
  pushad                                ; Protect the registers
  mov ecx, tabs                         ; Move the location
  mov edx, 2h                           ; Move the length
  mov eax, 0x04                         ; Write
  mov ebx, 0x01                         ; Stdout
  int 80h                               ; Interupt
  popad                                 ; Pop the registers back
ret                                 ;  End Print_space
;----------------------------------------

;----------------------------------------
print_newline:
; Takes:
;   newline variable
; Modifies:
;   Nothing, but calls the kernel
;----------------------------------------
  pushad                                ; Protect the registers
  mov ecx, newline                      ; Move the location
  mov edx, 3h                           ; Move the length
  mov eax, 0x04                         ; Write
  mov ebx, 0x01                         ; Stdout
  int 80h                               ; Interupt
  popad                                 ; Pop the registers back
ret                                 ;  End Print_newline
;----------------------------------------
