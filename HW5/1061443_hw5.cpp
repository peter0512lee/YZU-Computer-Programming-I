#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	const int row = 5;
	const int column = 6;
	double sales[row][column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			sales[i][j] = 0;

	cout << "Enter the salesperson (1 - 4), product number (1 - 5), and total sales." << endl;
	cout << "Enter -1 for the salesperson to end input." << endl;

	int person, product, money;
	while (cin >> person && person != -1)
	{			
		cin >> product >> money;
		sales[person - 1][product - 1] += money;		
	}

	for (int i = 0; i < row - 1; i++)
		for (int j = 0; j < column - 1; j++)
			sales[i][5] += sales[i][j];

	for (int i = 0; i < column - 1; i++)
		for (int j = 0; j < row - 1; j++)
			sales[4][i] += sales[j][i];

	cout << "The total sales for each salesperson are displayed at the end of each row, \nand the total sales for each product are displayed at the bottom of each column.\n" << endl;
	cout << fixed << setprecision(2);
	cout << setw(11) << 1 << setw(10) << 2 << setw(10) << 3 << setw(10) << 4 << setw(10) << 5 << setw(10) << "Total" << endl;


	for (int i = 0; i < row - 1; i++)
	{
		cout << i + 1;
		for (int j = 0; j < column; j++)
			cout << setw(10) << sales[i][j];
		cout << endl;
	}

	cout << "\nTotal";
	cout << setw(6) << sales[4][0];
	for (int j = 1; j < column - 1; j++)
		cout << setw(10) << sales[4][j];
	
	cout << endl;
	system("pause");	
}