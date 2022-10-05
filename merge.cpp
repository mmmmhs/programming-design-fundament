#include <iostream>
using namespace std;

void merge_sort(int A[], int start, int end);

int main() {
	int n;
    cin >> n;  // just for test
    int *A = new int[n];
    for(int i = 0;i < n;i++)
    {
    	cin >> A[i];
	}
    merge_sort(A, 0, n);
    return 0;
}
void merge_sort(int A[], int start, int end) {
    /// 1. 递归中止条件
    if (start == end-1) return ;
    /// 2. 对两个子数组分开排序
    int mid = (end + start)/2;
    merge_sort(A, start, mid);
    merge_sort(A, mid, end);
    /// 3. 合并有序子数组中的元素
    /// 3.1 分配临时空间存放合并元素
    int *tmp = new int[end-start];
    /// 3.2 依次取出子数组的元素，进行合并
    int left_idx = start, right_idx = mid, i = 0;
    while (left_idx < mid && right_idx < end) {
        if (A[left_idx] < A[right_idx]) 
            tmp[i++] = A[left_idx++];
        else 
            tmp[i++] = A[right_idx++];
    }
/// 3.3 如果有子数组元素没有取完，则全部并入临时空间
    while (left_idx < mid)  tmp[i++] = A[left_idx++];
    while (right_idx < end) tmp[i++] = A[right_idx++];
/// 3.4 从临时空间复制回返回数组中
	for (int i=0, idx=start; i<end-start; i++, idx++){ 
        A[idx] = tmp[i];
        cout << tmp[i] << ' ';
	}
	cout << endl;
    /// 3.5 释放临时空间
    delete[] tmp;
}
