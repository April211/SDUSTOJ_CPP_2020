#include <bits/stdc++.h>
using namespace std;

class Point
{

private:
    double x$, y$;
public:
    Point(double x, double y):x$(x), y$(y){++sumofpt; ++nowptcnt; }
    Point():x$(0), y$(0){++sumofpt; ++nowptcnt; }
    Point(const Point &tt):x$(tt.x$), y$(tt.y$){++sumofpt; ++nowptcnt; }
    ~Point(){--nowptcnt; }
    friend class Line;
    static void showCounter();
    static void showSum();
    static int sumofpt;
    static int nowptcnt;

};
int Point::sumofpt = 0;
int Point::nowptcnt = 0;
inline void Point::showCounter()//����������ʽ�����ǰ������Point����ļ�����
{
    cout << "Current : " << nowptcnt << " points." << endl;
}
inline void Point::showSum()//����������ʽ���������������ǰ���ڹ���Point����������
{
    cout << "In total : " << sumofpt << " points." << endl;
}

class Line
{
private:
    Point pt1$, pt2$;
public:
    Line(double x1, double y1, double x2, double y2):pt1$(x1, y1), pt2$(x2, y2){++sumofll; ++nowllcnt; }
    Line():pt1$(0, 0), pt2$(0, 0){++sumofll; ++nowllcnt; }
    Line(Point &tt1, Point &tt2):pt1$(tt1), pt2$(tt2){++sumofll; ++nowllcnt;}
    Line(const Line &tt):pt1$(tt.pt1$), pt2$(tt.pt2$){++sumofll; ++nowllcnt;}
    ~Line(){--nowllcnt; }
    void readLine();
    friend class Point;
    static void showCounter();
    static void showSum();
    static int sumofll;
    static int nowllcnt;


};
inline void Line::readLine()
{
    double x1, x2, y1, y2;
    char tt;
    cin >> x1 >> tt >> y1;
    cin >> x2 >> tt >> y2;
    pt1$.x$ = x1; pt1$.y$ = y1;
    pt2$.x$ = x2; pt2$.y$ = y2;
}


int Line::sumofll = 0;
int Line::nowllcnt = 0;

void Line::showCounter()
{
    cout << "Current : " << nowllcnt << " lines." << endl;
}
void Line::showSum()
{
    cout << "In total : " << sumofll << " lines." << endl;
}




int main()
{
    int num, i;
    Point p(1, -2), q(2, -1), t;
    t.showCounter();
    t.showSum();
    std::cin>>num;
    Line line[num + 1];
    for(i = 1; i <= num; i++)
    {
        Line *l1, l2;
        l1->showCounter();
        l1->showSum();
        l1 = new Line(p, q);
        line[i].readLine();
        p.showCounter();
        p.showSum();
        delete l1;
        l2.showCounter();
        l2.showSum();
        q.showCounter();
        q.showSum();
    }
    Line l1(p, q), l2(p,t), l3(q,t), l4(l1);
    Line::showCounter();
    Line::showSum();
    Point::showCounter();
    Point::showSum();
    Line *l = new Line[num];
    l4.showCounter();
    l4.showSum();
    delete[] l;
    t.showCounter();
    t.showSum();
}




//Problem G: ƽ���ϵĵ���ߡ���Point�ࡢLine�� (VII)
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 4914  Solved: 3366
//[Submit][Status]
//Description
//����ѧ�ϣ�ƽ��ֱ������ϵ�ϵĵ���X���Y���ϵ���������ֵΨһȷ��������ȷ��һ���߶Ρ��������Ƿ�װһ����Point�ࡱ�͡�Line�ࡱ��ʵ��ƽ���ϵĵ�Ĳ�����
//���ݡ�append.cc�������Point���Line��Ĺ��췽����show()�����������Line�����Point����Ĺ������������
//�ӿ�������
//Point::showCounter()����������ʽ�����ǰ������Point����ļ�����
//Point::showSum()����������ʽ���������������ǰ���ڹ���Point����������
//Line::showCounter()����������ʽ�����ǰ������Line����ļ�����
//Line::showSum()����������ʽ���������������ǰ���ڹ���Line����������
//Input
//����ĵ�һ��ΪN����ʾ������N�в���������
//ÿ��Ϊ�������ꡰx,y�����ֱ��ʾ�߶������յ��x�����y���꣬�����������һ���ո�ֿ���x��y��ֵ����double���ݷ�Χ�ڡ�
//Output
//�����ʽ��sample��
//C���Ե�������������á�
//Sample Input
//4
//0,0 1,1
//1,1 2,3
//2,3 4,5
//0,1 1,0
//Sample Output
//Current : 3 points.
//In total : 3 points.
//Current : 6 lines.
//In total : 6 lines.
//Current : 17 points.
//In total : 17 points.
//Current : 6 lines.
//In total : 7 lines.
//Current : 15 points.
//In total : 17 points.
//Current : 6 lines.
//In total : 8 lines.
//Current : 17 points.
//In total : 21 points.
//Current : 6 lines.
//In total : 9 lines.
//Current : 15 points.
//In total : 21 points.
//Current : 6 lines.
//In total : 10 lines.
//Current : 17 points.
//In total : 25 points.
//Current : 6 lines.
//In total : 11 lines.
//Current : 15 points.
//In total : 25 points.
//Current : 6 lines.
//In total : 12 lines.
//Current : 17 points.
//In total : 29 points.
//Current : 6 lines.
//In total : 13 lines.
//Current : 15 points.
//In total : 29 points.
//Current : 9 lines.
//In total : 17 lines.
//Current : 21 points.
//In total : 37 points.
//Current : 13 lines.
//In total : 21 lines.
//Current : 21 points.
//In total : 45 points.
//HINT
//Append Code
//append.cc,
