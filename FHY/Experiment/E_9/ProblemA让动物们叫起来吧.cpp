#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()const = 0;
};

class Cock: public Animal
{
protected:
    string name$;
public:
    Cock(string name):name$(name){}
    void sound()const { cout << name$ << " is a cock, and it can crow." << endl;}
};

class Turkey: public Animal
{
protected:
    string name$;
public:
    Turkey(string name):name$(name){}
    void sound()const { cout << name$ << " is a turkey, and it can gobble." << endl;}


};

class Duck: public Animal
{
protected:
    string name$;
public:
    Duck(string name):name$(name){}
    void sound()const { cout << name$ << " is a duck, and it can quack." << endl;}
};


int main()
{
    int cases;
    string name;
    char type;
    Animal *animal;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
       cin>>name>>type;
       switch(type)
       {
        case 'A':
            animal = new Duck(name);
            break;
        case 'B':
            animal = new Turkey(name);
            break;
        case 'C':
            animal = new Cock(name);
            break;
       }
       animal->sound();
    }
    return 0;
}


/* 
Problem A: �ö����ǽ������ɣ�
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4116  Solved: 3255
[Submit][Status]
Description
Tom�������˺ܶද�������Ѽ�ӡ��𼦺͹��������ǵĽ���������ͬ�����ڣ����д��Animal��Cock��Turkey��Duck�����ݸ�����main()��������������ÿ��������ԡ���Ϊ���໥��ϵ����ģ��Tom�ҵ������

��ʾ�������Ƕ����Լ������֡�

Input
�����ж��С���һ��������M��ʾ֮����M������������ÿ��������������2���֣�ǰһ�����Ƕ�������֣���һ�����Ƕ�������ͣ���A��B��C�ֱ��ʾѼ�ӡ��𼦺͹�������

Output
�����M�У�ÿ������������Ӧһ������������

Sample Input
3
Baby C
Rubby B
Tobby A
Sample Output
Baby is a cock, and it can crow.
Rubby is a turkey, and it can gobble.
Tobby is a duck, and it can quack.
HINT
Append Code
append.cc, */