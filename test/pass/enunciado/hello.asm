; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
sub esp, 4
sub esp, 4
; IMM
	push	dword 10
; IMM
	push	dword -4
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop dword [eax]
; IMM
	push	dword 2
; IMM
	push	dword -8
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop dword [eax]
; IMM
	push	dword -4
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
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
	push	dword -8
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
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
	push	dword -4
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
; IMM
	push	dword -8
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
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
$_L3:
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
; IMM
	push	dword -4
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
; IMM
	push	dword -8
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
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
$_L4:
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
add esp, 8
; IMM
	push	dword 0
; POP
	pop	eax
; LEAVE
	leave
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
