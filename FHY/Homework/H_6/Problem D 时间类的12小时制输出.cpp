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
    const Time& getTime()const;

    void  showTime()const;
    Time& inputTime();
    void showTime12Hour()const;
    
};

void Time::showTime12Hour()const
{
    if((hour$ < 24 ) && (hour$ >= 0) && (min$ < 60) && (min$ >= 0) && (sec$ < 60) && (sec$ >= 0))
    {
        int hour = 0, min = 0, sec = 0;
        if(hour$ == 0)
        {
            hour = 12; min = min$; sec = sec$;
            cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << " a.m." << endl;
        }
        if(hour$ >= 1 && hour$ <= 11)
        {
            hour = hour$; min = min$; sec = sec$;
            cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << " a.m." << endl;

        }
        if(hour$ == 12)
        {
            hour = hour$; min = min$; sec = sec$;
            cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << " p.m." << endl;

        }
        if(hour$ >= 13 && hour$ <= 23)
        {
            hour = hour$ - 12; min = min$; sec = sec$;
            cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << " p.m." << endl;

        }
    }
    else 
    {
        cout << "Time error" << endl;
    }

}
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

inline const Time& Time::getTime()const
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
    cout<<"Constant test output :"<<endl;
    const Time c(11, 59, 58);
    const Time cc(12, 0, 1);
    c.showTime12Hour();
    cc.showTime12Hour();
    c.showTime();
    cc.showTime();
 
    cout<<"\nTest data output :"<<endl;
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
            tt.showTime12Hour();
        }
        if(i % 4 == 1)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            t.setTime(hour, minute, second).showTime();
        }
        if(i % 4 == 2)
            t.inputTime().showTime12Hour();
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


/* Problem D: ʱ�����12Сʱ�����
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 6978  Solved: 3864
[Submit][Status]
Description
��װһ��ʱ����Time������ʱ�䴦�����ع��ܣ�֧��24Сʱ�ƺ�12Сʱ�ƣ�֧�����²�����
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
9. Time::showTime12Hour()���������12Сʱ�Ƶ�ʱ�䣺���������hh:mm:ss a.m.�������������hh:mm:ss p.m.������������ǺϷ���ʱ�䣬�������Time error����ע�⣺�ú�������ʾ12Сʱ��ʱ�䣬�����޸Ķ�������ݳ�Ա��������Ȼ�洢24Сʱ��ʱ�䡣
12Сʱ��������12��1��2��3��4��5��6��7��8��9��10��11�������ʾÿ��ʱ�εġ�
24Сʱ�Ƶ�00:00��00:59����12Сʱ�Ƶ�12:00 a.m.��12:59 a.m.��
24Сʱ�Ƶ�1:00��11:59��ʮ��Сʱ�Ƶ�1:00 a.m.��11:59 a.m.��
24Сʱ�Ƶ�12:00��12:59����12Сʱ�Ƶ�12:00 p.m.��12:59 p.m.��
24Сʱ�Ƶ�13:00��23:59��ʮ��Сʱ�Ƶ�1:00 p.m.��11:59 p.m.��
�����һ��ʱ����Time��ʹ��main()�����ܹ���ȷ���С�
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()������main()����������΢��������Ϊ���Զ���ĸ��ֵ��������
Input
����ĵ�һ������n����ʾ��n��������ݣ�ÿ��3��������hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ����int��Χ�ڡ�
Output
��ʼ����Ϊ��main()���������Ĺ̶���������ڲ��Զ����ĳЩ�����ĵ�������������Test data output :��֮��Ϊ�������ݶ�Ӧ�������
ÿ��������ݶ�Ӧһ������������е������Ӧ���24Сʱ��ʱ�䡰hh:mm:ss����ż���е������Ӧ���12Сʱ��ʱ�䣺���������hh:mm:ss a.m.�������������hh:mm:ss p.m.����������λ�������Ҫǰ�油0����������ʱ�䲻�Ϸ����������Time error������ʽ��sample��
Sample Input
6
0 0 1
0 59 59
1 1 60
23 0 0
23 59 59
24 1 0
Sample Output
Constant test output :
11:59:58 a.m.
12:00:01 p.m.
11:59:58
12:00:01

Test data output :
00:00:01
12:59:59 a.m.
Time error
11:00:00 p.m.
23:59:59
Time error
HINT
�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�

setw(w)   ���������ݵ�������Ϊw���ַ�

setfill(c)���������ַ�c��Ϊ����ַ�

Append Code
append.cc, */