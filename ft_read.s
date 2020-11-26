global _ft_read
extern ___error

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc		error_ret
	ret
error_ret:
	push	rax
	call	___error
	mov		rdi, rax
	pop		rax
	mov		byte[rdi], al
	mov		rax, -1
	ret