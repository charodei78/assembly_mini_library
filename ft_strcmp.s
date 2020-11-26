global _ft_strcmp

_ft_strcmp:
	mov rax, -1
	cmp rsi, 0
	jz	return
	cmp rdi, 0
	jz	return
while:
	inc rax
	movzx bx, byte [rsi + rax]
	movzx cx, byte [rdi + rax]
	cmp cx, bx
	jne compare
	cmp bx, 0
	jne while

compare:
	cmp cx, bx
	jg	return_more
	cmp bx, 0
	jne return_less
	jmp	return

return_more:
	mov rax, 1
	ret
return_less:
	mov rax, -1
	ret
return:
	mov rax, 0
	ret
