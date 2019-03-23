.text
.global f
.ent f
.type f, @function

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
addiu $2,$0,7
sw $2,0($sp)
addiu $sp, $sp, -4
addi $2, $sp, 4
sw $2,0($sp)
addiu $sp, $sp, -4
sw $16, 0($sp)
lw $2,4($sp)
add $16, $2, $0
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
addiu $2,$0,4
add $16, $2, $0
addiu $2,$0,13
add $17, $2, $0
add $2, $16, $17
lw $16, 4($sp)
lw $17, 0($sp)

addiu $sp, $sp, 8
sw $2, 0($16)
lw $16, 0($sp)
addiu $sp, $sp, 4
lw $2,4($sp)
lw $31, 12($sp) 
nop
move $sp, $fp
jr $31 
nop

addiu $sp, $sp, 8
lw $31, 4($sp) 
nop
move $sp, $fp
jr $31 
nop

.end f
