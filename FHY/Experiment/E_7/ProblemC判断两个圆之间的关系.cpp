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
    } //外切
    else if (fabs(dcsq - drsq) <= 0.0000001)
    {
        return 4;
    } //内切
    else if (dcsq - drsq < -0.0000001)
    {
        return 2;
    } //内含
    else if (dcsq - sumrsq > 0.0000001)
    {
        return 1;
    } //外离
    else
    {
        return 5;
    } //相交
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


/* Problem C: 判断两个圆之间的关系
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2854  Solved: 2359
[Submit][Status]
Description
定义Point类，包括double类型的两个属性，分别表示二维空间中一个点的横纵坐标；定义其必要的构造函数和拷贝构造函数。

定义Circle类，包括Point类的对象和一个double类型的数据作为其属性，分别表示圆心坐标及半径；定义其必要的构造函数、拷贝构造函数。定义Circle类的成员函数：

int JudgeRelation(const Circle& another)

用于判断当前圆与another之间的位置关系。该函数的返回值根据以下规则确定：当两个圆外离时返回1；当两个圆内含时返回2；当两个圆外切时返回3； 当两个圆内且时返回4；当两个圆相交时返回5。

Input
第1行N>0表示测试用例个数。

每个测试用例包括2行，第1行是第1个圆的位置及半径；第2行是第2个圆的位置和半径。

Output
每个测试用例对应一行输出，输出两个圆之间的位置关系。见样例。

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
外离与内含均指两个圆没有任何交点，但内含是指一个圆完全包含在另一个的内部，否则便是外离。


Append Code
append.cc, */