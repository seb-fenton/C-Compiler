.text
.global f
.ent f
.type f, @function

f:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
addi $8, $sp, -20
sw $8, 0($sp)
addiu $sp, $sp, -20
addiu $sp, $sp, -4
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
lw $2,32($sp)
add $16, $2, $0
addiu $2,$0,2
add $17, $2, $0
sll $17, $17, 2
add $2, $16, $17
lw $16, 4($sp)
lw $17, 0($sp)

addiu $sp, $sp, 8
sw $2,0($sp)
addiu $sp, $sp, -4
sw $16, 0($sp)
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
lw $2,36($sp)
add $16, $2, $0
addiu $2,$0,2
add $17, $2, $0
sll $17, $17, 2
add $2, $16, $17
lw $16, 4($sp)
lw $17, 0($sp)
addiu $sp, $sp, 8
add $16, $2, $0
addiu $2,$0,3
sw $2, 0($16)
lw $16, 0($sp)
addiu $sp, $sp, 4
lw $2,0($sp)
lw $2, 0($2)
lw $31, 32($sp) 
nop
addiu $sp, $sp, 36
jr $31 
nop

addiu $sp, $sp, 28
lw $31, 4($sp) 
nop
addiu $sp, $sp, 8
jr $31 
nop

.end f
