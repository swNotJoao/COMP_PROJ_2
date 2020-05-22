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
sub esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; IMM
	push	dword -4
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
mov ecx, $_L1
mov [eax], ecx
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; IMM
	push	dword -8
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
mov ecx, $_L2
mov [eax], ecx
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; IMM
	push	dword -12
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
mov ecx, $_L3
mov [eax], ecx
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
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword -12
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
add esp, 12
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
