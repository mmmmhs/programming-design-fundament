#include <iostream>
using namespace std;

int num = 1;

int** corner(int n);
int** diag(int** m,int i);
void output(int** m,int n);

int main()
{
	int n;
	cin >> n;
	output(corner(n),n);
	return 0;
} 

int** corner(int n)
{
	int **m;
	m = new int *[n];
	for(int i = 0;i < n;i++)
	{
		m[i] = new int[n];
		for(int j = 0;j < n;j++)
			m[i][j] = 0;
	}
	for(int i = 0;i <= n;i++)
		m = diag(m,i);
	return m;
}

int** diag(int** m,int i)
{
	if(i % 2 == 1)
	{
		for(int j = 0;j < i;j++)
			m[j][i - j - 1] = num++;
	}
	else
	{
		for(int j = 0;j < i;j++)
			m[i - j - 1][j] = num++;
	}
	return m;
}

void output(int** m,int n)
{
	for(int i = 1;i < n;i++)
	{
		for(int j = n - i;j < n;j++)
			m[i][j] = n * n - m[n - 1 - i][n - 1 - j] + 1;
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			cout << m[i][j] << ' ';
		cout << endl;
	}
	return;
}
