#include <bits/stdc++.h>
using namespace std;

class Point
{
protected:
    double x$, y$;

public:
    Point() : x$(0), y$(0) { cout << fixed << setprecision(2) << "The Point (" << x$ << ", " << y$ << ") is created!" << endl; }
    Point(double x, double y) : x$(x), y$(y) { cout << fixed << setprecision(2) << "The Point (" << x$ << ", " << y$ << ") is created!" << endl; }
    Point(const Point &tt) : x$(tt.x$), y$(tt.y$) { cout << fixed << setprecision(2) << "A Point (" << x$ << ", " << y$ << ") is copied!" << endl; }
    ~Point() { cout << fixed << setprecision(2) << "A Point (" << x$ << ", " << y$ << ") is erased!" << endl; }
    double getX() const { return x$; }
    double getY() const { return y$; }
    friend class Graph;
};

class Graph
{
protected:
    Point *points$;
    int numOfPoints$;

public:
    Graph(const Point *tt, int num) : points$(0), numOfPoints$(num)
    {
        points$ = new Point[num];
        for (int i = 0; i < num; i++)
        {
            points$[i].x$ = tt[i].x$;
            points$[i].y$ = tt[i].y$;
        }
        cout << "A graph with " << numOfPoints$ << " points is created!" << endl;
    }
    ~Graph()
    {
        delete[] points$;
        cout << "A graph with " << numOfPoints$ << " points is erased!" << endl;
    }
    Point getCentroid();
};

Point Graph::getCentroid()
{
    double cx = 0.0, cy = 0.0;
    double sumx = 0.0, sumy = 0.0;
    for (int i = 0; i < numOfPoints$; i++)
    {
        sumx += points$[i].x$;
        sumy += points$[i].y$;
    }
    cx = sumx / numOfPoints$;
    cy = sumy / numOfPoints$;
    Point *tt = new Point(cx, cy);
    return *tt;
}

int main()
{
    //freopen("src.txt", "w", stdout);
    int cases, num;
    double x, y;
    Point centroid;

    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> num;
        Point points[num];
        for (int j = 0; j < num; j++)
        {
            cin >> x >> y;
            points[j] = *(new Point(x, y));
        }
        Graph graph(points, num);
        centroid = graph.getCentroid();
        cout << setprecision(2) << fixed << "The centroid is (" << centroid.getX() << ", " << centroid.getY() << ")." << endl;
    }
    return 0;
}


/* Problem B: �����㷨
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4704  Solved: 2375
[Submit][Status]
Description
�ںܶ�Ӧ���У���Ҫ��ĳ��Ŀ����ж�λ���������һ��δ֪����ĵ�A���ٶ���֪A����N�������ڣ�����֪N�����ڵ�����꣬���ȡN�����������ΪA�������һ������ֵ��

��ν���ģ�����ָ������ꡢ������ֱ�ΪN����ĺ�����ƽ��ֵ��������ƽ��ֵ�ĵ㡣�����ٶ�N���������ֱ�x1,y1)��(x2,y2)��......�������ĵ�����Ϊ��(x1+x2+...)/N, (y1+y2+...)/N)��

������Ҫ���д2���ࣺ

1. Point�ࣺ����һ����ĺ�����������꣬���ṩ�ʵ��Ĺ��캯�������������Ϳ������캯�����Լ�getX()��getY()������

2. Graph��

��1�����ݳ�ԱPoint *points����ʾ��A�����ڵĵ�ļ��ϡ�

��2�����ݳ�Ա��int numOfPoints����ʾ���ڵ�ĸ�����

��3���ʵ��Ĺ��캯��������������

��4��Point getCentroid()���������ڷ������ĵ㡣

ע�⣺ͬһ��Ķ���֮��ĸ�ֵ���㣨=�������ÿ������캯����

Input
����Ϊ���У���һ��M>0��ʾ��M������������

ÿ�����������������С���һ��N>0��ʾ��N���㣬֮����N����ĺ�����������꣬ÿ����ռһ�С�

Output
��������

Sample Input
1
5
0 0
1 1
2 2
3 3
4 4
Sample Output
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (1.00, 1.00) is created!
The Point (2.00, 2.00) is created!
The Point (3.00, 3.00) is created!
The Point (4.00, 4.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
The Point (0.00, 0.00) is created!
A graph with 5 points is created!
The Point (2.00, 2.00) is created!
A Point (2.00, 2.00) is copied!
A Point (2.00, 2.00) is erased!
The centroid is (2.00, 2.00).
A Point (4.00, 4.00) is erased!
A Point (3.00, 3.00) is erased!
A Point (2.00, 2.00) is erased!
A Point (1.00, 1.00) is erased!
A Point (0.00, 0.00) is erased!
A graph with 5 points is erased!
A Point (4.00, 4.00) is erased!
A Point (3.00, 3.00) is erased!
A Point (2.00, 2.00) is erased!
A Point (1.00, 1.00) is erased!
A Point (0.00, 0.00) is erased!
A Point (2.00, 2.00) is erased!
HINT
 ��ʹ�ö�����Ϊ��������ֵʱ�������һ����ʱ���󣬴�ʱ����ÿ������캯����������g++��������Ҳ���Ǵ�ҳ��õ�code::blocks���õı��������У����������صĶ������һ��������и�ֵʱ�������������ֵ��һ���ֲ��������򲻻���ÿ������캯�������ԣ�������ڴ˳�����ʵ�ֿ������캯���ĵ��ã�������getCentroid�з���һ��ʹ��new����������Ķ��󣬶�����һ���Ѿ�����ľֲ�����

Append Code
append.cc, */