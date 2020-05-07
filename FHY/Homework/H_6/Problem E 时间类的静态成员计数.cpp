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
Problem E: 时间类的静态成员计数
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 4658  Solved: 3461
[Submit][Status]
Description
封装一个时间类Time，用于时间处理的相关功能，支持以下操作：
1. Time::Time()无参构造方法。
2. Time::Time(int,int,int)构造方法：传递时分秒的三个参数构造对象。
3. Time::Time(const T&)拷贝构造方法。
4. 对象整体读写方法：
   Time::setTime(int,int,int)方法：传递时分秒三个参数修改Time对象的时分秒数。该方法返回修改后的对象。
   Time::setTime(const T&)方法：传递一个参数修改Time对象的时分秒数。该方法返回修改后的对象。
   Time::getTime()方法：返回对象自身的引用。其实，t.getTime()即t。
   仅在Time类中的Time::getTime()方法实在是多余，在组合或者继承关系时才会有机会用到。
5. Time::showTime()方法：输出“hh:mm:ss”，不足两位的要前面补0。如果对象不是合法的时间，则输出“Time error”。
6. 静态成员方法：
   Time::getNumber()方法：返回程序中已创建的Time对象总数。
   Time::displayNumber()方法：输出程序中已创建的Time对象总数。
注意：在用Time对象传递参数时应传对象的引用而不是直接传对象，返回对象时同样返回引用，以免产生多余的对象拷贝。多余的拷贝构造会引起对象计数的错误。
你设计一个时间类Time，使得main()函数能够正确运行。
函数调用格式见append.cc。
append.cc中已给出main()函数。main()函数内容稍微繁复，仅为测试对象的各种调用情况。
Input
输入为多行，每行为一组测试数据，每组3个整数：hh,mm,ss，分别表示时、分、秒，其值都在int范围内。
Output
开始部分为由main()函数产生的固定输出，用于测试对象的某些方法的调用情况。输出“Test data output :”之后为测试数据对应的输出：
每组测试数据对应一组输出“hh:mm:ss”，不足两位的输出需要前面补0。如果输入的时间不合法，则输出“Time error”。格式见sample。
最后一行输出一个整数n，表示有n组测试数据输入。
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