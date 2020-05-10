; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; DATA
segment	.data
; LABEL
$var_1:
; INTEGER
	dd	1
; TEXT
segment	.text
; DATA
segment	.data
; LABEL
$var_2:
; INTEGER
	dd	2
; TEXT
segment	.text
; ADDR
	push	dword $var_2
; TEXT
segment	.text
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
