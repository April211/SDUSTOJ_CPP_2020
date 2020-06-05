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
    Time &inputTime();

    void operator+=(int num)
    {
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            num %= 86400;
            int ssec = 0;
            ssec += (*this).hour$* 3600;
            ssec += (*this).min$* 60;
            ssec += (*this).sec$;
            ssec = (ssec + num) % 86400;
            (*this).hour$ =  (ssec / 3600) % 24;
            (*this).min$  =  (ssec % 3600) / 60;
            (*this).sec$  =  (ssec % 60);
        }
        else
        {
            //
        }
    }
    void operator-=(int num)
    {
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            num %= 86400;
            int ssec = 0;
            ssec += (*this).hour$* 3600;
            ssec += (*this).min$* 60;
            ssec += (*this).sec$;
            if(ssec >= num)
            {
                ssec -= num;
            }
            else
            {
                ssec = ssec + 86400 - num;
            }
            
            
            (*this).hour$ =  (ssec / 3600) % 24;
            (*this).min$  =  (ssec % 3600) / 60;
            (*this).sec$  =  (ssec % 60);
        }
        else
        {
            //
        }
    }
};

inline Time &Time::inputTime()
{
    int hour, min, sec;
    cin >> hour;
    cin >> min;
    cin >> sec;
    hour$ = hour;
    min$ = min;
    sec$ = sec;
    return *this;
}

inline void Time::showTime() const
{
    if ((hour$ < 24) && (hour$ >= 0) && (min$ < 60) && (min$ >= 0) && (sec$ < 60) && (sec$ >= 0))
    {
        cout << setw(2) << setfill('0') << (*this).hour$ << ':' << setw(2) << setfill('0') << (*this).min$ << ':' << setw(2) << setfill('0') << (*this).sec$ << endl;
    }
    else
    {
        cout << "Time error" << endl;
    }
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        Time t;
        t.inputTime();
        Time tt(t);
        int num;
        cin >> num;
        t += num;
        t.showTime();
        tt -= num;
        tt.showTime();
    }
}


/* Problem F: ʱ����ļӡ�������ֵ����
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 8239  Solved: 5199
[Submit][Status]
Description
��װһ��ʱ����Time�����������������������ʹ��main()�����ܹ���ȷ���С�
1. Time::Time()�޲ι��췽����
2. Time::inputTime()����������ʽ�ӱ�׼�����ȡ�����޸�Time�����ʱ������ֵ���÷��������޸ĺ�Ķ���
3. Time::showTime()�����������hh:mm:ss����������λ��Ҫǰ�油0����������ǺϷ���ʱ�䣬�������Time error����
4. �����
�ӷ���ֵ�������+=���ͼ�����ֵ�������-=������һ������m�ӵ�Time�����������ҽ��ԺϷ���ʱ�����������������Ϸ���ʱ�䣬���磺
��ԭʱ�����Ϊ��00:00:00������ȥ2��Ķ���Ϊ��23:59:58��;
��ԭʱ�����Ϊ��23:59:59��������1��Ķ���Ϊ��00:00:00��;
��ԭʱ�����Ϊ��24:60:60�����Ӽ���Ķ�����Ϊ��24:60:60��
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()����
Input
����ĵ�һ������n����ʾ��n��������ݣ�ÿ��4��������ǰ��������Ϊ��hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ����int��Χ�ڣ����һ������Ϊm��
Output
ÿ�������Ӧ����������ֱ�Ϊʱ�䡰hh,mm,ss������m��ͼ�ȥm����ֵ�������ʱ�������Time error��
Sample Input
6
0 0 1 2
0 59 59 1
1 1 60 10
23 0 0 60
23 59 59 100
24 1 0 3
Sample Output
00:00:03
23:59:59
01:00:00
00:59:58
Time error
Time error
23:01:00
22:59:00
00:01:39
23:58:19
Time error
Time error
HINT
�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�

setw(w)   ���������ݵ�������Ϊw���ַ�

setfill(c)���������ַ�c��Ϊ����ַ�

left      ��������������

right     ����������Ŷ���

Append Code
append.cc, */