#include <iostream>
#include <cstring>
#include <string>
using namespace std;
 
struct node
{
    string name;
    int delay;
    node *next;
};
 
node *read = NULL;
int N = 0;
node *q = NULL;
 
void append(int delay,string name)
{
    node *p = new node;
    p->name = name;
    p->delay = delay;
    if(read == NULL)
        read = p;
    else 
        q->next = p; 
    q = p;
    p->next = read;
    N++;
}
 
void eliminate(int m,int n)
{
    node *s = NULL;
    node *p = q;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m - 1;j++)
            p = p->next;
        s = p->next; 
        p->next = s->next;
        if(read->name == s->name)
        {
            read = s->next;
            q = p;
        }
        if(q == s)
            q = p;
        delete s;    
    }
    N -= n;
}
 
void move(bool d,int l)
{
    node *p = read;
    if(!d)
    {
        int i = (l % N) - 1;
        if (i >= 0)
        {
            while(i--)
                p = p->next;
            q = p;
            read = p->next;
        }
        else 
            return;
    }
    else
    {
        int i = N - (l % N) - 1;
        if (i >= 0)
        {
            while(i--)
                p = p->next;
            q = p;
            read = p->next;
        }
        else
            return;
    }
}
 
void sort()
{
    if(N == 0 || N == 1)
	    return;
    node *p, *s, *r, *tmp;
    s = q;
    p = read;
    r = q;
    for(int i = 0;i < N - 1;i ++)
    {           
        for(int k = 0;k < N - i - 1;k ++)
        {
            r = s;
            s = p;
            p = s -> next;
            if((s -> delay > p -> delay )|| 
              ((s -> delay == p -> delay) 
              && (s -> name > p -> name)))
            {
                s -> next = p -> next;
                r -> next = p;
                p -> next = s;
                tmp = p;
                p = s;
                s = tmp; 
            }
        if(k == N - 2)
            q = p;
        }
        s = q;
        p = q -> next;
    }
    while(q -> next != read)
    	q = q -> next;
}
 
void fdelete(string name)
{
    node *p = read;
    node *s = NULL;
    if(N == 0)
    	return;
    for(int i = 0;i < N;i++)
    {
        s = p->next; 
        if(s->name == name)
        {
            p->next = s->next;
            N--;
            if(read->name == name)
            {
                if(N > 0)
                {
                    read = s->next;
                    q = p;
                }
                else
                {
                    read = NULL;
                    q = NULL;
                }
            }
            if(q == s)
                q = p;
            delete s;    
            break;			
        }
        p = s;
    }
}
 
int main()
{
	ios::sync_with_stdio(false); 
    int T;
    cin >> T;
    string str;
    for(int i = 0;i < T;i++)
    {
        cin >> str;
        if(str == "Append")
        {
            int delay;
            string name;
            cin >> delay;
            cin >> name;
            append(delay,name);
        }
        else if(str == "Eliminate")
        {
            int m,n;
            cin >> m >> n;
            eliminate(m,n);
        }
        else if(str == "Sort")
    		sort();
        else if(str == "Move")
        {
            bool d;
            int l;
            cin >> d >> l;
            move(d,l);
        }
        else if(str == "Delete")
        {
            string name;
            cin >> name;
            fdelete(name);
        }
    } 
    string aim;
    cin >> aim;
    if(read == NULL)
    {
        cout << -1;
        return 0;
    }
    int sum = 0,k = 0;
    node *p = read; 
    for(k = 0;k < N;k++)
    {
        if(p->name == aim)
        {
            node *s = read;
            for(int j = 0;j < k;j++)
            {
                cout << s->name << endl;
                sum += s->delay;
                s = s->next;
            }
            cout << sum;
            break;
        }
        p = p->next;
    }
    if(k == N)
        cout << -1;
    return 0;
}
 
 
 
