.text
.global f

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
sw $4, 0($fp)
sw $5, 4($fp)
addiu $sp, $sp, -4
addiu $2,$0,5
sw $2, 0($sp)
addiu $sp, $sp, -4
addiu $2,$0,2
sw $2, 0($sp)
lw $2,4($sp)
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

addiu $sp, $sp, 8
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

