#include <iostream>
#include <algorithm> 
#include <cstring>       
using namespace std;

int num, n; /// 方案数
int assigned[1000]; /// assigned[book_id] = reader_id，值为-1表示没有被分配
void Try(int reader, int **like, char **scheme);
bool cmp(char *a, char *b);

int main() {
    // 设置分书方案数初始值为0
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
    /// 设置书本初始状态为未分配
    for (int book = 0; book < 5; book++)
		assigned[book] = -1;
    /// 从第0个读者开始，寻找所有分书方案
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
    /// 递归中止条件：所有读者均已分配合适书籍
    if (reader == n) {
        num++;
        for (int i = 0; i < n; i++) 
			scheme[num - 1][i] = assigned[i] + 1 + '0';
        return;
    }
    /// 逐一为每本书找到合适的读者
    for (int book = 0; book < n; book++) {
        /// 是否满足分书条件
        if ((like[reader][book] != 1) || assigned[book] != -1) 
			continue;
        /// 记录当前这本书的分配情况
        assigned[book] = reader;
        /// 从下一位读者开始，分配剩余书籍的所有方案
        Try(reader+1, like, scheme);       
        /// 将书退还（回溯），尝试另一种方案
        assigned[book] = -1;
    }
}

bool cmp(char *a, char *b)
{
	return(strcmp(a, b) < 0);
}
