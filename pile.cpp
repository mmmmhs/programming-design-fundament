#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

struct card{
	char color[8];
	char num[3];
} pile[2000] = {{{'0'}, {'0'}}}, pile1[2000];

int sum = 0;
char aim[8] = {'0'};

void append(){
	char color[8];
	char num[3];
	cin >> color >> num;
	strcpy(pile[sum].color, color);
	strcpy(pile[sum].num, num);
	sum ++;
}

int order(card a){
	int i;
	for(i = 0;i < sum;i++){
		if((!strcmp(a.color, pile1[i].color)) 
		&& (!strcmp(a.num, pile1[i].num)))
			return i;
	}
}

bool cmp(card a, card b){
	if((!strcmp(a.color, aim)) && (!strcmp(b.color, aim)))
	{
		if((a.num[0] == 'A') || (b.num[0] == 'K'))
			return 1;
		else if((b.num[0] == 'A') || (a.num[0] == 'K'))
			return 0;	
		else if(a.num[0] == 'Q')
			return 0;
		else if(b.num[0] == 'Q')
			return 1;
		else if(a.num[0] == 'J')
			return 0;
		else if(b.num[0] == 'J')
			return 1;
		else
			return (atoi(a.num) < atoi(b.num));
	}
	else if(!strcmp(a.color, aim))
		return 1;
	else if(!strcmp(b.color, aim))
		return 0;
	else 
		return (order(a) < order(b));						
}

void extract(){
	for(int i = 0;i < 2000;i++)
		pile1[i] = {{'0'}, {'0'}};
	for(int i = 0;i < sum;i++)
		pile1[i] = pile[i];
	cin >> aim;
	sort(pile, pile + sum, cmp);
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
