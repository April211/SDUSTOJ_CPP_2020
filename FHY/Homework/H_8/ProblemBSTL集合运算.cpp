#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numberofgroup = 0;

    cin >> numberofgroup;

    for (int i = 1; i <= numberofgroup; i++)
    {
        int n = 0;
        set<int, less<int> > set1;
        set<int, less<int> > set2;
        set<int, less<int> > ans;
        set<int, less<int> >::iterator p1;
        set<int, less<int> >::iterator p2;
        set<int, less<int> >::iterator p3;
        cin >> n;
        for (int j = 0; j < n; j++) //向set1中插入元素
        {
            int tt;
            cin >> tt;
            set1.insert(tt);
        }
        cin >> n;
        for (int j = 0; j < n; j++) //向set2中插入元素
        {
            int tt;
            cin >> tt;
            set2.insert(tt);
        }
        cout << "Case# " << i << ':' << endl;
        cout << "A = {";

        for (p1 = set1.begin(); p1 != set1.end(); p1++)
        {
            if (p1 == set1.begin())
            {
                cout << *p1;
            }
            else
            {
                cout << ", " << *p1;
            }
        }

        cout << '}' << endl;

        cout << "B = {";
        for (p2 = set2.begin(); p2 != set2.end(); p2++)
        {
            if (p2 == set2.begin())
            {
                cout << *p2;
            }
            else
            {
                cout << ", " << *p2;
            }
        }
        cout << '}' << endl;

        cout << "A u B = {";

        for (p1 = set1.begin(); p1 != set1.end(); p1++)
        {
            ans.insert(*p1);
        }
        for (p2 = set2.begin(); p2 != set2.end(); p2++)
        {
            ans.insert(*p2);
        }

        for (p3 = ans.begin(); p3 != ans.end(); p3++) //向ans集合中插入元素
        {
            if (p3 == ans.begin())
            {
                cout << *p3;
            }
            else
            {
                cout << ", " << *p3;
            }
        }
        cout << '}' << endl;
        ans.clear();

        cout << "A n B = {";
        for (p1 = set1.begin(); p1 != set1.end(); p1++)
        {
            for (p2 = set2.begin(); p2 != set2.end(); p2++)
            {
                if (*p1 == *p2)
                {
                    ans.insert(*p1);
                }
            }
        }
        for (p3 = ans.begin(); p3 != ans.end(); p3++)
        {
            if (p3 == ans.begin())
            {
                cout << *p3;
            }
            else
            {
                cout << ", " << *p3;
            }
        }
        cout << '}' << endl;
        ans.clear();

        cout << "A - B = {";
        for (p1 = set1.begin(); p1 != set1.end(); p1++)
        {
            if (set2.count(*p1) == 0) //set2中没有这个元素
            {
                ans.insert(*p1);
            }
        }
        for (p3 = ans.begin(); p3 != ans.end(); p3++)
        {
            if (p3 == ans.begin())
            {
                cout << *p3;
            }
            else
            {
                cout << ", " << *p3;
            }
        }
        cout << '}' << endl;
        ans.clear();

        cout << "SA = {";
        for (p2 = set2.begin(); p2 != set2.end(); p2++)
        {
            if (set1.count(*p2) == 0) //set2中没有这个元素
            {
                ans.insert(*p2);
            }
        }
        for (p3 = ans.begin(); p3 != ans.end(); p3++)
        {
            if (p3 == ans.begin())
            {
                cout << *p3;
            }
            else
            {
                cout << ", " << *p3;
            }
        }
        cout << '}' << endl;
        ans.clear();

        cout << "SB = {";
        for (p1 = set1.begin(); p1 != set1.end(); p1++)
        {
            if (set2.count(*p1) == 0) //set2中没有这个元素
            {
                ans.insert(*p1);
            }
        }
        for (p3 = ans.begin(); p3 != ans.end(); p3++)
        {
            if (p3 == ans.begin())
            {
                cout << *p3;
            }
            else
            {
                cout << ", " << *p3;
            }
        }
        cout << '}' << endl;
        ans.clear();

        set1.clear();
        set2.clear();
    }

    return 0;
}


/* Problem B: STL——集合运算
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 7082  Solved: 3399
[Submit][Status]
Description
集合的运算就是用给定的集合去指定新的集合。设A和B是集合，则它们的并差交补集分别定义如下：
A∪B={x|x∈A∨x∈B}
A∩B={x|x∈A∧x∈B}
A-B={x|x∈A∧x不属于 B}
SA ={x|x∈(A∪B)∧x 不属于A}
SB ={x|x∈(A∪B)∧x 不属于B}

Input
第一行输入一个正整数T，表示总共有T组测试数据。（T<=200）
然后下面有2T行，每一行都有n+1个数字，其中第一个数字是n(0<=n<=100)，表示该行后面还有n个数字输入。
Output
对于每组测试数据，首先输出测试数据序号，”Case #.NO”，
接下来输出共7行，每行都是一个集合，
前2行分别输出集合A、B，接下5行来分别输出集合A、B的并(A u B)、交(A n B)、差(A – B)、补。
集合中的元素用“{}”扩起来，且元素之间用“， ”隔开。
Sample Input
1
4 1 2 3 1
0
Sample Output
Case# 1:
A = {1, 2, 3}
B = {}
A u B = {1, 2, 3}
A n B = {}
A - B = {1, 2, 3}
SA = {}
SB = {1, 2, 3}
HINT
如果你会用百度搜一下关键字“stl set”，这个题目我相信你会很快很轻松的做出来。加油哦！


Append Code */