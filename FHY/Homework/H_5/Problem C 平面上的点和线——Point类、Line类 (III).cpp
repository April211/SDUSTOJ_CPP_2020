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
    friend class Line;
};
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
    Line(Point &tt1, Point &tt2):pt1$(tt1), pt2$(tt2){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is created." << endl;}
    ~Line(){cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << " is erased." << endl;}
    void show()const;
    friend class Point;


};

inline void Line::show()const
{
    cout << "Line : (" << pt1$.x$ << ", " << pt1$.y$ << ") to (" << pt2$.x$ << ", " << pt2$.y$  << ')' << endl;
}







int main()
{
    char c;
    int num, i;
    double x1, x2, y1, y2;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin>>num;
    for(i = 1; i <= num; i++)
    {
        std::cout<<"=========================\n";
        std::cin>>x1>>c>>y1>>x2>>c>>y2;
        Line line(x1, y1, x2, y2);
        line.show();
    }
    std::cout<<"=========================\n";
    Line l1(p, q), l2(p, t), l3(q, t), l4(t, q);
    l1.show();
    l2.show();
    l3.show();
    l4.show();
}


//Problem C: ƽ���ϵĵ���ߡ���Point�ࡢLine�� (III)
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 8967  Solved: 4420
//[Submit][Status]
//Description
//����ѧ�ϣ�ƽ��ֱ������ϵ�ϵĵ���X���Y���ϵ���������ֵΨһȷ��������ȷ��һ���߶Ρ��������Ƿ�װһ����Point�ࡱ�͡�Line�ࡱ��ʵ��ƽ���ϵĵ�Ĳ�����
//���ݡ�append.cc�������Point���Line��Ĺ��췽����show()�����������Line�����Point����Ĺ������������
//�ӿ�������
//Point::show()����������ʽ���Point����
//Line::show()����������ʽ���Line����
//Input
//����ĵ�һ��ΪN����ʾ������N�в���������ÿ��Ϊ�������ꡰx,y�����ֱ��ʾ�߶������յ��x�����y���꣬�����������һ���ո�ֿ���x��y��ֵ����double���ݷ�Χ�ڡ�
//
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
//=========================
//Point : (0, 0) is created.
//Point : (1, 1) is created.
//Line : (0, 0) to (1, 1) is created.
//Line : (0, 0) to (1, 1)
//Line : (0, 0) to (1, 1) is erased.
//Point : (1, 1) is erased.
//Point : (0, 0) is erased.
//=========================
//Point : (1, 1) is created.
//Point : (2, 3) is created.
//Line : (1, 1) to (2, 3) is created.
//Line : (1, 1) to (2, 3)
//Line : (1, 1) to (2, 3) is erased.
//Point : (2, 3) is erased.
//Point : (1, 1) is erased.
//=========================
//Point : (2, 3) is created.
//Point : (4, 5) is created.
//Line : (2, 3) to (4, 5) is created.
//Line : (2, 3) to (4, 5)
//Line : (2, 3) to (4, 5) is erased.
//Point : (4, 5) is erased.
//Point : (2, 3) is erased.
//=========================
//Point : (0, 1) is created.
//Point : (1, 0) is created.
//Line : (0, 1) to (1, 0) is created.
//Line : (0, 1) to (1, 0)
//Line : (0, 1) to (1, 0) is erased.
//Point : (1, 0) is erased.
//Point : (0, 1) is erased.
//=========================
//Point : (1, -2) is copied.
//Point : (2, -1) is copied.
//Line : (1, -2) to (2, -1) is created.
//Point : (1, -2) is copied.
//Point : (0, 0) is copied.
//Line : (1, -2) to (0, 0) is created.
//Point : (2, -1) is copied.
//Point : (0, 0) is copied.
//Line : (2, -1) to (0, 0) is created.
//Point : (0, 0) is copied.
//Point : (2, -1) is copied.
//Line : (0, 0) to (2, -1) is created.
//Line : (1, -2) to (2, -1)
//Line : (1, -2) to (0, 0)
//Line : (2, -1) to (0, 0)
//Line : (0, 0) to (2, -1)
//Line : (0, 0) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (0, 0) is erased.
//Line : (2, -1) to (0, 0) is erased.
//Point : (0, 0) is erased.
//Point : (2, -1) is erased.
//Line : (1, -2) to (0, 0) is erased.
//Point : (0, 0) is erased.
//Point : (1, -2) is erased.
//Line : (1, -2) to (2, -1) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//Point : (0, 0) is erased.
//Point : (2, -1) is erased.
//Point : (1, -2) is erased.
//HINT
//Append Code
//append.cc,

