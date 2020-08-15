#include <iostream>
#include <iomanip>
using namespace std;

class Shape
{
public:
    virtual ~Shape(){}
    virtual int area()const = 0;
};

class Square: public Shape
{
protected:
    int a$;
public:
    Square(int a):a$(a){}
    ~Square(){}
    int area()const {return a$* a$;}
};

class Rectangle: public Shape
{
protected:
    int a$, b$;
public:
    Rectangle(int a, int b):a$(a), b$(b){}
    ~Rectangle(){}
    int area()const {return a$* b$;}

};

class Cube: public Shape
{
protected:
    int a$;
public:
    Cube(int a):a$(a){}
    ~Cube(){}
    int area()const {return a$* a$* 6;}
};

class Cuboid: public Shape
{
protected:
    int a$, b$, c$;
public:
    Cuboid(int a, int b, int c):a$(a), b$(b), c$(c){}
    ~Cuboid(){}
    int area()const {return ((a$* b$* 2)+(c$* b$* 2)+(a$* c$* 2));}

};


int main()
{
    int n, l, w, h;
    cin >> n;
    Shape *sp[100];
    string name;
    for(int i = 0; i < n; i++)
    {
        cin >> name;
        if(name == "SQR")
        {
            cin >> l;
            sp[i] = new Square(l);
        }
        if(name == "RCT")
        {
            cin >> l >> w;
            sp[i] = new Rectangle(l, w);
        }
        if(name == "CUB")
        {
            cin >> l;
            sp[i] = new Cube(l);
        }
        if(name == "CBD")
        {
            cin >> l >> w >> h;
            sp[i] = new Cuboid(l, w, h);
        }
    }
    for(int i = 0; i < n; i++)
        cout << sp[i]->area() << endl;
    for(int i = 0; i < n; i++)
        delete sp[i];
}

/* 

Problem I: 正方形、长方形、立方体 之二
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1730  Solved: 1463
[Submit][Status]
Description
给出正方形（Square）、长方形（Rectangle）、立方体（Cube）、长方体（Cuboid）的边长，求（表）面积。
正方形、立方体各边相等的，因此只需存储一条边长。
长方形需存储两条边长。
长方体需存储三条边长
设计一个基类Shape，用于多态的实现求求（表）面积。
-----------------------------------------------------------------------------
请仔细阅读append.cc代码，并设计好正方形、长方形、立方体、长方体派生关系，使main()函数能够运行并得到正确的输出。
Input
输入第一个整数n，表示后面有n个图形。每个图形占用一行输入。SQR表示正方形、CUB表示立方体，后面只输入一个边长；RCT表示长方形，后面输入长和宽；CBD表示长方体，后面输入长宽高。

Output
从输入的第二行开始，每行对应输出一个图形的（表）面积字符串。

Sample Input
6
RCT 3 5
SQR 3
CUB 3
CBD 3 4 5
CBD 1 2 1
RCT 3 1
Sample Output
15
9
54
94
10
3
HINT
Append Code
append.cc, */