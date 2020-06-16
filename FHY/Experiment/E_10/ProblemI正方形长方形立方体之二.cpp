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

Problem I: �����Ρ������Ρ������� ֮��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1730  Solved: 1463
[Submit][Status]
Description
���������Σ�Square���������Σ�Rectangle���������壨Cube���������壨Cuboid���ı߳����󣨱������
�����Ρ������������ȵģ����ֻ��洢һ���߳���
��������洢�����߳���
��������洢�����߳�
���һ������Shape�����ڶ�̬��ʵ�����󣨱������
-----------------------------------------------------------------------------
����ϸ�Ķ�append.cc���룬����ƺ������Ρ������Ρ������塢������������ϵ��ʹmain()�����ܹ����в��õ���ȷ�������
Input
�����һ������n����ʾ������n��ͼ�Ρ�ÿ��ͼ��ռ��һ�����롣SQR��ʾ�����Ρ�CUB��ʾ�����壬����ֻ����һ���߳���RCT��ʾ�����Σ��������볤�Ϳ�CBD��ʾ�����壬�������볤��ߡ�

Output
������ĵڶ��п�ʼ��ÿ�ж�Ӧ���һ��ͼ�εģ�������ַ�����

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