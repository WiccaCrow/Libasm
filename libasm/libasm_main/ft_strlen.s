;========================================================
;		ft_strelen										|
;========================================================
;Return length of string								|
;________________________________________________________
section .text
	global _ft_strlen
_ft_strlen:
	mov RAX, -1
.while:
	inc RAX
	cmp byte[RDI + RAX], 0
	jne .while
.return:
	ret
;
;========================================================
;		Theory											|
;________________________________________________________
;section .text					program code
;	global _ft_strlen			name "ft_strlen" is global (function) 
;_ft_strlen:					start function
;	mov RAX, -1					RAX is return value || MOV mean put -1 in RAX
;.while:						.blablabla is label
;	inc RAX
;	cmp byte[RDI + RAX], 0		'cmp' compares 1st with 0
;								and sets a flag for command 'j'
;
;								'byte' is size specification.
;								it can be byte, word or dword
;	jne .while					'j' jump to label .blablabla.
;								jne jump if flag (cmp) NO
;.return:
;	ret