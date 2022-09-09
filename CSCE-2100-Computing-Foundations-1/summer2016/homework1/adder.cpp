#include "adder.h"

Adder::Adder(int a, int b)
{
	bin1 = a;
	bin2 = b;

}
int Adder::pluse(int, int)
{
	int sum[10];
	int rem = 0 , i = 0;
	while (bin1 != 0 || bin2 != 0)
	{
		sum[i++] = (bin1 % 10 + bin2 % 10 + rem) % 2;
		rem = (bin1 % 10 + bin2 % 10 + (static_cast<long>(rem))) / 2;
		bin1 = static_cast<long>(bin1) / 10;
		bin2 = static_cast<long>(bin2) / 10;
	}
	if (rem != 0)
	sum[i++] = rem;
	--i;
	while (i >= 0) cout << sum[i--];
	cout << endl;
	return 0;
}