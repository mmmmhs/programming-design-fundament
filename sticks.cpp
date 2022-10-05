#include <iostream>
#include <algorithm>
using namespace std;

struct stick{
	int len;
	int power;
} sticks[1005] = {{0, -100000000}};

int N;
int memo[1005] = {0};

bool cmp(stick a, stick b){
	return a.power > b.power;
}

int ord(int n){
	for(int i = 0;i < N;i++)
	{
		if(sticks[i].len == n)
			return i;	
	}
	return N;
}

int r(int n) {
	if(memo[n])
		return memo[n];
	if (n == 0)
		return 0;	
    int max = sticks[ord(n)].power;
    int val;
    for (int i = 1; i < n; i++) {
    	if(n == 2 * i)
        	val = r(n - i) + r(i) + 233;
        else 
			val = r(n - i) + r(i);
		if (val > max) max = val;
	}
    return memo[n] = max;
}

int main(){
	int M;
	cin >> N >> M;
	for(int i = 0;i < N;i++)
		cin >> sticks[i].len;
	for(int i = 0; i < 1005; i++)
		sticks[i].power = -10000000;
	for(int i = 0;i < N;i++)
		cin >> sticks[i].power;
	sort(sticks, sticks + N, cmp);	
	cout << r(M);		
	return 0;
}  
