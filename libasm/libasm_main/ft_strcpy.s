;========================================================
;		ft_strcpy										|
;========================================================
;Return copy of string. Rewrite strcpy (man 3 strcpy).	|
;________________________________________________________
section .text
	global _ft_strcpy
_ft_strcpy:
	mov RCX, 0
.while:
	mov AL, byte [RSI + RCX]
	mov byte [RDI + RCX], AL
	inc RCX
	cmp AL, 0
	jne .while
.return:
	mov RAX, RDI
	ret
;
;========================================================
;		Theory											|
;________________________________________________________
; RDI 1st arg, RSI 2nd arg
;section .bss					uninitialized variables