#include <iostream>
#include <iomanip>
using namespace std;



class Point
{
public:
    Point(double x = 0.0, double y = 0.0):_x(x), _y(y){cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is created." << endl;}
    Point(int x):_x(x), _y(x){cout << setprecision(16) << "Point : (" << _x << ", " << _x << ") is created." << endl;}
    ~Point(){cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is erased." << endl;}
    Point(const Point &c){ _x = c._x; _y = c._y; cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is copied." << endl;}
private:
    double _x, _y;
public:
    int show()
    {
       cout << setprecision(16);
       cout << "Point : (" << _x << ", " << _y << ')' << endl;
       return 0;
    }

};
int showPoint(Point &a, Point &b, Point &c)
{
    Point aa(a), bb(b), cc(c);

    aa.show();
    bb.show();
    cc.show();
    return 0;
}
int showPoint(Point &a)
{
    Point aa(a);
    aa.show();
    return 0;
}

int main()
{
    char c;
    double a, b;
    Point q;
    while(std::cin>>a>>c>>b)
    {
        Point p(a, b);
        showPoint(p);
    }
    Point q1(q), q2(1);
    showPoint(q1, q2, q);
}


// Problem C: 平面上的点——Point类 (III)
// Time Limit: 1 Sec  Memory Limit: 4 MB
// Submit: 8005  Solved: 5159
// [Submit][Status]
// Description
// 在数学上，平面直角坐标系上的点用X轴和Y轴上的两个坐标值唯一确定。现在我们封装一个“Point类”来实现平面上的点的操作。

// 根据“append.cc”，完成Point类的构造方法和show()方法，输出各Point对象的构造和析构次序。实现showPoint()函数。

// 接口描述：
// showPoint()函数按输出格式输出Point对象，调用Point::show()方法实现。
// Point::show()方法：按输出格式输出Point对象。

// Input
// 输入多行，每行为一组坐标“x,y”，表示点的x坐标和y坐标，x和y的值都在double数据范围内。

// Output
// 输出每个Point对象的构造和析构行为。showPoint()函数用来输出（通过参数传入的）Point对象的值：X坐标在前，Y坐标在后，Y坐标前面多输出一个空格。每个坐标的输出精度为最长16位。输出格式见sample。

// C语言的输入输出被禁用。

// Sample Input
// 1,2
// 3,3
// 2,1
// Sample Output
// Point : (0, 0) is created.
// Point : (1, 2) is created.
// Point : (1, 2) is copied.
// Point : (1, 2)
// Point : (1, 2) is erased.
// Point : (1, 2) is erased.
// Point : (3, 3) is created.
// Point : (3, 3) is copied.
// Point : (3, 3)
// Point : (3, 3) is erased.
// Point : (3, 3) is erased.
// Point : (2, 1) is created.
// Point : (2, 1) is copied.
// Point : (2, 1)
// Point : (2, 1) is erased.
// Point : (2, 1) is erased.
// Point : (0, 0) is copied.
// Point : (1, 1) is created.
// Point : (0, 0) is copied.
// Point : (1, 1) is copied.
// Point : (0, 0) is copied.
// Point : (0, 0)
// Point : (1, 1)
// Point : (0, 0)
// Point : (0, 0) is erased.
// Point : (1, 1) is erased.
// Point : (0, 0) is erased.
// Point : (1, 1) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// HINT
// 思考构造函数、拷贝构造函数、析构函数的调用时机。

// Append Code
// append.cc,
