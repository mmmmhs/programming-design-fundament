#include <iostream>
#include <algorithm>
using namespace std;

int max1(int a, int b)
{
	if(a >= b)
		return a;
	else 
		return b;	
} 

int main(){
	int N;
	cin >> N;
	int **tri;
	tri = new int*[N];
	int **p;
	p = new int*[N];
	for(int i = 0;i < N;i++)
	{
		tri[i] = new int [i + 1];
		p[i] = new int [i + 1];
		for(int k = 0;k < i + 1;k++){
			cin >> tri[i][k];
			p[i][k] = 0;
		}
	}
	p[0][0] = tri[0][0];
	for(int i = 1;i < N;i++)
	{
		p[i][0] = p[i - 1][0] + tri[i][0];
		p[i][i] = p[i - 1][i - 1] + tri[i][i];
	}
	for(int i = 2;i < N;i++)
	{ 
		for(int k = 1;k < i;k++)
			p[i][k] = max1(p[i - 1][k - 1], p[i - 1][k]) + tri[i][k];
	} 
	sort(p[N - 1], p[N - 1] + N);
	cout << p[N - 1][N - 1];
	return 0;
}  
