global _ft_strcpy

_ft_strcpy:
	mov rax, -1
	cmp rsi, 0
	jz	return
	cmp rdi, 0
	jz	return
while:
	inc rax
	mov dl, byte [rsi + rax]
	mov byte [rdi + rax], dl
	cmp dl, 0
	jne while
return:
	mov rax, rdi
	ret