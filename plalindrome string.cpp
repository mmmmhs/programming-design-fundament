#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
int main()
{
    char h[101];
    char a[101];
    int k = 0, s = 0;
    cin.getline(h, 101);
    for (int i = 0; i <= strlen(h) - 1; i++)
    {
        if (((int (h[i]) < 58) && (int (h[i]) > 47)) ||
            ((int (h[i]) > 64) && (int (h[i]) < 91)) ||
            ((int (h[i]) > 96) && (int (h[i]) < 123)))
        {
            a[k] = h[i];
            k++;
        }
    }
    if ((k == 0) || (k == 1))
    {
        cout << 1;
    }
    else
    {
        for (int i = 0; i < k ; i++)
        {
            if ((int (a[i]) < 123) && (int (a[i]) > 96))
                a[i] = a[i] - 32;
        }
        for (int i = 0; i < k / 2 ; i++)
        {
            if (a[i] == a[k - 1 - i])
                s++;
        }
        if (s == k / 2)
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
