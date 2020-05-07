.data
endline: .asciiz "\n"
.text
main:
subu $sp, $sp, 108
sw $ra, 104($sp)
sw $fp, 100($sp)
move $fp, $sp
li $t0, 0
sw $t0, 12($sp)
li $t0, 0
sw $t0, 4($sp)
li $t0, 0
sw $t0, 8($sp)
L7:
lw $t1, 8($sp)
li $t2, 10
slt $t3, $t1, $t2
beq $t3, 0, L75
j L18
L13:
lw $t2, 8($sp)
addu $t1, $t2, 1
sw $t1, 8($sp)
j L7
L18:
li $t2, 0
sw $t2, 0($sp)
L21:
lw $t3, 0($sp)
li $t0, 3
slt $t1, $t3, $t0
beq $t1, 0, L73
j L32
L27:
lw $t0, 0($sp)
addu $t3, $t0, 1
sw $t3, 0($sp)
j L21
L32:
lw $t0, 12($sp)
lw $t1, 8($sp)
add $t2, $t0, $t1
sw $t2, 12($sp)
lw $t2, 8($sp)
lw $t1, 0($sp)
add $t0, $t2, $t1
li $t1, 3
div $t2, $t0, $t1
mfhi $t2
li $t1, 0
seq $t0, $t2, $t1
beq $t0, 0, L71
lw $t0, 4($sp)
addu $t1, $t0, 1
sw $t1, 4($sp)
lw $t0, 4($sp)
li $t1, 3
div $t2, $t0, $t1
mfhi $t2
li $t1, 0
seq $t0, $t2, $t1
bne $t0, 0, L62
lw $t1, 4($sp)
li $t2, 3
sub $t3, $t1, $t2
li $t2, 0
sgt $t1, $t3, $t2
bne $t1, 0, L62
li $t2, 0
j L64
L62:
li $t2, 1
L64:
beq $t2, 0, L70
lw $t2, 4($sp)
li $t1, 2
add $t0, $t2, $t1
sw $t0, 4($sp)
L70:
L71:
j L27
L73:
j L13
L75:
lw $t0, 12($sp)
move $a0, $t0
li $v0 1
syscall
li $v0, 4
la $a0, endline
syscall
lw $t0, 8($sp)
move $a0, $t0
li $v0 1
syscall
li $v0, 4
la $a0, endline
syscall
lw $t0, 4($sp)
move $a0, $t0
li $v0 1
syscall
li $v0, 4
la $a0, endline
syscall
li $t0, 0
move $v0, $t0
j end_main
end_main:
move $sp, $fp
lw $ra, 104($sp)
lw $fp, 100($sp)
addu $sp, $sp, 108
j $ra
