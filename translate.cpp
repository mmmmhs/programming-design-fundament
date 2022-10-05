#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	char a;
	int num = 0;
	string str;
	while((a = getchar()) != EOF) 
		{
			if((('A' <= a) && (a <= 'Z'))
			  ||(('a' <= a) && (a <= 'z')))
		    {
		    	str[num] = a;
		    	num++;
		    }
		    else
		    {
		    	for(int i = num - 1;i >= 0;i--)
		    	{
		    		cout << str[i];
				}
				cout << a;
				num = 0;
			}
		}
	return 0;
} 
