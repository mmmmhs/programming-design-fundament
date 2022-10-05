#include <iostream>
#include <stdlib.h>
using namespace std;

struct position { int x, y; };
position dxy[] = {{1,0}, {0,1}, {1,1}, {2,0}, {0,2}, 
				  {2,1}, {3,0}, {0,3}, {2,2}, {3,1},
				  {4,0}, {0,4}, {5,0}, {4,1}, {3,2}, 
				  {0,5}, {6,0}, {5,1}, {4,2}, {3,3},
				  {0,6}, {7,0}, {6,1}, {5,2}, {4,3},
				  {0,7}, {8,0}, {7,1}, {6,2}, {5,3},
				  {4,4}, {0,8}, {9,0}, {8,1}, {7,2},
				  {6,3}, {5,4}, {0,9}, {10,0}, {9,1},
				  {8,2}, {7,3}, {6,4}, {5,5}, {0,10}};

struct state {
    int dir;
    position pos;
} goal = {1, {0, 0}};


state path[100];
int num, m, n;

bool IsEq(state st1, state st2) {
    return (st1.dir == st2.dir) && 
           (st1.pos.x == st2.pos.x) && (st1.pos.y == st2.pos.y);
}

bool IsValid(state st, int step, int t) {
    /// 1. 合法性检查
    if (st.pos.x < 0 || st.pos.x > n || 
        st.pos.y < 0 || st.pos.y > n) 
        return false;
    /// 2. 安全性检查【根据游戏规则推导出来】
    if (st.pos.x != 0 && st.pos.x != n && st.pos.x != st.pos.y) 
        return false;
    /// 3. 重复性检查
    for (int i=step-2; i>=0; i-=2)
        if (IsEq(st, path[i])) 
            return false;
    if(step > t)
    	return false;
    return true;
}

state GetNewState(state st, int k, int step) {
    state next_st = {-st.dir, {st.pos.x + st.dir * dxy[k].x, 
                               st.pos.y + st.dir * dxy[k].y}};
    return next_st;
}

bool IsDone(state st) {  return IsEq(st, goal);  } 

void LogStep(state st, int step) { path[step] = st; }

int f(int mm){
	if(mm == 1)
		return 2;
	if(mm == 2)
		return 5;
	if(mm == 3)
		return 8;
	if(mm == 4)
		return 12;
	if(mm == 5)
		return 16;
	if(mm == 6)
		return 21;
	if(mm == 7)
		return 26;
	if(mm == 8)
		return 32;
	if(mm == 9)
		return 38;
	if(mm == 10)
		return 45;						
}

void Jump(state st, int step,int t) {
    // 是否到达目标？
    if (IsDone(st)) {
        cout << t;
        exit(0);
    }

    // 遍历N种决策
    for (int k = 0; k < f(m); k++) {
        state next_st = GetNewState(st, k, step);
        if (!IsValid(next_st, step+1,t)) continue;
        LogStep(next_st, step+1); // 记录该决策
        Jump(next_st, step+1, t);    // 转到下一状态
    }
}

int main() {
	cin >> n >> m;
	state start = {-1, {n, n}};
    num = 0; // 初始方案数置0
    LogStep(start, 0);
	for(int t = 0;t < 60;t++) // 记录起点
    	Jump(start, 0, t);    // 从起点出发
    return 0;
}

