#include <iostream>
using namespace std;
bool checkSpecial(int i, int n);      // 未定义，需要完成

int main() {
    int n;
    cin >> n;
    for (int i = 10000; i < 1000000; i ++) {
        if (checkSpecial(i, n)) {
            cout << i << endl;
        }
    }
    return 0;
}

bool checkSpecial(int i, int n)
{
	int sum = 0;
	int s = 0;
	if (i < 100000){
	   int a[5];
	   int m = 100000;
	   int p = 10000;
	   for (int k = 0; k < 5; k ++){
	   	    a[k] = (i % m - i % p) / p;
	        sum += a[k];
	        m /= 10.0;
	        p /= 10.0;
	    }
	   for (int t = 0; t < 2; t ++){
	       if (a[t] == a[4 - t])
	           s ++;
	    }
	    if ((sum == n) + s == 3)
	       return true;
	    else
		   return false;   
    }
    if (i >= 100000){
	   int a[6];
	   int m = 1000000;
	   int p = 100000;
	   for (int k = 0; k < 6; k ++){
	   	   a[k] =( i % m - i % p) / p;
	       sum += a[k];
	       m /= 10.0;
	       p /= 10.0;
	    }
	   for (int t = 0; t < 3; t ++){
	       if (a[t] == a[5 - t])
	          s ++;
	    }
	    if ((sum == n) + s == 4)
	       return true;
	    else
		   return false;   
    }
}
