.data
	.type	v, %object
	.type	i, %object
	.type	n, %object
	.size	v, 5
	.size   n, 1


n:	.xword 5
v:	.xword	31, 32, 33, 34, 35       // 64-bit values


	.text
	.global	main
	.arch armv8-a+fp+simd
	.type main, %function
	.global find_smallest
	.global find_largest
	.global find_sum
	.global find_values
	.type find_smallest, %function
	.type find_largest, %function
	.type find_sum, %function
	.type find_values, %function

//----------------------------------------

find_sum:
	// X0 contains address of v; X1 contains n,
	//X2 will contain sum returned
    ADD X5, X5, X2
    B then

//----------------------------------------

find_largest:
	// X0 contains address of v; X1 contains n,
	//X2 will contain largest value returned
	// X3 will contain the index of largest value returned
    CMP X2, X6
    BGT changeG
	B sum

changeG:
	MOV X6, X2
	MOV X13, X16
	B sum

//----------------------------------------

find_smallest:
	// X0 contains address of v; X1 contains n,
	//X2 will contain smallest value returned
	// X3 will contain the index of smallest value returned
     CMP X2, X7
     BLT ChangeL
	 B Large

ChangeL:
	MOV X7, X2
	MOV X14, X0
	B Large

//----------------------------------------

find_values:
	ADRP X0, v           	// Load the array address to X0
	ADD X0, X0, :lo12:v
	ADRP X4, n           	// address of n
	ADD X4, X4, :lo12:n
	LDUR X4, [X4, #0]

	SUB X5, X5, X5        	// int sum = 0;
	SUB X6, X6, X6        	// int greatest = 0;
	SUB X7, X7, X7        	// int lowest = 0;
	SUB X16, X16, X16       // int i = 0;

	LDUR X6, [X0, #0]
	LDUR X7, [X0, #0]
loop:

	LDUR X2, [X0, #0]
	BL find_smallest		// call find_smallest

Large:
	LDUR X2, [X0, #0]
	BL find_largest 		// call find_largest

sum:
	LDUR X2, [X0, #0]
	BL find_sum				// call find_sum

then:
	ADD X16, X16, #1
	ADD X0,X0, #8
	SUB X15, X4, X16
	CBNZ X15, loop

	B END_Find_Values_Func

//----------------------------------------

main:

	BL find_values

B END_Find_Values_Func:

exit:

