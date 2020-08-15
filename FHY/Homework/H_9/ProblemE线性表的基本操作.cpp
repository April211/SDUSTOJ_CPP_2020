#include <bits/stdc++.h>
using namespace std;

class Cell
{
protected:
    int num$;
    Cell *next$;

public:
    Cell() : num$(0), next$(NULL) {}
    //~Cell() { delete[] next$; }
    friend class MyList;
};

class MyList
{
protected:
    Cell *head$; // head
    int len$;    //最大容量
    int curLen$; //现有元素
public:
    MyList(int len) : head$(0), len$(len), curLen$(0)
    {
        /* if (len == 0)
        {
            head$ = NULL;
        }
        else
        {
            Cell *ttl = NULL;
            Cell *ttr = NULL;
            head$ = new Cell[1];
            (head$->num$) = 0;
            (head$->next$) = NULL;
            ttl = head$;
            for (int i = 1; i < len; i++)
            {
                ttr = new Cell[1];
                (ttl->next$) = ttr;
                ttl = ttr;
                (ttl->num$) = 0;
                (ttl->next$) = NULL;
            }
        } */
    }
    ~MyList()
    {
        Cell *tp = NULL;
        while ((head$->next$) != NULL)//循环析构头元素
        {
            tp = head$->next$;
            delete head$;
            head$ = tp;
        }
        delete head$;
    }

    void append(int d);
    void insert(int p, int d);
    void erase(int p);
    void set(int p, int d);
    void show();
};

void MyList::append(int d)
{
    Cell *tt = NULL;
    if (head$ == NULL)
    {
        head$ = new Cell;
        head$->next$ = NULL;
        head$->num$ = d;
        curLen$++;
    }
    else
    {
        Cell *ttl = head$;
        while ((ttl->next$) != NULL)
        {
            ttl = ttl->next$;
        }
        tt = new Cell;
        ttl->next$ = tt;
        tt->next$ = NULL;
        tt->num$ = d;
        curLen$++;
    }
}

void MyList::insert(int p, int d)
{
    int cnt = 0;
    Cell *tt = NULL;
    Cell *ttl = NULL;
    Cell *ttr = NULL;
    if (p == 0)
    {
        ttl = head$;
        ttr = ttl->next$;
        tt = new Cell;
        tt->next$ = ttr;
        ttl->next$ = tt;
        tt->num$ = d;
    }
    else
    {
        ttl = head$;
        while (cnt != p - 1)
        {
            ttl = ttl->next$;
            cnt++;
        }
        ttr = ttl->next$;
        tt = new Cell;
        ttl->next$ = tt;
        tt->next$ = ttr;
        tt->num$ = d;
    }

    curLen$++;
    if (curLen$ > len$)
    {
        len$ = curLen$;
    }
}

void MyList::erase(int p)
{
    int cnt = 0;
    Cell *tt = NULL;
    Cell *ttl = NULL;
    Cell *ttr = NULL;
    if (p == 0)
    {
        ttl = head$;
        ttr = ttl->next$;
        delete head$;
        head$ = ttr;
    }
    else
    {
        ttl = head$;
        while (cnt != p - 1)
        {
            ttl = ttl->next$;
            cnt++;
        }
        tt = ttl->next$; //要删除的
        ttr = tt->next$;
        delete tt;//delete pt删除堆元素。如果new是用的[], 就需要用delete []pt了。否则会卡壳
        ttl->next$ = ttr;
    }

    curLen$--;
}

void MyList::set(int p, int d)
{
    int cnt = 0;
    Cell *tt = head$;
    while (cnt != p)
    {
        tt = tt->next$;
        cnt++;
    }
    tt->num$ = d;
}

void MyList::show()
{

    Cell *tt = head$;
    while (tt != NULL)
    {
        if (tt == head$)
        {
            cout << tt->num$;
        }
        else
        {
            cout << ' ' << tt->num$;
        }
        tt = tt->next$;
    }
    cout << endl;
}

int main()
{
    int cases, len, data, pos;
    char op;
    cin >> len;
    MyList myList(len);
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> op;
        switch (op)
        {
        case 'A':
            cin >> data;
            myList.append(data);
            break;
        case 'I':
            cin >> pos >> data;
            myList.insert(pos, data);
            break;
        case 'E':
            cin >> pos;
            myList.erase(pos);
            break;
        case 'S':
            cin >> pos >> data;
            myList.set(pos, data);
        }
        myList.show();
    }
    return 0;
}

/* 

Problem E: 线性表的基本操作
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2143  Solved: 1424
[Submit][Status]
Description
线性表是一类重要的且基础的数据结构。请定义MyList类，来模拟针对线性表的插入、删除等操作：

1. 数据成员int *elements：线性表元素。

2. 数据成员int len：线性表容量，即线性表的最大长度。

3. 数据成员int curLen：线性表的当前容量，即当前拥有的元素个数。

4. 构造函数MyList(int _len)：构造最大容量为_len的线性表。

5. void append(int d)：在线性表的末尾追加元素d。

6. void insert(int p, int d)：在线性表的第p个位置（0<=p<curLen）插入元素d。

7. void erase(int p)：删除线性表的第p个位置（0<=p<curLen）上的元素。

8. void set(int p, int d)：设置线性表的第p个位置（0<=p<curLen）元素为d。

9. void show()：显示当前线性表的所有元素。输出时，两两之间用一个空格隔开，首尾不能有空格。

上述“p”是指下标，从0开始计算。

Input
第1行的整数N>0，表示线性表的最大容量。

第2行的整数M>0，表示之后有M个操作。

每个操作的类型用字母A、I、E、S分别表示追加、插入、擦除和设置。

如果操作是A，则之后输入追加的元素值。

如果操作是I，则之后输入插入的位置及元素值。

如果操作是E，则之后输入擦除的位置。

如果操作是S，则之后输入设置的位置及元素值。

所有输入均在针对线性表的合法操作范围内。

Output
每次操作后，输出线性表的所有元素。

Sample Input
10
10
A 1
A 2
A 3
A 4
A 5
A 6
A 7
I 3 10
E 6
S 1 15
Sample Output
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6 7
1 2 3 10 4 5 6 7
1 2 3 10 4 5 7
1 15 3 10 4 5 7
HINT
不能使用vector、set等容器。


Append Code
append.cc, */