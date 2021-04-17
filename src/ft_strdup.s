global ft_strdup

extern ft_strlen
extern malloc
extern ft_strcpy
extern __errno_location

ft_strdup:
	push rdi
	call ft_strlen
	inc rax
	pop rdi
	mov rbx, rdi
	mov rdi, rax
	call malloc
	cmp rax, 0
	jz error
	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy
	ret

error:
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	mov rax, -1
	ret

