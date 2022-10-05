#include <iostream>        // cout
using namespace std;

int dx[] = {1, 2, 2, 1}, dy[] = {2, 1, -1, -2};
int num, path[100][2], m, n, k;

void Jump(int x, int y, int step, int *banx, int *bany);

int main() {
    // 初始方案数置0
    num = 0;
    cin >> m >> n >>k;
    int *banx = new int [k];
    int *bany = new int [k];
    for(int i = 0;i < k;i++)
    	cin >> banx[i] >> bany[i];
    Jump(0, 0, 0, banx, bany);
    cout << num;
    return 0;
}

void Jump(int x, int y, int step, int *banx, int *bany) {
    if ((x == m) && (y == n)) {   // 是否到达目标？
        num++;    // 方案数加1
        for (int i=0; i<step; i++) // 从起点开始输出各步的坐标
        {
        	for(int s = 0;s < k;s++)
        	{
        		if((path[i][0] == banx[s]) && (path[i][1] == bany[s])){
        			num--;
        			return;
        	    }
			}
		}            
        return;
    }
    for (int k=0; k<4; k++) {
        int x1 = x + dx[k], y1 = y + dy[k];
        // 若(x1, y1)不可行，则放弃当前测试，转至下一个跳步方案
        if ((x1 < 0) || (x1 > m) || (y1 < 0) || (y1 > n)) continue;
        path[step][0] = x1;     
        path[step][1] = y1;
        /// 从(x1, y1)出发到目标点，有多少种跳法？--- 问题性质相同，规模缩小：递归！
        Jump(x1, y1, step+1, banx, bany);
    }
}
