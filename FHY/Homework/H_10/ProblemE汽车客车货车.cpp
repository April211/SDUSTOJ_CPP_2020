#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int num$;//��������
public:
    Vehicle(int num):num$(num){cout << "Vehicle has " << num$ <<" wheels is created." << endl;}
    virtual ~Vehicle(){cout << "Vehicle has " << num$ << " wheels is erased." << endl;}
};//����������

class Bus: public Vehicle
{
protected:
    int guest$;
public:
    Bus(int num, int guest):Vehicle(num), guest$(guest){cout << "Bus which can carry " << guest$ <<" persons is created." << endl;}
    ~Bus(){cout << "Bus which can carry " << guest$ << " persons is erased." << endl;}

};


class Truck: public Vehicle
{
protected:
    int weight$;
public:
    Truck(int num, int weight):Vehicle(num), weight$(weight){cout << "Truck which can carry " << weight$ <<" tons goods is created." << endl;}
    ~Truck(){cout << "Truck which can carry " << weight$ << " tons goods is created." << endl;}




};


int main()
{
    int w, g;
    char t;
    Vehicle *veh;
    while (cin>>w>>t>>g)
    {
        if (t == 'b')
        {
            veh = new Bus(w, g);
        }
        else
        {
            veh = new Truck(w, g);
        }
        delete veh;
    }
    return 0;
}

/* 






Problem E: �������ͳ�������
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4207  Solved: 2323
[Submit][Status]
Description
����Vehicle�࣬������
1. һ��int��������num����ʾ����������������
2. ���캯�������������������������ʾ����Ϣ��
����Bus�࣬��Vehicle������࣬������
1. һ��int��������guest����ʾ�ͳ��ɳ�����������
2. ���캯�������������������������ʾ����Ϣ��
����Truck�࣬��Vehicle������࣬������
1. һ��int��������weight����ʾ�������غɵĻ���������
2. ���캯�������������������������ʾ����Ϣ��
Input
�����ж��У�ÿ��һ������������ÿ�а���1��������������������������1���ַ�b����t��b��t�ֱ��ʾ�ͳ�����������1�����������ɳ�����������ɳ��صĻ�����������

Output
��������
Sample Input
4 b 40
8 t 15
Sample Output
Vehicle has 4 wheels is created.
Bus which can carry 40 persons is created.
Bus which can carry 40 persons is erased.
Vehicle has 4 wheels is erased.
Vehicle has 8 wheels is created.
Truck which can carry 15 tons goods is created.
Truck which can carry 15 tons goods is created.
Vehicle has 8 wheels is erased.
HINT
Append Code
append.cc, */