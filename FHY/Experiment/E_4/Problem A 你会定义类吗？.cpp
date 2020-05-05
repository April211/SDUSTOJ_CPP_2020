#include <bits/stdc++.h>
using namespace std;

class Demo
{
private:
    int num$;
public:
    Demo(int tt):num$(tt){cout << "A data " << num$ << " is created!" << endl;}
    Demo():num$(0){cout << "A data " << num$ << " is created!" << endl;}
    ~Demo(){cout << "A data " << num$ << " is erased!" << endl;}
    void show()const;
};

void Demo::show()const
{
    cout << "This is data " << num$ << endl;
}


int main()
{
    Demo tmp(10), tmp2;
    int d;
    cin>>d;
    Demo tmp3(d);

    tmp.show();
    tmp2.show();
    tmp3.show();
    return 0;
}


//Problem A: 你会定义类吗？
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 3159  Solved: 2402
//[Submit][Status]
//Description
//定义一个类Demo，有构造函数、析构函数和成员函数show()，其中show()根据样例的格式输出具体属性值。该类只有一个int类型的成员。
//
//Input
//输入只有一个整数，int类型范围内。
//
//Output
//见样例。
//
//Sample Input
//-100
//Sample Output
//A data 10 is created!
//A data 0 is created!
//A data -100 is created!
//This is data 10
//This is data 0
//This is data -100
//A data -100 is erased!
//A data 0 is erased!
//A data 10 is erased!
//HINT
//Append Code
//append.cc,
