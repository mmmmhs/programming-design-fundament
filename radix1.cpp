#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct number{
	int n;
	int r;
};
number num[2][1000004] = {};

int main(){
    int N;
    cin >> N;
    int *log = new int[N];
    for(int i = 0;i < N;i++){
        cin >> num[0][i].n;
        log[i] = (int)floor(log10(num[0][i].n));
    }
    sort(log, log + N);
    int M = log[N - 1] + 1;	
    delete log;
    for(int i = 1;i <= M;i++)
    {
    	int mhs1 = (int)pow(10, i);
    	int mhs2 = (int)pow(10, i - 1);
    	for(int k = 0; k < N; k++)
    		num[0][k].r = (num[0][k].n % mhs1 - (num[0][k].n % mhs1) % mhs2) / mhs2;
    	int n = 0;
        for(int r = 0; r < 10; r++)
		{
        	for(int k = 0; k < N; k++)
        	{
            	if(r == num[0][k].r)
            		num[1][n++] = num[0][k];
        	}
        }
        for(int k = 0; k < N; k++)
		{
            num[0][k] = num[1][k];
            cout << num[0][k].n << ' ';
    	}
        cout << endl;	
    }		
    return 0;
}  
