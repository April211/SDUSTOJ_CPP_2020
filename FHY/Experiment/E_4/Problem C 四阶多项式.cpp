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


//Problem C: �Ľ׶���ʽ
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 1112  Solved: 278
//[Submit][Status]
//Description
//����һ����Equation��������ʾһ���Ľ׶���ʽ��a*x^4+b*x^3+c*x^2+d*x+e������a��b��c��d��e����int���͵ķǸ��������Ƿ��̵�ϵ�����ڸ�����������Ҫ����3����Ա������
//
//1. void Equation::print()�������������ʽ�����ʱ���˺ţ���*�������������^��ʾ����x^5��ʾx����η��������е�ϵ����Ϊ0ʱ�����0�����ֻ�в���ϵ��Ϊ0������ЩΪ0��ϵ����Ӧ����������ϵ��Ϊ1ʱ��ϵ����������統a=1ʱ�������Ӧ���x^4��������1x^4�����ʱ�����ս����Ӵ�С���������ֻҪϵ����Ϊ0��ָ���������Ҳ����˵��x^1���Ϊx^1��������x��Ψһ�������ǳ������x^0��ֻ�����ϵ��e����e>0ʱ����
//
//2. double Equation::getValue(double x)��x�Ǹ����Ĳ���ֵ������ֵ�Ƕ�Ӧ�Ķ���ʽ�е�xȡֵΪ�����Ĳ���ʱ������ʽ��ֵ��
//
//3. void Equation::setArgs(int a[])��a[]�����Ԫ�ص��������飬�ú������ڽ���׶���ʽ��a��b��c��d��e�ֱ�����Ϊa[0]��a[1]��a[2]��a[3]��a[4]��
//
//Input
//������2�С�
//
//��1�������int���ͷ�Χ�ڵķǸ�������
//
//��2����һ��double���͵�ʵ����
//
//Output
//��������
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
