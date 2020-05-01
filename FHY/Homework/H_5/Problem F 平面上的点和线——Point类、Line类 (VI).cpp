#include <bits/stdc++.h>
using namespace std;

class Point
{

private:
    double x$, y$;
public:
    Point(double x, double y):x$(x), y$(y){cout << "Point : (" << x$ << ", " << y$ << ')' << " is created." << endl;}
    Point():x$(0), y$(0){cout << "Point : (" << x$ << ", " << y$ << ')' << " is created." << endl;}
    Point(const Point &tt):x$(tt.x$), y$(tt.y$){cout << "Point : (" << x$ << ", " << y$ << ')' << " is copied." << endl;}
    ~Point(){cout << "Point : (" << x$ << ", " << y$ << ')' << " is erased." << endl;}
    void show()const;
    double x()const{return x$;}
    double y()const{return y$;}
    void showNoEndOfLine()const;
    friend class Line;

};

void Point::showNoEndOfLine()const
{
    cout << "Point : (" << x$ << ", " << y$ << ')';
}
inline void Point::show()const
{
    cout << "Point : (" << x$ << ", " << y$ << ')' << endl;
}

class Line
{
private:
    Point pt1$, pt2$;
public:
    Line(double x1, double y1, double x2, double y2):pt1$(x1, y1), pt2$(x2, y2){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is created." << endl;}
    Line():pt1$(0, 0), pt2$(0, 0){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is created." << endl;}
    Line(Point &tt1, Point &tt2):pt1$(tt1), pt2$(tt2){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is created." << endl;}
    Line(const Line &tt):pt1$(tt.pt1$), pt2$(tt.pt2$){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is copied." << endl;}
    ~Line(){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is erased." << endl;}
    const Line& show()const;
    Line& setLine(double, double, double, double);
    Line& setLine(const Point &, const Point &);
    Line& setLine(const Line&);
    const Point& start()const;//������ȡLine�����
    const Point& end()const;//������ȡLine���յ�
    void setStart(Point&);//����������Line�����
    void setEnd(Point&);//����������Line���յ�
    void readLine();
    friend class Point;


};

inline const Point& Line::start()const//������ȡLine�����
{
    return pt1$;
}
inline const Point& Line::end()const//������ȡLine���յ�
{
    return pt2$;
}
inline void Line::setStart(Point& tt)//����������Line�����
{
    pt1$.x$ = tt.x$; pt1$.y$ = tt.y$;
}
inline void Line::setEnd(Point& tt)//����������Line���յ�
{
    pt2$.x$ = tt.x$; pt2$.y$ = tt.y$;
}

inline Line& Line::setLine(double x1, double y1, double x2, double y2)
{
    pt1$.x$ = x1; pt1$.y$ = y1;
    pt2$.x$ = x2; pt2$.y$ = y2;
    return *this;
}

inline Line& Line::setLine(const Point &tt1, const Point &tt2)
{
    pt1$.x$ = tt1.x$; pt1$.y$ = tt1.y$;
    pt2$.x$ = tt2.x$; pt2$.y$ = tt2.y$;
    return *this;
}

inline Line& Line::setLine(const Line& ttl)
{
    pt1$.x$ = ttl.pt1$.x$; pt1$.y$ = ttl.pt1$.y$;
    pt2$.x$ = ttl.pt2$.x$; pt2$.y$ = ttl.pt2$.y$;
    return *this;
}

inline void Line::readLine()
{
    double x1, x2, y1, y2;
    char tt;
    cin >> x1 >> tt >> y1;
    cin >> x2 >> tt >> y2;
    pt1$.x$ = x1; pt1$.y$ = y1;
    pt2$.x$ = x2; pt2$.y$ = y2;
}

inline const Line& Line::show()const
{
    cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << endl;
    return *this;
}




void showLineCoordinate(const Line& line)
{
    std::cout<<"Line : ";
    std::cout<<"("<<line.start().x()<<", "<<line.start().y()<<")";
    std::cout<<" to ";
    std::cout<<"("<<line.end().x()<<", "<<line.end().y()<<")";
    std::cout<<std::endl;
}

void showLinePoint(const Line& line)
{
    std::cout<<"Line : ";
    line.start().showNoEndOfLine();
    std::cout<<" to ";
    line.end().showNoEndOfLine();
    std::cout<<std::endl;
}

void showLine(const Line& line)
{
    line.show();
}

int main()
{
    int num, i;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin>>num;
    Line line[num + 1];
    for(i = 1; i <= num; i++)
    {
        line[i].readLine();
        showLine(line[i]);
    }
    Line l1(p, q), l2(p,t), l3(q,t), l4(l1);
    showLineCoordinate(l1);
    showLinePoint(l2);
    showLinePoint(l3.setLine(l1));
    showLineCoordinate(l4.setLine(t,q));
    line[0].setStart(t);
    line[0].setEnd(q);
}




//Problem F: ƽ���ϵĵ���ߡ���Point�ࡢLine�� (VI)
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 7459  Solved: 3414
//[Submit][Status]
//Description
//����ѧ�ϣ�ƽ��ֱ������ϵ�ϵĵ���X���Y���ϵ���������ֵΨһȷ��������ȷ��һ���߶Ρ��������Ƿ�װһ����Point�ࡱ�͡�Line�ࡱ��ʵ��ƽ���ϵĵ�Ĳ�����
//���ݡ�append.cc�������Point���Line��Ĺ��췽����show()�����������Line�����Point����Ĺ������������
//�ӿ�������
//Point::show()����������ʽ���Point����
//Point::x()������ȡx���ꡣ
//Point::y()������ȡy���ꡣ
//Line::show()����������ʽ���Line����
//Line::SetLine(double, double, double, double)����������Line��������x,y���꣨��һ���͵ڶ����������յ��x,y���꣨�������͵��ĸ����꣩�������ر�����
//Line::SetLine(const Point &, const Point &)����������Line�������㣨��һ�����������յ㣨�ڶ������꣩�������ر�����
//Line::SetLine(const Line&)����������Line���󣬸��Ʋ��������꣬�����ر�����
//Line::readLine()�������ӱ�׼�����϶������꣬��ʽ��Sample
//Line::start()������ȡLine�����
//Line::end()������ȡLine���յ�
//Line::setStart()����������Line�����
//Line::setEnd()����������Line���յ�
//�������������������Line���󣬸�ʽͬsample
//showLineCoordinate(const Line&)
//showLinePoint(const Line&)
//showLine(const Line&)
//Input
//����ĵ�һ��ΪN����ʾ������N�в���������
//ÿ��Ϊ�������ꡰx,y�����ֱ��ʾ�߶������յ��x�����y���꣬�����������һ���ո�ֿ���x��y��ֵ����double���ݷ�Χ�ڡ�
//Output
//���Ϊ���У�ÿ��Ϊһ���߶Σ����������ǰ�յ������ں�ÿ�����X������ǰ��Y�����ں�Y����ǰ������һ���ո������Ű��������������ʽ��sample��
//C���Ե�������������á�
//Sample Input
//4
//0,0 1,1
//1,1 2,3
//2,3 4,5
//0,1 1,0
//Sample Output
//Point : (1, -2) is created.
//Point : (2, -1) is created.
//Point : (0, 0) is created.
//Point : (0, 0)
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Point : (0, 0) is created.
//Point : (0, 0) is created.
//Line : (0, 0) to (0, 0) is created.
//Line : (0, 0) to (1, 1)
//Line : (1, 1) to (2, 3)
//Line : (2, 3) to (4, 5)
//Line : (0, 1) to (1, 0)
//Point : (1, -2) is copied.
//Point : (2, -1) is copied.
//Line : (1, -2) to (2, -1) is created.
//Point : (1, -2) is copied.
//Point : (0, 0) is copied.
//Line : (1, -2) to (0, 0) is created.
//Point : (2, -1) is copied.
//Point : (0, 0) is copied.
//Line : (2, -1) to (0, 0) is created.
//Point : (1, -2) is copied.
//Point : (2, -1) is copied.
//Line : (1, -2) to (2, -1) is copied.
//Line : (1, -2) to (2, -1)
//Line : Point : (1, -2) to Point : (0, 0)
//Line : Point : (1, -2) to Point : (2, -1)
//Line : (0, 0) to (2, -1)
//Line : (0, 0) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (0, 0) is erased.
//Line : (1, -2) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//Line : (1, -2) to (0, 0) is erased.
//Point : (0, 0) is erased.
//Point : (1, -2) is erased.
//Line : (1, -2) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//Line : (0, 1) to (1, 0) is erased.
//Point : (1, 0) is erased.
//Point : (0, 1) is erased.
//Line : (2, 3) to (4, 5) is erased.
//Point : (4, 5) is erased.
//Point : (2, 3) is erased.
//Line : (1, 1) to (2, 3) is erased.
//Point : (2, 3) is erased.
//Point : (1, 1) is erased.
//Line : (0, 0) to (1, 1) is erased.
//Point : (1, 1) is erased.
//Point : (0, 0) is erased.
//Line : (0, 0) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (0, 0) is erased.
//Point : (0, 0) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//HINT
//Append Code
//append.cc,
