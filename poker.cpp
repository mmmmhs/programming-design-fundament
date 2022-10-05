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
void append(string hua, string num); //在下面添加一张牌 
void append2(string hua, string num); //在上面添加一张牌 
void yiwei(int start, int end);//将数组中start~end向前移一位 注意没改变bottom和top 
void Delete(string tar);//删除指定名称或者指定类 
void refine(string tar);  //找一个指定类最大的放在最上面 剩余的删除 
void pop(); //删除最上面的一张牌 
void pop2();//删除最下面的一张牌 
void revert(); //使整个牌堆逆序。
Card extract_cards[MAX_N];
Card rest_cards[MAX_N];
void extract(string hua); //从牌堆中抽取某种花色的所有牌，按照编号从小到大进行排序，并放到牌堆的顶部。 
void Eliminate(int m, int n);	//以接入点所在的网络节点为1开始朝顺时针方向计数，每计到第m个节点就
								//将其从当前网络中剔除，然后由下一个节点重新计数，直至剔除出n个网络节点为止
void Move1();//顺时针（向右）移动一个
void Move1();//逆时针（向左）移动一个
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
 
void append(string hua, string num) //在下面添加一张牌 
{
    --bottom;
    cards[bottom].hua = hua;
    cards[bottom].num = num;
}

void append2(string hua, string num) //在上面添加一张牌 
{
    cards[top].hua = hua;
    cards[top].num = num;
	top ++;
}

void yiwei(int start, int end) //将数组中start~end向前移一位 注意没改变bottom和top 
{
	for(int i = start - 1; i < end; i ++)
	{
		cards[i] = cards[i + 1];
	}
}

void Delete(string tar)//删除指定名称或者指定类 
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


void refine(string tar)   //找一个指定类最大的放在最上面 剩余的删除 
{
	Card max_delete = {tar, -1000000}; //最小值 
	for(int i = bottom; i < top; i ++)
	{
		if(cards[i].hua == tar && cards[i].num > max_delete.num)
			max_delete = cards[i];
	}
	Delete(tar);
	append2(max_delete.hua, max_delete.num);
	return;
}

void pop() //删除最上面的一张牌 
{ 
    if(bottom < top)
		--top;
}

void pop2()//删除最下面的一张牌 
{
	if(bottom < top)
		++bottom;
}
 
void revert() //使整个牌堆逆序。
{
    for (int i = 0; i < (top - bottom) / 2; ++i) {
        swap(cards[bottom + i], cards[top - 1 - i]);
    }
}
void extract(string hua) //从牌堆中抽取某种花色的所有牌，按照编号从小到大进行排序，并放到牌堆的顶部。 
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

void Eliminate(int m, int n)	//以接入点所在的网络节点为1开始朝顺时针方向计数，每计到第m个节点就
								//将其从当前网络中剔除，然后由下一个节点重新计数，直至剔除出n个网络节点为止
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

void Move1()//顺时针（向右）移动一个
{
	if(top == bottom || top == bottom + 1)
		return;
	Append2(cards[bottom].hua, cards[bottom].num);
	bottom ++;
	return;
}

void Move1()//逆时针（向左）移动一个
{
	if(top == bottom || top == bottom + 1)
		return;
	Append(cards[top - 1].hua, cards[top - 1].num);
	top --;
	return;
}


