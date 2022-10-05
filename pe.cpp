#include <fstream>
#include <iostream> 
#include <stdint.h>
#include <iomanip>
#include <cmath>
using namespace std;

#pragma pack(1)
struct student
{
	char name[8] = {'\0'};
	char sex;
	uint8_t age;
	float w;
	float h;
};
#pragma pack()
int main()
{
	uint32_t N;
	int numm = 0,numf = 0;//男女个数
	float aam = 0,aaf = 0,ahm = 0,ahf = 0;//男女平均身高、体重
	ifstream input("input",ios::binary);
	input.read((char*)(&N),sizeof(N));
	student *pe = new student[N + 100];
	for(int i = 0;i < N;i++)
	{
		input.read((char*)(&pe[i]),sizeof(pe[i]));
		if(pe[i].sex == 'm')
		{
			numm++;
			aam += pe[i].age;
			ahm += pe[i].h;
		}
		else
		{
			numf++;
			aaf += pe[i].age;
			ahf += pe[i].h;
		}	
	}
	if(numm != 0)
	{
		aam /= float(numm);
		ahm /= float(numm);
	}
	else
	{
		aam = 0;
		ahm = 0;
	}
	if(numf != 0)
	{
		aaf /= float(numf);
		ahf /= float(numf);
	}
	else
	{
		aaf = 0;
		ahf = 0;
	}
	float *bmim = new float[numm + 100];//男bmi
	float *bmif = new float[numf + 100];//女bmi
	int j = 0,mt = 0,ms = 0,mo = 0,mf = 0,ft = 0,fs = 0,fo = 0,ff = 0;//男女瘦、标准、超重、胖
	for(int i = 0;i < N;i++)
	{
		if(pe[i].sex == 'm')
		{
			bmim[j] = pe[i].w / (pe[i].h * pe[i].h);
			if(bmim[j] < 18.5)
			{
				mt++;
			}
			else if((bmim[j] >= 18.5) && (bmim[j] < 24))
			{
				ms++;
			}
			else if((bmim[j] >= 24) && (bmim[j] < 28))
			{
				mo++;
			}
			else
			{
				mf++;
			}
			j++;
		}
	}
	j = 0;
	for(int i = 0;i < N;i++)
	{
		if(pe[i].sex == 'f')
		{
			bmif[j] = pe[i].w / (pe[i].h * pe[i].h);
			if(bmif[j] < 18.5)
			{
				ft++;
			}
			else if((bmif[j] >= 18.5) && (bmif[j] < 24))
			{
				fs++;
			}
			else if((bmif[j] >= 24) && (bmif[j] < 28))
			{
				fo++;
			}
			else
			{
				ff++;
			}
			j++;
		}		
	}
	float mmax = bmim[0];
	float fmin = bmif[0];
	for(int i = 1;i < numm;i++)
	{
		if(bmim[i] > mmax)
			mmax = bmim[i];
	}
	for(int i = 1;i < numf;i++)
	{
		if(bmif[i] < fmin)
			fmin = bmif[i];
	}
    int mm,fm;
    for(int i = 0;i < N;i++)
	{  
		if((fabs(mmax - pe[i].w / (pe[i].h * pe[i].h))<1e-5) 
		  && (pe[i].sex == 'm'))
		{
			mm = i;
			break;
		}
	}
    for(int i = 0;i < N;i++)
	{  
		if((fabs(fmin - pe[i].w / (pe[i].h * pe[i].h))<1e-5) 
		  && (pe[i].sex == 'f'))
		{
			fm = i;
			break;
		}
	}
    input.close();
    ofstream out;
    out.open("output.txt");
    out << numm << ' ' << numf << endl;
    out << fixed << setprecision(3) << aam << ' ' << aaf << endl;
    out << fixed << setprecision(3) << ahm << ' ' << ahf << endl;
    out << mt << ' ' << ms << ' ' << mo << ' ' << mf << endl;
    out << ft << ' ' << fs << ' ' << fo << ' ' << ff << endl;
    out << pe[mm].name << endl << pe[fm].name;
    out.close();
    return 0;
} 
