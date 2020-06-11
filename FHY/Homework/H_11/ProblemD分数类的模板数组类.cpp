#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Array;

class Fract
{
protected:
    int n$, m$;

public:
    Fract(int n = 0, int m = 1) : n$(n), m$(m)
    {
        if (m$ < 0)
        {
            m$ *= -1, n$ *= -1;
        }
        int gcd, num1 = abs(n$), num2 = abs(m$);
        gcd = __gcd(num1, num2);
        n$ /= gcd, m$ /= gcd;
    }
    operator double() { return (double)n$ / m$; }
    void show() const
    {
        if (n$ == 0 || m$ == 1)
            cout << n$ << endl;
        else
            cout << n$ << '/' << m$ << endl;
    }
    Fract operator*(const Fract &tt)
    {
        int n, m;
        n = (*this).n$ * tt.n$;
        m = (*this).m$ * tt.m$;
        int gcd, num1 = abs(n), num2 = abs(m);
        gcd = __gcd(num1, num2);
        n /= gcd, m /= gcd;
        Fract ans(n, m);
        return ans;
    }
    void operator+=(Fract tt) //���ܼ����ã�����
    {
        if (abs(tt.n$) == 0)
        {
        }
        else if (abs((*this).n$) == 0)
        {
            (*this).n$ = tt.n$;
            (*this).m$ = tt.m$;
        }
        else
        {
            int lcm = (abs(tt.m$) * abs((*this).m$)) / (__gcd(abs(tt.m$), abs((*this).m$)));
            int nn1, nn2, nn, mm;
            mm = lcm;   
            nn1 = (tt.n$) * (lcm / abs(tt.m$)); 
            nn2 = ((*this).n$) * (lcm / abs((*this).m$));  
            nn = nn1 + nn2;
            int gcd = __gcd(abs(nn), abs(mm));
            nn /= gcd, mm /= gcd;
            (*this).n$ = nn;
            (*this).m$ = mm;
        }
    }
    friend class Array<Fract>;
};

template <typename T>
class Array
{
protected:
    int len$;
    T *pt$;
public:
    Array(int n) : len$(n)
    {
        pt$ = new T[len$];
        memset(pt$, 0, sizeof(pt$));
    }
    void input(int); //������Ҫ������ȥ���壨Ϊʲô����
    T operator[](int i) { return pt$[i]; }
};

template <>
void Array<double>::input(int n) //ģ����ʽ�ػ�
{
    for (int i = 0; i < n; i++)
    {
        cin >> pt$[i];
    }
}

template <>
void Array<Fract>::input(int n)
{
    for (int i = 0; i < n; i++)
    {
        int nn, mm;
        cin >> nn >> mm;
        if (mm < 0) { mm *= -1, nn *= -1;}
        int gcd, num1 = abs(nn), num2 = abs(mm);
        gcd = __gcd(num1, num2);
        nn /= gcd, mm /= gcd;
        pt$[i].n$ = nn, pt$[i].m$ = mm;
    }
}

int main()
{
    int n;
    cin >> n;
    Array<double> db(1000);
    db.input(n);
    double dbsum(0.0);
    for (int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(1000);
    fr.input(n);
    Fract frsum(0, 1);
    for (int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
        
}
/* 



Problem D: �������ģ��������
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 3005  Solved: 2236
[Submit][Status]
Description
��װһ��ģ��������Array��֧��һ�²�����
1. ���캯��Array(int n)���������ʼ��Ϊn���洢�ռ䣻
2. ����input(int n)����ȡ���n��Ԫ�أ������ܳ�������洢�ռ�����ޣ�
3. �����±�����������������Ԫ�ء�
��װһ��������Fract����������������ܺ����㣬��֧�����Array��ʹ�á�
1. ���죺������������n��m����ʾn/m�������ڹ���ʱ����ת������������
2. show()�������������Ϊ��a/b����-a/b������ʽ��a��b�����޷�����������aΪ0��bΪ1��ֻ������źͷ��ӣ��������/���ͷ�ĸ��
3. �ڷ�����������+=����������з����ļӷ����㡣
-----------------------------------------------------------------------------
����������ࣺArray���Fract�࣬ʹ��main()�����ܹ����в��õ���ȷ����������ø�ʽ��append.cc
Input
����Ϊ�����֣��ֱ���һ��ʵ������������һ�鸴������������
�����������������������n����nС��1000��n��ʾ��Ҫ����n��ʵ�������������
���������ĵڶ��п�ʼΪn��ʵ�����������������ÿ����������Ϊ��������n��m����ʾ����n/m��
Output
��һ�������һ��ʵ�����ǵ�һ���������֮�ͣ��ڶ��������һ���������ǵڶ����������֮�͡�
�������ʱΪ�����ʽ������ֻ���������ǰ�棬����ĸΪ1�����Ϊ0����ֻ���һ�������������Ӳ��֣���û�С�/���ͷ�ĸ���֡�
Sample Input
4
6 8 7 5
9
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
26
-17117/2640
HINT
Append Code
append.c, append.cc, */