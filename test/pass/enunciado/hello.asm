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
; ADDRA
	pop	eax
	mov	[$var_1], eax
; IMM
	push	dword 2
; ADDRA
	pop	eax
	mov	[$var_2], eax
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; CHAR
	db	0x43
; CHAR
	db	0x6F
; CHAR
	db	0x6E
; CHAR
	db	0x63
; CHAR
	db	0x61
; CHAR
	db	0x74
; CHAR
	db	0x3A
; CHAR
	db	0x69
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; CHAR
	db	0x53
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x31
; CHAR
	db	0x20
; CHAR
	db	0x63
; CHAR
	db	0x6F
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x65
; CHAR
	db	0x77
; CHAR
	db	0x6C
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x65
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
; CHAR
	db	0x53
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x32
; CHAR
	db	0x20
; CHAR
	db	0x63
; CHAR
	db	0x6F
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x65
; CHAR
	db	0x77
; CHAR
	db	0x6C
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x65
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L3
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L4:
; CHAR
	db	0x56
; CHAR
	db	0x61
; CHAR
	db	0x72
; CHAR
	db	0x5F
; CHAR
	db	0x31
; CHAR
	db	0x20
; CHAR
	db	0x3D
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L4
; CALL
	call	$_prints
; TRASH
	add	esp, 4
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
$_L5:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L5
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
; LABEL
$var_2:
; INTEGER
	dd	0
; LABEL
$var_1:
; INTEGER
	dd	0
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_readi
