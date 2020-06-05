#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int x;
public:


};

class B: virtual public A
{
private:
    int x;
public:
    

};

class C: virtual public A
{
private:
    int x;
public:
    

};
//虚拟继承中，派生类（继承自虚拟基类）要为远端基类提供构造


int main()
{

    return 0;
}


//基类与派生类的关系：（多态的基础）
/* 把派生类对象赋值给基类对象；
把派生类对象的地址赋值给基类指针（即：基类的指针可以指向派生类；小学生是人，人不全是小学生）, 但只能访问自己类的；
用派生类对象初始化基类对象的引用； sdudent& tt = SE1;*/    /* reference */
/* 反之不可以 */