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
	.type find_smallest, %function
	.type find_largest, %function
	.type find_sum, %function

find_sum:
    ADD X10, X10, X2
    B then

find_largest:
    CMP X2, X11
    BGT changeGreater
	B sum

changeGreater:
	MOV X11, X2
	MOV X13, X16
	B sum

find_smallest:
     CMP X2, X12
     BLT ChangeLowest
	 B Largest

ChangeLowest:
	MOV X12, X2
	MOV X14, X0
	B Largest


main:
	ADRP X0, v           	// Load the array address to X0
	ADD X0, X0, :lo12:v
	ADRP X4, n           	// address of n
	ADD X4, X4, :lo12:n
	LDUR X4, [X4, #0]

	SUB X10, X10, X10        	// int sum = 0;
	SUB X11, X11, X11        	// int greatest = 0;
	SUB X12, X12, X12        	// int lowest = 0;
	SUB X16, X16, X16        	// int i = 0;

	LDUR X11, [X0, #0]
	LDUR X12, [X0, #0]
loop:

	LDUR X2, [X0, #0]
	BL find_smallest	// call find_smallest

Largest:
	LDUR X2, [X0, #0]
	BL find_largest 	// call find_largest
//	LDUR X2, [X0, #0]

sum:
	LDUR X2, [X0, #0]
	BL find_sum		// call find_sum
//	LDUR X2, [X0, #0]

then:
	ADD X16, X16, #1
	ADD X0,X0, #8
	SUB X15, X4, X16
	CBNZ X15, loop

exit: