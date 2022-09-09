#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
long a, b;
int i = 0, r = 0, sum[20];
cout << "Enter the first binary number: ";

cin >> a;

cout << "Enter the second binary number: ";

cin >> b;

while (a != 0 || b != 0)
{
sum[i++] = (a % 10 + b % 10 + r) % 2;
r = (a % 10 + b % 10 + r) / 2;
a = a / 10;
b = b / 10;
}
if (r != 0)
sum[i++] = r;
--i;
cout << "The sum of the two binary numbers is: ";
while (i >= 0)
cout << sum[i--];
cout << ". ";

//system("pause");
return 0;
}
