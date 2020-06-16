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

Problem A: н�����
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 5436  Solved: 3131
[Submit][Status]
Description
ĳ��˾�о���Manager������Ա��Employee����Сʱ����HourlyWorker����Ӫ����Ա��CommWorker������Ա����Person�������ǵ�н����㷽������һ����
Manager������н�ƣ�
Employee���¼Ƴ꣬�����ǣ��»�������+���𣬽�����ָ���������¹��ʣ�
HourlyWorker�ǰ�����ʱ��Ƴ꣬�����ǣ�����Сʱ*ÿСʱ���ʣ�
CommWorker���¼Ƴ꣬�����ǣ��»�������+�����۶��2%��
����ÿ��Ա����Person���Ĺ������루input�����������ʼ���취��pay����������ʾ��Ϣ��show����������һ�������ʹ�ö�̬��ʵ�֡�
-----------------------------------------------------------------------------
����ϸ�Ķ�append.cc���룬����Ʋ�ʵ�����Ա�����������ϵ��ʹmain()�����ܹ����в��õ���ȷ�������
Input
����ĵ�һ������n����ʾ��n�����������
ÿ���������ռһ�У��ֱ�ΪԱ��ְλ��Ա����������������base��������k��Manager�޴����
Ա��ְλΪManager����baseΪ��н����λΪǧԪ��
Ա��ְλΪEmployee����baseΪ��н����λΪǧԪ��������Ϊ����k���µĹ��ʣ�
Ա��ְλΪHourlyWorker����baseΪʱн����λΪԪ��������Ϊ�깤��k��Сʱ��
Ա��ְλΪCommWorker����baseΪ��н����λΪǧԪ���������������۶�kǧԪ��
Output
����ʽ���ÿ���˵�������ְλ�����ռ������н����ϸ��ʽ��sample��
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