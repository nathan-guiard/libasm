bits 64

section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	;prologue
	push 		rbp				;save le content de rbp en le mettant dans la stack
	mov 		rbp, rsp		;met dans rbp l'adresse de retour stockee dans rsp

	call		ft_strlen			;rax = strlen(src)
	inc			rax					;rax++
	push		rdi					;rdi au top de la stack
	mov			rdi, rax			;rdi = rax
	call		malloc wrt ..plt	;rax = malloc(rdi)
	cmp			rax, 0x0			;if (!rax)
	je			end_strdup			; end_strdup()
	jmp			copy				;else copy()

copy:
	pop			rsi				;on reprend rdi pour le mettre dans rdx (l 16)
	mov			rdi, rax		;rsi = rax(return malloc)
	push		rax				;push return malloc
	call		ft_strcpy
	pop			rax				;pop return malloc pour la return value
	jmp			end_strdup

end_strdup:
	;epilogue
	mov			rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop			rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret							;return a la suite du programme