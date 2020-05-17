; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; IMM
	push	dword 0
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L1
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; CHAR
	db	0x49
; CHAR
	db	0x46
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
; JMP
	jmp	dword $_L3
; LABEL
$_L1:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L4:
; CHAR
	db	0x45
; CHAR
	db	0x4C
; CHAR
	db	0x53
; CHAR
	db	0x45
; CHAR
	db	0x0A
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
; LABEL
$_L3:
; IMM
	push	dword 0
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L5
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L6:
; CHAR
	db	0x4E
; CHAR
	db	0x4F
; CHAR
	db	0x50
; CHAR
	db	0x45
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L6
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_L7
; LABEL
$_L5:
; LABEL
$_L7:
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
