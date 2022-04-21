bits 64

section .data
	string db "Bonjour", 0x0

section .text
	global _start

_start:
	mov rax, string
	push	rax
	call ft_strlen
	mov		rbx, rax
	mov		rax, 1
	int 0x80

ft_strlen: 					;ft_strlen(const char *s)
	;prologue
	push 	rbp				;save le content de rbp en le mettant dans la stack
	mov 	rbp, rsp		;met dans rbp l'adresse de retour stockee dans rsp

	;recuperation de l'argument
	mov		rbx, [rsp + 16]	;met dans rbx la valeur du premier argument

	;initialisation de mon compteur
	xor		rax, rax

	;check si le pointeur n'est pas nul
	cmp		rbx, 0			;compare rbx avec 0
	je		end_prog		;si les deux sont egaux, jump a end

loop:
	;verification de la condition
	cmp	byte	[rbx], 0x0
	je			end_prog

	;loop
	inc		rax
	inc		rbx
	jmp		loop


end_prog:
	;epilogue
	mov		rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop		rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret						;return a la suite du programme
