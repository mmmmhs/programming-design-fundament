#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int num = 0, m, M, n, len;
char b[26];

void output(int wei, char ch);

int main(){
	cin >> m >> M >> n;
	cin >> b;
	len = strlen(b);
	for(int i = 1; i <= n; i++)
		output(i, b[len - i]);
	return 0;
}
 
void output(int wei, char ch){
	if(wei == 0){
		cout << b << endl;
		num++;
	}
	else
	{	
		for(char c = ch + 1; c <= 'a' - 1 + M; c++)
		{
			b[len - wei] = c;
			output(wei - 1, c);
			
			if(num == 5)
				exit(0);	
		}
	}
} 
