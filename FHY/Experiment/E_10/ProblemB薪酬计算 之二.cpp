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



Problem B: н����� ֮��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1992  Solved: 1419
[Submit][Status]
Description
ĳ��˾�о���Manager�������ۣ�Sales�������۾���SalesManager�������Ա��Employee�������ǵ�н����㷽������һ����
ÿ����Ա��Employee������ÿ�µĻ������ʣ�
����Manager�����˻�������֮�⻹�����շֺ죻
���ۣ�Sales�����˻�������֮�⣬ÿ�»���Ӫ����ɣ�
���۾���SalesManager���������ۣ�Sales����ԱҲ�Ǿ���Manager�������������ÿ�µ�Ӫ����ɣ�Ҳ�����շֺ졣
ÿ���Ա����н���㷽ʽ��һ�������ʹ�ö�̬��ʵ�֡�
-----------------------------------------------------------------------------
����ϸ�Ķ�append.cc���룬����Ʋ�ʵ�����Ա�����������ϵ��ʹmain()�����ܹ����в��õ���ȷ�������
Input
�����һ������n����ʾ������n����Ա��ÿ����Առ��һ�����롣�ֱ���Ա�����͡��������»������ʡ���Ӫ����ɣ����ۣ������շֺ죨��������������۾��������߶��С�

Output
������ĵڶ��п�ʼ��ÿ�ж�Ӧ���һ����Ա�����͡���������н��

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