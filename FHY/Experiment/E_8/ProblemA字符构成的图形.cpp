#include <bits/stdc++.h>
using namespace std;

class CharGraph
{
protected:
    int level$;
    char ch$;

public:
    CharGraph(int level, char ch) : level$(level), ch$(ch) {}
    ~CharGraph() {}
    void print() const;
};

void CharGraph::print() const
{
    if (level$ == 0)
    {
        cout << endl;
    }
    else if (level$ > 0)
    {
        for (int i = 0; i < level$; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << ch$;
            }
            cout << endl;
        }
    }
    else
    {
        int level;
        level = -level$;
        for (int i = level; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                cout << ch$;
            }
            cout << endl;
        }
    }
}

int main()
{
    int cases, n;
    char c;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> n >> c;
        CharGraph cGraph(n, c);
        cGraph.print();
    }
    return 0;
}


/* Problem A: �ַ����ɵ�ͼ��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4041  Solved: 2742
[Submit][Status]
Description
����CharGraph�࣬�������һ����ָ���ַ���ɵ�ͼ�Ρ����������

1. һ��int�������ݳ�Ա����ʾ��ͼ�εĲ�����

2. һ��char���͵����ݳ�Ա����ʾ��ɸ�ͼ���ַ���

3. void print()���������ڸ���ָ����ʽ����ַ�ͼ�Ρ�

Input
��1��N>0����ʾ��N������������

ÿ������������������һ���Ǹ�������һ���ַ���ɡ�

Output
ÿ��������������һ�������

��ָ���Ĳ���Ϊ0ʱ�����һ�����С�

��ָ���Ĳ���Ϊ����ʱ�����ÿ���ַ��������ϵ������ε����ҿ�������ֱ�������Ρ�

��ָ���Ĳ���Ϊ����ʱ�����ÿ���ַ��������϶������εݼ��俿������ֱ�������Ρ�

�����ʽ��������

Sample Input
3
10 c
0 0
-5 +
Sample Output
c
cc
ccc
cccc
ccccc
cccccc
ccccccc
cccccccc
ccccccccc
cccccccccc

+++++
++++
+++
++
+
HINT
Append Code
append.cc, */