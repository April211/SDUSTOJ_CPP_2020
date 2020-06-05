#include <iostream>
using namespace std;


class Square
{
protected:
    double aside$;
public:
    Square(double a):aside$(a){cout << "Construct Square (" << aside$ << ')' << endl;}
    double length()const {return aside$;}
    virtual double area()  const {return aside$* aside$;}
    virtual double perimeter() const {return 4.0* aside$;}

};

class Rectangle: public Square
{
protected:
    double bside$;
public:
    Rectangle(double a, double b):Square(a),bside$(b){cout << "Construct Rectangle (" << aside$ << ", " << bside$ << ')' << endl;}
    double area()const {return aside$* bside$;}
    double perimeter() const {return 2.0* (aside$ + bside$);}
    double width()const {return bside$;}
};

class Cuboid: public Rectangle
{
protected:
    double hside$;
public:
    Cuboid(double a, double b, double h):Rectangle(a, b), hside$(h){cout << "Construct Cuboid (" << aside$ << ", " <<  bside$ << ", " << hside$ << ')' << endl;}
    double height()const {return hside$;}
    double perimeter() const {return 4.0* (aside$ + bside$ + hside$);}
    double area()const {return 2.0* (aside$* bside$ + aside$* hside$ + hside$* bside$);}
    double volume()const {return aside$* bside$* hside$;}
   
};



int main()
{
    int cases, l, w, h;
    cin >> cases;
    for(int i = 1; i <= cases; ++i)
    {
        cin >> l;
        Square squa(l);
        cout << "A Square length " << squa.length() << ", ";
        cout << "Perimeter " << squa.perimeter() << ", ";
        cout << "Area " << squa.area() << endl;
    }
 
    cout << "=========================" << endl;
 
    cin >> cases;
    for(int i = 1; i <= cases; ++i)
    {
        cin >> l >> w;
        Rectangle rect(l, w);
        cout << "A Rectangle length " << rect.length() << ", width " << rect.width() << ", ";
        cout << "Perimeter " << rect.perimeter() << ", ";
        cout << "Area " << rect.area() << endl;
    }
 
    cout << "=========================" << endl;
 
    cin >> cases;
    for(int i = 1; i <= cases; ++i)
    {
        cin >> l >> w >> h;
        Cuboid cubo(l, w, h);
        cout << "A Cuboid length " << cubo.length() << ", width " << cubo.width() << ", height " << cubo.height() << ", ";
        cout << "Perimeter " << cubo.perimeter() << ", ";
        cout << "Area " << cubo.area() << ", ";
        cout << "Volume " << cubo.volume() << endl;
    }
 
}

/* 


Problem B: �����Ρ������Ρ�������
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 4759  Solved: 3490
[Submit][Status]
Description
���������Σ�Square���������Σ�Rectangle���������壨Cuboid���ı߳������ܳ�������������
Square��ֻ���һ���߳������캯������һ��������б߳����ܳ�������ĺ�����
Rectangle����泤�Ϳ�����Square���������������ֻ������һ���ߣ����캯������һ��������г������ܳ�������ĺ�����
Cuboid����泤��ߣ�����Rectangle���������������Ҳֻ����һ���ߣ����캯������һ��������г������ߡ��ܳ������������ĺ����������ܳ�����Ϊ�����ⳤ֮�͡�
-----------------------------------------------------------------------------
����ϸ�Ķ�append.cc���룬����ƺ������Ρ������Ρ�������������ϵ��ʹmain()�����ܹ����в��õ���ȷ�������
Input
�����Ϊ�����֣�ÿһ���ֶ���һ������n��ʼ����ʾ������n��������ݡ�
�ڵ�һ���ֲ��������У�ÿ����һ����������ʾ�����εı߳���
�ڵڶ����ֲ��������У�ÿ����������������ʾ�����εĳ��Ϳ�
�ڵ������ֲ��������У�ÿ�������������� ��ʾ������ĳ��Ϳ�
Output
ÿ��������ݶ�Ӧ�����Ϊ�����֣�ǰ���ǹ��캯�����������������ͼ�ε���Ϣ����������ߡ��ܳ���������������Ϣ����ʽ��sample��

Sample Input
1
4
1
3 4
1
3 4 6
Sample Output
Construct Square (4)
A Square length 4, Perimeter 16, Area 16
=========================
Construct Square (3)
Construct Rectangle (3, 4)
A Rectangle length 3, width 4, Perimeter 14, Area 12
=========================
Construct Square (3)
Construct Rectangle (3, 4)
Construct Cuboid (3, 4, 6)
A Cuboid length 3, width 4, height 6, Perimeter 52, Area 108, Volume 72
HINT
Append Code
append.c, append.cc, */