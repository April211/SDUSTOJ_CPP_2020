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
    friend ostream& operator<<(ostream &os, const Time &tt); //���������������أ�һ����Ϊ��Ԫ
    friend istream& operator>>(istream &is, Time &tt); //����������������أ�һ����Ϊ��Ԫ

    Time operator++(int) //������
    {
        Time tt(*this);
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            ssec = (ssec + 1) % 86400;
            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return tt;
    }
    Time& operator++() //ǰ����
    {
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            ssec = (ssec + 1) % 86400;
            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return *this;
    }

    Time operator--(int)
    {
        Time tt(*this);
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            if (ssec >= 1)
            {
                ssec -= 1;
            }
            else
            {
                ssec = ssec + 86400 - 1;
            }

            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return tt;
    }
    Time& operator--()
    {
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            if (ssec >= 1)
            {
                ssec -= 1;
            }
            else
            {
                ssec = ssec + 86400 - 1;
            }

            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return *this;
    }
};

ostream& operator<<(ostream &os, const Time &tt)
{
    if ((tt.hour$ < 24) && (tt.hour$ >= 0) && (tt.min$ < 60) && (tt.min$ >= 0) && (tt.sec$ < 60) && (tt.sec$ >= 0))
    {
        os << setw(2) << setfill('0') << tt.hour$ << ':' << setw(2) << setfill('0') << tt.min$ << ':' << setw(2) << setfill('0') << tt.sec$;
    }
    else
    {
        os << "error!!!";
    }
    return os;
}
istream& operator>>(istream &is, Time &tt)
{
    int hour, min, sec;
    is >> hour; is >> min; is >> sec;
    tt.hour$ = hour; tt.min$ = min; tt.sec$ = sec;
    return is;
}

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
    Time t;
    int cases;
    cin >> cases;
    cout << setw(8) << left << "++t"
         << " ";
    cout << setw(8) << left << "--t"
         << " ";
    cout << setw(8) << left << "t"
         << " ";
    cout << setw(8) << left << "t--"
         << " ";
    cout << setw(8) << left << "t++"
         << " ";
    cout << setw(8) << left << "t" << right << endl;
    for (int i = 1; i <= cases; ++i)
    {
        cin >> t;
        cout << (++t) << " ";
        cout << (--t) << " ";
        cout << t << " ";
        cout << t-- << " ";
        cout << t++ << " ";
        cout << t << endl;
    }
}


/* Problem G: ʱ����������롢��ȡ�͵������ݼ�����
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 5363  Solved: 3610
[Submit][Status]
Description
��װһ��ʱ����Time�����������������������ʹ��main()�����ܹ���ȷ���С�
�������������>>�������������ʽ�ӱ�׼�����ȡ����������hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ��int��Χ�ڡ�
����ȡ��������<<�������ա�hh:mm:ss�����Time��Ķ��󣬲��Ϸ���ʱ�������error!!!����
ǰ�������������++������ʱ������������1�����ء�
ǰ���Լ��������--������ʱ������������1�����ء�
���������������++������ʱ������������1������ԭֵ��
�����Լ��������--������ʱ������������1������ԭֵ��
����4���������Լ����ԺϷ���ʱ����������Ҳ���������Ϸ���ʱ�䡣���磺
��ԭʱ�����Ϊ��00:00:00�����Լ������Ķ���Ϊ��23:59:59��;
��ԭʱ�����Ϊ��23:59:59�������������Ķ���Ϊ��00:00:00��;
��ԭʱ�����Ϊ��24:60:60�����������Լ�����������Ϊ��24:60:60����
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()����
Input
����ĵ�һ������n����ʾ��n��������ݣ�ÿ��3��������hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ����int��Χ�ڡ�
Output
���һ�ű�ÿ��8���ַ�������֮����һ���ո�
���ȣ����һ����ͷ����++t      --t      t        t--      t++      t       ����
��Σ���Ӧÿ�����������һ���������������ݣ�
ǰ��++��ǰ��--��ԭֵ������--������++��ԭֵ��
����������ںϷ��������ʽΪ��hh:mm:ss����������λ�������Ҫǰ�油0����������ʱ�䲻�Ϸ����������error!!!������ʽ��sample��
Sample Input
6
0 0 1
0 59 59
1 1 60
23 0 0
23 59 59
24 1 0
Sample Output
++t      --t      t        t--      t++      t       
00:00:02 00:00:01 00:00:01 00:00:01 00:00:00 00:00:01
01:00:00 00:59:59 00:59:59 00:59:59 00:59:58 00:59:59
error!!! error!!! error!!! error!!! error!!! error!!!
23:00:01 23:00:00 23:00:00 23:00:00 22:59:59 23:00:00
00:00:00 23:59:59 23:59:59 23:59:59 23:59:58 23:59:59
error!!! error!!! error!!! error!!! error!!! error!!!
HINT
�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�

setw(w)   ���������ݵ�������Ϊw���ַ�

setfill(c)���������ַ�c��Ϊ����ַ�

left      ��������������

right     ����������Ŷ���

Append Code
append.cc, */