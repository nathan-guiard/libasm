bits 64

section .text
	global ft_strcmp

ft_strcmp:
	;prologue
	push 		rbp				;save le content de rbp en le mettant dans la stack
	mov 		rbp, rsp		;met dans rbp l'adresse de retour stockee dans rsp

	mov			rbx, rdi		;met s1 dans rbx
	mov			rcx, rsi		;met s2 dans rcx

	xor			rax, rax

	mov 		al, [rbx]		;soit ABCD 16 octects, je met s1[0] dans CD
	mov 		ah, [rcx]		;	et s2[0] dans AB. si ABCD est 0 alors les
	cmp			rax, 0			;	deux strings sont vides
	je			.end_strcmp

.loop_strcmp:
	xor			rax, rax		;rax = 0
	xor			rdx, rdx		;rdx = 0
	mov			al, [rbx]		;al = *s1
	mov			dl, [rcx]		;dl = *s2
	sub			rax, rdx		;rax -= rdx (*s1 -= *s2)
	inc			rbx				;s1++
	inc			rcx				;s2++
	cmp			byte [rbx], 0x0	;stop si une des strings est finie
	je			.last_compare_strcmp
	cmp			byte [rcx], 0x0
	je			.last_compare_strcmp
	cmp			byte al, 0x0	;si les deux sont egales: on continue
	je			.loop_strcmp
	jmp			.end_strcmp				;sinon on fini

.last_compare_strcmp:
	xor			rax, rax		;rax = 0
	xor			rdx, rdx		;rdx = 0
	mov			al, [rbx]		;substraction finale
	mov			dl, [rcx]
	sub			rax, rdx
	jmp			.end_strcmp

.end_strcmp:
	;epilogue
	mov			rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop			rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret							;return a la suite du programme