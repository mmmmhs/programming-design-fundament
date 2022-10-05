#include <iostream>
using namespace std;
 
struct state{
	int w;
	int s;
	int v;
} dep = {1, 1, 1}, arr = {0, 0, 0}; 
state d[5] = {{0, 0, 0}, {0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
state recod[20], recoa[20];
int choice[20] = {0};
int k = 1;            

void transfer(){
	recod[1] = dep;
	recoa[1] = arr;
	do{
		int dir = 1;
		if(k % 2 == 1)
			dir = -1;
		int i;
		for (i = choice[k+1]+1; i <= 4; i++) {
			dep.w = recod[k].w + dir * d[i].w;
			dep.s = recod[k].s + dir * d[i].s;
			dep.v = recod[k].v + dir * d[i].v;
			arr.w = recoa[k].w - dir * d[i].w;
			arr.s = recoa[k].s - dir * d[i].s;
			arr.v = recoa[k].v - dir * d[i].v;
			if((dep.w > 1) || (dep.w < 0) || (dep.s > 1) ||
			  (dep.s < 0) || (dep.v > 1) || (dep.v < 0))
				continue;
			bool dsafe =((dep.w + dep.s + dep.v <= 1)
            		    || ((dep.w == 1) && (dep.s == 0) && (dep.v == 1)));
			bool asafe =((arr.w + arr.s + arr.v <= 1)
            			|| ((arr.w == 1) && (arr.s == 0) && (arr.v == 1)));	
			if(((dir == -1) && (!dsafe)) || 
			  ((dir == 1) && (!asafe)))
				continue;
			bool rep = false;
			for (int j = k - 1; j > 0; j -= 2)
                if ((recod[j].w == dep.w) && 
				   (recod[j].s == dep.s) && (recod[j].v == dep.v))
					rep = true; 
            if (rep)
				continue;
			k++;
			recod[k] = dep;
			recoa[k] = arr;
			choice[k] = i;
			break;
		}
		if (i > 4) {
		choice[k+1]=0;
		k--;
		}
	}while((dep.s != 0) || (dep.w != 0) || (dep.v != 0));
}

void display(){
	for(int i = 1;i <= k;i++)
	{
		if(choice[i] == 1)
			cout << "H ";
		if(choice[i] == 2)
			cout << "HW ";
		if(choice[i] == 3)
			cout << "HS ";
		if(choice[i] == 4)
			cout << "HV ";			
	}
} 

int main(){
	transfer();
	display();
	return 0;
}
