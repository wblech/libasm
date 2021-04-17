global ft_write

extern __errno_location

ft_write:
	mov rax, 1 ; chama o wit do sistema
	syscall
	cmp rax, 0 ; vê se é negativo
	jl error ; caso negativo chama o erro
	ret

error:
	neg rax ; pega o valor negativo e transforma em positivo
	mov rdi, rax ; salva o valor do erro em rdi
	call __errno_location ; chama a função error e devolverá um ponteiro para ela
	mov [rax], rdi ; manda o valor do erro para onde a função error está lendo o erro
	mov rax, -1 ; coloca o retorno da função ft_write
	ret
