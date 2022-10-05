#include <iostream>
#include <algorithm> 
#include <cstring>       
using namespace std;

int num, n; /// ������
int assigned[1000]; /// assigned[book_id] = reader_id��ֵΪ-1��ʾû�б�����
void Try(int reader, int **like, char **scheme);
bool cmp(char *a, char *b);

int main() {
    // ���÷��鷽������ʼֵΪ0
    num = 0;
    cin >> n;
    int ** like;
    like = new int *[n];
    for(int i = 0;i < n;i++)
    {
    	like[i] = new int [n];
    	for(int k = 0;k < n;k++)
    		cin >> like[i][k];
	}
	char *scheme[1000];
	for(int i = 0;i < 1000;i ++)		
		scheme[i] = new char [n];	   
    /// �����鱾��ʼ״̬Ϊδ����
    for (int book = 0; book < 5; book++)
		assigned[book] = -1;
    /// �ӵ�0�����߿�ʼ��Ѱ�����з��鷽��
    Try(0, like, scheme);
    sort(scheme, scheme + num - 1, cmp);
    for(int i = 0;i < num;i++)
    {
    	for(int k = 0;k < n;k++)
    		cout << scheme[i][k] << ' ';
    	cout << endl;	
	}
    return 0;
}

void Try(int reader, int **like, char **scheme) {
    /// �ݹ���ֹ���������ж��߾��ѷ�������鼮
    if (reader == n) {
        num++;
        for (int i = 0; i < n; i++) 
			scheme[num - 1][i] = assigned[i] + 1 + '0';
        return;
    }
    /// ��һΪÿ�����ҵ����ʵĶ���
    for (int book = 0; book < n; book++) {
        /// �Ƿ������������
        if ((like[reader][book] != 1) || assigned[book] != -1) 
			continue;
        /// ��¼��ǰ�Ȿ��ķ������
        assigned[book] = reader;
        /// ����һλ���߿�ʼ������ʣ���鼮�����з���
        Try(reader+1, like, scheme);       
        /// �����˻������ݣ���������һ�ַ���
        assigned[book] = -1;
    }
}

bool cmp(char *a, char *b)
{
	return(strcmp(a, b) < 0);
}
