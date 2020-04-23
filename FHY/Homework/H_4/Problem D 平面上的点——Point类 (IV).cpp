#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double $x, $y;
public:
    Point(const double x = 0.0, const double y = 0.0):$x(x), $y(y){ counter++; ++sums;}
    ~Point(){counter--;}
    Point(const Point& p):$x(p.$x), $y(p.$y){counter++; ++sums;}
    Point(const int x):$x(x), $y(x){counter++; ++sums;}
    static int showCounter();
    static int showSumOfPoint();
    static int sums;
    static int counter;
    int show()const;
};
inline int Point::show()const
{
    cout << setprecision(16) << "Point : (" << $x << ", " << $y << ')' << endl;
    return 0;
}
inline int Point::showCounter()
{
    cout << "Current : " << Point::counter << " points." << endl;
    return 0;
}
inline int Point::showSumOfPoint()
{
    cout << "In total : " << Point::sums << " points." << endl;
    return 0;
}

int showPoint(const Point &ss, const Point &mm, const Point &zz)
{
    ss.show();
    mm.show();
    zz.show();
    return 0;
}
int Point::counter = 0;
int Point::sums = 0;

int main()
{
    char c;
    double a, b;
    Point q;
    while(std::cin>>a>>c>>b)
    {
        Point p(a, b);
        p.show();
        p.showCounter();
    }
    q.showSumOfPoint();
    Point q1(q), q2(1);
    Point::showCounter();
    showPoint(q1, q2, q);
    Point::showSumOfPoint();
}
