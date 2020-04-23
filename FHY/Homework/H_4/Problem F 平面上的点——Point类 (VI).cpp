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

    bool isEqual(Point&)const;//方法：判断传入的参数与对象的坐标是否相同，相同返回true。
    Point& copy(Point&);//方法：传参数复制给对象。
    Point& inverse();
    Point& inverse(Point&);

    double x()const;
    double y()const;
    double x(double);
    double y(double);
    Point& setPoint(double,double);
    static int showSumOfPoint();
    static int sums;
    int show()const;
};

    double Point::x()const{return $x;}
    double Point::y()const{return $y;}
    double Point::x(double tt){$x = tt; return tt;}
    double Point::y(double tt){$y = tt; return $y;}
    Point& Point::setPoint(double ss,double tt){$x = ss; $y = tt; return *this;}
    bool Point::isEqual(Point &tt)const//方法：判断传入的参数与对象的坐标是否相同，相同返回true。
    {
        if((tt.x() == $x) && (tt.y() == $y))
            return true;
        else
            return false;
    }
    Point& Point::copy(Point &tt)//方法：传参数复制给对象。
    {
        this -> $x = tt.x();
        this -> $y = tt.y();
        return *this;
    }
    Point& Point::inverse()//有两个版本：不传参数则将对象自身的x坐标和y坐标互换；
    {
        double tt;
        tt = $x;
        $x = $y;
        $y = tt;
        return *this;

    }
    Point& Point::inverse(Point& tt)//若将Point对象做参数传入，则将传入对象的坐标交换复制给对象自身，不修改参数的值。
    {
        this -> $x = tt.y();
        this -> $y = tt.x();
        return *this;

    }



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


void ShowPoint(const Point &p)
{
    cout<<std::setprecision(16)<<"Point : ("<<p.x()<<", "<<p.y()<<")"<<endl;
}

void ShowPoint(double x, double y)
{
    cout<<std::setprecision(16)<<"Point : ("<<x<<", "<<y<<")"<<endl;
}

int main()
{
    int l(0);
    char c;
    double a, b;
    Point p, q, pt[60];
    while(std::cin>>a>>c>>b)
    {
        if(a == b)
            p.copy(pt[l].setPoint(a, b));
        if(a > b)
            p.copy(pt[l].setPoint(a, b).inverse());
        if(a < b)
            p.inverse(pt[l].setPoint(a, b));
        if(a < 0)
            q.copy(p).inverse();
        if(b < 0)
            q.inverse(p).copy(pt[l]);
        pt[l++].show();
        p.show();
    }
    q.show();
    cout<<"==========gorgeous separator=========="<<endl;
    double x(0), y(0);
    for(int i = 0; i < l; i++)
        x += pt[i].x(), y -= pt[i].y();
    pt[l].x(y), pt[l].y(x);
    q.copy(pt[l]).show();
    for(int i = 0; i <= l; i++)
        pt[i].show();
    cout<<"==========gorgeous separator=========="<<endl;
    const Point const_point(3, 3);
    const_point.show();
    for(int i = 0; i <= l; i++)
    {
        if(const_point.isEqual(pt[i]))
        {
            ShowPoint(const_point);
            ShowPoint(const_point.x(), const_point.y());
            ShowPoint(Point(const_point.x(), const_point.y()));
        }
    }
    const_point.showSumOfPoint();
}
