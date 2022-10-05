#include <iostream>        // cout
using namespace std;

int dx[] = {1, 2, 2, 1}, dy[] = {2, 1, -1, -2};
int num, path[100][2], m, n, k;

void Jump(int x, int y, int step, int *banx, int *bany);

int main() {
    // ��ʼ��������0
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
    if ((x == m) && (y == n)) {   // �Ƿ񵽴�Ŀ�ꣿ
        num++;    // ��������1
        for (int i=0; i<step; i++) // ����㿪ʼ�������������
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
        // ��(x1, y1)�����У��������ǰ���ԣ�ת����һ����������
        if ((x1 < 0) || (x1 > m) || (y1 < 0) || (y1 > n)) continue;
        path[step][0] = x1;     
        path[step][1] = y1;
        /// ��(x1, y1)������Ŀ��㣬�ж�����������--- ����������ͬ����ģ��С���ݹ飡
        Jump(x1, y1, step+1, banx, bany);
    }
}
