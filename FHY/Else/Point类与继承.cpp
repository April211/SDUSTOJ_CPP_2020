#include <bits/stdc++.h>
using namespace std;

class Point 
{
protected://��private, �ɼ̳У��������಻�ɷ���
    double x$, y$;
public:
    Point(double x, double y):x$(x), y$(y){}
    ~Point(){}
    double getX()const {return x$;}  
    double getY()const {return y$;}
    void   setX(double x) { x$ = x;}
    void   setY(double y) { y$ = y;}   
    Point& setPoint(double x, double y){x$ = x, y$ = y; return *this;}

};

class Point3D: public Point  //�������ּ̳з�ʽ��private, public, protected.
{
private:
    double z$;
public:
    Point3D():Point(0, 0), z$(0){cout << "A default 3DPoint was created: " << x$ << y$ << z$ << endl;}//x, u�ýӿ�������
    Point3D(double x, double y, double z):Point(x, y), z$(z){ cout << "A 3DPoint was created: " << getX() << getX() << z$ << endl;}
    double getZ(){return z$;}
};
int main()
{
    Point3D p3d(1,0,1);
                                    //p3d.Point::show();
                                    //����ָ�����ָ�������࣬���ʵ��Ǹ���������еĳ�Ա
    return 0;
}