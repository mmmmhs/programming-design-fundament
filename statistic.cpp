#include<iostream>
#include<iomanip>
#include <cstring>
using namespace std;
 
int main()
{
    char a[50000];
    int m;
    int i = 0;
    double num;
    cin.getline(a, 50000);
    m = strlen(a);
    char *c = new char[m];
    for (int j = 0; j < m; j++)
    {
        if (('A' <= a[j]) && (a[j] <= 'Z'))
        {
            c[i] = a[j] + 32;
            a[j] = '0';
            i++;
        }
        if (('a' <= a[j]) && (a[j] <= 'z'))
        {
            c[i] = a[j];
            a[j] = '0';
            i++;
        }
    }
    for (int k = 0; k < 26; k++)
    {
        num = 0;
        for (int l = 0; l < i; l++)
        {
            if (c[l] == 'a' + k)
                num++;
        }
        cout << char ('a' +
                      k) << ' ' << fixed << setprecision(2) << num /
            double (i) * 100 << '%' << endl;
    }
    delete []c;
    return 0;
}
