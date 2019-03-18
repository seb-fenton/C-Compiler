main:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
start_0:
sw $8,0($sp)
sw $9,0($sp)
add $8,$2,$0
add $9,$2,$0
beq $8,$9,3abel
slt $2,$8,$9
beq $2,0,2abel
jump 3abel
nop
2abel: addiu $2,$0,1
3abel: nop
lw $8,0($sp)
lw $9,0($sp)

beq $2, 0, end_1
nop
addiu $sp, $sp, -4
addiu $sp, $sp, 4
b start_0
nop
end_1:
move $2, $0
addiu $sp, $sp, 4
move $sp, $fp
lw $31, -4($sp) 
nop
j $31


