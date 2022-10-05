#include <iostream>
#include <cmath>
using namespace std;
 
bool checkprime(int af) {
	if(af == 1)
		return 0;
    for (int k = 2; k <= sqrt(af); k++)
        if (af % k == 0) return false; // af �ܱ�k����������false
    return true; // af ���ܱ�k����������true
}
 
int main(){
    int min, max, num = 0;
    cin >> min >> max;
    for(int i = min;i <= max - 2;i++)
    {
        if(checkprime(i) && checkprime(i + 2))
            num ++;
    } 
    cout << num;
    return 0;
}  
