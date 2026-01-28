; main.asm
; MASM + Irvine32 skeleton for Mini Text Editor (Phase 1)
; Requires: Irvine32.inc and Irvine32.lib in your MASM/VS setup

.386
.model flat, stdcall
.stack 4096

; prototype for Win32 ExitProcess
ExitProcess proto :DWORD

INCLUDE Irvine32.inc

; ---------------------------
.data
; welcome / menu text
welcomeMsg BYTE "=== Mini Text Editor (Assembly) ===", 0Dh,0Ah, 0
menuMsg    BYTE "(N) New  (O) Open  (Q) Quit", 0Dh,0Ah, 0
promptOpen BYTE "Enter filename to open: ", 0
openedMsg  BYTE "Opening file: ", 0
newMsg     BYTE "Creating new (empty) buffer...", 0Dh,0Ah, 0
invalidMsg BYTE "Invalid choice. Press any key to continue...",0Dh,0Ah,0

; Editor small data moved to .data (was previously placed after .code)
newLine BYTE 0Dh,0Ah,0
editorMsg BYTE 0Dh,0Ah, "=== EDITOR (console mode) ===", 0Dh,0Ah, 0
editorHint BYTE "Editor not yet implemented. Press any key to return to menu...",0Dh,0Ah,0

; Editor buffer: 1 MiB (adjust if needed)
; We'll store file contents here; track length with bufferLen.
bufferSize EQU 1048576           ; 1 MB
textBuffer BYTE bufferSize DUP(0)
bufferLen DWORD 0

; filename buffer for Open (max 260)
maxName EQU 260
fileName BYTE maxName DUP(0)
fileNameLen DWORD 0

; flag: 0 = no unsaved changes, 1 = unsaved changes (placeholder)
dirtyFlag DWORD 0

.code

; ---------------------------
main PROC
    ; show welcome and menu, wait for selection
    call ShowWelcomeMenu

    ; Return to OS
    invoke ExitProcess,0
main ENDP

; ---------------------------
ShowWelcomeMenu PROC
    LOCAL ch:BYTE

menuLoop:
    mov edx, OFFSET welcomeMsg
    call WriteString

    mov edx, OFFSET menuMsg
    call WriteString

    ; read single character input (ReadChar returns char in AL)
    call ReadChar
    mov ch, al

    ; echo newline for nicer UX
    mov edx, OFFSET newLine
    call WriteStringNoCR

    ; normalize to uppercase
    movzx eax, byte ptr ch
    cmp al, 'n'
    je DoNew
    cmp al, 'N'
    je DoNew
    cmp al, 'o'
    je DoOpen
    cmp al, 'O'
    je DoOpen
    cmp al, 'q'
    je DoQuit
    cmp al, 'Q'
    je DoQuit

    ; invalid
    mov edx, OFFSET invalidMsg
    call WriteString
    call ReadKey
    jmp menuLoop

DoNew:
    mov edx, OFFSET newMsg
    call WriteString

    ; initialize buffer length = 0
    mov dword ptr [bufferLen], 0
    mov dword ptr [dirtyFlag], 0

    ; jump to editor main loop (placeholder)
    call EditorLoop
    jmp menuLoop

DoOpen:
    ; prompt filename
    mov edx, OFFSET promptOpen
    call WriteString

    ; read filename using ReadString (Irvine function)
    lea edx, fileName
    mov ecx, maxName
    call ReadString

    ; store filename length (Irvine may return length in ECX)
    mov [fileNameLen], ecx

    ; echo "Opening file: {name}"
    mov edx, OFFSET openedMsg
    call WriteString
    lea edx, fileName
    call WriteString

    ; placeholder: pretend file loaded
    mov dword ptr [bufferLen], 0
    mov dword ptr [dirtyFlag], 0

    call EditorLoop
    jmp menuLoop

DoQuit:
    ; before quitting, if dirtyFlag==1 prompt for save - placeholder
    ; simply return to caller (main will ExitProcess)
    ret

ShowWelcomeMenu ENDP

; ---------------------------
; EditorLoop - placeholder for main editing routine
; For now it displays a small message and waits for a key before returning.
EditorLoop PROC
    LOCAL unusedByte:BYTE
    mov edx, OFFSET editorMsg
    call WriteString
    mov edx, OFFSET editorHint
    call WriteString
    call ReadKey
    ret
EditorLoop ENDP

; ---------------------------
; WriteStringNoCR: wrapper that calls Irvine's WriteString with EDX set
WriteStringNoCR PROC
    call WriteString
    ret
WriteStringNoCR ENDP

END main
