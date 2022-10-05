#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std; 

struct book{
	char type[5];
	char name[11];
	int exp;
};

book shelf[1000];
int num = 0;

void enlist(){
	char type[5] = {}, name[11] = {};
	int exp;
	cin >> type >> name >> exp;
	for(int k = num - 1;k >= 0;k--)
	{
		for(int m = 0;m < 5;m++){			
			shelf[k + 1].type[m] = shelf[k].type[m];
    	}
    	for(int m = 0;m < 11;m++){
			shelf[k + 1].name[m] = shelf[k].name[m];
		}
		shelf[k + 1].exp = shelf[k].exp;
	} 
	for(int m = 0;m < 5;m++){			
		shelf[0].type[m] = type[m];
    }
    for(int m = 0;m < 11;m++){
		shelf[0].name[m] = name[m];
	}
	shelf[0].exp = exp;
	num++;
}

void remove(){
	char name[11];
	cin >> name;
	int j = 0;
	for(int i = 0;i < num;i++)
	{
		if(!strcmp(shelf[i].name, name))
		{
			j++; 
			for(int k = i + 1;k < num;k++)
			{
				for(int m = 0;m < 5;m++){			
					shelf[k - 1].type[m] = shelf[k].type[m];
    			}
    			for(int m = 0;m < 11;m++){
					shelf[k - 1].name[m] = shelf[k].name[m];
				}
				shelf[k - 1].exp = shelf[k].exp;	
			}
		}
	}
	if(j > 0)
		num --;	
}

bool cmp1(book a, book b){
	return a.exp > b.exp;
}

void refine(){ 
	char type[5];
	cin >> type; 
	book stat[1000];
	int i = 0, j = 0;
	for(i = 0;i < num;i++)
	{
		if(!strcmp(shelf[i].type, type))
		{
			stat[j] = shelf[i];
			j++;
			for(int k = i + 1;k < num;k++)
			{
				for(int m = 0;m < 5;m++){			
					shelf[k - 1].type[m] = shelf[k].type[m];
    			}
    			for(int m = 0;m < 11;m++){
					shelf[k - 1].name[m] = shelf[k].name[m];
				}
				shelf[k - 1].exp = shelf[k].exp;	
			}
			i--;
			num--;
		}
	}
	if(j > 0){
		sort(stat, stat + j, cmp1);
		for(int k = num;k > 0;k--){
			for(int m = 0;m < 5;m++){			
				shelf[k].type[m] = shelf[k - 1].type[m];
    		}
    		for(int m = 0;m < 11;m++){
				shelf[k].name[m] = shelf[k - 1].name[m];
			}
			shelf[k].exp = shelf[k - 1].exp;
    	}
		for(int m = 0;m < 5;m++){			
			shelf[0].type[m] = stat[0].type[m];
    	}
    	for(int m = 0;m < 11;m++){
				shelf[0].name[m] = stat[0].name[m];
		}
		shelf[0].exp = stat[0].exp;
		num = num + 1;
	}
}

void cleanup(){
	char type[5];
	cin >> type;
	int i = 0;
	for(i = 0;i < num;i++)
	{
		if(!strcmp(shelf[i].type, type))
		{
			for(int k = i + 1;k < num;k++)
			{
				for(int m = 0;m < 5;m++){			
					shelf[k - 1].type[m] = shelf[k].type[m];
    			}
    			for(int m = 0;m < 11;m++){
					shelf[k - 1].name[m] = shelf[k].name[m];
				}
				shelf[k - 1].exp = shelf[k].exp;	
			}
			i--;
			num--;
		}
	}
	sort(shelf, shelf + num, cmp1);
}

int main(){
	int t;
	cin >> t;
	for(int i = 0;i < t;i ++)
	{
		string str;
		cin >> str;
		if(str == "ENLIST")
			enlist();
		else if(str == "REMOVE")	
			remove();
		else if(str == "REFINE")
			refine();
		else if(str == "CLEANUP")
			cleanup();
	}
	if(num == 0)
		cout << "NULL";
	else if(num <= 3)
	{
		for(int i = 0;i < num;i ++)
			cout << shelf[i].type << ' ' 
				 << shelf[i].name << ' '
				 << shelf[i].exp << endl;
	}
	else
	{
		for(int i = 0;i < 3;i ++)
			cout << shelf[i].type << ' ' 
				 << shelf[i].name << ' '
				 << shelf[i].exp << endl;
	}
	return 0;	
}
