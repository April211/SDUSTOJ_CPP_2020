#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int, less<int> > seta;
    set<int, less<int> > setb;
    set<int, less<int> > ans;
    set<int, less<int> >::iterator p1;
    set<int, less<int> >::iterator p2;
    set<int, less<int> >::iterator p3;

    int a = 0, b = 0;

    while(cin >> a)
    {
        if(a != 0)
        {
            seta.insert(a);
            cin >> b;
            while(b)
            {
                seta.insert(b);
                cin >> b;
            }

        }

        cin >> a;
        if(a != 0)
        {
            setb.insert(a);
            cin >> b;
            while(b)
            {
                setb.insert(b);
                cin >> b;
            }

        }

        //A - B
        for (p1 = seta.begin(); p1 != seta.end(); p1++)
        {
            if (setb.count(*p1) == 0) //setb��û�����Ԫ��
            {
                ans.insert(*p1);
            }
        }

        //B - A
        for (p2 = setb.begin(); p2 != setb.end(); p2++)
        {
            if (seta.count(*p2) == 0) //seta��û�����Ԫ��
            {
                ans.insert(*p2);
            }
             
        }


        if(ans.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        ans.clear();
        seta.clear();
        setb.clear();
        
    }



    return 0;
}


/* Problem C: STL����Jerry������
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5213  Solved: 3363
[Submit][Status]
Description
���Jerry���ڿ̿��ѧϰSTL�е�set�Ĺ��ܺ�����������set���������еĺ���ʵ�ֲ���������ԳƲ�ȹ��ܣ�������û���ҵ���ô���Ƚ����������Ƿ���ȵĹ��ܺ��������������Լ��������Ĺ��ܺ�����ʵ�����ж����������Ƿ���ȵĹ��ܺ�����������Jerry��һ����뵽�˽���취������������������������㣬������û����������
Input
�����ж��飬ÿ�����������У�ÿһ�ж�����һ�����ϣ�ÿһ�������ɸ�������(0<d<=2147483647)������ÿ�е����һ�����ֶ���0,����������ݵĽ�������ĩβ��0�����뼯���С������EOF�������롣

Output
����ÿ�����������Ҫ����һ��������������������ȱ������YES�������������NO����ÿ�����ռһ��
Sample Input
1 2 3 4 0
1 2 3 4 0
1 2 2 2 2 2 0
1 2 0
1 2 3 4 0
1 3 3 4 0
Sample Output
YES
YES
NO
HINT
�ԳƲ����㣺�õ��Ľ���ǵ�һ��������ڶ������ϵĲ���ϵڶ������һ���Ĳ


Append Code */