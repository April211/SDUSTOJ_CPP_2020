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


Problem D: 家禽和家畜
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1218  Solved: 1032
[Submit][Status]
Description
农户家里通常要养一些家禽、家畜，它们吃的东西和作用不同。现在用多态来描述这种情况。
定义类Animal，是一个抽象类，有纯虚函数void eat()和void fun()，分别用于展示动物吃的行为和作用。
定义Animal的子类Cat、Dog和Rooster，分别是猫、狗和公鸡类。
对于Cat类，eat()输出“Cat eats fishes.”；fun()输出“Cat catches mouses.”。
对于Dog类，eat()输出“Dog eats bones.”；fun()输出“Dog can be housekeeping.”。
对于Rooster类，eat()输出“Rooster eats corns.”；fun()输出“Rooster crows.”。

Input
输入有若干行，每行一个字母c或d或r，分别表示猫、狗、公鸡。

Output
见样例。

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