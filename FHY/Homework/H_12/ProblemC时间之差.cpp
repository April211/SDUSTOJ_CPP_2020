#include <bits/stdc++.h>
using namespace std;

class Time
{
protected:
    int hh$, mm$, ss$;
public:
    Time(int hh, int mm, int ss):hh$(hh), mm$(mm), ss$(ss){}
    ~Time(){}
    int operator- (const Time& tt)
    {
        int ssum1 = 0, ssum2 = 0;
        ssum1 = (*this).hh$* 3600 + (*this).mm$* 60 + (*this).ss$;
        ssum2 = tt.hh$* 3600 + tt.mm$* 60 + tt.ss$;
        return abs(ssum1 - ssum2);
    }
};



int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    Time t1(a, b, c);
    cin>>a>>b>>c;
    Time t2(a, b, c);
    cout<<"Deference is "<<(t2 - t1)<<" seconds."<<endl;
    return 0;
}

/* 

Problem C: 时间之差
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2405  Solved: 1381
[Submit][Status]
Description
定义一个类Time，包含小时、分钟、秒三个属性。定义其构造函数Time(int, int, int)分别初始化其小时、分钟、秒。重载减法运算符，用于求两个时间之间相差的秒数（非负整数）。

Input
输入有2行。每行表示1个时间，包括小时、分钟、秒三个值。输入都是合法的24小时制的时间。

Output
见样例。

Sample Input
12 10 10
10 20 20
Sample Output
Deference is 6590 seconds.
HINT
Append Code
append.cc,
 */