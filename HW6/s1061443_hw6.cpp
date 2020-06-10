#include<iostream>
using namespace std;
const int row = 20;
const int col = 20;
int main()
{
	int floor[row][col];
	bool m_floor[row][col];
	int x = 0, y = 0, dir = 3;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			m_floor[i][j] = false;

	int cmd, buffer = 1;

	while (true)
	{
		cout << "Enter command (9 to end input) : ";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			buffer = 1;
			break;
		case 2:
			buffer = 0;
			break;
		case 3:
			dir = (dir + 3) % 12;
			break;
		case 4:
			dir -= 3;
			dir = (dir == 0 ? 12 : dir);
			break;
		case 5:
			int index;
			cin >> index;
			if (buffer == 1)
			{
				if (dir == 3)
					for (int i = 1; i <= index; i++)
						m_floor[y][x++] = false;
				else if (dir == 6)
					for (int i = 1; i <= index; i++)
						m_floor[y++][x] = false;
				else if (dir == 9)
					for (int i = 1; i <= index; i++)
						m_floor[y][x--] = false;
				else
					for (int i = 1; i <= index; i++)
						m_floor[y--][x] = false;
			}
			else
			{
				if (dir == 3)
					for (int i = 1; i <= index; i++)
						m_floor[y][x++] = true;
				else if (dir == 6)
					for (int i = 1; i <= index; i++)
						m_floor[y++][x] = true;
				else if (dir == 9)
					for (int i = 1; i <= index; i++)
						m_floor[y][x--] = true;
				else
					for (int i = 1; i <= index; i++)
						m_floor[y--][x] = true;
			}
			break;
		case 6:
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (m_floor[i][j])
						cout << "*";
					else
						cout << " ";
				}
				cout << endl;
			}
			break;
		case 9:
			break;
		}
		if (cmd == 9)
			break;
	}
	
	system("pause");
	return 0;
}

