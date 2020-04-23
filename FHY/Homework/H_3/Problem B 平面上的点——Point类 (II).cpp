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
    Point q1(q), q2(1);
    q1.show();
    q2.show();
    q.show();
}

//1,2
//3,3
//2,1
