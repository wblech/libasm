global ft_strcmp

ft_strcmp:
	xor rcx, rcx
	xor rax, rax
	xor rdx, rdx
.loop:
	mov al, [rdi+rcx]
	mov dl, [rsi+rcx]
	test al, dl
	jz end
	cmp al, dl
	jne end
	inc rcx
	jmp .loop

end:
	sub rax, rdx
	ret
