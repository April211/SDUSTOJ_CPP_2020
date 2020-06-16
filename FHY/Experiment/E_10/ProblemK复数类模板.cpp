#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Complex
{
protected:
    T real$;
    T imag$;
public:
    Complex(T real, T imag):real$(real), imag$(imag){}
    double getModulus(){ return sqrt(real$* real$ + imag$* imag$);}
};

int main()
{
    int a, b;
    double c, d;
    cin>>a>>b;
    Complex<int> c1(a, b);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<c1.getModulus()<<endl;
    cin>>c>>d;
    Complex<double> c2(c, d);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<c2.getModulus()<<endl;
    return 0;
}
/* 


Problem K: ������ģ��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1101  Solved: 939
[Submit][Status]
Description
����һ����ģ��Complex����һ�����Ͳ���T������T���͵���������real��imag���ֱ��Ǹ�����ʵ�����鲿����һ����Ա����double getModulus()����������ģ��������ģ����Ϊʵ�����鲿��ƽ���͵�ƽ������

Input
��2�С���һ����2��int���͵��������ڶ�����2��double���͵�ʵ����

Output
����������ģ��

Sample Input
3 4
3.56 2.13
Sample Output
5.00
4.15
HINT
Append Code
append.cc, */