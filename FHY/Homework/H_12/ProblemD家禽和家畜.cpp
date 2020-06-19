#include <iostream>
#include <iomanip>
using namespace std;

class Animal
{
public:
    Animal(){}
    virtual ~Animal(){}
    virtual void eat()const = 0;
    virtual void fun()const = 0;    
};

class Cat: public Animal
{
public:
    Cat(){}
    ~Cat(){}
    void eat()const { cout << "Cat eats fishes." << endl;}
    void fun()const { cout << "Cat catches mouses." << endl;}
};

class Dog: public Animal
{
public:
    Dog(){}
    ~Dog(){}
    void eat()const { cout << "Dog eats bones." << endl;}
    void fun()const { cout << "Dog can be housekeeping." << endl;}
};
class Rooster: public Animal
{
public:
    Rooster(){}
    ~Rooster(){}
    void eat()const { cout << "Rooster eats corns." << endl;}
    void fun()const { cout << "Rooster crows." << endl;}
};


int main()
{
    Animal *animal;
    char ch;
    while(cin>>ch)
    {
        switch(ch)
        {
        case 'c':
            animal = new Cat();
            break;
        case 'd':
            animal = new Dog();
            break;
        case 'r':
            animal = new Rooster();
            break;
        }
        animal->eat();
        animal->fun();
        delete animal;
    }
    return 0;
}

/* 


Problem D: ���ݺͼ���
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1218  Solved: 1032
[Submit][Status]
Description
ũ������ͨ��Ҫ��һЩ���ݡ��������ǳԵĶ��������ò�ͬ�������ö�̬���������������
������Animal����һ�������࣬�д��麯��void eat()��void fun()���ֱ�����չʾ����Ե���Ϊ�����á�
����Animal������Cat��Dog��Rooster���ֱ���è�����͹����ࡣ
����Cat�࣬eat()�����Cat eats fishes.����fun()�����Cat catches mouses.����
����Dog�࣬eat()�����Dog eats bones.����fun()�����Dog can be housekeeping.����
����Rooster�࣬eat()�����Rooster eats corns.����fun()�����Rooster crows.����

Input
�����������У�ÿ��һ����ĸc��d��r���ֱ��ʾè������������

Output
��������

Sample Input
c
c
d
r
d
r
c
Sample Output
Cat eats fishes.
Cat catches mouses.
Cat eats fishes.
Cat catches mouses.
Dog eats bones.
Dog can be housekeeping.
Rooster eats corns.
Rooster crows.
Dog eats bones.
Dog can be housekeeping.
Rooster eats corns.
Rooster crows.
Cat eats fishes.
Cat catches mouses.
HINT
Append Code
append.cc, */