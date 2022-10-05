#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

void f(int x);
int get_bit(int n, int pos);
void answer(int n);

int main(){
	int n;
	cin >> n;
	answer(n);
	return 0;
}

void answer(int n){	
	if(n == 1)
		cout << "2(0)";
	else if(n == 2)	
		cout << '2';
	else
	{	
		int num = 0;
		int wei[15];
		for(int i = 14; i >= 0; i--){
			if(get_bit(n, i)){
				wei[num] = i;
				num++;
			}	
		}
		for(int i = 0;i < num - 1;i++){
			f(wei[i]);
			cout << '+';
		}
		f(wei[num - 1]);
	}
} 

int get_bit(int n, int pos)
{
	int mask = (1 << pos);	
	int bit = (n & mask) >> pos;
	// int bit = (n & (1 << pos)) >> pos;
	return bit;
	// return (n & (1 << pos)) >> pos;
} 


void f(int x){
	if(x == 1)
		cout << '2';
	else if(x == 0)
		cout << "2(0)";	
	else
	{
		cout << "2(";
		answer(x);
		cout << ")";
	}			
}
