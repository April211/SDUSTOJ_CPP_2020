#include <bits/stdc++.h>
using namespace std;

class Data
{
private:
    double dd$;
    int ii$;
    int tpe$;
public:
    Data():dd$(0), ii$(0), tpe$(0){cout << "A default object is created." << endl;}
    Data(int tt):dd$(0), ii$(tt), tpe$(1){cout << "An integer object " << ii$ << " is created." << endl;}
    Data(double tt):dd$(tt), ii$(0), tpe$(-1){cout << "A double object " << dd$ << " is created." << endl;}
    ~Data()
    {
        if(tpe$ == 0)
        {
            cout << "The default object is erased." << endl;
        }
        else if(tpe$ == 1)
        {
            cout << "The integer object " << ii$ << " is erased." << endl;

        }
        else
        {
            cout << "The double object " << dd$ << " is erased." << endl;

        }
        


    }
};


int main()
{
    Data d1;
    int i;
    cin>>i;
    Data d2(i);
    double d;
    cin>>d;
    Data d3(d);
    return 0;
}

/* Problem C: 类型可变的类
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2890  Solved: 1484
[Submit][Status]
Description
定义一个Data类，至少包含1个int类型的数据成员、1个double类型的数据成员，定义其构造函数和析构函数，使得程序执行时，能产生样例所示的结果。

Input
输入2行，第1行是1个int类型的数据，第2行是1个double类型的数据。

Output
见样例。

Sample Input
120
3.14
Sample Output
A default object is created.
An integer object 120 is created.
A double object 3.14 is created.
The double object 3.14 is erased.
The integer object 120 is erased.
The default object is erased.
HINT
Append Code
append.cc, */