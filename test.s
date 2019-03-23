.text
.global f
.ent f
.type f, @function

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, 0
addiu $2,$0,5
sw $2,-4($sp)
lw $2,-4($sp)
lw $31, 4($sp) 
nop
addiu $sp, $sp, 8
jr $31 
nop

addiu $sp, $sp, 0
lw $31, 4($sp) 
nop
addiu $sp, $sp, 8
jr $31 
nop

.end f
