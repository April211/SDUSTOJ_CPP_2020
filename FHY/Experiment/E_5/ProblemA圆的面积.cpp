#include <bits/stdc++.h>
using namespace std;

class Circle
{
private:
    const double radius$;
public:
    static double PI;
    Circle(double r):radius$(r){}
    double getArea()const
    {
        double Area = PI* radius$* radius$;
        return Area;
    }
    double getRadius()const
    {
        return radius$;
    }
};

double Circle::PI = 3.14;

int main()
{
    double radius;
    cout<<"PI="<<Circle::PI<<endl;
    const Circle c1(2);
    cout<<"radius="<<c1.getRadius();
    cout<<",area="<<c1.getArea()<<endl;
    cin>>radius;
    Circle c2(radius);
    cout<<"radius="<<c2.getRadius();
    cout<<",area="<<c2.getArea()<<endl;
    return 0;
}


/* Problem A: Բ�����
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1579  Solved: 1138
[Submit][Status]
Description
����Circle�࣬��һ��˽�еġ�double���͵�����radius����ʾԲ�İ뾶����һ�����еġ�double���͵ĳ���̬���ݳ�ԱPI=3.14����ʾԲ���ʡ�����getArea()��getRadius()����������Բ������Ͱ뾶��ע�⣺�ڶ���������������ʱ��Ҫ��֤��������ȷִ�С�

Input
һ��double���͵����ݡ�

Output
��������

Sample Input
3.15
Sample Output
PI=3.14
radius=2,area=12.56
radius=3.15,area=31.1566
HINT
Append Code
append.cc, */