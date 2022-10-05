#include <iostream>        // cout
using namespace std;

int num;
/// ���䷽������¼5����ֱ�ָ�˭���û����)
struct assign_state { int assigned[5]; } state;
void Try(int reader, assign_state state, int **like);

int main() {
    num = 0; // ���鷽������ʼֵ
    int n;
    cin >> n;
    int ** like;
    like = new int *[n];
    for(int i = 0;i < n;i++)
    {
    	like[i] = new int [n];
    	for(int k = 0;k < n;k++)
    		cin >> like[i][k];
	}    
    for (int book = 0; book < 5; book++) 
		state.assigned[book] = -1;
    Try(0, state, like); // �ӵ�0���ˣ�A����ʼ����
    return 0;
}

void Try(int reader, assign_state state, int **like) {
    /// �ݹ���ֹ���������ж��߾��ѷ�������鼮
    if (reader == 5) {
        num++;
        for (int i = 0; i < 5; i++) 
			cout << state.assigned[i] << ' ';
        cout << endl;   
        return;
    }
    /// ��һΪÿ�����ҵ����ʵĶ���
    for (int book = 0; book < 5; book++) {
        /// �Ƿ������������
        if (like[reader][book] != 1 || state.assigned[book] != -1) 
            continue;
        
        /// ��¼��ǰ�Ȿ��ķ������
        assign_state next_state = state; /// �����µ�״̬����
        next_state.assigned[book] = reader;
        
        /// ����һλ���߿�ʼ��������ʣ���鼮�����з���
        Try(reader+1, next_state, like);  /// �����ٻ�����!
    }
}
