#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int main()
{
	const int size = 80;
	char text[size];
	cout << "Enter a line of text:\n";
	cin.getline(text, size);

	char *ptr[50];
	char *temp;
	char *nextToken;
	

	int count = 0;

	temp = strtok_s(text, " ", &nextToken);
	
	while (temp != NULL)
	{		
		ptr[count++] = temp;		
		temp = strtok_s(0, " ", &nextToken);
	}
		
	for (int i = 0; i < count - 1; i++)
	{	
		for (int j = 0; j < count - 1; j++)
			if (strcmp(ptr[j], ptr[j + 1]) > 0)
			{
				char *buffer = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = buffer;
			}
	}
	cout << endl;

	cout << "The tokens in sorted order are:" << endl;
	for (int i = 0; i < count; i++)
		cout << ptr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
