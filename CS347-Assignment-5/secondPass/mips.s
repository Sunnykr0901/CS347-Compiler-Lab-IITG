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
