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



Problem E: Test��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 738  Solved: 557
[Submit][Status]
Description
����һ����Test��ֻ��һ��string���͵Ĳ���name���������Ա������ʹ�������ܵõ�������ʾ�Ľ����

Input
����һ���ַ������������ո�

Output
��������

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