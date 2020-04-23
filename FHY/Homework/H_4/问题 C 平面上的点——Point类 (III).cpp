#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double $x, $y;
public:
    Point(const double x = 0.0, const double y = 0.0):$x(x), $y(y){cout << "Point : (" << $x << ", " << $y << ") is created." << endl;}
    ~Point(){cout << "Point : (" << $x << ", " << $y << ") is erased." << endl;}
    Point(const Point& p):$x(p.$x), $y(p.$y){cout << "Point : (" << $x << ", " << $y << ") is copied." << endl;}
    Point(const int x):$x(x), $y(x){cout << "Point : (" << $x << ", " << $y << ") is created." << endl;}
    int show()const;
};
inline int Point::show()const
{
    cout << setprecision(16) << "Point : (" << $x << ", " << $y << ')' << endl;
    return 0;
}
int showPoint(Point &ss)
{
    Point temp(ss);
    temp.show();
    return 0;
}
int showPoint(Point &ss, Point &mm, Point &zz)
{
    Point temp0(ss); Point temp1(mm);Point temp2(zz);
    temp0.show();

    temp1.show();

    temp2.show();
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
