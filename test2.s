main:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, 4
move $sp, $fp
lw $31, -4($sp) 
nop
j $31


f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
addiu $sp, $sp, 4
addiu $sp, $sp, -4
addiu $sp, $sp, 8
move $sp, $fp
lw $31, -4($sp) 
nop
j $31


