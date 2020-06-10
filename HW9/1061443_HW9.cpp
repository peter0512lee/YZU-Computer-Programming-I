#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Fruit
{
	bool b = false;
	string f = "";
	int q = 0;
	double p = 0.0;
};

void List_all_fruits(Fruit *fruit)
{
	cout << endl <<
		left << setw(11) << "Record#" << left << setw(30) << "Fruit name" << left << setw(13) << "Quantity"  << "Price" << endl;

	for (size_t i = 0; i < 100; i++)
	{
		if (fruit[i].b == true)
		{
			cout <<
				left << setw(11) << i + 1 << left << setw(30) << fruit[i].f << left << setw(13) << fruit[i].q << fixed << setprecision(2) << fruit[i].p << endl;
		}
	}
}

void Update_record(Fruit *fruit)
{
	int num;

	cout << endl <<
		"Enter the fruit number for update: ";
	cin >> num;

	if (fruit[num - 1].b == false)
	{
		cout <<
			"Cannot update. The record is empty." << endl;
		return;
	}

	cout << endl <<
		left << setw(11) << "Becord#" << left << setw(30) << "Fruit name" << left << setw(13) << "Quantity" << "Price" << endl <<
		left << setw(11) << num << left << setw(30) << fruit[num - 1].f << left << setw(13) << fruit[num - 1].q << fixed << setprecision(2) << fruit[num - 1].p << endl;

	cout <<
		"Enter the fruit name: ";
	cin >> fruit[num - 1].f;

	cout <<
		"Enter quantity and price: ";
	cin >> fruit[num - 1].q >> fruit[num - 1].p;

	cout <<
		"Record updated." << endl;
}

void Insert_record(Fruit *fruit)
{
	int num;

	cout << endl <<
		"Enter the fruit number for insertion: ";	
	cin >> num;

	if (fruit[num - 1].b == true)
	{
		cout <<
			"Cannot insert. The record contains information." << endl;
		return;
	}
	else
		fruit[num - 1].b = true;

	cout <<
		"Enter the fruit name: ";
	cin >> fruit[num - 1].f;

	cout <<
		"Enter quantity and price: ";
	cin >> fruit[num - 1].q >> fruit[num - 1].p;

	cout <<
		"Record inserted." << endl;
}

void Delete_record(Fruit *fruit)
{
	int num;

	cout << endl <<
		"Enter the fruit number for deletion: ";
	cin >> num;

	if (fruit[num - 1].b == false)
	{
		cout <<
			"Cannot delete. The record is empty." << endl;
		return;
	}
	else
		fruit[num - 1].b = false;

	cout <<
		"Record deleted." << endl;
}

void load(Fruit *fruit)
{
	ifstream file("fruit.dat", ios::in || ios::binary);
	if (!file)
	{
		file.close();
		ofstream file_create("fruit.dat", ios::out);
		file_create.close();
		ifstream file("fruit.dat", ios::in || ios::binary);
	}

	for (size_t i = 0; i < 100; i++)
	{
		file.read((char*)&fruit[i], sizeof(Fruit));
	}

	cout << "Data of fruit.dat is loaded!" << endl << endl;

	file.close();
}

void save(Fruit *fruit)
{
	ofstream file("fruit.dat", ios::out || ios::binary);

	for (size_t i = 0; i < 100; i++)
	{
		file.write((char*)&fruit[i], sizeof(Fruit));
	}

	file.close();
}

int main()
{
	Fruit *fruit = new Fruit[100];
	load(fruit);

	int choice;

	while (true)
	{
		cout << endl <<
			"Enter a choice:" << endl <<
			"1  List all fruits." << endl <<
			"2  Update record." << endl <<
			"3  Insert record." << endl <<
			"4  Delete record." << endl <<
			"5  End program." << endl <<
			"? ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			List_all_fruits(fruit);
			break;
		case 2:
			Update_record(fruit);
			save(fruit);
			break;
		case 3:
			Insert_record(fruit);
			save(fruit);
			break;
		case 4:
			Delete_record(fruit);
			save(fruit);
			break;
		case 5:
			cout << endl <<
				"Bye." << endl;
			system("pause");
			return 0;
		default:
			cout << endl <<
				"Input error!" << endl;
			break;
		}
	}
}