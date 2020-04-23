#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    Point(double x = 0.0, double y = 0.0):_x(x), _y(y){};
    ~Point(){};
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
