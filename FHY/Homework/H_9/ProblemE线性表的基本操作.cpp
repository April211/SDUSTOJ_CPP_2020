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
    int len$;    //�������
    int curLen$; //����Ԫ��
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
        while ((head$->next$) != NULL)//ѭ������ͷԪ��
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
        tt = ttl->next$; //Ҫɾ����
        ttr = tt->next$;
        delete tt;//delete ptɾ����Ԫ�ء����new���õ�[], ����Ҫ��delete []pt�ˡ�����Ῠ��
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

Problem E: ���Ա�Ļ�������
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2143  Solved: 1424
[Submit][Status]
Description
���Ա���һ����Ҫ���һ��������ݽṹ���붨��MyList�࣬��ģ��������Ա�Ĳ��롢ɾ���Ȳ�����

1. ���ݳ�Աint *elements�����Ա�Ԫ�ء�

2. ���ݳ�Աint len�����Ա������������Ա����󳤶ȡ�

3. ���ݳ�Աint curLen�����Ա�ĵ�ǰ����������ǰӵ�е�Ԫ�ظ�����

4. ���캯��MyList(int _len)�������������Ϊ_len�����Ա�

5. void append(int d)�������Ա��ĩβ׷��Ԫ��d��

6. void insert(int p, int d)�������Ա�ĵ�p��λ�ã�0<=p<curLen������Ԫ��d��

7. void erase(int p)��ɾ�����Ա�ĵ�p��λ�ã�0<=p<curLen���ϵ�Ԫ�ء�

8. void set(int p, int d)���������Ա�ĵ�p��λ�ã�0<=p<curLen��Ԫ��Ϊd��

9. void show()����ʾ��ǰ���Ա������Ԫ�ء����ʱ������֮����һ���ո��������β�����пո�

������p����ָ�±꣬��0��ʼ���㡣

Input
��1�е�����N>0����ʾ���Ա�����������

��2�е�����M>0����ʾ֮����M��������

ÿ����������������ĸA��I��E��S�ֱ��ʾ׷�ӡ����롢���������á�

���������A����֮������׷�ӵ�Ԫ��ֵ��

���������I����֮����������λ�ü�Ԫ��ֵ��

���������E����֮�����������λ�á�

���������S����֮���������õ�λ�ü�Ԫ��ֵ��

�����������������Ա�ĺϷ�������Χ�ڡ�

Output
ÿ�β�����������Ա������Ԫ�ء�

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
����ʹ��vector��set��������


Append Code
append.cc, */