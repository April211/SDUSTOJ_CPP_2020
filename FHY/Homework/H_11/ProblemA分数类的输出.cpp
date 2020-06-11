#include <bits/stdc++.h>
using namespace std;

class Fract
{
protected:
    int n$, m$;
public:
    Fract(int n, int m) : n$(n), m$(m)
    {
        if(m$ < 0){ m$ *= -1, n$ *= -1;}
        int gcd, num1 = abs(n$), num2 = abs(m$);
        gcd = __gcd(num1, num2);
        n$ /= gcd, m$ /= gcd;
    }
    operator double(){ return (double)n$ / m$;}
    void show() const
    {
        if (n$ == 0 || m$ == 1)  cout << n$ << endl;
        else cout << n$ << '/' << m$ << endl;
    }
};

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        Fract fr(n, m);
        fr.show();
    }
}/* 





Problem A: ����������
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 6652  Solved: 3077
[Submit][Status]
Description
��װһ��������Fract����������������ܺ����㣬֧�����²�����
1. ���죺������������n��m����ʾn/m�������ڹ���ʱ����ת������������
2. show()�������������Ϊ��a/b����-a/b������ʽ��a��b�����޷�����������aΪ0��bΪ1��ֻ������źͷ��ӣ��������/���ͷ�ĸ��
-----------------------------------------------------------------------------
�����һ��Fract�࣬ʹ��main()�����ܹ����в��õ���ȷ����������ø�ʽ��append.cc
Input
������У�ÿ�������������ֱ�Ϊ���Ӻͷ�ĸ����EOF����������ķ�ĸ����Ϊ0��
Output
ÿ�����һ��������������˳��һ�¡�
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
1/3
-4/3
8/15
-9
1
3/4
11/16
6/11
0
HINT
Append Code
append.c, append.cc,
 */