#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

float pol();

int main()
{
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << pol();
	return 0;
} 

float pol()
{
	char s[100];
	cin >> s;
	if(s[0] == '+')
	{
		return pol() + pol();
	}
	else if(s[0] == '-')
	{
		return pol() - pol();
	}
	else if(s[0] == '*')
	{
		return pol() * pol(); 
	}
	else if(s[0] == '/')
	{
		return pol() / pol();
	}
	else
	{
		return atof(s);
	}
}
