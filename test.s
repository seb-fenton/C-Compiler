main:
addiu $sp, $sp, -8
sw $fp, 0($sp)
sw $31, 4($sp)
addiu $sp, $sp, -4
start_0:
beq $2, $0, end_1
nop
addiu $sp, $sp, -4
addiu $sp, $sp, 4
iterate_2:
addiu $2,$2,1
b start_0
nop
end_1:
move $2, $0
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

addiu $sp, $sp, 4
move $sp, $fp
lw $31, -4($sp) 
nop
j $31

