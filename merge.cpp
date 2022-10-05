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
    /// 1. �ݹ���ֹ����
    if (start == end-1) return ;
    /// 2. ������������ֿ�����
    int mid = (end + start)/2;
    merge_sort(A, start, mid);
    merge_sort(A, mid, end);
    /// 3. �ϲ������������е�Ԫ��
    /// 3.1 ������ʱ�ռ��źϲ�Ԫ��
    int *tmp = new int[end-start];
    /// 3.2 ����ȡ���������Ԫ�أ����кϲ�
    int left_idx = start, right_idx = mid, i = 0;
    while (left_idx < mid && right_idx < end) {
        if (A[left_idx] < A[right_idx]) 
            tmp[i++] = A[left_idx++];
        else 
            tmp[i++] = A[right_idx++];
    }
/// 3.3 �����������Ԫ��û��ȡ�꣬��ȫ��������ʱ�ռ�
    while (left_idx < mid)  tmp[i++] = A[left_idx++];
    while (right_idx < end) tmp[i++] = A[right_idx++];
/// 3.4 ����ʱ�ռ临�ƻط���������
	for (int i=0, idx=start; i<end-start; i++, idx++){ 
        A[idx] = tmp[i];
        cout << tmp[i] << ' ';
	}
	cout << endl;
    /// 3.5 �ͷ���ʱ�ռ�
    delete[] tmp;
}
