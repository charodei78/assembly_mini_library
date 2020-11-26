global _ft_strdup

extern _ft_strcpy 
extern _ft_strlen 
extern _malloc

_ft_strdup:
	cmp		rdi, 0
	jz		return
	call	_ft_strlen
	inc		rax
alloc:
	push	rdi
	mov		rdi, rax
	call	_malloc
	pop		rsi
	cmp		rax, 1
	JL		return
	push	rax	
	pop		rdi
	call	_ft_strcpy
	ret

return:
	ret