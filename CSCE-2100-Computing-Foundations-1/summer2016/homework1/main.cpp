#include "adder.h"
#pragma once
int main()
{
	int x, y;
	string ops;
	 
	cout << "ripple_carry>";
	cin >> ops;
	if ((ops != "add") && (ops != "quit")) {
		cout << "please type add for addition or quit to quit program";
		cout << endl;
		cout << "ripple_carry>";
		cin >> ops;
	}
	while ((ops == "add") && (ops != "quit")) {
		cin >> x >> y;
		Adder math(x, y);
		math.pluse(x, y);
		cout << "ripple_carry>";
		cin >> ops;
	}
 return 0;
}
