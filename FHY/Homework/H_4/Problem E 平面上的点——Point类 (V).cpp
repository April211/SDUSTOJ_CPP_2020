#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double $x, $y;
    int is;
public:
    Point(const double x, const double y):$x(x), $y(y){ ++sums;is = sums;}
    Point(const double x):$x(x), $y(x){ ++sums;is = sums;}
    Point():$x(0), $y(0){ ++sums;is = sums;}
    ~Point(){}
    Point(const Point& p):$x(p.$x), $y(p.$y){ ++sums;is = sums;}

    double x()const;
    double y()const;
    double x(double);
 //   double y(double);
    double getX()const;
    double getY()const;
    double setX(double);
    double setY(double);
    Point& setPoint(double,double);
    static int showSumOfPoint();
    static int sums;
    int show()const;
};

    double Point::x()const{return $x;}
    double Point::y()const{return $y;}
    double Point::x(double tt){$x = tt; return tt;}
//    double Point::y(double tt){$y = tt; return $y;}
    double Point::getX()const{return $x;}
    double Point::getY()const{return $y;}
    double Point::setX(double tt){$x = tt; return tt;}
    double Point::setY(double tt){$y = tt; return tt;}
    Point& Point::setPoint(double ss,double tt){$x = ss; $y = tt; return *this;}



inline int Point::show()const
{
    cout << setprecision(16) << "Point[" << is << "] : (" << $x << ", " << $y << ')' << endl;
    return 0;
}

inline int Point::showSumOfPoint()
{
    cout << "In total : " << Point::sums << " points." << endl;
    return 0;
}

int Point::sums = 0;


void ShowPoint(Point p)
{
    cout<<std::setprecision(16)<<"Point : ("<<p.x()<<", "<<p.y()<<")"<<endl;
}

void ShowPoint(double x, double y)
{
    Point p(x, y);
    cout<<std::setprecision(16)<<"Point : ("<<p.x()<<", "<<p.y()<<")"<<endl;
}

void ShowPoint(Point &p, double x, double y)
{
    cout<<std::setprecision(16)<<"Point : ("<<p.x(x)<<", "<<p.x(y)<<")"<<endl;
}

int main()
{
    int l(0);
    char c;
    double a, b;
    Point pt[60];
    while(std::cin>>a>>c>>b)
    {
        if(a == b)
            ShowPoint(pt[l].setPoint(a, b));
        if(a > b)
            ShowPoint(a, b);
        if(a < b)
            ShowPoint(pt[l], a, b);
        l++;
    }     //l == 3
 //   cout << "***" << pt[0].x() << pt[0].y()<< pt[1].x()<< pt[1].y()<< pt[2].x()<< pt[2].y()<< pt[3].x() << pt[3].y()<< endl;
    Point p(a), q(b);
    ShowPoint(q);
    double x(0), y(0);
    for(int i = 0; i < l; i++)
        x += pt[i].getX(), y -= pt[i].getY();
  //      cout << "***" << x << y << endl;
    ShowPoint(pt[l].setX(x), pt[l].setY(y));
    cout<<"==========gorgeous separator=========="<<endl;
    for(int i = 0; i <= l; i++)
        pt[i].show();
    q.setPoint(q.x() - p.x() + a, q.y() - p.y() + b).show();
    q.show();
    cout<<"==========gorgeous separator=========="<<endl;
    p.showSumOfPoint();
}
