#include <iostream>
using namespace std;

class A
{
public:
    virtual void f(){cout << "A::f" << endl;}//����fΪ�麯���������������ͬ������ͬ����Ч
};

class B: public A
{
public:
    void f(){cout << "B::f" << endl;}
};

class C: public B
{
public:
    void f(){cout << "C::f" << endl;}
};

class D: public C
{
public:
    void f(){cout << "D::f" << endl;}
};


int main()
{
    A *pa, a;
    B b;

    pa = &b;
    pa -> f();//B::f


    return 0;
}