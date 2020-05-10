; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; IMM
	push	dword 1
; IMM
	push	dword 2
; ADD
	pop	eax
	add	dword [esp], eax
; IMM
	push	dword 3
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; POP
	pop	eax
; RET
	ret
; DATA
segment	.data
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_readi
