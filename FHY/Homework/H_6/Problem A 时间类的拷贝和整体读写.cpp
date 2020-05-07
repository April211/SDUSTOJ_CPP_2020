#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int  hour$, min$, sec$;
public:
    //Constructor & Destructor :
    Time() : sec$(0), min$(0), hour$(0) {}
    Time(const Time &tt) : sec$(tt.sec$), min$(tt.min$), hour$(tt.hour$) {cout << "There was a call to the copy constructor : " << hour$ << ',' << min$ << ',' << sec$ << endl;}
    Time(int hour, int minute, int second) : sec$(second), min$(minute), hour$(hour){}
    ~Time() {}
    //Method in class Time :
    Time& setTime(int, int, int);
    Time& setTime(const Time&);
    void  showTime()const;
    inline Time& getTime();
    
};

inline void Time::showTime()const
{
    cout << setw(2) << setfill('0') << (*this).hour$ << ':' << setw(2) << setfill('0') << (*this).min$ << ':' << setw(2) << setfill('0') << (*this).sec$ << endl;
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
    cout<<"Copy constructor test output :"<<endl;
    Time t;
    Time tt(t);
    Time ttt(1, 2, 3);
    Time tttt(ttt.getTime());
    cout<<"\nTest data output :"<<endl;
 
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        if(i % 2 == 0)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            t.setTime(hour, minute, second).showTime();
        }
        if(i % 2 == 1)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            Time tt(hour, minute, second);
            t.setTime(tt).showTime();
        }
    }
}

/* Problem A: ʱ����Ŀ����������д
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 5733  Solved: 4214
[Submit][Status]
Description
��װһ��ʱ����Time������ʱ�䴦�����ع��ܣ�֧�����²�����
1. Time::Time()�޲ι��췽����
2. Time::Time(int,int,int)���췽��������ʱ��������������������
3. Time::Time(const T&)�������췽�����������캯������ʱ�����There was a call to the copy constructor : h,m,s������h,m,s��Ϊ����������ʱ������ֵ�����貹0��
4. ���������д������
   Time::setTime(int,int,int)����������ʱ�������������޸�Time�����ʱ���������÷��������޸ĺ�Ķ���
   Time::setTime(const T&)����������һ�������޸�Time�����ʱ���������÷��������޸ĺ�Ķ���
   Time::getTime()���������ض�����������á���ʵ��t.getTime()��t��
   ����Time���е�Time::getTime()����ʵ���Ƕ��࣬����ϻ��߼̳й�ϵʱ�Ż��л����õ���
5. Time::showTime()�����������hh:mm:ss����������λ��Ҫǰ�油0��
ע�⣺����Time���󴫵ݲ���ʱӦ����������ö�����ֱ�Ӵ����󣬷��ض���ʱͬ���������ã������������Ķ��󿽱���
�����һ��ʱ����Time��ʹ��main()�����ܹ���ȷ���С�
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()������main()����������΢��������Ϊ���Զ���ĸ��ֵ��������
Input
����ĵ�һ������n����ʾ��n��������ݣ�ÿ��3��������hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ���ںϷ���ʱ�䷶Χ�ڡ�
Output
��ʼ����Ϊ��main()���������Ĺ̶���������ڲ��Զ����ĳЩ�����ĵ�������������Test data output :��֮��Ϊ�������ݶ�Ӧ�������
ÿ��������ݶ�Ӧһ�������hh:mm:ss����������λ�������Ҫǰ�油0����ʽ��sample��
Sample Input
5
0 0 1
0 59 59
1 1 1
23 0 0
23 59 59
Sample Output
Copy constructor test output :
There was a call to the copy constructor : 0,0,0
There was a call to the copy constructor : 1,2,3

Test data output :
00:00:01
00:59:59
01:01:01
23:00:00
23:59:59
HINT
�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�

setw(w)   ���������ݵ�������Ϊw���ַ�

setfill(c)���������ַ�c��Ϊ����ַ�

Append Code
append.cc, */