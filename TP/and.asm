; GLOBL
global	$_main:function
; TEXT
segment	.text
; ALIGN
align	4
; LABEL
$_main:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; IMM
	push	dword 1
; IMM
	push	dword 2
; AND
	pop	eax
	and	dword [esp], eax
; EXTRN
extern	$_printi
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; COMM line 3
; IMM
	push	dword 0
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
