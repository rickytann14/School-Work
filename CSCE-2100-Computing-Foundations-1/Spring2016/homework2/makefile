a.out: main.cpp
	@g++ main.cpp

test: a.out output2.txt string2.txt
	@(echo harrypotter; echo severussnape) | ./a.out > string.txt
	@echo -n "Testing response: "
	@if diff string.txt string2.txt > /dev/null; then echo "Pass"; else echo "Fail"; fi
	@echo -n "Testing output file: "
	@if diff output.txt output2.txt > /dev/null; then echo "Pass"; else echo "Fail"; fi

cleanup:
	rm a.out output.txt string.txt
