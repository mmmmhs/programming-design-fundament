#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
 
struct student
{
    char name[10];
    float c;
    float m;
    float e;
    float p;
};
    
int main()
{
    ifstream fin;
    fin.open("input.txt");
    if (!fin)
    {
        return 1;
    }
    ofstream fout;
    fout.open("output.txt");
    if (!fout)
    {
        return 1;
    }
    int n;
    fin >> n;
    student *grade = new student[n];
    for(int i = 0;i < n;i++)
    {
        fin >> grade[i].name;
        fin >> grade[i].c;
        fin >> grade[i].m;
        fin >> grade[i].e;
        fin >> grade[i].p;
    }
    float *b[5];
    for(int i = 0;i < 5;i++)
    {
        b[i] = new float[n];
    }
    for(int i = 0;i < n;i++)
    {
        b[1][i] = grade[i].c;
        int m = i - 1;
        while ((b[1][m] > grade[i].c) && (m > -1))
        {
        	b[1][m + 1] = b[1][m];
            m--;
        }
        b[1][m + 1] = grade[i].c;
    }
    for(int i = 0;i < n;i++)
    {
        b[2][i] = grade[i].m;
        int m = i - 1;
        while ((b[2][m] > grade[i].m) && (m > -1))
        {
        	b[2][m + 1] = b[2][m];
            m--;
        }
        b[2][m + 1] = grade[i].m;
    }
    for(int i = 0;i < n;i++)
    {
        b[3][i] = grade[i].e;
        int m = i - 1;
        while ((b[3][m] > grade[i].e) && (m > -1))
        {
        	b[3][m + 1] = b[3][m];
            m--;
        }
        b[3][m + 1] = grade[i].e;
    }
    for(int i = 0;i < n;i++)
    {
        b[4][i] = grade[i].p;
        int m = i - 1;
        while ((b[4][m] > grade[i].p) && (m > -1))
        {
        	b[4][m + 1] = b[4][m];
            m--;
        }
        b[4][m + 1] = grade[i].p;
    }
    for(int i = 0;i < n;i++)
    {
        b[0][i] = grade[i].c + grade[i].m + grade[i].e + grade[i].p;
        int m = i - 1;
        while ((b[0][m] > grade[i].c + grade[i].m + grade[i].e + grade[i].p) 
              && (m > -1))
        {
        	b[0][m + 1] = b[0][m];
            m--;
        }
        b[0][m + 1] = grade[i].c + grade[i].m + grade[i].e + grade[i].p;
    }
    float sum[5] = {0};
    for(int i = 0;i < 5;i++)
    {
    	for(int j = 0;j < n;j++)
    	{
    		sum[i] += b[i][j];
        }
    }
    fout << setiosflags(ios::fixed);
    for(int i = 1;i < 5;i++)
    {
        fout << setprecision(3) << b[i][n - 1] << ' ' << b[i][0] << ' ' 
             << sum[i] / n << endl;
    }
    fout << setprecision(3) << b[0][n - 1] << ' ' << b[0][0] << ' ' 
         << sum[0] / n;
    delete[] grade;
	for(int i = 0;i < 5;i++)
    {
        delete[] b[i];
    }     
    fin.close();
	fout.close();     
    return 0;
}
 
