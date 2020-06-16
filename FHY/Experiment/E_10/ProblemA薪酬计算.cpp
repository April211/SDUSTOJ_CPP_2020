#include <iostream>
using namespace std;


class Person
{
protected:
    string name$;
public:
    Person(string name):name$(name){}
    virtual ~Person(){}
    virtual void input(){}
    virtual int pay()const = 0;
    virtual void show(){}
};

class Manager: public Person
{
protected:
    int base$;
public:
    Manager(string name):Person(name), base$(0){}
    ~Manager(){}
    void input(){ cin >> base$;}
    int pay()const { return base$* 1000;}
    void show(){ cout << name$ << " (Manager)"; }
};

class Employee: public Person
{
protected:
    int base$;
    int month$;
public:
    Employee(string name):Person(name), base$(0), month$(0){}
    ~Employee(){}
    void input(){ cin >> base$ >> month$;}
    int pay()const { return (base$* 12 + month$* base$)* 1000;}
    void show(){ cout << name$ << " (Employee)"; }
};


class HourlyWorker: public Person
{
protected:
    int base$;
    int hour$;
public:
    HourlyWorker(string name):Person(name), base$(0), hour$(0){}
    ~HourlyWorker(){}
    void input(){ cin >> base$ >> hour$;}
    int pay()const { return base$* hour$;}
    void show(){ cout << name$ << " (HourlyWorker)"; }
};


class CommWorker: public Person
{
protected:
    int base$;
    int perf$;
public:
    CommWorker(string name):Person(name), base$(0), perf$(0){}
    ~CommWorker(){}
    void input(){ cin >> base$ >> perf$;}
    int pay()const { return base$*12 * 1000 + (perf$* 20);}
    void show(){ cout << name$ << " (CommWorker)"; }
};




int main()
{
    Person *person;
    string name, job;
    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; ++i)
    {
        cin >> job >> name;
        if(job == "Manager")
            person = new Manager(name);
        if(job == "Employee")
            person = new Employee(name);
        if(job == "HourlyWorker")
            person = new HourlyWorker(name);
        if(job == "CommWorker")
            person = new CommWorker(name);
        person->input();
        person->show();
        cout << " Annual Salary is " << person->pay() << "." << endl;
    }
 
}


/* 

Problem A: 薪酬计算
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 5436  Solved: 3131
[Submit][Status]
Description
某公司有经理（Manager）、雇员（Employee）、小时工（HourlyWorker）和营销人员（CommWorker）四类员工（Person），他们的薪酬计算方法各不一样：
Manager采用年薪制；
Employee按月计酬，方法是：月基本工资+奖金，奖金是指奖励几个月工资；
HourlyWorker是按工作时间计酬，方法是：工作小时*每小时工资；
CommWorker按月计酬，方法是：月基本工资+年销售额的2%；
由于每类员工（Person）的工资输入（input函数）、工资计算办法（pay函数）、显示信息（show函数）均不一样，因此使用多态来实现。
-----------------------------------------------------------------------------
请仔细阅读append.cc代码，并设计并实现这个员工类的派生体系，使main()函数能够运行并得到正确的输出。
Input
输入的第一个整数n，表示用n组测试样例。
每组测试样例占一行，分别为员工职位、员工姓名、基础工资base、附加项k（Manager无此项）。
员工职位为Manager，其base为年薪，单位为千元；
员工职位为Employee，其base为月薪，单位为千元，附加项为奖励k个月的工资；
员工职位为HourlyWorker，其base为时薪，单位为元，附加项为年工作k个小时；
员工职位为CommWorker，其base为月薪，单位为千元，附加项是年销售额k千元；
Output
按格式输出每个人的姓名、职位和最终计算的年薪，详细格式见sample。
Sample Input
6
Manager Zhang3 200
Employee Li4 8 5
Employee Wang5 10 3
HourlyWorker Zhao6 45 650
CommWorker Liu7 5 300
CommWorker Sun8 6 180
Sample Output
Zhang3 (Manager) Annual Salary is 200000.
Li4 (Employee) Annual Salary is 136000.
Wang5 (Employee) Annual Salary is 150000.
Zhao6 (HourlyWorker) Annual Salary is 29250.
Liu7 (CommWorker) Annual Salary is 66000.
Sun8 (CommWorker) Annual Salary is 75600.
HINT
Append Code
append.c, append.cc, */