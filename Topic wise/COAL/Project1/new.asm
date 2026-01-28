Include Irvine32.inc
.data
var1 DWORD 5
var2 DWORD 6

.code
main proc
push var2
push var1
call AddTwo
call writedec 
call crlf
exit
main endp


AddTwo PROC
push ebp
mov ebp, esp
mov eax, [ebp + 12]
add eax, [ebp + 8]
pop ebp
ret
AddTwo ENDP
end main
