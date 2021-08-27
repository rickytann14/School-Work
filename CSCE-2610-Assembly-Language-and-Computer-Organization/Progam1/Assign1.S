.data
.text
.global main
.arch armv8-a+fp+simd
.type main, %function
//.type changeGT, %function
//.type changeLT, %function

.type v, %object
.type n, %object

.size v, 5
.size n, 1

n:    .xword 5
v:    .xword 31,32,33,34,35

//changeGT:
//	MOV X11, X2
//	BR X30
//changeLT:
//	MOV X12, X2
//	BR X30


main:

	ADRP X0, v
	ADD X0, X0, :lo12:v
	ADRP X4, n
	ADD X4, X4, :lo12:n
	LDUR X4, [X4, #0]

	SUB X10, X10, X10        	// int sum = 0;
	SUB X11, X11, X11        	// int greatest = 0;
	SUB X12, X12, X12        	// int lowest = 0;
	SUB X13, X13, X13        	// int i = 0;
	LDUR X11, [X0, #0]
	LDUR X12, [X0, #0]

loop:

	LDUR X2, [X0, #0]        	// Loads v[i] in X2 (v = 31,32,33,34,35)
	ADD X10, X10, X2        	// sum = sum + v[i] (Adding 0 + 31)

	CMP X2, X11                 // Comparing each number of the array to the greates number stored in X11
	BGT changeGT                // If its bigger greater then it will jump to changeGT

changeGT:
	MOV X11, X2                 // It will move the array number to X11 if its greater than the one stored
	CMP X2, X12                 // Compares the number in the array to the lowest number stored in X12
	BLT changeLT                // If its lower it will jump to changeLT
	B then                      // If not it will go back to then

changeLT:
	MOV X12, X2                 // It will move the array number to X12 if its lower than the one stored
	B then                      // IT will then go back to then

then:
		ADD X13, X13, #1        // i = i + 1 (X13 is 0 + 1 = 1) Counter
		ADD X0, X0, #8          // getting the next address of the array (8 bits)
		SUB X14, X4, X13        // Subtracting n-i and storing it on X14 (check if i < n)
		CBNZ X14, loop          // Comparing i < n repeat loop

exit:
