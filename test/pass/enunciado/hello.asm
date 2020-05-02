; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; STR
	db	'olá pessoal!
', 0
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
