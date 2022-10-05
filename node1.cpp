#include <iostream>
#include <cstring>
#include <string>
using namespace std;
 
struct node
{
    char name[7];
    int delay;
    node *next;
};
 
node *read = NULL;
int N = 0;
node *q = NULL;
 
void append(int delay,char name[])
{
    node *p = new node;
    for(int i = 0;i < 7;i++)
    { 
        p->name[i] = name[i];
    } 
    p->delay = delay;
    if(read == NULL)
    {
        read = p;
    }
    else 
    {
        q->next = p; 
    }
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
        {
            p = p->next;
        }
        s = p->next; 
        p->next = s->next;
        if(!strcmp(read->name,s->name))
        {
            read = s->next;
            q = p;
        }
        if(q == s)
        {
            q = p;
        }
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
            {
                p = p->next;
            }
            q = p;
            read = p->next;
        }
        else 
        {
            return;
        }
    }
    else
    {
        int i = N - (l % N) - 1;
        if (i >= 0)
        {
            while(i--)
            {
                p = p->next;
            }
            q = p;
            read = p->next;
        }
        else
        {
            return;
        }
    }
}
 
void sort()
{
    if(N == 0 || N == 1)
    	return;
    node *p, *s, *r, *tmp, *head;
    s = q;
    p = read;
    r = q;
    head = read;
    for(int i = 0;i < N - 1;i ++)
    {
        if((head -> delay > head -> next -> delay )|| 
            ((head -> delay == head -> next -> delay) 
            && (strcmp(head -> name,head -> next -> name) > 0)))
            head = head -> next;
        for(int k = 0;k < N - i - 1;k ++)
        {
            r = s;
            s = p;
            p = s -> next;
            if((s -> delay > p -> delay )|| 
                ((s -> delay == p -> delay) 
                && (strcmp(s -> name,p -> name) > 0)))
            {
                s -> next = p -> next;
                r -> next = p;
                p -> next = s;
                tmp = p;
                p = s;
                s = tmp; 
            }                
        }
        s = head;
        p = head -> next;
    }
        while(q -> next != read)
        	q = q -> next;
}
 
void fdelete(char *name)
{
    node *p = read;
    node *s = NULL;
    if(N == 0)
    {
    	return;
	}
    for(int i = 0;i < N;i++)
    {
        s = p->next; 
        if(!strcmp(s->name,name))
        {
            p->next = s->next;
            N--;
            if(!strcmp(read->name,name))
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
            {
                q = p;
            }
            break;			
        }
        p = s;
    }
}

int main()
{
    int T;
    cin >> T;
    string str;
    for(int i = 0;i < T;i++)
    {
        cin >> str;
        if(str == "Append")
        {
            int delay;
            char name[7];
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
        {
            sort();
        }
        else if(str == "Move")
        {
            bool d;
            int l;
            cin >> d >> l;
            move(d,l);
        }
        else if(str == "Delete")
        {
            char name[7];
            cin >> name;
            fdelete(name);
        }
    } 
    char aim[7];
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
        if(!strcmp(p->name,aim))
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
    {
        cout << -1;
    }
    return 0;
}
 
 
 
