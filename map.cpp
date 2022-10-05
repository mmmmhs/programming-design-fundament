#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n,x,y;
	cin >> n;
	char **map;
	map = new char *[n];
	for(int i = 0;i < n;i++)
	{
		map[i] = new char[n];
		for(int j = 0;j < n;j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 'H')
			{
				y = i;
				x = j;
			}
		}
	}
	char p[1000] = {0};
	cin >> p;
	int num = strlen(p);
	for(int i = 0;i < num;i++)
	{
		map[y][x] = '_';
		if(p[i] == 'w')
			y--;
		if(p[i] == 'a')
			x--;
		if(p[i] == 's')
			y++;
		if(p[i] == 'd')
			x++;
		if(x > n - 1)
			x = n - 1;
		if(x < 0)
			x = 0;	
		if(y > n - 1)
			y = n - 1;
		if(y < 0)
			y = 0;
		map[y][x] = 'H';
		for(int j = 0;j < n;j++)
		{
			for(int k = 0;k < n;k++)
				cout << map[j][k] << ' ';
			cout << endl;	
		}
		cout << endl;
	}
	return 0;
} 


