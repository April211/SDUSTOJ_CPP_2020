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
    void operator+=(Fract tt) //不能加引用！！！
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
    void input(int); //这里需要到类外去定义（为什么？）
    T operator[](int i) { return pt$[i]; }
};

template <>
void Array<double>::input(int n) //模板显式特化
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



Problem D: 分数类的模板数组类
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 3005  Solved: 2236
[Submit][Status]
Description
封装一个模板数组类Array，支持一下操作：
1. 构造函数Array(int n)，将数组初始化为n个存储空间；
2. 函数input(int n)，读取最多n个元素，但不能超过数组存储空间的上限；
3. 重载下标运算符，返回数组的元素。
封装一个分数类Fract，用来处理分数功能和运算，能支持你的Array类使用。
1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。
2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。若a为0或b为1，只输出符号和分子，不输出“/”和分母。
3. 在分数类上重载+=运算符，进行分数的加法运算。
-----------------------------------------------------------------------------
你设计两个类：Array类和Fract类，使得main()函数能够运行并得到正确的输出。调用格式见append.cc
Input
输入为两部分，分别是一组实数测试样例和一组复数测试样例。
这两组测试样例都以正整数n，且n小于1000，n表示需要输入n个实数（或分数）。
测试样例的第二行开始为n个实数（或分数）。其中每个分数输入为两个整数n、m，表示分数n/m。
Output
第一部分输出一个实数，是第一组测试样例之和；第二部分输出一个分数，是第二组测试样例之和。
分数输出时为最简形式，负号只会出现在最前面，若分母为1或分子为0，则只输出一个整数，即分子部分，而没有“/”和分母部分。
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