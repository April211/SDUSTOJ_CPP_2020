#include <bits/stdc++.h>
using namespace std;

class Point
{
protected:
    double x$, y$;

public:
    Point() : x$(0.0), y$(0.0) {}
    Point(double x, double y) : x$(x), y$(y) {}
    Point(const Point &tt) : x$(tt.x$), y$(tt.y$) {}
    ~Point() {}
    double getX() const { return x$; }
    double getY() const { return y$; }
    friend class Circle;
};

class Circle
{
protected:
    Point centroid$;
    double radius$;

public:
    Circle() : centroid$(0.0, 0.0), radius$(0.0) {}
    Circle(const Point &tt, double r) : centroid$(tt.x$, tt.y$), radius$(r) {}
    Circle(const Circle &tt) : centroid$(tt.centroid$), radius$(tt.radius$) {}
    ~Circle() {}
    int JudgeRelation(const Circle &another);
};

inline int Circle::JudgeRelation(const Circle &another)
{
    double dcsq = 0.0, sumrsq = 0.0, drsq = 0.0;
    dcsq = (centroid$.x$ - another.centroid$.x$) * (centroid$.x$ - another.centroid$.x$) + (centroid$.y$ - another.centroid$.y$) * (centroid$.y$ - another.centroid$.y$);
    sumrsq = (radius$ + another.radius$) * (radius$ + another.radius$);
    drsq = (radius$ - another.radius$) * (radius$ - another.radius$);
    if (fabs(dcsq - sumrsq) <= 0.0000001)
    {
        return 3;
    } //����
    else if (fabs(dcsq - drsq) <= 0.0000001)
    {
        return 4;
    } //����
    else if (dcsq - drsq < -0.0000001)
    {
        return 2;
    } //�ں�
    else if (dcsq - sumrsq > 0.0000001)
    {
        return 1;
    } //����
    else
    {
        return 5;
    } //�ཻ
}

int main()
{
    int cases;
    double x, y, r;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> x >> y >> r;
        Point p1(x, y);
        Circle c1(p1, r);
        cin >> x >> y >> r;
        Point p2(x, y);
        Circle c2(p2, r);
        switch (c1.JudgeRelation(c2))
        {
        case 1:
            cout << "Outside" << endl;
            break;
        case 2:
            cout << "Inside" << endl;
            break;
        case 3:
            cout << "Externally tangent" << endl;
            break;
        case 4:
            cout << "Internally tangent" << endl;
            break;
        case 5:
            cout << "Intersection" << endl;
        }
    }
}


/* Problem C: �ж�����Բ֮��Ĺ�ϵ
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2854  Solved: 2359
[Submit][Status]
Description
����Point�࣬����double���͵��������ԣ��ֱ��ʾ��ά�ռ���һ����ĺ������ꣻ�������Ҫ�Ĺ��캯���Ϳ������캯����

����Circle�࣬����Point��Ķ����һ��double���͵�������Ϊ�����ԣ��ֱ��ʾԲ�����꼰�뾶���������Ҫ�Ĺ��캯�����������캯��������Circle��ĳ�Ա������

int JudgeRelation(const Circle& another)

�����жϵ�ǰԲ��another֮���λ�ù�ϵ���ú����ķ���ֵ�������¹���ȷ����������Բ����ʱ����1��������Բ�ں�ʱ����2��������Բ����ʱ����3�� ������Բ����ʱ����4��������Բ�ཻʱ����5��

Input
��1��N>0��ʾ��������������

ÿ��������������2�У���1���ǵ�1��Բ��λ�ü��뾶����2���ǵ�2��Բ��λ�úͰ뾶��

Output
ÿ������������Ӧһ��������������Բ֮���λ�ù�ϵ����������

Sample Input
5
0 0 10
20 20 1
0 0 10
1 1 4
0 0 10
0 20 10
0 0 10
0 5 5
0 0 10
15 0 10
Sample Output
Outside
Inside
Externally tangent
Internally tangent
Intersection
HINT
�������ں���ָ����Բû���κν��㣬���ں���ָһ��Բ��ȫ��������һ�����ڲ�������������롣


Append Code
append.cc, */