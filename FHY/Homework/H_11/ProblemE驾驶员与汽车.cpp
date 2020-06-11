#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <typeinfo>
using namespace std;


class Automobile
{
protected:
    double speed$;
public:
    Automobile(double speed):speed$(speed){}
    virtual ~Automobile(){ cout << "An automobile is erased!" << endl;}
    virtual void run()const = 0;
};

class Benz: public Automobile
{
public:
    Benz(double speed):Automobile(speed){}
    ~Benz(){ cout << "A Benz is erased!" << endl;}
    void run()const { cout << "Benz at speed of " << fixed << setprecision(2) << speed$ << "km/h." << endl;}
};

class Buick: public Automobile
{
public:
    Buick(double speed):Automobile(speed){}
    ~Buick(){cout << "A Buick is erased!" << endl;}
    void run()const { cout << "Buick at speed of " << fixed << setprecision(2) << speed$ << "km/h." << endl;}
};

class Zhongba: public Automobile
{
public:
    Zhongba(double speed):Automobile(speed){}
    ~Zhongba(){cout << "A Zhongba is erased!" << endl;}
    void run()const { cout << "Zhongba at speed of " << fixed << setprecision(2) << speed$ << "km/h." << endl;}
};

class Beiqi: public Automobile
{
public:
    Beiqi(double speed):Automobile(speed){}
    ~Beiqi(){cout << "A Beiqi is erased!" << endl;}
    void run()const { cout << "Beiqi at speed of " << fixed << setprecision(2) << speed$ << "km/h." << endl;}
};

class Dayu: public Automobile
{
public:
    Dayu(double speed):Automobile(speed){}
    ~Dayu(){cout << "A Dayu is erased!" << endl;}
    void run()const { cout << "Dayu at speed of " << fixed << setprecision(2) << speed$ << "km/h." << endl;}
};

class Jianghuai: public Automobile
{
public:
    Jianghuai(double speed):Automobile(speed){}
    ~Jianghuai(){cout << "A Jianghuai is erased!" << endl;}
    void run()const { cout << "Jianghuai at speed of " << fixed << setprecision(2) << speed$ << "km/h." << endl;}
};
 
class Driver
{
protected:
    string name;
    char type;
public:
    Driver(string namez, char typez):name(namez), type(typez){}
    ~Driver(){}
    void Drive(Automobile*);
};

void Driver::Drive(Automobile *automobile)
{
    switch (type)
    {
    case 'A':
        cout<<"Driver "<<name<<" can drive ";
        automobile->run();
        break;
    case 'B':
        if (typeid(*automobile) == typeid(Dayu) || typeid(*automobile) == typeid(Jianghuai))
            cout<<"Driver "<<name<<" cannot drive large bus."<<endl;
        else
        {
            cout<<"Driver "<<name<<" can drive ";
            automobile->run();
        }
        break;
    case 'C':
        if (typeid(*automobile) != typeid(Benz) && typeid(*automobile) != typeid(Buick))
            cout<<"Driver "<<name<<" cannot drive bus."<<endl;
        else
        {
            cout<<"Driver "<<name<<" can drive ";
            automobile->run();
        }
        break;
    }
}




int main()
{
    string name;
    char type;
    double speed;
    char automobileType;
    int cases;
    Automobile *automobile;
 
 
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>name>>type>>automobileType>>speed;
        Driver driver(name, type);
        switch (automobileType)
        {
        case 'a':
            automobile = new Benz(speed);
            break;
        case 'b':
            automobile = new Buick(speed);
            break;
        case 'c':
            automobile = new Zhongba(speed);
            break;
        case 'd':
            automobile = new Beiqi(speed);
            break;
        case 'e':
            automobile = new Dayu(speed);
            break;
        case 'f':
            automobile = new Jianghuai(speed);
            break;
        }
        driver.Drive(automobile);
        delete automobile;
    }
    return 0;
}
/* 


Problem E: ��ʻԱ������
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 6394  Solved: 2872
[Submit][Status]
Description
����֪����Ŀǰ�ҹ��ļ��մ��¿ɷ�ΪA��B��C���֣�����Cֻ֤�ܿ�С�Ϳͳ�����������B֤�ɿ��С�С�Ϳͳ�����������A֤û�����ơ������붨�����¼����ࣺ

1. Automobile�������࣬�������ݳ�Աdouble speed�����麯��virtual void run() const = 0��

2. ���ֳ��ͣ���С�ͳ�Benz��Buick�����ͳ�Zhongba��Beiqi���Լ����ͳ�Dayu��Jianghuai�����Ƕ���Automobile�����ࡣ

3. Driver�࣬����string name��char type�������ݳ�Ա��ǰ����˾�������֣�������˾�����еļ������ͣ�A��B��C�����ṩDrive(Automobile *)���������ݼ��������ж���˾���Ƿ���Լ�ʻָ����������

Input
����ֶ��С���һ����һ������M>0����ʾ֮����M������������

ÿ���������������Ĳ��֣�˾�������������հ׷������������ͣ�A��B��C�������ͣ��ֱ�����ĸa~f��ʾ���ֳ��ͣ���Ӧ�ĳ��Ϳ��Դ�main()�п������Լ��ó�����ʻ�ٶȣ�double���ͷ�Χ�ڵ���������

Output
�����M�У�ÿ������������Ӧһ�����룬�����ʽ�μ�������

Sample Input
4
zhangsan C a 100.33
lisi C d 100.33
wangwu B f 100.33
Tom A e 300.00
Sample Output
Driver zhangsan can drive Benz at speed of 100.33km/h.
A Benz is erased!
An automobile is erased!
Driver lisi cannot drive bus.
A Beiqi is erased!
An automobile is erased!
Driver wangwu cannot drive large bus.
A Jianghuai is erased!
An automobile is erased!
Driver Tom can drive Dayu at speed of 300.00km/h.
A Dayu is erased!
An automobile is erased!
HINT
1.ʹ��typeid���ж�һ������ָ��ʵ��ָ��Ķ�������͡�


2.ע�⣺append.cc���Ѿ�������Driver���һ����������Ҫ��Driver���ظ������ˡ�


Append Code
append.cc, */