#include <iostream>
using namespace std;

int num, n;

void Try(int height, int *path, int *ban,int step);

int main() {
    /// �ܷ�������ֵΪ0
    num = 0;
    int h;
    cin >> h >> n;
    int *path = new int [h];
    for(int i = 0;i < h;i ++)
    	path[i] = 0;
    int *ban = new int [n];
    for(int i = 0;i < n;i ++)
    	cin >> ban[i];
    /// ��0�����Ӹ߶�TARGET_H����
    Try(h, path, ban, 0); // height = TARGET_H, step = 0
    cout << num;
    return 0;
}

/// ��step�����Ӹ߶�height��ʼ��������¥
void Try(int height, int *path, int *ban, int step) {
    /// �ݹ���ֹ����������¥�ݵײ�
    if (height == 0) {
    	int sum;
        num ++;  
        for (int i = 1; i <= step; i++){
        	sum = 0;
        	for(int k = 0;k < i;k++)
        	{
				sum += path[k];
            }    
			for(int j = 0;j < n;j ++)
			{
				if(sum == ban[j])
					num --;
			}
		}
        return;
    }    
    /// ���γ��Բ�ͬ����¥����(ѭ������i�ǿ��ܵĲ���)
    for (int i = 1; i <= 3; i++) {
        /// 1. �����¸߶�
        int new_height = height - i;
        /// 2. �߶��Ƿ���У�
        if (new_height < 0) break; /// ��������continue��?
        /// 3. ��¼��ǰ����
        path[step] = i; 
		step ++; 
        /// 4. ������Ŀ��ǰ��
        Try(new_height, path, ban, step);
    }
}
