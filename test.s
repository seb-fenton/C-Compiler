.text
.global f
.ent f
.type f, @function

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $2,$0,1
beq $2, $0, TRUE_END_0
nop
addiu $2,$0,1
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

TRUE_END_0:
nop
move $2, $0
addiu $2,$0,5
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

addiu $sp, $sp, 0
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

.end f
