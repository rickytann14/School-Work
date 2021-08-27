.data
	.type	v, %object
	.type	i, %object
	.type	n, %object
	.size	v, 5
	.size   n, 1
n:
	.xword 5
v:
	.xword	31, 32, 33, 34, 35       // 64-bit values


	.text
	.global	main
	.global find_smallest
	.global find_largest
	.global find_sum
	.arch armv8-a+fp+simd
	.type find_smallest, %function
	.type find_largest, %function
	.type find_sum, %function
	.type	main, %function

find_sum:  	
	// X0 contains address of v; X1 contains n, 
	//X2 will contain sum returned
        (add your code here)

	
find_largest: 
	// X0 contains address of v; X1 contains n, 
	//X2 will contain largest value returned
	// X3 will contain the index of largest value returned
        (add your code here)



find_smallest: 
	// X0 contains address of v; X1 contains n, 
	//X2 will contain smallest value returned
	// X3 will contain the index of smallest value returned
        (add your code here)

main:
	ADRP X0, v           	// Load the array address to X0
	ADD X0, X0, :lo12:v	
	ADRP X1, n           	// address of n
	ADD X1, X1, :lo12:n  	

        (some code if you need)
	BL find_smallest	// call find_smallest
	(add code here)	        // copy smallest and its index to required registers

	BL find_largest 	// call find_largest
	(add code here)	        // copy largest and its index to required registers

	BL find_sum		// call find_sum
	(add code here)	        // copy sum to required registers
exit:

