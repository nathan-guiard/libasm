bits 64

section .text
	global ft_strcpy

ft_strcpy:
	;prologue
	push 		rbp				;save le content de rbp en le mettant dans la stack
	mov 		rbp, rsp		;met dans rbp l'adresse de retour stockee dans rsp

	mov			rbx, rdi		;met dest dans rbx
	mov			rcx, rsi		;met src dans rcx
	
	mov			rax, rbx		;initilisation de rax

.loop_strcpy:
	mov			dl, [rcx]		;*dest = *src
	mov			[rbx], dl
	inc			rbx				;dst++
	inc			rcx				;src++
	cmp			byte dl, 0x0	;if (rdx != 0)
	jne			.loop_strcpy	;refare la boucle

	;epilogue
	mov			rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop			rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret							;return a la suite du programme