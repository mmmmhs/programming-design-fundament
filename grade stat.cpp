#include <iostream> 
#include <fstream>
using namespace std;

struct student
{
	char name[1000];
	int score = 0;
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
	int num[10] = {0};
	student grade[200];
	int n = 0;
	while(fin >> grade[n].name >> grade[n].score)
	{
		n++;
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			if((grade[i].score >= j * 10) 
			   && (grade[i].score < j * 10 + 10))
			   num[j]++;
		}
		if((grade[i].score >= 90) 
		   && (grade[i].score <= 100))
		   num[9]++;
	}
	for(int j = 0;j < 10;j++)
	{
		if(num[j] > 10)
		   num[j] = 10;
	}
	for(int j = 0;j < 10;j++)
	{
		for(int i = 0;i < num[j];i++)
		{
			fout << '@';
		}
		for(int i = 0;i < 10 - num[j];i++)
		{
			fout << '.';
		}
		fout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
