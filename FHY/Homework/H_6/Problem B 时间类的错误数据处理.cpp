#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int  hour$, min$, sec$;
public:
    //Constructor & Destructor :
    Time() : sec$(0), min$(0), hour$(0) {}
    Time(int hour, int minute, int second) : sec$(second), min$(minute), hour$(hour){}
    Time(const Time &tt) : sec$(tt.sec$), min$(tt.min$), hour$(tt.hour$) {cout << "There was a call to the copy constructor : " << hour$ << ',' << min$ << ',' << sec$ << endl;}
    ~Time() {}
    //Method in class Time :
    int hour()const {return hour$;}
    int minute()const {return min$;}
    int second()const {return sec$;}

    void hour(int th){hour$ = th;}
    void minute(int tm){min$ = tm;}
    void second(int ts){sec$ = ts;}

    Time& setTime(int, int, int);
    Time& setTime(const Time&);
    void  showTime()const;
    Time& getTime();
    Time& inputTime();
    
};

inline Time& Time::inputTime()
{
    int hour, min, sec;
    cin >> hour; cin >> min; cin >> sec;
    hour$ = hour;
    min$ = min;
    sec$ = sec;
    return *this; 

}
inline void Time::showTime()const
{
    if((hour$ < 24 ) && (hour$ >= 0) && (min$ < 60) && (min$ >= 0) && (sec$ < 60) && (sec$ >= 0))
    {
        cout << setw(2) << setfill('0') << (*this).hour$ << ':' << setw(2) << setfill('0') << (*this).min$ << ':' << setw(2) << setfill('0') << (*this).sec$ << endl;
    }
    else 
    {
        cout << "Time error" << endl;
    }
    
}

inline Time& Time::getTime()
{
    return *this;
}
inline Time& Time::setTime(int hour, int minute, int second)
{
    sec$ = second; 
    min$ = minute;
    hour$ = hour;
    return *this;

}
inline Time& Time::setTime(const Time& tt)
{
    sec$ = tt.sec$; min$ = tt.min$; hour$ = tt.hour$;
    return *this;

}

int main()
{
    Time t;
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        if(i % 4 == 0)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            Time tt(hour, minute, second);
            tt.showTime();
        }
        if(i % 4 == 1)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            t.setTime(hour, minute, second).showTime();
        }
        if(i % 4 == 2)
            t.inputTime().showTime();
        if(i % 4 == 3)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            t.hour(hour);
            t.minute(minute);
            t.second(second);
            t.showTime();
        }
    }
}


/* Problem B: ʱ����Ĵ������ݴ���
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 5565  Solved: 3789
[Submit][Status]
Description
��װһ��ʱ����Time������ʱ�䴦�����ع��ܣ�֧�����²�����
1. Time::Time()�޲ι��췽����
2. Time::Time(int,int,int)���췽��������ʱ��������������������
3. Time::Time(const T&)�������췽����
4. ��Ա��������
   Time::hour()  ������Time��Сʱ����
   Time::minute()������Time�ķ�������
   Time::second()������Time��������
5. ��Աд������
   Time::hour(int)  �������޸�Time��Сʱ����
   Time::minute(int)�������޸�Time�ķ�������
   Time::second(int)�������޸�Time��������
6. ���������д������
   Time::setTime(int,int,int)����������ʱ�������������޸�Time�����ʱ���������÷��������޸ĺ�Ķ���
   Time::setTime(const T&)����������һ�������޸�Time�����ʱ���������÷��������޸ĺ�Ķ���
   Time::getTime()���������ض�����������á���ʵ��t.getTime()��t��
   ����Time���е�Time::getTime()����ʵ���Ƕ��࣬����ϻ��߼̳й�ϵʱ�Ż��л����õ���
7. Time::inputTime()����������ʽ�ӱ�׼�����ȡ�����޸�Time�����ʱ������ֵ���÷��������޸ĺ�Ķ���
8. Time::showTime()�����������hh:mm:ss����������λ��Ҫǰ�油0����������ǺϷ���ʱ�䣬�������Time error����
�����һ��ʱ����Time��ʹ��main()�����ܹ���ȷ���С�
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()������main()����������΢��������Ϊ���Զ���ĸ��ֵ��������
Input
����ĵ�һ������n����ʾ��n��������ݣ�ÿ��3��������hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ����int��Χ�ڡ�
Output
ÿ��������ݶ�Ӧһ�������hh:mm:ss����������λ�������Ҫǰ�油0����������ʱ�䲻�Ϸ����������Time error������ʽ��sample��
Sample Input
6
0 0 1
0 59 59
1 1 60
23 0 0
23 59 59
24 1 0
Sample Output
00:00:01
00:59:59
Time error
23:00:00
23:59:59
Time error
HINT
�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�

setw(w)   ���������ݵ�������Ϊw���ַ�

setfill(c)���������ַ�c��Ϊ����ַ�

Append Code
append.cc, */