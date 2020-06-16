#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Test
{
protected:
    string name$;
public:
    Test(){ cout << "Create an object with name NULL" << endl;}
    Test(string name):name$(name){ cout << "Create an object with name " << name$ << endl;}
    ~Test()
    {
        if(name$.size() == 0){ cout << "Erase an object with name NULL" << endl;}
        else { cout << "Erase an object with name " << name$ << endl;}
    }



};


int main()
{
    string name;
    Test t1;
    cin>>name;
    Test t2(name);
    return 0;
}
/* 



Problem E: Test类
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 738  Solved: 557
[Submit][Status]
Description
定义一个类Test，只有一个string类型的参数name。定义其成员函数，使主函数能得到样例所示的结果。

Input
输入一个字符串，不包含空格。

Output
见样例。

Sample Input
Computer
Sample Output
Create an object with name NULL
Create an object with name Computer
Erase an object with name Computer
Erase an object with name NULL
HINT
Append Code
append.cc, */