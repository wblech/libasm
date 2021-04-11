
global ft_strlen

ft_strlen:
	push rcx
	xor rcx, rcx

.loop:
	cmp [rdi], byte 0
	jz end
	inc rcx
	inc rdi
	jmp .loop

end:
	mov rax, rcx
	pop rcx
	ret
