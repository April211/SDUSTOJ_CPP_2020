#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hour$, min$, sec$;
public:
    //Constructor & Destructor :
    Time() : sec$(0), min$(0), hour$(0) { ++ssum; }
    Time(int hour, int minute, int second) : sec$(second), min$(minute), hour$(hour){ ++ssum;}
    Time(const Time &tt) : sec$(tt.sec$), min$(tt.min$), hour$(tt.hour$) { ++ssum; cout << "There was a call to the copy constructor : " << hour$ << ',' << min$ << ',' << sec$ << endl;}
    ~Time() {}
    //Method in class Time :

    Time& setTime(int, int, int);
    Time& setTime(const Time&);
    const Time& getTime()const;

    void  showTime()const;
    Time& inputTime();
    void showTime12Hour()const;

    static int ssum;
    static void displayNumber();
    static int getNumber();
    
};

int Time::ssum = 0;
void Time::displayNumber()
{
    cout << "Now, There is " << Time::ssum << " object of Time." << endl;
}
int Time::getNumber()
{
    return Time::ssum;
}

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
    cout<<"Static member test output :"<<endl;
    Time::displayNumber();
    Time t;
    t.displayNumber();
    Time tt(t);
    tt.displayNumber();
    Time ttt(1, 2, 3);
    ttt.displayNumber();
    Time tttt(ttt.getTime());
    tttt.displayNumber();
    int non_cases = Time::getNumber();
 
    cout<<"\nTest data output :"<<endl;
    int hour, minute, second;
    while(cin>>hour>>minute>>second)
    {
        Time t;
        t.setTime(hour, minute, second).showTime();
    }
    cout<<t.getNumber() - non_cases<<endl;
}

/* 
Problem E: ʱ����ľ�̬��Ա����
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 4658  Solved: 3461
[Submit][Status]
Description
��װһ��ʱ����Time������ʱ�䴦�����ع��ܣ�֧�����²�����
1. Time::Time()�޲ι��췽����
2. Time::Time(int,int,int)���췽��������ʱ��������������������
3. Time::Time(const T&)�������췽����
4. ���������д������
   Time::setTime(int,int,int)����������ʱ�������������޸�Time�����ʱ���������÷��������޸ĺ�Ķ���
   Time::setTime(const T&)����������һ�������޸�Time�����ʱ���������÷��������޸ĺ�Ķ���
   Time::getTime()���������ض�����������á���ʵ��t.getTime()��t��
   ����Time���е�Time::getTime()����ʵ���Ƕ��࣬����ϻ��߼̳й�ϵʱ�Ż��л����õ���
5. Time::showTime()�����������hh:mm:ss����������λ��Ҫǰ�油0����������ǺϷ���ʱ�䣬�������Time error����
6. ��̬��Ա������
   Time::getNumber()���������س������Ѵ�����Time����������
   Time::displayNumber()����������������Ѵ�����Time����������
ע�⣺����Time���󴫵ݲ���ʱӦ����������ö�����ֱ�Ӵ����󣬷��ض���ʱͬ���������ã������������Ķ��󿽱�������Ŀ�������������������Ĵ���
�����һ��ʱ����Time��ʹ��main()�����ܹ���ȷ���С�
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()������main()����������΢��������Ϊ���Զ���ĸ��ֵ��������
Input
����Ϊ���У�ÿ��Ϊһ��������ݣ�ÿ��3��������hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ����int��Χ�ڡ�
Output
��ʼ����Ϊ��main()���������Ĺ̶���������ڲ��Զ����ĳЩ�����ĵ�������������Test data output :��֮��Ϊ�������ݶ�Ӧ�������
ÿ��������ݶ�Ӧһ�������hh:mm:ss����������λ�������Ҫǰ�油0����������ʱ�䲻�Ϸ����������Time error������ʽ��sample��
���һ�����һ������n����ʾ��n������������롣
Sample Input
0 0 1
0 59 59
1 1 60
23 0 0
23 59 59
24 1 0
Sample Output
Static member test output :
Now, There is 0 object of Time.
Now, There is 1 object of Time.
There was a call to the copy constructor : 0,0,0
Now, There is 2 object of Time.
Now, There is 3 object of Time.
There was a call to the copy constructor : 1,2,3
Now, There is 4 object of Time.

Test data output :
00:00:01
00:59:59
Time error
23:00:00
23:59:59
Time error
6
HINT
Append Code
append.cc, */