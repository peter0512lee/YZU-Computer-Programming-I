#include<iostream>
using namespace std;
#include<ctime>

int main()
{
	char input[2] = { 'y', '\0' };
	for (;input[0] != 'n';)
	{
		cout << "I have a number between 1 and 1000." << endl;
		cout << "Can yot guess my number?" << endl;
		cout << "Please type your first guess." << endl;

		srand(time(NULL));
		int Ans, myAns;
		Ans = (rand() % 1000) + 1;

		for (;cin >> myAns;)
		{
			if (myAns > Ans)
				cout << "Too high. Try again." << endl;

			else if (myAns < Ans)
				cout << "Too low. Try again." << endl;

			else
			{
				cout << "Excellent! You guess the number!" << endl;
				break;
			}

		}

		cout << "Would you like to play again (y or n)?";
		cin >> input[0];		
		if (input[0] == 'y')
			continue;

	}

	system("pause");
}