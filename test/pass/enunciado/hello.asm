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
sub esp, 40
; IMM
	push	dword 0
; IMM
	push	dword 0
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 1
; IMM
	push	dword 1
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 2
; IMM
	push	dword 2
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 3
; IMM
	push	dword 3
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 4
; IMM
	push	dword 4
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 5
; IMM
	push	dword 5
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 6
; IMM
	push	dword 6
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 7
; IMM
	push	dword 7
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 8
; IMM
	push	dword 8
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 9
; IMM
	push	dword 9
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
pop ecx
mov [eax], ecx
; IMM
	push	dword 0
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
	push	dword 2
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
	push	dword 3
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
; IMM
	push	dword 4
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
	push	dword 5
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
$_L6:
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
; IMM
	push	dword 6
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
$_L7:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L7
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 7
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
$_L8:
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
; IMM
	push	dword 8
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
$_L9:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L9
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 9
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword -40
push ebp
; ADD
	pop	eax
	add	dword [esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; POP
	pop	eax
push dword [eax]; TEXT
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
$_L10:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L10
; CALL
	call	$_prints
; TRASH
	add	esp, 4
add esp, 40
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
