#include <iostream>
using namespace std;

char first,second,third;

int food(char a);

int main()
{
	for (int k = 0;k <= 2;k ++)
	{
		first = 'A' + k;
		for (int i = 0;i <= 2;i ++)
		{
			second = 'A' + i;
			if (k == i)
			   continue;
			for (int j = 0;j <= 2;j ++)
			{
				third = 'A' + j;
				if ((j == i)||(j == k))
				   continue;
				if (((food ('B') > food ('A')) + (food ('C') == food ('A')) == 2 - food ('A'))
				&& ((food ('A') > food ('B')) + (food ('A') > food ('C')) == 2 - food ('B'))
				&& ((food ('C') > food ('B')) + (food ('B') > food ('A')) == 2 - food ('C')))
				   cout << first << ' ' << second << ' ' << third;  
			}   
		}
	}
	return 0;	
} 

int food(char a)
{
	if (a == first)
	   return 0;
	if (a == second)
	   return 1;
	if (a == third)
	   return 2;      
}
