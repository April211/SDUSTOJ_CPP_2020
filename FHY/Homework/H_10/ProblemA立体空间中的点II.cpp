#include <iostream>
using namespace std;

class Point 
{
protected:
    double x$, y$;
public:
    Point():x$(0.0), y$(0.0){ ++cnt1;}
    Point(double x, double y):x$(x), y$(y){ ++cnt1;}
    ~Point(){}
    //
    double x()const { return x$;}  
    double y()const { return y$;}
    double x(double x) { x$ = x; return x$;}
    double y(double y) { y$ = y; return y$;}   
    void showPoint()const;
    //
    static int cnt1;
    static int showNumber(){ return cnt1;}

};

int Point::cnt1 = 0;

inline void Point::showPoint()const
{
    cout << "2D Point (" << x$ << "," << y$ << ')' << endl;
}

class Point_3D: public Point
{
private:
    double z$;
public:
    Point_3D():Point(0, 0), z$(0){ ++cnt2;}
    Point_3D(double x, double y, double z):Point(x, y), z$(z){ ++cnt2;}
    //
    double z(){ return z$;}
    double z(double z){ z$ = z; return z$;}
    void setPoint(double x, double y, double z){ x$ = x; y$ = y; z$ = z; }
    void showPoint()const;
    //
    static int cnt2;
    static int showNumber(){ return cnt2;}
};

int Point_3D::cnt2 = 0;

inline void Point_3D::showPoint()const
{
    cout << "3D Point (" << x$ << "," << y$ << "," << z$ << ')' << endl;
}

int main()
{
    cout<<"Invariable test output :"<<endl;
    Point_3D p3d;
    p3d.setPoint(-100, 0, 100);
    p3d.showPoint();
    p3d.x(0);
    p3d.y(100);
    cout<<"Point ("<<p3d.x()<<","<<p3d.y()<<","<<p3d.z()<<")"<<endl;
    cout<<"\nTest data output :"<<endl;
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; i++)
    {
        double x, y, z;
        int point_type;
        cin>>point_type;
        if(point_type == 2)
        {
            cin>>x>>y;
            Point p(x, y);
            p.showPoint();
        }
        if(point_type == 3)
        {
            cin>>x>>y>>z;
            Point_3D p(x, y, z);
            p.showPoint();
        }
    }
    cout<<"Number of 2D Points : "<<Point::showNumber() - Point_3D::showNumber()<<endl;
    cout<<"Number of 3D Points : "<<Point_3D::showNumber() - 1<<endl;
}

/* 

Problem A: ����ռ��еĵ㣨II��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5109  Solved: 4044
[Submit][Status]
Description
���һ��ƽ���ϵĵ�Point���3ά�ĵ�Point_3D�࣬����Point_3D��̳���Point�࣬���ڶ�ȡ��������ݣ��������������ֵ�����ꡣ��ͳ����������ֵ�ĸ�����
���Point����֧��һ�²�����
Point::Point()�޲ι��졣
Point::Point(double,double)��������������졣
Point::x()����x����
Point::y()����y����
Point::x(int)�޸�x���겢����
Point::y(int)�޸�y���겢����
Point::showPoint()����ʽ���Point����
Point::showNumber()����Point���������ľ�̬����
���Point_3D����֧��һ�²�����
Point_3D::Point_3D()�޲ι��졣
Point_3D::Point_3D(double,double,double)��������������졣
Point_3D::z()����z���ꡣ
Point_3D::z(int)�޸�z���겢���ء�
Point_3D::showPoint()����ʽ���Point_3D����
Point_3D::setPoint(double,double,double)����������������޸�Point_3D��������ꡣ
Point_3D::showNumber()����Point_3D���������ľ�̬������
-----------------------------------------------------------------------------
�����Point���Point_3D�࣬ʹ��main()�����ܹ���ȷ���С�
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()������
Input
����ĵ�һ������n����ʾ��n��������ݣ����������ÿ��Ϊһ��������ݡ�ÿ��������ݵĵ�һ����һ������m��m������ȡֵ��2��3��mΪ2ʱ������������������x��y����ʾһ��ƽ���ϵĵ������(x,y)��mΪ3ʱ������3��������x��y��z����ʾһ��3ά�ĵ������(x,y,z)��
Output
��ʼ����Ϊ��main()���������Ĺ̶���������ڲ��Զ����ĳЩ�����ĵ�������������Test data output :��֮��Ϊ�������ݶ�Ӧ�������
ÿ��������ݶ�Ӧһ�������
������Ϊƽ���ϵĵ㣬���������2D Point (x,y)����x��yΪ���������ֵ��
������Ϊ3ά�ĵ㣬���������3D Point (x,y,y)����x��y��zΪ���������ֵ��
��󣬷ֱ�����ܹ������ƽ���ϵĵ�����3ά�ĵ�����
Sample Input
5
3 1 2 3
3 0 0 0
2 -1 1
3 -1 -1 -1
2 0 0
Sample Output
Invariable test output :
3D Point (-100,0,100)
Point (0,100,100)

Test data output :
3D Point (1,2,3)
3D Point (0,0,0)
2D Point (-1,1)
3D Point (-1,-1,-1)
2D Point (0,0)
Number of 2D Points : 2
Number of 3D Points : 3
HINT
Append Code
append.cc, */