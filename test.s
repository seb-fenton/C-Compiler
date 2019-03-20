.text
.global f

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
sw $4, 0($fp)
addiu $sp, $sp, -8
sw $8,4($sp)
sw $9,0($sp)
lw $2,16($sp)
add $8,$2,$0
addiu $2,$0,1
add $9,$2,$0
sub $2,$8,$9
lw $8,4($sp)
lw $9,0($sp)

addiu $sp, $sp, 8
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

addiu $sp, $sp, 0
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

