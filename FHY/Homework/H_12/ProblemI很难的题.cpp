#include <bits/stdc++.h>
using namespace std;

class Difficult
{
protected:
    int x$;
public:
    Difficult(int x):x$(x){}
    ~Difficult(){}
    void show()const { cout << abs(x$);}
};



int main()
{
    int a;
    cin>>a;
    Difficult difficult(a);
    difficult.show();
    return 0;
}


/* 
Problem I: 很难的题
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1621  Solved: 1375
[Submit][Status]
Description
定义一个类Difficult，只有一个int类型的数据成员。定义其构造函数，以及用于输出数据成员的绝对值的成员名函数void show()。数据成员及其绝对值都在int类型范围内。

Input
一个int类型范围内的整数。

Output
输入的数据的绝对值。

Sample Input
-100
Sample Output
100
HINT
Append Code
append.cc, */