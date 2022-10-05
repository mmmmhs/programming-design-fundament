#include <iostream>
using namespace std;

int main(){
	int a[10];
	int kill = 0;
	for (int i = 0;i < 10;i ++)
	    a[i] = i + 1; 
    for (int t = 0;t < 9;t ++)
	{
    	kill = (kill + 5) % (10 - t);
    	for (int k = kill + 1; k < 10; k++)
    		a[k-1] = a[k];
	}
	cout << a[0];
	return 0;
}

 
