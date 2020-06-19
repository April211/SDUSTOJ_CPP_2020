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

Problem C: ʱ��֮��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2405  Solved: 1381
[Submit][Status]
Description
����һ����Time������Сʱ�����ӡ����������ԡ������乹�캯��Time(int, int, int)�ֱ��ʼ����Сʱ�����ӡ��롣���ؼ��������������������ʱ��֮�������������Ǹ���������

Input
������2�С�ÿ�б�ʾ1��ʱ�䣬����Сʱ�����ӡ�������ֵ�����붼�ǺϷ���24Сʱ�Ƶ�ʱ�䡣

Output
��������

Sample Input
12 10 10
10 20 20
Sample Output
Deference is 6590 seconds.
HINT
Append Code
append.cc,
 */