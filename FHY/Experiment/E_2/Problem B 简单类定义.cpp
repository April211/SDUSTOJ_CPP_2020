#include <iostream>
#include <iomanip>
using namespace std;

class Test
{
private:
    int _member;
public:
    Test(int temp = 0):_member(temp){cout << "Test " << _member << " is created." << endl;}
    ~Test(){cout << "Test " << _member << " is erased." << endl;}
    int getMem()
    {
        return _member;
    }
    int setMem(int a)
    {
        _member = a;
        return 0;
    }

};
int main()
{
    Test t1;
    int i;
    cin>>i;

    Test t2(i);
    cout<<"t2 is "<<t2.getMem()<<"."<<endl;
    cin>>i;
    t2.setMem(i);
    cout<<"t2 is "<<t2.getMem()<<"."<<endl;
    return 0;
}
/* 
Problem B: 简单类定义
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2797  Solved: 1766
[Submit][Status]
Description
定义一个类Test，只有一个int类型的数据成员member，定义其构造函数、析构函数，定义成员函数getMem()和setMem(int)分别用来获取和设置member的值。

Input
2个int类型范围内的整数。

Output
见样例。

Sample Input
10
20
Sample Output
Test 0 is created.
Test 10 is created.
t2 is 10.
t2 is 20.
Test 20 is erased.
Test 0 is erased.
HINT
Append Code
append.cc, */
