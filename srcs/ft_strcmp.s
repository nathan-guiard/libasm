bits 64

section .text
	global ft_strcmp

ft_strcmp:
	;prologue
	push 		rbp				;save le content de rbp en le mettant dans la stack
	mov 		rbp, rsp		;met dans rbp l'adresse de retour stockee dans rsp

	mov			rbx, rdi		;met s1 dans rbx
	mov			rcx, rsi		;met s2 dans rcx

	mov			rax, 0

loop:
	mov			rax, [rbx]		;rax = *s1
	and			rax, 0x000000ff	;petite manip pour garder que le premier octet
	sub			al, [rcx]		;rax -= *s2
	inc			rbx				;*s1++
	inc			rcx				;*s2++
	cmp			byte [rbx], 0x0	;stop si une des strings est finie
	je			end_cmp
	cmp			byte [rcx], 0x0
	je			end_cmp
	cmp			byte al, 0x0	;si les deux sont egales: on continue
	je			loop
	jmp			end				;sinon on fini

end_cmp:
	mov			rax, [rbx]		;fais un dernier check si les strings ont
	and			rax, 0x000000ff	;	pas la meme taille
	sub			rax, [rcx]
	jmp			end

end:
	;epilogue
	mov			rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop			rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret							;return a la suite du programme