			global	ft_strcmp
			section	.text
ft_strcmp:
	.loop:
			mov		al, byte [rdi]
			mov		cl, byte [rsi]
			cmp		al, cl
			jnz		.done
			test	al, al
			je		.done
			inc		rdi
			inc		rsi
			jmp		.loop
	.done:
			sub		al, cl
			movsx	rax, al
			ret
