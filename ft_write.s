global _ft_write
extern ___error

_ft_write:
	mov		rax, 0x2000004
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