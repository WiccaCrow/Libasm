;========================================================
;		ft_write										|
;========================================================
; Rewrite write (man 2 write).							|
;________________________________________________________
section .text
	extern ___error
	global _ft_write
_ft_write:
	mov rax, 0x2000004
	syscall
	jc .error
	ret
.error:
	push RAX
	call ___error
	pop qword [RAX]
	mov RAX, -1
	ret
;
;========================================================
;		Theory											|
;________________________________________________________
; RDI 1st arg, RSI 2nd arg, RDX 3d
; https://filippo.io/making-system-calls-from-assembly-in-mac-os-x/
; http://www.opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master
; 	mov     rax, 0x2000004 ; write nb 4 + 0x20000000 = 0x20000004