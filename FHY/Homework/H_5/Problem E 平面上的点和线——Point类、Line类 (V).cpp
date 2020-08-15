#include <bits/stdc++.h>
using namespace std;

class Point
{

private:
    double x$, y$;
public:
    Point(double x, double y):x$(x), y$(y){cout << "Point : (" << x$ << ", " << y$ << ')' << " is created." << endl;}
    Point():x$(0), y$(0){cout << "Point : (" << x$ << ", " << y$ << ')' << " is created." << endl;}
    Point(const Point &tt):x$(tt.x$), y$(tt.y$){cout << "Point : (" << x$ << ", " << y$ << ')' << " is copied." << endl;}
    ~Point(){cout << "Point : (" << x$ << ", " << y$ << ')' << " is erased." << endl;}
    void show()const;
    friend class Line;
};
inline void Point::show()const
{
    cout << "Point : (" << x$ << ", " << y$ << ')' << endl;
}

class Line
{
private:
    Point pt1$, pt2$;
public:
    Line(double x1, double y1, double x2, double y2):pt1$(x1, y1), pt2$(x2, y2){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is created." << endl;}
    Line():pt1$(0, 0), pt2$(0, 0){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is created." << endl;}
    Line(Point &tt1, Point &tt2):pt1$(tt1), pt2$(tt2){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is created." << endl;}
    Line(const Line &tt):pt1$(tt.pt1$), pt2$(tt.pt2$){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is copied." << endl;}
    ~Line(){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is erased." << endl;}
    Line& show();
    Line& setLine(double, double, double, double);
    Line& setLine(const Point &, const Point &);
    Line& setLine(const Line&);
    void readLine();
    friend class Point;


};

inline Line& Line::setLine(double x1, double y1, double x2, double y2)
{
    pt1$.x$ = x1; pt1$.y$ = y1;
    pt2$.x$ = x2; pt2$.y$ = y2;
    return *this;
}

inline Line& Line::setLine(const Point &tt1, const Point &tt2)
{
    pt1$.x$ = tt1.x$; pt1$.y$ = tt1.y$;
    pt2$.x$ = tt2.x$; pt2$.y$ = tt2.y$;
    return *this;
}

inline Line& Line::setLine(const Line& ttl)
{
    pt1$.x$ = ttl.pt1$.x$; pt1$.y$ = ttl.pt1$.y$;
    pt2$.x$ = ttl.pt2$.x$; pt2$.y$ = ttl.pt2$.y$;
    return *this;
}

inline void Line::readLine()
{
    double x1, x2, y1, y2;
    char tt;
    cin >> x1 >> tt >> y1;
    cin >> x2 >> tt >> y2;
    pt1$.x$ = x1; pt1$.y$ = y1;
    pt2$.x$ = x2; pt2$.y$ = y2;
}

inline Line& Line::show()
{
    cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << endl;
    return *this;
}


int main()
{
    int num, i;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin>>num;
    Line line[num];
    for(i = 0; i < num; i++)
    {
        line[i].readLine();
        line[i].show();
    }
    Line l1(p, q), l2(p,t), l3(q,t), l4(l1);
    l1.show();
    l2.setLine(l1).show();
    l3.show();
    l4.setLine(t,q).show();
}



//Problem E: 平面上的点和线——Point类、Line类 (V)
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 8879  Solved: 4454
//[Submit][Status]
//Description
//在数学上，平面直角坐标系上的点用X轴和Y轴上的两个坐标值唯一确定，两点确定一条线段。现在我们封装一个“Point类”和“Line类”来实现平面上的点的操作。
//根据“append.cc”，完成Point类和Line类的构造方法和show()方法，输出各Line对象和Point对象的构造和析构次序。
//接口描述：
//Point::show()方法：按格式输出Point对象。
//Line::show()方法：按格式输出Line对象。
//Line::SetLine(double, double, double, double)方法：设置Line对象起点的x,y坐标（第一个和第二参数）和终点的x,y坐标（第三个和第四个坐标），并返回本对象
//Line::SetLine(const Point &, const Point &)方法：设置Line对象的起点（第一个参数）和终点（第二个坐标），并返回本对象
//Line::SetLine(const Line&)方法：设置Line对象，复制参数的坐标，并返回本对象
//Line::readLine()方法：从标准输入上读入坐标，格式见Sample
//Input
//输入的第一行为N，表示后面有N行测试样例。
//每行为两组坐标“x,y”，分别表示线段起点和终点的x坐标和y坐标，两组坐标间用一个空格分开，x和y的值都在double数据范围内。
//Output
//输出为多行，每行为一条线段，起点坐标在前终点坐标在后，每个点的X坐标在前，Y坐标在后，Y坐标前面多输出一个空格，用括号包裹起来。输出格式见sample。
//C语言的输入输出被禁用。
//Sample Input
//4
//0,0 1,1
//1,1 2,3
//2,3 4,5
//0,1 1,0
//Sample Output
//Point : (1, -2) is created.
//Point : (2, -1) is created.
//Point : (0, 0) is created.
//Point : (0, 0)
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Line : (0, 0) to (1, 1)
//Line : (1, 1) to (2, 3)
//Line : (2, 3) to (4, 5)
//Line : (0, 1) to (1, 0)
//Point : (1, -2) is copied.
//Point : (2, -1) is copied.
//Line : (1, -2) to (2, -1) is created.
//Point : (1, -2) is copied.
//Point : (0, 0) is copied.
//Line : (1, -2) to (0, 0) is created.
//Point : (2, -1) is copied.
//Point : (0, 0) is copied.
//Line : (2, -1) to (0, 0) is created.
//Point : (1, -2) is copied.
//Point : (2, -1) is copied.
//Line : (1, -2) to (2, -1) is copied.
//Line : (1, -2) to (2, -1)
//Line : (1, -2) to (2, -1)
//Line : (2, -1) to (0, 0)
//Line : (0, 0) to (2, -1)
//Line : (0, 0) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (0, 0) is erased.
//Line : (2, -1) to (0, 0) is erased.
//Point : (0, 0) is erased.
//Point : (2, -1) is erased.
//Line : (1, -2) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//Line : (1, -2) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//Line : (0, 1) to (1, 0) is erased.
//Point : (1, 0) is erased.
//Point : (0, 1) is erased.
//Line : (2, 3) to (4, 5) is erased.
//Point : (4, 5) is erased.
//Point : (2, 3) is erased.
//Line : (1, 1) to (2, 3) is erased.
//Point : (2, 3) is erased.
//Point : (1, 1) is erased.
//Line : (0, 0) to (1, 1) is erased.
//Point : (1, 1) is erased.
//Point : (0, 0) is erased.
//Point : (0, 0) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//HINT
//Append Code
//append.cc,
