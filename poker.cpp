#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
 
const int MAX_N = 2000;
 
struct Card {
    string hua;
    string num;
};
 
Card cards[MAX_N * 2];
int bottom = MAX_N;
int top = MAX_N;
int f(string num);
bool cmp(Card a, Card b) { return f(a.num) < f(b.num); }
void append(string hua, string num); //���������һ���� 
void append2(string hua, string num); //���������һ���� 
void yiwei(int start, int end);//��������start~end��ǰ��һλ ע��û�ı�bottom��top 
void Delete(string tar);//ɾ��ָ�����ƻ���ָ���� 
void refine(string tar);  //��һ��ָ�������ķ��������� ʣ���ɾ�� 
void pop(); //ɾ���������һ���� 
void pop2();//ɾ���������һ���� 
void revert(); //ʹ�����ƶ�����
Card extract_cards[MAX_N];
Card rest_cards[MAX_N];
void extract(string hua); //���ƶ��г�ȡĳ�ֻ�ɫ�������ƣ����ձ�Ŵ�С����������򣬲��ŵ��ƶѵĶ����� 
void Eliminate(int m, int n);	//�Խ�������ڵ�����ڵ�Ϊ1��ʼ��˳ʱ�뷽�������ÿ�Ƶ���m���ڵ��
								//����ӵ�ǰ�������޳���Ȼ������һ���ڵ����¼�����ֱ���޳���n������ڵ�Ϊֹ
void Move1();//˳ʱ�루���ң��ƶ�һ��
void Move1();//��ʱ�루�����ƶ�һ��
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        if (op == "Append") {
            string a, b;
            cin >> a >> b;
            append(a, b);
        } else if (op == "Extract") {
            string a;
            cin >> a;
            extract(a);
        } else if (op == "Revert") {
            revert();
        } else if(op == "Pop"){
            pop();
        }
    }
    if(top == bottom)
    {
		cout << "null";
		return 0;
	}
    cout << cards[top - 1].hua << " " << cards[top - 1].num;
    return 0;
}
int f(string num) {
    if (num == "A") return 1;
    if (num == "J") return 11;
    if (num == "Q") return 12;
    if (num == "K") return 13;
    if (num == "10")
        return 10;
    else
        return num[0] - '0';
}
 
bool cmp(Card a, Card b) { return f(a.num) < f(b.num); }
 
void append(string hua, string num) //���������һ���� 
{
    --bottom;
    cards[bottom].hua = hua;
    cards[bottom].num = num;
}

void append2(string hua, string num) //���������һ���� 
{
    cards[top].hua = hua;
    cards[top].num = num;
	top ++;
}

void yiwei(int start, int end) //��������start~end��ǰ��һλ ע��û�ı�bottom��top 
{
	for(int i = start - 1; i < end; i ++)
	{
		cards[i] = cards[i + 1];
	}
}

void Delete(string tar)//ɾ��ָ�����ƻ���ָ���� 
{
	for(int i = bottom; i < top; i ++)
	{
		if(cards[i].hua == tar)
		{
			yiwei(i + 1, top);
			top --;
		}
	}
	return;
}


void refine(string tar)   //��һ��ָ�������ķ��������� ʣ���ɾ�� 
{
	Card max_delete = {tar, -1000000}; //��Сֵ 
	for(int i = bottom; i < top; i ++)
	{
		if(cards[i].hua == tar && cards[i].num > max_delete.num)
			max_delete = cards[i];
	}
	Delete(tar);
	append2(max_delete.hua, max_delete.num);
	return;
}

void pop() //ɾ���������һ���� 
{ 
    if(bottom < top)
		--top;
}

void pop2()//ɾ���������һ���� 
{
	if(bottom < top)
		++bottom;
}
 
void revert() //ʹ�����ƶ�����
{
    for (int i = 0; i < (top - bottom) / 2; ++i) {
        swap(cards[bottom + i], cards[top - 1 - i]);
    }
}
void extract(string hua) //���ƶ��г�ȡĳ�ֻ�ɫ�������ƣ����ձ�Ŵ�С����������򣬲��ŵ��ƶѵĶ����� 
{
    int ext_cnt = 0;
    int rest_cnt = 0;
    for (int i = bottom; i < top; i++) 
	{
        if (cards[i].hua == hua) 
		{
            extract_cards[ext_cnt++] = cards[i];
        }
		else 
		{
            rest_cards[rest_cnt++] = cards[i];
        }
    }
    sort(extract_cards, extract_cards + ext_cnt, cmp);
 
    bottom = top = MAX_N;
    for (int i = 0; i < ext_cnt; ++i) {
        append(extract_cards[i].hua, extract_cards[i].num);
    }
    for (int i = 0; i < rest_cnt; ++i) {
        append(rest_cards[rest_cnt - 1 - i].hua, rest_cards[rest_cnt - 1 - i].num);
    }
}

void Eliminate(int m, int n)	//�Խ�������ڵ�����ڵ�Ϊ1��ʼ��˳ʱ�뷽�������ÿ�Ƶ���m���ڵ��
								//����ӵ�ǰ�������޳���Ȼ������һ���ڵ����¼�����ֱ���޳���n������ڵ�Ϊֹ
{
	n = min(n, top - bottom);
	int kill = 0;
	for (int t = 0;t < n;t ++)
	{
    	kill = (kill + m - 1) % (top - bottom);
    	yiwei(kill + 1 + bottom, top);
    	top --;
   	}
   	return;
}

void Move1()//˳ʱ�루���ң��ƶ�һ��
{
	if(top == bottom || top == bottom + 1)
		return;
	Append2(cards[bottom].hua, cards[bottom].num);
	bottom ++;
	return;
}

void Move1()//��ʱ�루�����ƶ�һ��
{
	if(top == bottom || top == bottom + 1)
		return;
	Append(cards[top - 1].hua, cards[top - 1].num);
	top --;
	return;
}


