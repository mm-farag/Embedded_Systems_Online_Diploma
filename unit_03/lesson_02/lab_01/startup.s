.global reset
reset:
	ldr sp, =stack_Top
 	bl main
stop: b stop