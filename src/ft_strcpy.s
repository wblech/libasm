global ft_strcpy

ft_strcpy:
	xor rcx, rcx

.loop:
	cmp [rsi+rcx], byte 0
	jz end
	mov dh, [rsi+rcx]
	mov [rdi+rcx], dh
	inc rcx
	jmp .loop

end:
	mov [rdi+rcx], byte 0
	mov rax, rdi
	ret
