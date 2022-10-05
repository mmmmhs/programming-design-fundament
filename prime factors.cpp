#include <iostream>
#include <cmath>
using namespace std;
void printPrime(int num);    // 未定义，需要完成

int main() {
    int n, i;
    cin >> n;
    while (n --) {
        cin >> i;
        printPrime(i);
    }
    return 0;
}
void printPrime(int num){
	int i;
	for ( i = 2; i <= num ; i++)
   {
		if(num % i == 0)
	   {
		  cout << num << '=' << i;
		  num /= i;
		  break;
	    }
    }
	for ( i = 2; i <= num ; i++)
   {
		while(num % i == 0)
	   {
		    num /= i;
		    cout << '*' << i;
		}	
	}
	cout << endl; 
}
