#include <iostream>        // cout
using namespace std;

int num;
/// 分配方案：记录5本书分别分给谁（用户编号)
struct assign_state { int assigned[5]; } state;
void Try(int reader, assign_state state, int **like);

int main() {
    num = 0; // 分书方案数初始值
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
    Try(0, state, like); // 从第0个人（A）开始分书
    return 0;
}

void Try(int reader, assign_state state, int **like) {
    /// 递归中止条件：所有读者均已分配合适书籍
    if (reader == 5) {
        num++;
        for (int i = 0; i < 5; i++) 
			cout << state.assigned[i] << ' ';
        cout << endl;   
        return;
    }
    /// 逐一为每本书找到合适的读者
    for (int book = 0; book < 5; book++) {
        /// 是否满足分书条件
        if (like[reader][book] != 1 || state.assigned[book] != -1) 
            continue;
        
        /// 记录当前这本书的分配情况
        assign_state next_state = state; /// 产生新的状态变量
        next_state.assigned[book] = reader;
        
        /// 从下一位读者开始，求解分配剩余书籍的所有方案
        Try(reader+1, next_state, like);  /// 不用再回溯了!
    }
}
