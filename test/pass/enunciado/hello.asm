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
; IMM
	push	dword 2
; ADDRA
	pop	eax
	mov	[$var_1], eax
; ADDRV
	push	dword [$var_1]
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
; ADDRV
	push	dword [$var_1]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRA
	pop	eax
	mov	[$var_2], eax
; ADDRV
	push	dword [$var_2]
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
