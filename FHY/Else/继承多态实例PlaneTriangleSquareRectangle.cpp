#include <iostream>
using namespace std;

class Plane
{
public:
    virtual double area()const = 0;
};

class Square: public Plane//继承自平面类Plane
{
protected:
    double side$;
public:
    Square(double s):side$(s){}
    double length()const {return side$;}
    double area()  const {return side$* side$;}
};

class Rectangle: public Square
{
protected:
    double width$;
public:
    Rectangle(double s, double w):Square(s),width$(w){}
    double area()const {return width$* side$;}
};

class Triangle: public Plane
{
protected:
    double length$, height$;
public:
    Triangle(double l, double h):length$(l), height$(h){}
    double area()const {return length$* height$;}
   
};

class Circle: public Plane
{
protected:
    double radius$;
    const double Pi = 3.1415926;
public:
    Circle(double r):radius$(r){}
    double area()const {return Pi* radius$* radius$;}
};

void showarea(Plane* &pt)
{
    cout << "=============" << endl;
    cout << "Area: " << pt-> area() << endl; 
}

int main()
{
    Plane *pp, *p2;    //祖父类指针
    Square s(12);
    Rectangle r1(2, 4);
    Plane* aplane[2] = {&s, &r1};


    pp = &s;
    cout << pp-> area() << endl;

    pp = &r1;
    cout << pp-> area() << endl;

    p2 = &r1;
    showarea(p2);//不可直接：showarea(&r1)


    return 0;
}