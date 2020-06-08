#include <bits/stdc++.h>
using namespace std;

class Fract
{
protected:
    int n$, m$;

public:
    Fract(int n, int m) : n$(n), m$(m)
    {
        int temp, num1 = abs(n$), num2 = abs(m$);
        if (num1 < num2) { temp = num1; num1 = num2; num2 = temp;}
        int a = num1, b = num2;
        while (b != 0)
        {
            temp = a % b;
            a = b;
            b = temp;
        }
        n$ /= a, m$ /= a;
    }

    operator double()
    {
        if(n$ == 0) return 0;
        else        return ((n$* 1.0)/ (m$* 1.0));
    }

    void show() const
    {
        if (n$ == 0)          cout << '0' << endl;
        else if (n$ > 0)
        {
            if (m$ < 0)
            {
                if (m$ == -1) cout << '-' << n$ << endl;
                else          cout << '-' << n$ << '/' << -m$ << endl;
            }
            else
            {
                if (m$ == 1)  cout << n$ << endl;
                else          cout << n$ << '/' << m$ << endl;
            }
            
        }
        else// n$ < 0
        {
            if (m$ < 0)
            {
                if (m$ == -1) cout << -n$ << endl;
                else          cout << -n$ << '/' << -m$ << endl;
            }
            else
            {
                if (m$ == 1)  cout << n$ << endl;
                else          cout << n$ << '/' << m$ << endl;
            }
        }
    }
};



int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Fract fr(n, m);
        cout << (double)fr << " ";
        fr.show();
    }
}

/* 

Problem D: �����������ת��
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 4055  Solved: 2918
[Submit][Status]
Description
��װһ��������Fract����������������ܺ����㣬֧�����²�����
1. ���죺������������n��m����ʾn/m�������ڹ���ʱ����ת������������
2. show()�������������Ϊ��a/b����-a/b������ʽ��a��b�����޷�����������aΪ0��bΪ1��ֻ������źͷ��ӣ��������/���ͷ�ĸ��
3. double����ת���������÷��ӳ��Է�ĸ���õ���С����ע�⣺����Ϊ0ʱ��Ҫ���Ϊ��-0��
-----------------------------------------------------------------------------
�����һ��Fract�࣬ʹ��main()�����ܹ����в��õ���ȷ����������ø�ʽ��append.cc
Input
������У�ÿ�������������ֱ�Ϊ���Ӻͷ�ĸ����EOF����������ķ�ĸ����Ϊ0��
Output
ÿ�����һ��ʵ���ͷ�����������˳��һ�¡�ʵ��Ϊ���ӳ��Է�ĸ���á�
�������ʱΪ�����ʽ������ֻ���������ǰ�棬����ĸΪ1�����Ϊ0����ֻ���һ�������������Ӳ��֣���û�С�/���ͷ�ĸ���֡�
Sample Input
1 3
20 -15
80 150
-9 1
6 6
12 16
-33 -48
6 11
0 -10
Sample Output
0.333333 1/3
-1.33333 -4/3
0.533333 8/15
-9 -9
1 1
0.75 3/4
0.6875 11/16
0.545455 6/11
0 0
HINT
Append Code
append.c, append.cc, */