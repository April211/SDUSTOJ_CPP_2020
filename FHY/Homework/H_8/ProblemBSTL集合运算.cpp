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
        for (int j = 0; j < n; j++) //��set1�в���Ԫ��
        {
            int tt;
            cin >> tt;
            set1.insert(tt);
        }
        cin >> n;
        for (int j = 0; j < n; j++) //��set2�в���Ԫ��
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

        for (p3 = ans.begin(); p3 != ans.end(); p3++) //��ans�����в���Ԫ��
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
            if (set2.count(*p1) == 0) //set2��û�����Ԫ��
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
            if (set1.count(*p2) == 0) //set2��û�����Ԫ��
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
            if (set2.count(*p1) == 0) //set2��û�����Ԫ��
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


/* Problem B: STL������������
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 7082  Solved: 3399
[Submit][Status]
Description
���ϵ���������ø����ļ���ȥָ���µļ��ϡ���A��B�Ǽ��ϣ������ǵĲ�������ֱ������£�
A��B={x|x��A��x��B}
A��B={x|x��A��x��B}
A-B={x|x��A��x������ B}
SA ={x|x��(A��B)��x ������A}
SB ={x|x��(A��B)��x ������B}

Input
��һ������һ��������T����ʾ�ܹ���T��������ݡ���T<=200��
Ȼ��������2T�У�ÿһ�ж���n+1�����֣����е�һ��������n(0<=n<=100)����ʾ���к��滹��n���������롣
Output
����ÿ��������ݣ������������������ţ���Case #.NO����
�����������7�У�ÿ�ж���һ�����ϣ�
ǰ2�зֱ��������A��B������5�����ֱ��������A��B�Ĳ�(A u B)����(A n B)����(A �C B)������
�����е�Ԫ���á�{}������������Ԫ��֮���á��� ��������
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
�������ðٶ���һ�¹ؼ��֡�stl set���������Ŀ���������ܿ�����ɵ�������������Ŷ��


Append Code */