			global		ft_strcpy
			section		.text
ft_strcpy:
			mov			rax, rdi
loop:
			mov			cl, byte [rsi]
			mov			byte [rdi], cl
			inc			rdi
			inc			rsi
			test		cl, cl
			jnz			loop
			ret
