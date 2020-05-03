; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; STR
	db	'1 olá pessoal!', 0
; TEXT
segment	.text
; ADDR
	push	dword $_L1
; CALL
	call	$_prints
; CALL
	call	$_println
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; STR
	db	'2 olá pessoal!', 0
; TEXT
segment	.text
; ADDR
	push	dword $_L2
; CALL
	call	$_prints
; CALL
	call	$_println
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
; STR
	db	'3 olá pessoal!', 0
; TEXT
segment	.text
; ADDR
	push	dword $_L3
; CALL
	call	$_prints
; CALL
	call	$_println
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
