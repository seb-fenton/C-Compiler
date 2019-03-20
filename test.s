.text
.global f
.ent f
.type f, @function

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
addiu $sp, $sp, -4
sw $8, 0($sp)
addiu $2,$0,2
add $8, $2, $0
addi $2, $sp, 4
sw $8, 0($2)
lw $8, 0($sp)
addiu $sp, $sp, 4
lw $2,0($sp)
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

addiu $sp, $sp, 4
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

.end f
