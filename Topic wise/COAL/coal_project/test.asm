.386

INCLUDE Irvine32.inc        ; this pulls in .MODEL from SmallWin.inc
.stack 4096
ExitProcess proto stdcall :DWORD

.data

char BYTE ?
; welcome / menu text
welcomeMsg BYTE "=== Mini Text Editor (Assembly) ===",0Dh,0Ah,0
menuMsg    BYTE "(N) New  (O) Open  (Q) Quit",0Dh,0Ah,0
promptOpen BYTE "Enter filename to open: ",0
openedMsg  BYTE "Opening file: ",0
newMsg     BYTE "Creating new (empty) buffer...",0Dh,0Ah,0
invalidMsg BYTE "Invalid choice. Press any key to continue...",0Dh,0Ah,0

; single buffer (choose one size) - 128KB here
bufferSize    = 131072
textBuffer     BYTE bufferSize DUP(0)
bufferLen      DWORD 0

cursorPos DWORD 0

; filename buffer for Open (max 260)
maxName EQU 260
fileName BYTE maxName DUP(0)
fileNameLen DWORD 0

; flag: 0 = no unsaved changes, 1 = unsaved changes (placeholder)
dirtyFlag DWORD 0

; temporary one-char + null (for WriteString usage)
tmpChar BYTE 2 DUP(0)

; status & messages used by editor core
statusLine    BYTE 80 DUP(0)
promptSave    BYTE 0Dh,0Ah,"Save as (enter filename): ",0
savedMsg      BYTE 0Dh,0Ah,"File saved.",0Dh,0Ah,0
saveFailMsg   BYTE 0Dh,0Ah,"Save failed.",0Dh,0Ah,0
helpMsg       BYTE "(Ctrl+S Save) (Ctrl+Q Quit) (Arrows move) (Backspace Delete)",0Dh,0Ah,0

; constants
CR    = 13
BS    = 8
ESC_KEY = 27
CTRL_S = 19   ; 0x13
CTRL_Q = 17   ; 0x11

.code

; ---------------------------
main PROC
    mov dword ptr [bufferLen], 0
    mov dword ptr [dirtyFlag], 0

    mov edx, OFFSET welcomeMsg
    call WriteString
    mov edx, OFFSET helpMsg
    call WriteString

    call ShowWelcomeMenu

    invoke ExitProcess,0
main ENDP



ShowWelcomeMenu PROC

menuLoop:
    mov edx, OFFSET welcomeMsg
    call WriteString

    mov edx, OFFSET menuMsg
    call WriteString

    ; read single character input (ReadChar waits until ENTER)
    ; Better for single-key: use ReadKey (returns in AX) if available.
    ; We'll use ReadChar and accept first char of input string.
    call ReadChar           ; returns char in AL, echo disabled in some Irvine versions
    mov char, al

    ; echo newline for nicer UX
    mov edx, OFFSET newLine
    call WriteStringNoCR   ; custom small routine below prints \n (we use data)
    ; normalize to uppercase
    movzx eax, ch
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
     mov dword ptr [cursorPos], 0

    ; jump to editor main loop (placeholder)
    call EditorLoop
    jmp menuLoop

DoOpen:
    ; prompt filename
    mov edx, OFFSET promptOpen
    call WriteString

    ; read filename using ReadString (Irvine function)
    ; ReadString expects buffer in EDX and returns string with CR removed,
    ; the length is in ECX (Irvine's version differences exist).
    lea edx, fileName
    mov ecx, maxName
    call ReadString

    ; store filename length in fileNameLen (Irvine stores count in ECX)
    mov [fileNameLen], ecx

    ; echo "Opening file: {name}"
    mov edx, OFFSET openedMsg
    call WriteString
    ; print filename
    lea edx, fileName
    call WriteString

    ; placeholder: call LoadFile routine (to be implemented next)
    ; For now we zero bufferLen and pretend file loaded.
    mov dword ptr [bufferLen], 0
    mov dword ptr [dirtyFlag], 0
     mov dword ptr [cursorPos], 0

    ; go to editor loop (even if file not really loaded)
    call EditorLoop
    jmp menuLoop

DoQuit:
    ; before quitting, if dirtyFlag==1 prompt for save - placeholder
    ; just exit for now
    ret

ShowWelcomeMenu ENDP

; ---------------------------
; EditorLoop - placeholder for main editing routine
; For now it displays a small message and waits for a key before returning.
EditorLoop PROC
    
    LOCAL keyAscii:BYTE
    LOCAL keyScan:BYTE
    LOCAL keepGoing:DWORD

    mov dword ptr [keepGoing], 1

edLoop:
    ; redraw entire buffer
    call RedrawScreen

    ; read key
    call ReadKey           ; returns ASCII in AL, scan in AH
    mov keyAscii, al
    mov keyScan, ah

    ; check for extended keys (when AL == 0)
    cmp al, 0
    jne handleAscii
    ; AL == 0 -> extended: AH has code
    cmp ah, 75            ; left
    je leftKey
    cmp ah, 77            ; right
    je rightKey
    ; other extended ignored for now
    jmp edLoop

 handleAscii:
    ; check control keys
    cmp keyAscii,CTRL_Q
    je quitEditor
    cmp keyAscii, CTRL_S
    je saveFile

    ; backspace?
    cmp keyAscii, BS
    je doBackspace

    ; enter (store CR)
    cmp keyAscii, CR
    je doInsertCR

    ; printable range (space .. tilde)
    cmp keyAscii, 32
    jl edLoop
    cmp keyAscii, 126
    jg edLoop

    ; insert printable char
    movzx eax, keyAscii
    push eax
    call InsertCharAtCursor
    add esp, 4
    jmp edLoop

leftKey:
    mov eax, [cursorPos]
    cmp eax, 0
    je edLoop
    dec dword ptr [cursorPos]
    jmp edLoop

rightKey:
    mov eax, [cursorPos]
    mov ebx, [bufferLen]
    cmp eax, ebx
    je edLoop
    inc dword ptr [cursorPos]
    jmp edLoop

doBackspace:
    mov eax, [cursorPos]
    cmp eax, 0
    je edLoop
    dec dword ptr [cursorPos]
    push eax
    call DeleteCharAtPos
    add esp, 4
    jmp edLoop

doInsertCR:
      mov al, CR
    movzx eax, al
    push eax
    call InsertCharAtCursor
    add esp, 4
    jmp edLoop

saveFile:
    ; prompt and read filename using ReadString
    mov edx, OFFSET promptSave
    call WriteString

    ; file name buffer (on stack or data) – reuse textBuffer tail: use small local on data
    ; We'll create a small filename buffer on the stack:
    ;LOCAL fnamePtr:DWORD
    ; allocate 260 bytes on stack
    sub esp, 260
    mov edx, esp
    mov ecx, 259
    call ReadString
    ; null-termination by ReadString, ECX = length
    ; call SaveBufferToFile with filename pointer on stack
    push edx    ; push pointer to filename (EDX after ReadString is start)
    call SaveBufferToFile
    add esp, 4

    add esp, 260   ; free filename buffer
    jmp edLoop

quitEditor:
    mov dword ptr [keepGoing], 0
    ret

EditorLoop ENDP

; -------------------------
; InsertCharAtCursor
; Params (stack): pushed dword charValue (low byte used)
; Shifts the bytes to the right from cursorPos..bufferLen-1, inserts char, updates bufferLen and cursorPos.
InsertCharAtCursor PROC
    ; [esp] = charValue
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]        ; char (in low byte)
    mov bl, al              ; store char in bl

    ; get addresses
    mov esi, OFFSET textBuffer
    mov edx, [bufferLen]    ; current length
    cmp edx, bufferSize-2   ; keep room for null
    jae overflow           ; if overflow, ignore insertion

    ; shift bytes right from end to cursorPos
    mov ecx, edx            ; count = bufferLen
    mov ebx, [cursorPos]    ; pos
    ; if pos < bufferLen then shift; else append
    cmp ebx, ecx
    je append_char

    ; shift loop: move from idx = bufferLen-1 downto pos
    ; esi = base
    ; use registers: edi = base + idx +1 ; esi = base + idx
    mov eax, ecx
    dec eax                 ; eax = bufferLen - 1 (start index)
shift_loop:
    cmp eax, ebx
    jl shift_done
    mov dl, [esi + eax]     ; dl = textBuffer[eax]
    mov [esi + eax + 1], dl
    dec eax
    jmp shift_loop

shift_done:
    ; now insert at pos
append_char:
    mov edx, [cursorPos]
    mov [esi + edx], bl

    ; update bufferLen and cursorPos
    inc dword ptr [bufferLen]
    inc dword ptr [cursorPos]
    jmp finish

overflow:
    ; beep or ignore; just return
    ; You could call MsgBox or write a message; we ignore for simplicity
    jmp finish

finish:
    pop ebp
    ret 4
InsertCharAtCursor ENDP

; -------------------------
; DeleteCharAtPos
; Params: pushed dword pos
; Shifts bytes left starting at pos (overwrite pos..), decrement bufferLen.
DeleteCharAtPos PROC
    push ebp
    mov ebp, esp
    mov edx, [ebp+8]        ; pos to delete at (position in buffer)
    mov esi, OFFSET textBuffer
    mov ecx, [bufferLen]

    ; if pos >= bufferLen -> nothing
    cmp edx, ecx
    jae done

    ; shift left: for i = pos to bufferLen-2 : buffer[i] = buffer[i+1]
    mov eax, edx            ; i = pos
shift_left_loop:
    mov ebx, eax
    inc ebx
    cmp ebx, [bufferLen]
    jae shift_done
    mov al, [esi + ebx]
    mov [esi + eax], al
    inc eax
    jmp shift_left_loop

shift_done:
    ; decrement length
    dec dword ptr [bufferLen]
    ; zero-terminate optional
    mov ebx, [bufferLen]
    mov byte ptr [esi + ebx], 0

done:
    pop ebp
    ret 4
DeleteCharAtPos ENDP

; -------------------------
; RedrawScreen
; Clear screen, print buffer (textBuffer up to bufferLen), and status line
; Uses WriteString with EDX pointer to null-terminated string; we null-terminate textBuffer temporarily.
RedrawScreen PROC
    push ebp
    mov ebp, esp

    ; clear screen
    call Clrscr

    ; null-terminate buffer for WriteString
    mov edx, OFFSET textBuffer
    mov eax, [bufferLen]
    mov byte ptr [edx + eax], 0

    ; write full buffer
    mov edx, OFFSET textBuffer
    call WriteString

    ; draw status line on last row
    ; compute line/col for cursor by scanning up to cursorPos
    mov ecx, [cursorPos]
    xor eax, eax
    mov esi, OFFSET textBuffer
    mov ebx, 0      ; col
    mov edi, 0      ; row
    cmp ecx, 0
    je status_compute_done

scan_loop:
    mov al, [esi + eax]
    cmp al, CR
    je new_line
    inc ebx
    ; wrap if column >= 80 -> emulate wrap
    cmp ebx, 79
    jle cont1
    inc edi
    mov ebx, 0
cont1:
    inc eax
    dec ecx
    jnz scan_loop
    jmp status_compute_done

new_line:
    inc edi
    mov ebx, 0
    inc eax
    dec ecx
    jnz scan_loop

status_compute_done:
    mov edx, OFFSET newLine
    call WriteString

    ; Ln:
    mov edx, OFFSET statLnLabel
    call WriteString
    mov eax, edi
    inc eax
    call WriteDec

    mov edx, OFFSET statColLabel
    call WriteString
    mov eax, ebx
    inc eax
    call WriteDec

    mov edx, OFFSET statPosLabel
    call WriteString
    mov eax, [cursorPos]
    call WriteDec

    mov edx, OFFSET statLenLabel
    call WriteString
    mov eax, [bufferLen]
    call WriteDec

    mov edx, OFFSET newLine
    call WriteString

    pop ebp
    ret
RedrawScreen ENDP

; Small labels used above
newLine BYTE 0Dh,0Ah,0
statLnLabel BYTE " Ln: ",0
statColLabel BYTE " Col: ",0
statPosLabel BYTE " Pos: ",0
statLenLabel BYTE " Len: ",0

; -------------------------
; WriteDecToConsole - prints decimal in EAX using WriteDec (Irvine) or WriteInt
; Uses EAX value to print decimal and a trailing space.
WriteDecToConsole PROC
    ; Irvine WriteInt expects EAX value? We use WriteDec which probably expects EAX in register.
    ; To be safe: push value in EAX and use WriteInt if present; we'll use WriteDec (prototype available).
    push eax
    call WriteDec
    ; Write a space
    mov edx, OFFSET spc
    call WriteString
    pop eax
    ret
WriteDecToConsole ENDP

spc BYTE " ",0

; -------------------------
; SaveBufferToFile
; param: pointer to filename (on stack)
; Uses Irvine CreateOutputFile and WriteToFile if available. We'll use CreateOutputFile and WriteToFile.

SaveBufferToFile PROC
    push ebp
    mov ebp, esp
    mov edx, [ebp+8]         ; filename ptr

    ; Call WriteToFile(filenamePtr, bufferPtr, length)
    push dword ptr [bufferLen]
    lea eax, textBuffer
    push eax
    push edx
    call WriteToFile
    add esp, 12

    mov edx, OFFSET savedMsg
    call WriteString

    pop ebp
    ret 4
SaveBufferToFile ENDP

; ---------------------------
; Small helper wrappers & data
editorMsg BYTE 0Dh,0Ah, "=== EDITOR (console mode) ===", 0Dh,0Ah, 0
editorHint BYTE "Editor not yet implemented. Press any key to return to menu...",0Dh,0Ah,0

; WriteStringNoCR: write the string starting at EDX but do NOT append extra CR (use for newlines)
; (Irvine's WriteString prints the provided string; here we just call it.)
WriteStringNoCR PROC
    call WriteString
    ret
WriteStringNoCR ENDP

END main
