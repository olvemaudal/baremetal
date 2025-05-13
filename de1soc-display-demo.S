.global _start

.equ DISPLAY_BASE, 0xff200020

_start:
	ldr r0, =DISPLAY_BASE
	mov r1, #0
forever:
	str r1, [r0]
	bl delay
	add r1, #1
	b forever

delay:
	ldr r2, =5000
.wait:
	sub r2, #1
	cmp r2, #0
	bne .wait
	bx lr