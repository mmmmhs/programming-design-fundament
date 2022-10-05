#include <iostream>
#include <stdlib.h>
using namespace std;

struct position { int a, b, c, d, e; };
position d[16] = {{0, 0, 0, 0, 0}, 
              	 {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, 
			  	 {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 0, 0}, 
			  	 {1, 0, 1, 0, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 0, 1}, 
			     {0, 1, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 0, 0, 1}, 
			     {0, 0, 1, 1, 0}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 1}};

struct state {
    int dir;
    position pos;
} start = {-1, {1, 1, 1, 1, 1}}, goal = {1, {0, 0, 0, 0, 0}};
position choice[100];
state path[100];
int t[100];

bool IsEq(state st1, state st2) {
    return  (st1.dir == st2.dir) && 
            (st1.pos.a == st2.pos.a) && 
		    (st1.pos.b == st2.pos.b) &&
		    (st1.pos.c == st2.pos.c) &&
			(st1.pos.d == st2.pos.d) &&
			(st1.pos.e == st2.pos.e);
}

bool IsEq1(position st1, position st2) {
    return  (st1.a == st2.a) && 
		    (st1.b == st2.b) &&
		    (st1.c == st2.c) &&
			(st1.d == st2.d) &&
			(st1.e == st2.e);
}

bool IsValid(state st, int step) {
    if (st.pos.a < 0 || st.pos.a > 1 || 
        st.pos.b < 0 || st.pos.b > 1 ||
		st.pos.c < 0 || st.pos.c > 1 ||
		st.pos.d < 0 || st.pos.d > 1 ||
		st.pos.e < 0 || st.pos.e > 1 ) 
        return false;
    if (step > 7)
    	return false;
    for (int i=step-2; i>=0; i-=2)
        if (IsEq(st, path[i])) 
            return false;
    return true;
}

state GetNewState(state st, int k, int step) {
    state next_st = {-st.dir, {st.pos.a + st.dir * d[k].a, 
                               st.pos.b + st.dir * d[k].b,
							   st.pos.c + st.dir * d[k].c,
							   st.pos.d + st.dir * d[k].d,
							   st.pos.e + st.dir * d[k].e}};
    return next_st;
}

bool IsDone(state st) {  return IsEq(st, goal);  } 

void LogStep(state st, int step) { 
	if(IsEq(st, start))
	for(int i = 0;i < 100;i++)
		t[i] = 0;
	path[step] = st;
	if(step > 0){ 
		choice[step - 1].a = path[step - 1].dir * 
							(path[step].pos.a - path[step - 1].pos.a);
		choice[step - 1].b = path[step - 1].dir * 
							(path[step].pos.b - path[step - 1].pos.b);
		choice[step - 1].c = path[step - 1].dir * 
							(path[step].pos.c - path[step - 1].pos.c);
		choice[step - 1].d = path[step - 1].dir * 
							(path[step].pos.d - path[step - 1].pos.d);
		choice[step - 1].e = path[step - 1].dir * 
							(path[step].pos.e - path[step - 1].pos.e);
		for(int j = 1;j < 16;j++){
        	if(IsEq1(choice[step - 1], d[j])){
        		if(j == 1)
            		t[step - 1] = 1;
            	else if(j == 2 || j == 6)
					t[step - 1] = 3;
				else if(j == 3 || j == 7 || j == 10)	
			    	t[step - 1] = 6;
				else if(j == 4 || j == 8 || j == 11 || j == 13)
					t[step - 1] = 8; 
				else 
					t[step - 1] = 12;	
			}
		}					
	}
}

void display(int step);

void Jump(state st, int step) {
    if (IsDone(st)) {
		int sum = 0;
		for(int i = 0;i <= step;i++)
			sum += t[i];
	    if(sum <= 30){
			display(step);
			exit(0);
    	}
    }
    
    for (int k = 1; k < 16; k++) {
        state next_st = GetNewState(st, k, step);
        if (!IsValid(next_st, step+1)) continue;	
        LogStep(next_st, step+1);
        Jump(next_st, step+1);   
    }
}

void display(int step){
	for(int i = 0;i <= step;i++)
	{
		if(IsEq1(choice[i], d[1]))
			cout << "A ";
		if(IsEq1(choice[i], d[2]))
			cout << "B ";
		if(IsEq1(choice[i], d[3]))
			cout << "C ";
		if(IsEq1(choice[i], d[4]))
			cout << "D ";
		if(IsEq1(choice[i], d[5]))
			cout << "E ";
		if(IsEq1(choice[i], d[6]))
			cout << "AB ";
		if(IsEq1(choice[i], d[7]))
			cout << "AC ";
		if(IsEq1(choice[i], d[8]))
			cout << "AD ";
		if(IsEq1(choice[i], d[9]))
			cout << "AE ";
		if(IsEq1(choice[i], d[10]))
			cout << "BC ";
		if(IsEq1(choice[i], d[11]))
			cout << "BD ";
		if(IsEq1(choice[i], d[12]))
			cout << "BE ";
		if(IsEq1(choice[i], d[13]))
			cout << "CD ";
		if(IsEq1(choice[i], d[14]))
			cout << "CE ";
		if(IsEq1(choice[i], d[15]))
			cout << "DE ";												
	}
	cout << endl;
} 

int main() {
    LogStep(start, 0); 
    Jump(start, 0);   
    return 0;
}

