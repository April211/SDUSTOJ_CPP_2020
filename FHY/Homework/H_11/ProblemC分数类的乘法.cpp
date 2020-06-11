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
    Fract operator* (const Fract &tt)
    {
        int n, m;
        n = (*this).n$* tt.n$;
        m = (*this).m$* tt.m$;
        int gcd, num1 = abs(n), num2 = abs(m);
        gcd = __gcd(num1, num2);
        n /= gcd, m /= gcd;
        Fract ans(n, m);
        return ans;
    }
};


int main()
{
    int n, m, p, q;
    while(cin >> n >> m >> q >> p)
    {
        Fract f1(n, m), f2(q, p);
        Fract fr = f1 * f2;
        fr.show();
    }
}

/* 

Problem C: ������ĳ˷�
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 3832  Solved: 2961
[Submit][Status]
Description
��װһ��������Fract����������������ܺ����㣬֧�����²�����
1. ���죺������������n��m����ʾn/m�������ڹ���ʱ����ת������������
2. show()�������������Ϊ��a/b����-a/b������ʽ��a��b�����޷�����������aΪ0��bΪ1��ֻ������źͷ��ӣ��������/���ͷ�ĸ��
3. �ڷ����������س˷�����������з����ĳ˷�����
-----------------------------------------------------------------------------
�����һ��Fract�࣬ʹ��main()�����ܹ����в��õ���ȷ����������ø�ʽ��append.cc
Input
������У�ÿ���ĸ�����n��m��q��p���ֱ�Ϊ��������n/m��q/p����EOF����������ķ�ĸ����Ϊ0��
Output
ÿ�����һ��������Ϊn/m��q/p�ĳ˻���������˳��һ�¡�
�������ʱΪ�����ʽ������ֻ���������ǰ�棬����ĸΪ1�����Ϊ0����ֻ���һ�������������Ӳ��֣���û�С�/���ͷ�ĸ���֡�
Sample Input
1 3 2 3 
20 -15 150 80
0 77 -9 1
6 6 4 4 
12 16 4 3
-33 -48 6 11
0 -10 360 12
Sample Output
2/9
-5/2
0
1
1
3/8
0
HINT
Append Code
append.c, append.cc,


 */