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
	dd	0
; TEXT
segment	.text
; ADDRV
	push	dword [$x]
; IMM
	push	dword 1
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
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
	db	0x58
; CHAR
	db	0x20
; CHAR
	db	0x3D
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x31
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
; ADDRV
	push	dword [$x]
; IMM
	push	dword 0
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L5:
; CHAR
	db	0x58
; CHAR
	db	0x20
; CHAR
	db	0x3D
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x30
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
; JMP
	jmp	dword $_L6
; LABEL
$_L4:
; JMP
	jmp	dword $_L7
; LABEL
$_L6:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L8:
; CHAR
	db	0x58
; CHAR
	db	0x20
; CHAR
	db	0x21
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x31
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L8
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_L3:
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
