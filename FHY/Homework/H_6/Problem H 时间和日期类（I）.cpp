#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hour$, min$, sec$;
public:
    //Constructor & Destructor :
    Time() : sec$(0), min$(0), hour$(0) {}
    Time(int hour, int minute, int second) : sec$(second), min$(minute), hour$(hour) {}
    Time(const Time &tt) : sec$(tt.sec$), min$(tt.min$), hour$(tt.hour$) {}
    ~Time() {}
    //Method in class Time :
    void showTime() const;


};
inline void Time::showTime() const
{
        cout << setw(2) << setfill('0') << (*this).hour$ << ':' << setw(2) << setfill('0') << (*this).min$ << ':' << setw(2) << setfill('0') << (*this).sec$;
}

class Date
{
private:
    int yyyy$, mm$, dd$;
public:
    Date(int yyyy, int mm, int dd) : yyyy$(yyyy), mm$(mm), dd$(dd) {}
    Date() : yyyy$(-1), mm$(-1), dd$(-1) {}
    ~Date(){}
    void showDate()const;


};

inline void Date::showDate()const
{
    cout << setw(4) << setfill('0') << yyyy$ << '-' << setw(2) << setfill('0') << mm$ << '-' << setw(2) << setfill('0') << dd$;
}


int main()
{
    int cases;
    cin >> cases;
    for(int ca = 0; ca < cases; ca++)
    {
        int year, month, day;
        cin >> year >> month >> day;
        Date date(year, month, day);
        date.showDate();
        cout << " ";
        int hour, minute, second;
        cin >> hour >> minute >> second;
        Time time(hour, minute, second);
        time.showTime();
        cout << endl;
    }
}


/* Problem H: ʱ��������ࣨI��
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 7325  Solved: 4203
[Submit][Status]
Description
���һ��ʱ�����һ�������࣬���ڶ�ȡ��������ݣ�����ʽ������ں�ʱ�䡣

���������Date��֧�����²�����
Date::Date(int,int,int)���췽��������Ĳ�������Ϊ�����գ��ò��������ڳ�ʼ����
Date::showDate()����ʽ���Date����

���ʱ����Time��֧�����²�����
Time::Time(int,int,int)���췽��������Ĳ�������Ϊʱ���룬�ò�����ʱ���ʼ����
Time::showTime()����ʽ���Time����

-----------------------------------------------------------------------------

�����Date���Time�࣬ʹ��main()�����ܹ���ȷ���С�

�������ø�ʽ��append.cc��

append.cc���Ѹ���main()������
Input
����ĵ�һ������n����ʾ��n��������ݡ�

���������ÿ��Ϊһ��������ݡ�ÿ��������ݵ�ǰ3�����������ڵ������գ���3��������ʱ���ʱ���롣

Output
ÿ��������ݶ�Ӧһ����������ڵ������ʽΪ��yyyy-mm-dd����ʱ��������ʽΪ��hh:mm:ss�����м���һ���ո�ֿ���

Sample Input
3
1982 10 1 0 0 0
2000 2 28 23 59 59
2014 7 2 13 30 01
Sample Output
1982-10-01 00:00:00
2000-02-28 23:59:59
2014-07-02 13:30:01
HINT
�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�

setw(w)   ���������ݵ�������Ϊw���ַ�

setfill(c)���������ַ�c��Ϊ����ַ�

Append Code
append.cc, */