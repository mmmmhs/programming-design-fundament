#include <iostream>
using namespace std;

int ring(int n);

int main()
{
	int n;
	cin >> n;
	cout << ring(n);
	return 0;
}

int ring(int n)
{
	if(n == 1)
	    return 1;
	else if(n == 2)
	    return 2;
	else
	    return 2 * ring(n - 2) + ring(n - 1) + 1;   
} 
