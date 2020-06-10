#include <iostream>
using namespace std;

int main()
{	
	int n, k, c, space = 1;
	cout << "Please input an integer for listing a rhombus with n asterisks in each side: ";
	cin >> n;

	space = n - 1;
	k = 1;
	do
	{
		c = 1;
		do
		{
			if (space == 0) break;
			cout << " ";
			c++;
		}while (c <= space);

		space--;
		
		c = 1;
		do
		{
			cout << "*";
			c++;
		}while (c <= 2 * k - 1);

		cout << endl;
		k++;

	}while (k <= n);

	space = 1;
	k = 1;
	do
	{
		if (k == n) break;
		c = 1;
		do
		{
			cout << " ";
			c++;
		}while (c <= space);

		space++;

		c = 1;
		do
		{
			cout << "*";
			c++;
		}while (c <= 2 * (n - k) - 1);

		cout << endl;
		k++;

	}while (k <= n);
			
	system("pause");
	return 0;
}
