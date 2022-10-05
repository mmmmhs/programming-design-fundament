#include <iostream>
#include <algorithm> 
using namespace std;

int n;

bool CanAttack(int q[], int pos1, int pos2) {
    if (q[pos1] == q[pos2]) 
        return true;
    if (abs(pos1-pos2) == abs(q[pos1]-q[pos2])) 
        return true;
    return false;
}

bool IsSafe(int q[]) {
    for (int i=2; i<=n; i++)
        for (int j=1; j<=i-1; j++)
            if (CanAttack(q, i, j)) 
                return false;
    return true;
}

int main()
{
	cin >> n;
    int *q = new int [n + 1]; 
	int num = 0;
    // int q = {?, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i=1; i<=n; i++) 
		q[i] = i;
    do {
        if (IsSafe(q)) {
            num ++;
        }
    } while(next_permutation(q + 1, q + n + 1));
    cout << num;
    return 0;
}
