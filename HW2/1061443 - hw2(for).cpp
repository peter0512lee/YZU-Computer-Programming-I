#include<iostream>
using namespace std;

int main()
{
	int n, j;

	cout << "Please input an integer for listing all the primes less than the integer:  ";
	cin >> n;

	cout << "Primes less than " << n << " are ";

	for (int i = 2; i < n; i++)
	{
		for (j = 2; j <= i; j++)
		{
			if (i % j == 0)
				break;			

		}		

		if (i == j)			
			cout << j << " ";

	}

	cout << endl;

	system("pause");
	return 0;

}