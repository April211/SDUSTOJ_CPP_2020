#include <bits/stdc++.h>
using namespace std;

class Equation
{
private:
    int a$, b$, c$, d$, e$;
public:
    Equation():a$(0), b$(0), c$(0), d$(0), e$(0) {}
    ~Equation() {}
    void print()const;
    double getValue(double x)const;
    void setArgs(int a[]);
};

void Equation::setArgs(int a[])
{
    a$ = a[0];
    b$ = a[1];
    c$ = a[2];
    d$ = a[3];
    e$ = a[4];
}

double Equation::getValue(double x)const
{
    double ans = 0.0;
    double a = (double)a$;
    double b = (double)b$;
    double c = (double)c$;
    double d = (double)d$;
    double e = (double)e$;
    ans = a*(x*x*x*x) + b*(x*x*x) + c*(x*x) + d*x + e;
    return ans;
}

void Equation::print()const
{
    //a
    if(a$ != 0 && a$ != 1)
    {
        cout << a$ << "x^4";
    }
    if(a$ == 1)
    {
        cout << "x^4";
    }
    //b
    if(b$ != 0 && b$ != 1)
    {
        if(a$ != 0)
        {
            cout << '+';
        }

        cout << b$ << "x^3";
    }
    if(b$ == 1)
    {
        if(a$ != 0)
        {
            cout << '+';
        }
        cout << "x^3";
    }
    //c
    if(c$ != 0 && c$ != 1)
    {
        if(a$ != 0 || b$ !=0)
        {
            cout << '+';
        }

        cout << c$ << "x^2";
    }
    if(c$ == 1)
    {
        if(a$ != 0 || b$ !=0)
        {
            cout << '+';
        }
        cout << "x^2";
    }
    //d
    if(d$ != 0 && d$ != 1)
    {
        if(a$ != 0 || b$ != 0 || c$ != 0)
        {
            cout << '+';
        }
        cout << d$ << "x^1";
    }
    if(d$ == 1)
    {
        if(a$ != 0 || b$ != 0 || c$ != 0)
        {
            cout << '+';
        }
        cout << "x^1";
    }
    //e
    if(e$ != 0)
    {
        if(a$ != 0 || b$ != 0 || c$ != 0 || d$ != 0)
        {
            cout << '+';
        }
        cout << e$ << endl;
    }
    if(e$ == 0)
    {
        if(a$ != 0 || b$ != 0 || c$ != 0 || d$ != 0)
        {
            cout << endl;
        }
        else
        {
            cout << '0' << endl;
        }

    }

}


int main()
{
    int i, a[5];
    double x;
    Equation eq1;
    cout<<"1:";
    eq1.print();
    for (i = 0; i < 5; i++)
        cin>>a[i];
    eq1.setArgs(a);
    cout<<"2:";
    eq1.print();
    cin>>x;
    cout<<eq1.getValue(x)<<endl;
    return 0;
}


//Problem C: 四阶多项式
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 1112  Solved: 278
//[Submit][Status]
//Description
//定义一个类Equation，用来表示一个四阶多项式：a*x^4+b*x^3+c*x^2+d*x+e。其中a、b、c、d、e都是int类型的非负整数，是方程的系数。在该类中至少需要以下3个成员函数：
//
//1. void Equation::print()：用来输出多项式。输出时，乘号（即*）不输出，幂用^表示，如x^5表示x的五次方。当所有的系数都为0时，输出0。如果只有部分系数为0，则这些为0的系数对应的项不输出。当系数为1时，系数不输出，如当a=1时，最高项应输出x^4，而不是1x^4。输出时，按照阶数从大到小依次输出。只要系数不为0，指数就输出，也就是说，x^1输出为x^1，而不是x。唯一的例外是常数项（即x^0）只需输出系数e（当e>0时）。
//
//2. double Equation::getValue(double x)：x是给定的参数值，返回值是对应的多项式中当x取值为给定的参数时，多项式的值。
//
//3. void Equation::setArgs(int a[])：a[]是五个元素的整数数组，该函数用于将五阶多项式的a、b、c、d、e分别设置为a[0]、a[1]、a[2]、a[3]和a[4]。
//
//Input
//输入有2行。
//
//第1行是五个int类型范围内的非负整数。
//
//第2行是一个double类型的实数。
//
//Output
//见样例。
//
//Sample Input
//1 2 0 3 2
//2
//Sample Output
//1:0
//2:x^4+2x^3+3x^1+2
//40
//HINT
//Append Code
//append.cc,
