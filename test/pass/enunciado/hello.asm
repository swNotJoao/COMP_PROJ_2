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
$x:
; INTEGER
	dd	1
; INTEGER
	dd	2
; INTEGER
	dd	3
; INTEGER
	dd	4
; INTEGER
	dd	5
; TEXT
segment	.text
; DATA
segment	.data
; LABEL
$y:
; INTEGER
	dd	77
; TEXT
segment	.text
; IMM
	push	dword 2
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADDR
	push	dword $x
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; TEXT
segment	.text
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; IMM
	push	dword 1
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADDR
	push	dword $x
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; TEXT
segment	.text
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADDR
	push	dword $x
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; TEXT
segment	.text
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L1
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADDR
	push	dword $y
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; TEXT
segment	.text
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L2
; CALL
	call	$_prints
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
