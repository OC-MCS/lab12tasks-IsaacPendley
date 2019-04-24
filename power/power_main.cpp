#include <iostream>
using namespace std;

int power(int n, int p)
{
	int result =1;
	if (p > 0)
	{
		result = n * power(n,p - 1);
	}
	else if (p = 0)
	{
		result = 1;
	}
	return result;
}

int main()
{
	cout << power(4,5) << endl;

	return 0;
}