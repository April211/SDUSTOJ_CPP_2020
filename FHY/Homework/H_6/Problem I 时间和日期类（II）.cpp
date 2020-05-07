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
    void setTime(int, int, int);
    friend class DateTime;


};

void Time::setTime(int hh, int mm, int ss)
{
    hour$ = hh; min$ = mm; sec$ = ss;
}

inline void Time::showTime() const
{
        cout << setw(2) << setfill('0') << (*this).hour$ << ':' << setw(2) << setfill('0') << (*this).min$ << ':' << setw(2) << setfill('0') << (*this).sec$;
}

class Date
{
private:
    int yyyy$, mm$, dd$;
public:
    Date() : yyyy$(1), mm$(1), dd$(1) {}
    Date(int yyyy, int mm, int dd) : yyyy$(yyyy), mm$(mm), dd$(dd) {}
    Date(const Date &tt) : yyyy$(tt.yyyy$), mm$(tt.mm$), dd$(tt.dd$) {}
    ~Date(){}
    void showDate()const;
    friend class DateTime;
    void setDate(int, int, int);
};

inline void Date::setDate(int yyyy, int mm, int dd)
{
    yyyy$ = yyyy; mm$ = mm; dd$ = dd;
}

inline void Date::showDate()const
{
    cout << setw(4) << setfill('0') << yyyy$ << '-' << setw(2) << setfill('0') << mm$ << '-' << setw(2) << setfill('0') << dd$;
}

class DateTime
{
private:
    Time time$;
    Date date$;
public:
    DateTime() : time$(0, 0, 0), date$(1, 1, 1) {}
    DateTime(const Date& tdate,const Time& ttime):time$(ttime), date$(tdate){} 
    DateTime(int yyyy, int mm, int dd, int hour, int min, int sec) : time$(hour, min, sec), date$(yyyy, mm, dd) {}
    ~DateTime(){}
    //
    void showDateTime()const;
    DateTime& setDateTime(int, int, int, int, int, int);
};

inline DateTime& DateTime::setDateTime(int yyyy, int mm, int dd, int hour, int min, int sec)
{   
    time$.hour$ = hour; time$.min$ = min; time$.sec$ = sec;
    date$.yyyy$ = yyyy; date$.mm$  = mm;  date$.dd$  = dd;
    return *this;
}

inline void DateTime::showDateTime()const
{
    date$.showDate();
    cout << ' ';
    time$.showTime();
}

int main()
{
    Date date(1000, 10, 10);
    Time time(1, 1, 1);
    DateTime date_time(date, time);
    date_time.showDateTime();
    cout << endl;
    int cases, flag = 0;
    cin >> cases;
    for(int ca = 0; ca < cases; ca++)
    {
        int year, month, day;
        cin >> year >> month >> day;
        int hour, minute, second;
        cin >> hour >> minute >> second;
        if(flag == 0)
        {
            flag = 1;
            DateTime dt(year, month, day, hour, minute, second);
            dt.showDateTime();
        }
        else if(flag == 1)
        {
            flag == 0;
            date_time.setDateTime(year, month, day, hour, minute, second).showDateTime();
        }
        cout << endl;
    }
}



/* Problem I: ʱ��������ࣨII��
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 4555  Solved: 3399
[Submit][Status]
Description
���һ������ʱ���࣬���ڶ�ȡ��������ݣ�����ʽ������ں�ʱ�䡣

�������ʱ����DateTime��2����Ա��ɣ��ֱ���һ��Date������һ��Time�����

���DateTime����֧�����²�����

DateTime::DateTime()�޲ι��췽������ʼ��Ϊ1��1��1�ա�0ʱ0��0�룻

DateTime::DateTime(const Date&,const Time&)���췽�������ղ�����������ں�ʱ���ʼ������

DateTime::DateTime(int,int,int,int,int,int)���췽�������ղ�����˳��Ϊ�����ա�ʱ���룩��ʼ������

DateTime::showDateTime()����������ʽ���DateTime����

DateTime::setDateTime(int,int,int,int,int,int)���������ղ�����˳��Ϊ�����ա�ʱ���룩�޸Ķ��������ֵ��

DateTime������������ࣺDate���Time��

���������Date��֧�����²�����

Date::Date()�޲ι��췽������ʼ��Ϊ1��1��1��

Date::Date(int,int,int)���췽��������Ĳ�������Ϊ�����գ��ò��������ڳ�ʼ����

Date::showDate()����������ʽ���Date����

Date::setDate(int,int,int)����������Ĳ�������Ϊ�����գ��ò����޸Ķ��������ֵ

���ʱ����Time��֧�����²�����

Time::Time()�޲ι��췽������ʼ��Ϊ0ʱ0��0��

Time::Time(int,int,int)���췽��������Ĳ�������Ϊʱ���룬�ò�����ʱ���ʼ����

Time::showTime()����������ʽ���Time����

Time::setTime(int,int,int)����������Ĳ�������Ϊʱ���룬�ò����޸Ķ��������ֵ

-----------------------------------------------------------------------------

�����DateTime�ࡢDate���Time�࣬ʹ��main()�����ܹ���ȷ���С�

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
1000-10-10 01:01:01
1982-10-01 00:00:00
2000-02-28 23:59:59
2014-07-02 13:30:01
HINT
�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�

setw(w)   ���������ݵ�������Ϊw���ַ�

setfill(c)���������ַ�c��Ϊ����ַ�

Append Code
append.cc, */