#include <iostream>
#include <iomanip>
using namespace std;

class Shape//������
{
public:
    virtual void show()const = 0;//��ʾ��XX��
};

class Solid: virtual public Shape//������
{
public:
    virtual double volume()const = 0;
};

class Plane: virtual public Shape//������
{
public:
    virtual double area()const = 0;
    virtual double perimeter()const = 0;
};

class Square: public Plane//�̳���ƽ����Plane
{
protected:
    double side$;
public:
    Square(double s):side$(s){}
    double length()const { return side$;}
    double area()  const { return side$* side$;}
    double perimeter()const {return 2.0* (side$ + side$);}
    void show()const {cout << "Square's Area: " << area() << endl;}//��ʾ��XX��

};

class Rectangle: public Square
{
protected:
    double width$;
public:
    Rectangle(double s, double w):Square(s), width$(w){}
    double area()const {return width$* side$;}
    double perimeter()const {return 2.0* (width$ + side$);}
    void show()const {cout << "Rectangle's Area: " << area() << endl;}
};

class Cube: public Square, public Solid //�����������
{
protected:
    //
public:
    Cube(double s):Square(s){}
    double area()const {return 6.0* side$* side$;}
    double perimeter()const {return 12.0* side$;}
    double volume()const {return side$* side$* side$;}
    void show()const {cout << "Cube's Area: " << area() << endl;}

};


class Circle: public Plane
{
protected:
    double radius$;
    const double Pi = 3.1415926;
public:
    Circle(double r):radius$(r){}
    double area()const {return Pi* radius$* radius$;}
    double perimeter()const {return 2.0* Pi* radius$;}
    void   show()const {cout << "Circle's Area: " << area() << endl;}
};

class Sphere: public Circle, public Solid //��
{
protected:
    //
public:
    Sphere(double r):Circle(r){}
    double volume()const {return (4.0* Pi* radius$* radius$* radius$)/3.0;}
    double area()const {return 4.0* Pi* radius$* radius$;}
    void   show()const {cout << "Sphere's Area: " << area() << endl;}

};


void Shape_Show(Shape* pt)
{
    pt-> show(); 
}

int main()
{
    Shape *sp;   //ֻ�ܷ���show()
    Square sq1(12);
    Rectangle rc1(2, 3);
    Cube cb1(1);
    Sphere se1(1);
    cout << fixed << setprecision(4);
    sq1.show();
    rc1.show();
    cb1.show();
    cout << "================" << endl;
    sp = &sq1;
    sp->show();
    sp = &rc1;
    sp->show();
    sp = &cb1;
    sp->show();//ͬһ���ƵĽӿڣ�ʵ�ֶ�̬
    cout << "================" << endl;
    Shape_Show(&sq1);
    sp = &se1;
    Shape_Show(sp);
    cout << "================" << endl;




    return 0;
}