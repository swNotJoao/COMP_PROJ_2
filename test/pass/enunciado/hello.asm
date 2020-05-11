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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$var_3:
; CHAR
	db	0x53
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x65
; CHAR
	db	0x63
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x72
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x31
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x00
; TEXT
segment	.text
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$var_4:
; CHAR
	db	0x4C
; CHAR
	db	0x49
; CHAR
	db	0x58
; CHAR
	db	0x4F
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; IMM
	push	dword 1
; ADDR
	push	dword $var_3
; ADD
	pop	eax
	add	dword [esp], eax
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
	push	dword 1
; ADDR
	push	dword $var_3
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
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
