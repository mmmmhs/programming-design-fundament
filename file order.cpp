#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input1;
	input1.open("input-1.txt");
	if (!input1)
	{
		return 1;
	}
	ifstream input2;
	input2.open("input-2.txt");
	if (!input2)
	{
		return 2;
	}
	ofstream output;
	output.open("output.txt");
	if (!output)
	{
		return 3;
	}
	int n1,n2;
    input1 >> n1;
    input2 >> n2;
    int *a = new int [n1 + n2];
    for(int i = 0;i < n1;i++)
    {
    	input1 >> a[i];
	}
	for(int i = n1;i < n1 + n2;i++)
    {
    	input2 >> a[i];
	}
	int *b = new int [n1 + n2];
	for(int i = 0;i < n1 + n2;i++)
	{   
	    b[i] = a[i];
	    int m = i - 1;
	    while ((b[m] > a[i]) && (m > -1))
	    {
	    	b[m + 1] = b[m];
	        m--;
		}
	    b[m + 1] = a[i];
    }
	output << n1 + n2 << endl;
	for(int k = 0;k < n1 + n2;k++)
	{
	    output << b[k] << endl;
	}
	delete []a;
	delete []b; 
	input1.close();
	input2.close();
	output.close();
	return 0;
}

