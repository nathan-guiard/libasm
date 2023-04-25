bits 64

section .text
	global ft_strlen

ft_strlen: 						;ft_strlen(const char *s)
	;prologue
	push 		rbp				;save le content de rbp en le mettant dans la stack
	mov 		rbp, rsp		;met dans rbp l'adresse de retour stockee dans rsp

	;recuperation de l'argument
	mov			rbx, rdi		;met dans rbx la valeur du premier argument

	;initialisation de mon compteur
	mov			rax, 0x0

	;check si le pointeur n'est pas nul
	cmp			rbx, 0			;compare rbx avec 0
	je			.end_strlen		;si les deux sont egaux, jump a end

.loop_strlen:
	;verification de la condition
	cmp	byte	[rbx], 0x0		;compare le premier bit de la valeur pointee par rbx
	je 			.end_strlen

	;loop
	inc			rax
	inc			rbx
	jmp			.loop_strlen


.end_strlen:
	;epilogue
	mov			rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop			rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret							;return a la suite du programme
