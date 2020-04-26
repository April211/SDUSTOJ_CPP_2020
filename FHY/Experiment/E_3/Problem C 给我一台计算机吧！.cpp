#include <bits/stdc++.h>
using namespace std;

class CPU
{
private:
    int cspeed$;
public:
    CPU(int temp):cspeed$(temp){}
    CPU(const CPU & tt):cspeed$(tt.cspeed$){}
    int getcspeed(){return cspeed$;}

};

class Memory
{
private:
    int capacity$;
public:
    Memory(int temp):capacity$(temp){}
    Memory(const Memory & tt):capacity$(tt.capacity$){}
    int getcapacity(){return capacity$;}
};

class Computer
{
private:
    CPU cc$;
    Memory mm$;
    string name$;
public:
    void show();
    Computer(CPU ct, Memory mt, string nt):cc$(ct), mm$(mt), name$(nt){}
};

inline void Computer::show()
{
    cout << "This is " << name$ << "' computer with CPU = " << cc$.getcspeed() << "GHz, memory = " << mm$.getcapacity() << "MB." << endl;
}
int main()
{
    int c, m;
    string n;
    cin>>c>>m>>n;
    CPU cpu(c);
    Memory mem(m);
    Computer com1(cpu, mem, n);
    cin>>c>>m>>n;
    Computer com2(c, m, n);
    com1.show();
    com2.show();
    return 0;
}


//Problem C: ����һ̨������ɣ�
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 3377  Solved: 2862
//[Submit][Status]
//Description
//CPU��Ƶ�����������Ǻ���һ̨�����������Ҫָ�ꡣ�붨�壺
//
//1. CPU�ֻࣺ��һ��int���͵����ݳ�Ա�Ա�ʾ����Ƶ�������������͸�����main()������д��Ҫ�ĳ�Ա�������������캯������
//
//2. Memory�ֻࣺ��һ��int���͵����ݳ�Ա�Ա�ʾ�������������������͸�����main()������д��Ҫ�ĳ�Ա�������������캯������
//
//3. Computer�ࣺ
//
//��1���������ݳ�Ա�ֱ�ΪCPU�Ķ���Memory�Ķ����һ���ַ�������ʾ�ü��������˭�ģ���
//
//��2����������͸�����main()������д��Ҫ�ĳ�Ա�������������캯������
//
//��3��void show()���������ڰ������������ʽ����ü��������Ϣ��
//
//Input
//������2�С�ÿ�а���2��������1���ַ������ֱ��ʾCPU����Ƶ���ڴ������ͼ��������������
//
//Output
//��������
//
//Sample Input
//2 1000 Zhang
//4 2000 Li
//Sample Output
//This is Zhang' computer with CPU = 2GHz, memory = 1000MB.
//This is Li' computer with CPU = 4GHz, memory = 2000MB.
