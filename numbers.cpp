#include <iostream>
using namespace std;

int main()
{
	int n,x,i;
	int sum = 0,k = 0;
	cin >> n;
	for (i = 1;i <= n;i ++){
	    cin >> x;
		if (x == -1)
		   break;
		if (((x % 3 == 0)||(x % 5 == 0)) && (x < 1000))
		{
		   sum += x;
		   k ++;	
		}
		if (k == 10)
		break;
    }
	for (int m = 1;m <= n - i;m ++){ 
	    cin >> x;
	}		
	cout << sum;
	return 0;
}
	      

