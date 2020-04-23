#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double $x, $y;
public:
    Point(const double x = 0.0, const double y = 0.0):$x(x), $y(y){}
    int show()const;
};
inline int Point::show()const
{
    cout << setprecision(16) << "Point : (" << $x << ", " << $y << ')' << endl;
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
        p.show();
    }
    q.show();
}
