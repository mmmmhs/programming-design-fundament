#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

struct card{
	char color[8];
	char num[3];
} pile[10000] = {{{'0'}, {'0'}}};

int sum = 0;

void append(){
	char color[8];
	char num[3];
	cin >> color >> num;
	strcpy(pile[sum].color, color);
	strcpy(pile[sum].num, num);
	sum ++;
}

int f(card a){
	if(a.num[0] == 'A')
		return 1;
	else if(a.num[0] == 'J')	
		return 11;
	else if(a.num[0] == 'Q')
		return 12;
	else if(a.num[0] == 'K')
		return 13;
	else 
		return (atoi(a.num));			
}

bool cmp(card a, card b){
	return (f(a) < f(b));						
}

void extract(){
	char color[8];
	cin >> color;
	card note[10000];
	card note1[10000];
	int j = 0, k = 0;
	for(int i = 0;i < sum;i++)
	{
		if(!strcmp(pile[i].color, color))
			note[j++] = pile[i];
		else
			note1[k++] = pile[i];	
	}
	if(j > 0)
	{
		sort(note, note + j, cmp);	
		for(int i = 0;i < j;i++)
			pile[i] = note[i]; 
		for(int i = 0;i < k;i++)
			pile[j + i] = note1[i];	
	}
}

void revert(){
	for(int i = 0;i < sum / 2;i++)
	{
		card tmp = pile[i];
		pile[i] = pile[sum - 1 - i];
		pile[sum - 1 - i] = tmp;
	}
}

void pop(){
	if(sum > 0){
		for(int i = 0;i < sum;i++)
			pile[i] = pile[i + 1];
		sum--;	
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		string str;
		cin >> str;
		if(str == "Append")
			append();
		else if(str == "Extract")
			extract();
		else if(str == "Revert")
			revert();
		else if(str == "Pop")
			pop();			
	}
	if(sum == 0)
		cout << "null";
	else
		cout << pile[0].color << ' ' << pile[0].num;
	return 0;		
}
