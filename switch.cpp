#include <iostream>
using namespace std;
int main() 
{
    int a,b,c,d,i;
    cin>>a>>b>>c>>d;
    if(a>=b) {
        i=b;
        b=a;
        a = i;
    }
    if (b>=c) {
        i=c;
        c = b;
        b = i;
    }
    if (c >= d) {
        i = d;
        d = c;
        c = i;
    }
    if (a >= b) {
        i = b;
        b = a;
        a = i;
    }
    if (b >= c) {
        i = c;
        c = b;
        b = i;
    }
    cout<<a<<" "<<b<<" "<<c<< " " <<d<< endl;
    return 0;
}
