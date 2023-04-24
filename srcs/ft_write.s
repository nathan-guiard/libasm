bits 64

section .text
	global ft_write
	extern __errno_location

ft_write:
	;prologue
	push 		rbp				;save le content de rbp en le mettant dans la stack
	mov 		rbp, rsp		;met dans rbp l'adresse de retour stockee dans rsp

	mov			rax, 1			;appel du syscall write
	syscall

	cmp			rax, 0			;si le retour de write est negatif
	jl			error			;	go dans l'error handling
	jmp			end				;sinon c fini

error:
	push		rax							;save la valeur de retour de write
	call		__errno_location wrt ..plt	;rax = &errno
	pop			rbx							;retrouve la valeur de retour de write
	neg			rbx							;rbx *= -1
	mov			[rax], rbx					;errno = rbx
	mov			rax, -1						;return -1
	jmp 		end

end:
	;epilogue
	mov			rsp, rbp		;remet la valeure stockee dans rbp dans rsp (voir prologue)
	pop			rbp				;reprend la valeur stockee dans la stack et la met dans rbp
	ret							;return a la suite du programme