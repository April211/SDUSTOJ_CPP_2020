#include <iostream>
using namespace std;


class Employee
{
protected:
    string name$;
    int base$;
public:
    Employee(string name, int base):name$(name), base$(base){}
    virtual ~Employee(){}
    virtual void print()const = 0;
};

class Manager: virtual public Employee
{
protected:
    int bonus$;
public:
    Manager(string name, int base, int bonus):Employee(name, base), bonus$(bonus){}
    ~Manager(){}
    void print()const { cout << "Manager " << name$ << " : " << base$* 12 + bonus$  << endl; }
};

class Sales: virtual public Employee
{
protected:
    int royalty$;
public:
    Sales(string name, int base, int royalty):Employee(name, base), royalty$(royalty){}
    ~Sales(){}
    void print()const { cout << "Sales " << name$ << " : " << (base$ + royalty$)* 12 << endl; }
};


class SalesManager: public Manager, public Sales
{
public:
    SalesManager(string name, int base, int royalty, int bonus):Employee(name, base), Manager(name, base, bonus),Sales(name, base, royalty){}
    ~SalesManager(){}
    void print()const { cout << "SalesManager " << name$ << " : " << (base$ + royalty$)* 12 + bonus$ << endl; }
};





int main()
{
    string label, name;
    Employee* p[100];
    int n;
    int base, royalty, bonus;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> label >> name;
        if(label == "Sales")
        {
            cin >> base >> royalty;
            p[i] = new Sales(name, base, royalty);
        }
        if(label == "Manager")
        {
            cin >> base >> bonus;
            p[i] = new Manager(name, base, bonus);
        }
        if(label == "SalesManager")
        {
            cin >> base >> royalty >> bonus;
            p[i] = new SalesManager(name, base, royalty, bonus);
        }
    }
    for(int i = 0; i < n; i++)
        p[i]->print();
    for(int i = 0; i < n; i++)
        delete p[i];
}/* 



Problem B: 薪酬计算 之二
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1992  Solved: 1419
[Submit][Status]
Description
某公司有经理（Manager）、销售（Sales）、销售经理（SalesManager）四类雇员（Employee），他们的薪酬计算方法各不一样：
每个雇员（Employee）都有每月的基本工资；
经理（Manager）除了基本工资之外还有年终分红；
销售（Sales）除了基本工资之外，每月还有营销提成；
销售经理（SalesManager）既是销售（Sales）人员也是经理（Manager），因此他既有每月的营销提成，也有年终分红。
每类雇员的年薪计算方式不一样，因此使用多态来实现。
-----------------------------------------------------------------------------
请仔细阅读append.cc代码，并设计并实现这个员工类的派生体系，使main()函数能够运行并得到正确的输出。
Input
输入第一个整数n，表示后面有n个雇员。每个雇员占用一行输入。分别是员工类型、姓名、月基本工资、月营销提成（销售）、年终分红（经理），如果是销售经理则两者都有。

Output
从输入的第二行开始，每行对应输出一个雇员的类型、姓名和年薪。

Sample Input
6
Sales Zhangsan 2500 1500
Manager Zhaosi 2500 10000
Manager Liuwu 10000 35000
Sales Sunliu 5000 10000
SalesManager Zhengqi 2500 1500 10000
SalesManager Wangba 10000 25000 10000
Sample Output
Sales Zhangsan : 48000
Manager Zhaosi : 40000
Manager Liuwu : 155000
Sales Sunliu : 180000
SalesManager Zhengqi : 58000
SalesManager Wangba : 430000
HINT
Append Code
append.cc, */