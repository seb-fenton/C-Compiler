.text
.global f
.ent f
.type f, @function

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
addiu $2,$0,4
sw $2,0($sp)
addiu $sp, $sp, -8
sw $8, 4($sp)
sw $9, 0($sp)
addiu $2,$0,4
sub $2,$0,$2
add $8, $2, $0
lw $2,8($sp)
add $9, $2, $0
add $8,$9,$8
addi $2, $sp, 8
sw $8, 0($2)
add $2, $8, $0
lw $8, 4($sp)
lw $9, 0($sp)
addiu $sp, $sp, 8
lw $31, 8($sp) 
nop
move $sp, $fp
jr $31 
nop

addiu $sp, $sp, 4
lw $31, 8($sp) 
nop
move $sp, $fp
jr $31 
nop

.end f
