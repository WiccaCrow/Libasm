;========================================================
;		ft_strcmp										|
;========================================================
; Compare two strings. Rewrite strcmp (man 3 strcmp).	|
;________________________________________________________
section .text
	global _ft_strcmp
_ft_strcmp:
	mov RCX, -1
	mov RAX, 0
.while:
	inc RCX
	movzx RAX, byte [RDI + RCX];			cmp S1, 0
	movzx RBX, byte [RSI + RCX];			cmp S2, 0
	cmp RAX, 0
	je .return
	cmp RBX, 0
	je .return
	cmp RAX, RBX;							cmp S2, S1
	je .while
.return:
	sub RAX, RBX
	ret
;
;========================================================
;		Theory											|
;________________________________________________________
; RDI 1st arg, RSI 2nd arg
;sub							subtraction