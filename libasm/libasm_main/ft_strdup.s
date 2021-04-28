;========================================================
;		ft_strdup										|
;========================================================
; Copies the string (man 3 strdup).						|
;________________________________________________________
section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
_ft_strdup:
	push RDI
    call _ft_strlen
	inc RAX
    mov RDI, RAX
	call _malloc
	jz .return_null
    mov RDI, RAX
	pop RSI
	call _ft_strcpy
	ret
.return_null:
	pop RSI
	ret
;
;========================================================
;		Theory											|
;________________________________________________________
; RDI 1st arg, RSI 2nd arg, RDX 3d
; https://filippo.io/making-system-calls-from-assembly-in-mac-os-x/
; http://www.opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master
; 	mov     rax, 0x2000004 ; write nb 4 + 0x20000000 = 0x20000004
; https://www.notion.so/LibASM-ddd4ac8ffb834c19a9e85ee1b1ca685b#97a08170236243a8b1680f83c12ad4cc
;	push RDI a value (not necessarily stored in a register)
;			means it is pushed onto the stack.
;	pop RSI popping means restoring everything at the top
;			of the stack to a register.