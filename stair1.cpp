#include <iostream>    // cout
using namespace std;

int take[99], num = 0;
int n;

void Try(int i, int s ,int *ban); 

int main() {
    int h;
    cin >> h >> n;  
	int *ban = new int[n];    
	for(int k = 0;k < n;k ++)
	{
		cin >> ban[k];
	}
    Try(h, 1, ban);     
    cout << num;
    return 0;
}

void Try(int i, int s,int *ban) { 
    for (int j=3; j>0; j--) {
        if (i >= j) {
            take[s] = j;   
            if (i==j) {    
                num++; 
				for(int k = 1;k <= s;k ++)
				{
					int sum = 0;
					for(int m = 1;m <= k;m ++)
						sum += take[m];
					for(int l = 0;l < n;l ++)
					{
						if(sum == ban[l]){
							num--;
							return;
							
						}	
					}
				}     
            }
            else 
                Try(i-j, s+1, ban); 
        } 
    } 
}
