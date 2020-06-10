#include<iostream>
using namespace std;

int main()
{
	int n, j;

	cout << "Please input an integer for listing all the primes less than the integer:  ";
	cin >> n;

	cout << "Primes less than " << n << " are ";

	int i = 2;

	do{
		j = 2;

		
		do{
			if (i % j == 0)
				break;
			j++;

		} while (j <= i);

		if (i == j)			
			cout << j << " ";
		i++;

	} while (i < n);
		
	cout << endl;

	system("pause");
	return 0;

}