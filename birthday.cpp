#include <iostream>
#include <cstring>
using namespace std;

struct stu{
	char name[20];
	int month;
	int day;
} cl[100];

int main(){
	int N;
	cin >> N;
	for(int i = 0;i < N;i++)
		cin >> cl[i].name >> cl[i].month >> cl[i].day;
	for(int i = 1;i < 13;i++)
	{
		for(int j = 1;j < 32;j++)
		{
			int num = 0;
			char same[100][20] = {{'0'}};
			for(int k = 0;k < N;k++)
			{
				if((cl[k].month == i) && (cl[k].day == j))
				{
					strcpy(same[num], cl[k].name);
					num++;
				}
			}
			if(num > 1)
			{
				cout << i << ' ' << j << ' ';
				for(int s = 0;s < num;s++)
					cout << same[s] << ' ';
				cout << endl;	
			}
		}
	}	
	return 0;
} 
