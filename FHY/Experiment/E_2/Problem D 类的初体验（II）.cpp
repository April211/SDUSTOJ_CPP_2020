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
Problem D: 类的初体验（II）
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3538  Solved: 3094
[Submit][Status]
Description
定义一个类Data，只有一个double类型的属性和如下3个方法：
1.   带1个参数的构造函数——初始化属性值为参数值。

2.   double getValue()——获得属性值。

3.    void showValue()——显示属性值。

Input
一个double类型的数值。

Output
输出输入的值2次，每次占一行。

Sample Input
3.14
Sample Output
3.14
3.14
HINT
Append Code
append.cc, */
