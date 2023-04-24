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
	mov			rbx, rdi			;rbx = src
	mov			rdi, rax			;rdi = rax
	call		malloc wrt ..plt	;rax = malloc(rdi)
	cmp			rax, 0x0			;if (!rax)
	je			end_strdup			; end_strdup()
	jmp			copy				;else copy()

copy:
	mov			rsi, rbx		;rdi = rbx(src)
	mov			rdi, rax		;rsi = rax(return malloc)
	mov			rcx, rax		;rcx = rax(return malloc)
	call		ft_strcpy
	mov			rax, rcx		;rcx == return value
	jmp			end_strdup

end_strdup:
	;epilogue
	mov			rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop			rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret							;return a la suite du programme