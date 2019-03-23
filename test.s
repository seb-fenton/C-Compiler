.text
.global f2
.ent f2
.type f2, @function

f2:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
sw $4, 0($fp)
addiu $sp, $sp, -4
sw $16, 0($sp)
addi $2, $sp, 12
add $16, $2, $0
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
lw $2,20($sp)
add $16, $2, $0
addiu $2,$0,2
add $17, $2, $0
sll $17, $17, 2
add $2, $16, $17
lw $16, 4($sp)
lw $17, 0($sp)

addiu $sp, $sp, 8
sw $2, 0($16)
lw $16, 0($sp)
addiu $sp, $sp, 4
lw $2,8($sp)
lw $2, 0($2)
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

.end f2
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
sw $16, 0($sp)
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
lw $2,32($sp)
add $16, $2, $0
addiu $2,$0,0
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
addiu $sp, $sp, -4
sw $16, 0($sp)
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
lw $2,32($sp)
add $16, $2, $0
addiu $2,$0,1
add $17, $2, $0
sll $17, $17, 2
add $2, $16, $17
lw $16, 4($sp)
lw $17, 0($sp)
addiu $sp, $sp, 8
add $16, $2, $0
addiu $2,$0,5
sw $2, 0($16)
lw $16, 0($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, -4
sw $16, 0($sp)
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
add $16, $2, $0
addiu $2,$0,7
sw $2, 0($16)
lw $16, 0($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, -4
sw $16, 0($sp)
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
lw $2,32($sp)
add $16, $2, $0
addiu $2,$0,3
add $17, $2, $0
sll $17, $17, 2
add $2, $16, $17
lw $16, 4($sp)
lw $17, 0($sp)
addiu $sp, $sp, 8
add $16, $2, $0
addiu $2,$0,8
sw $2, 0($16)
lw $16, 0($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, -4
sw $16, 0($sp)
addiu $sp, $sp, -8
sw $16, 4($sp)
sw $17, 0($sp)
lw $2,32($sp)
add $16, $2, $0
addiu $2,$0,4
add $17, $2, $0
sll $17, $17, 2
add $2, $16, $17
lw $16, 4($sp)
lw $17, 0($sp)
addiu $sp, $sp, 8
add $16, $2, $0
addiu $2,$0,9
sw $2, 0($16)
lw $16, 0($sp)
addiu $sp, $sp, 4
addiu $sp, $sp, -4
lw $2,24($sp)
sw $2,0($sp)
addiu $sp, $sp, -16
sw $4, 0($sp)
sw $5, 4($sp)
sw $6, 8($sp)
sw $7, 12($sp)
addiu $sp, $sp, -4
lw $2,20($sp)
move $4, $2
move $fp, $sp
jal f2
lw $fp, 48($sp)
nop
addi $sp, $sp, 4
lw $4, 0($sp)
lw $5, 4($sp)
lw $6, 8($sp)
lw $7, 12($sp)
addiu $sp, $sp, 16
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
