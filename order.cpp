#include <iostream>
using namespace std;

int main(){
    int n,ai;
	cin >> n;
	int b[101];
	for(int i = 0;i < n;i++)
	{
	    cin >> ai;   
	    b[i] = ai;
	    int m = i - 1;
	    while ((b[m] > ai) && (m > -1)) 
	    {
	    	b[m + 1] = b[m];
	        m--;
		}
	    b[m + 1] = ai;
	    for(int k = 0;k <= i;k++)
	    {
	        cout << b[k] << ' ';
	    }
	    cout << endl;
	}
	return 0;
} 

