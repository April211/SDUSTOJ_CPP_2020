#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    int x$, y$;
public:
    Point(int x, int y):x$(x), y$(y){cout << "A point (" << x$ << ", " << y$ << ") is created!" << endl;}
    Point(const Point& tt):x$(tt.x$), y$(tt.y$){cout << "A point (" << x$ << ", " << y$ << ") is copied!" << endl;}
    ~Point(){cout << "A point (" << x$ << ", " << y$ << ") is erased!" << endl;}
    int getX(){return x$;}
    int getY(){return y$;}
    friend class Rectangle;
};

class Rectangle
{
private:
    Point leftTop, rightBottome;
public:
    Rectangle(int x1, int y1, int x2, int y2):leftTop(x1, y1), rightBottome(x2, y2){cout << "A rectangle (" << leftTop.x$ << ", " << leftTop.y$ << ") to (" << rightBottome.x$ << ", " << rightBottome.y$ << ") is created!" << endl;}
    ~Rectangle(){cout << "A rectangle (" << leftTop.x$ << ", " << leftTop.y$ << ") to (" << rightBottome.x$ << ", " << rightBottome.y$ << ") is erased!" << endl;}
    Point& getLeftTop()
    {
        return leftTop;
    }
    Point getRightBottome()
    {
        return rightBottome;
    }
    int getArea()
    {
        int a, b;
        a = abs(leftTop.x$ - rightBottome.x$);
        b = abs(leftTop.y$ - rightBottome.y$); 
        return a* b;  
    }


};




int main()
{
    int cases;
    int x1, y1, x2, y2;
 
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        Rectangle rect(x1,y1,x2,y2);
        cout<<"Area: "<<rect.getArea()<<endl;
        cout<<"Left top is ("<<rect.getLeftTop().getX()<<", "<<rect.getLeftTop().getY()<<")"<<endl;
        cout<<"Right bottom is ("<<rect.getRightBottome().getX()<<", "<<rect.getRightBottome().getY()<<")"<<endl;
    }
    return 0;
}



/* Problem B: �ӵ㵽��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 6022  Solved: 3307
[Submit][Status]
Description
һ�����ο��������ϽǺ����½ǵĶ����Ψһȷ���������붨�������ࣺPoint��Rectangle��

����Point����x��y�������ԣ���Ϊint���ͣ�����ʾ��ά�ռ���һ����ĺ������꣬��������Ӧ�Ĺ��캯�������������Ϳ������캯�������⣬����getX()��getY()�������Եõ�һ���������ֵ��

Rectangle����leftTop��rightBottom�������ԣ���ΪPoint��Ķ��󣩣���ʾһ�����ε����ϽǺ����½ǵ������㣬��������Ӧ�Ĺ��캯�����������������⣬����getLeftTop()��getRightBottom()�������ڻ�ȡ��Ӧ�����Ͻǵ㡢���½ǵ㣬getArea()�������Ի�ȡ�����

Input
�����ж��С�

��һ����һ��������M����ʾ������M������������

ÿ����������ռһ�У�����4�����������ֱ�Ϊ���Ͻǵĺ����ꡢ�����꣬���½ǵĺ����ꡢ�����ꡣ

ע�⣺

1.�������������ж�����������Ӧ��������д������

2. �ٶ���Ļ�����½�Ϊ����ԭ�㡣

Output
�����������

Sample Input
1
10 10 20 0
Sample Output
A point (10, 10) is created!
A point (20, 0) is created!
A rectangle (10, 10) to (20, 0) is created!
Area: 100
Left top is (10, 10)
A point (20, 0) is copied!
A point (20, 0) is copied!
Right bottom is (20, 0)
A point (20, 0) is erased!
A point (20, 0) is erased!
A rectangle (10, 10) to (20, 0) is erased!
A point (20, 0) is erased!
A point (10, 10) is erased!
HINT
Append Code
append.cc, */