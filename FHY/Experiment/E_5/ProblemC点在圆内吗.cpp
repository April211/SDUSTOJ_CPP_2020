#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    int x$, y$;
public:
    Point(int x, int y):x$(x), y$(y){ numOfPoints++; cout << "The Point (" << x$ << ", " << y$ << ") is created! Now, we have " << getNumOfPoints() << " points." << endl;}
    Point(const Point& tt):x$(tt.x$), y$(tt.y$){numOfPoints++; cout << "A Point (" << x$ << ", " << y$ << ") is copied! Now, we have " << getNumOfPoints() << " points." << endl;}
    ~Point(){numOfPoints--; cout << "A Point (" << x$ << ", " << y$ << ") is erased! Now, we have " << getNumOfPoints() << " points." << endl;}
    int getX(){return x$;}
    int getY(){return y$;}
    friend class Circle;
    static int getNumOfPoints();
    static int numOfPoints;
};

int Point::numOfPoints = 0;
int Point::getNumOfPoints()
{
    return Point::numOfPoints;
}

class Circle
{
private:
    double radius$;
    Point  center$;
public:
    Circle(double x, double y, double r):radius$(r), center$(x, y){numOfCircles++;cout << "A circle at (" << center$.x$ << ", " << center$.y$ << ") and radius " << radius$ << " is created! Now, we have " << getNumOfCircles() << " circles." << endl;}
    Circle(Point tt, double r):radius$(r), center$(tt){numOfCircles++;cout << "A circle at (" << center$.x$ << ", " << center$.y$ << ") and radius " << radius$ << " is created! Now, we have " << getNumOfCircles() << " circles." << endl;}
    ~Circle(){numOfCircles--; cout << "A circle at (" << center$.x$ << ", " << center$.y$ << ") and radius " << radius$ << " is erased! Now, we have " << getNumOfCircles() << " circles." << endl;}
    double getArea()const{ double Area = PI* radius$* radius$; return Area;}
    double getRadius()const {return radius$;}
    Point& getCenter(){return center$;}
    bool pointInCircle(Point &);
    static double PI;
    static int numOfCircles;
    static int getNumOfCircles();
};

int Circle::numOfCircles = 0;
double Circle::PI = 3.14;
int Circle::getNumOfCircles(){ return Circle::numOfCircles;}
bool Circle::pointInCircle(Point &tt)
{
    int dsu;
    dsu = (tt.x$ - center$.x$)* (tt.x$ - center$.x$) + (tt.y$ - center$.y$)* (tt.y$ - center$.y$);
    if(dsu < radius$* radius$) { return true;}
    else{ return false;}
}

int main()
{
    //freopen("src.txt", "w", stdout);
    int cases,num;
    int x, y, r, px, py;
    Point aPoint(0,0), *bPoint;
    Circle aCircle(1,1,1);
    cin>>cases;
    cout<<"We have "<<Point::getNumOfPoints()<<" points and "<<Circle::getNumOfCircles()<<" circles now."<<endl;
    for (int i = 0; i < cases; i++)
    {
        cin>>x>>y>>r;
        bPoint = new Point(x,y);
        Circle circle(*bPoint, r);
        cin>>num;
        for (int j = 0; j < num; j++)
        {
            cin>>px>>py;
            if (circle.pointInCircle(*(new Point(px, py))))
            {
                cout<<"("<<px<<", "<<py<<") is in the circle at (";
                cout<<circle.getCenter().getX()<<", "<<circle.getCenter().getY()<<")."<<endl;
            }
            else
            {
                cout<<"("<<px<<", "<<py<<") is not in the circle at (";
                cout<<circle.getCenter().getX()<<", "<<circle.getCenter().getY()<<")."<<endl;
            }
        }
        delete bPoint;
    }
    cout<<"We have "<<Point::getNumOfPoints()<<" points, and "<<Circle::getNumOfCircles()<<" circles."<<endl;
    return 0;
}

/* Problem C: ����Բ����
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5418  Solved: 2846
[Submit][Status]
Description
����һ��Point���Circle�࣬�����жϸ�����һϵ�еĵ��Ƿ��ڸ�����Բ�ڡ�

���У�Point�ࣺ

1.��2����Աx��y���ֱ�Ϊ�������������ꣻ1����̬��ԱnumOfPoints�����ڼ������ɵĵ�ĸ�����

2.���й��캯�������������Ϳ������캯���������ʽ����������������жϡ�

3. ���о�̬����int getNumOfPoints()�����ڷ���numOfPoints��ֵ��

4. ����int getX()��int getY()���������ڻ�ȡ������������ꡣ

Circle�ࣺ

1. ӵ��Point��Ķ���center����ʾԲ�����ꡣӵ��radius���󣬱�ʾԲ�İ뾶��1����̬��ԱnumOfCircles������ָʾ�����˶��ٸ�Բ����

2. ���й��캯�������������Ϳ������캯���������ʽ�������������жϡ�

3.���о�̬����int getNumOfCircles()������numOfCircles��ֵ��

4. ����getCenter()����������Բ�����ꡣע�⣺�����������жϷ���ֵ���͡�

5. ����bool pointInCircle(Point &)�����������жϸ����ĵ��Ƿ��ڵ�ǰԲ�ڡ����򷵻�true�����򷵻�false��

Input
����ֶ��С�

��һ��M>0����ʾ��M������������

ÿ�����������ְ������С���1�а���3���������ֱ�Ϊһ��Բ�ĺ����ꡢ������Ͱ뾶����2��N>0����ʾ֮����N���㣬ÿ����ռһ�У��ֱ�Ϊ�������������ꡣ

���������Ϊ����������int���ͷ�Χ�ڡ�

Output
�����������ע�⣺��Բ�ı��ϵĵ㣬����Բ�ڡ�

Sample Input
2
0 0 10
3
2 2
11 11
10 0
1 1 20
3
2 2
1 1
100 100
Sample Output
The Point (0, 0) is created! Now, we have 1 points.
The Point (1, 1) is created! Now, we have 2 points.
A circle at (1, 1) and radius 1 is created! Now, we have 1 circles.
We have 2 points and 1 circles now.
The Point (0, 0) is created! Now, we have 3 points.
A Point (0, 0) is copied! Now, we have 4 points.
A Point (0, 0) is copied! Now, we have 5 points.
A circle at (0, 0) and radius 10 is created! Now, we have 2 circles.
A Point (0, 0) is erased! Now, we have 4 points.
The Point (2, 2) is created! Now, we have 5 points.
(2, 2) is in the circle at (0, 0).
The Point (11, 11) is created! Now, we have 6 points.
(11, 11) is not in the circle at (0, 0).
The Point (10, 0) is created! Now, we have 7 points.
(10, 0) is not in the circle at (0, 0).
A Point (0, 0) is erased! Now, we have 6 points.
A circle at (0, 0) and radius 10 is erased! Now, we have 1 circles.
A Point (0, 0) is erased! Now, we have 5 points.
The Point (1, 1) is created! Now, we have 6 points.
A Point (1, 1) is copied! Now, we have 7 points.
A Point (1, 1) is copied! Now, we have 8 points.
A circle at (1, 1) and radius 20 is created! Now, we have 2 circles.
A Point (1, 1) is erased! Now, we have 7 points.
The Point (2, 2) is created! Now, we have 8 points.
(2, 2) is in the circle at (1, 1).
The Point (1, 1) is created! Now, we have 9 points.
(1, 1) is in the circle at (1, 1).
The Point (100, 100) is created! Now, we have 10 points.
(100, 100) is not in the circle at (1, 1).
A Point (1, 1) is erased! Now, we have 9 points.
A circle at (1, 1) and radius 20 is erased! Now, we have 1 circles.
A Point (1, 1) is erased! Now, we have 8 points.
We have 8 points, and 1 circles.
A circle at (1, 1) and radius 1 is erased! Now, we have 0 circles.
A Point (1, 1) is erased! Now, we have 7 points.
A Point (0, 0) is erased! Now, we have 6 points.
HINT
Append Code
append.cc, */