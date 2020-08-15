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


/* Problem D: 时间类的12小时制输出
Time Limit: 4 Sec  Memory Limit: 128 MB
Submit: 6978  Solved: 3864
[Submit][Status]
Description
封装一个时间类Time，用于时间处理的相关功能，支持24小时制和12小时制，支持以下操作：
1. Time::Time()无参构造方法。
2. Time::Time(int,int,int)构造方法：传递时分秒的三个参数构造对象。
3. Time::Time(const T&)拷贝构造方法。
4. 成员读函数：
   Time::hour()  ：返回Time的小时数；
   Time::minute()：返回Time的分钟数；
   Time::second()：返回Time的秒数。
5. 成员写函数：
   Time::hour(int)  ：传参修改Time的小时数；
   Time::minute(int)：传参修改Time的分钟数；
   Time::second(int)：传参修改Time的秒数。
6. 对象整体读写方法：
   Time::setTime(int,int,int)方法：传递时分秒三个参数修改Time对象的时分秒数。该方法返回修改后的对象。
   Time::setTime(const T&)方法：传递一个参数修改Time对象的时分秒数。该方法返回修改后的对象。
   Time::getTime()方法：返回对象自身的引用。其实，t.getTime()即t。
   仅在Time类中的Time::getTime()方法实在是多余，在组合或者继承关系时才会有机会用到。
7. Time::inputTime()方法：按格式从标准输入读取数据修改Time对象的时分秒数值。该方法返回修改后的对象。
8. Time::showTime()方法：输出“hh:mm:ss”，不足两位的要前面补0。如果对象不是合法的时间，则输出“Time error”。
9. Time::showTime12Hour()方法：输出12小时制的时间：上午输出“hh:mm:ss a.m.”、下午输出“hh:mm:ss p.m.”。如果对象不是合法的时间，则输出“Time error”。注意：该函数仅显示12小时制时间，并不修改对象的数据成员，对象依然存储24小时制时间。
12小时制以数字12、1、2、3、4、5、6、7、8、9、10、11依次序表示每个时段的。
24小时制的00:00～00:59，是12小时制的12:00 a.m.～12:59 a.m.；
24小时制的1:00～11:59是十二小时制的1:00 a.m.～11:59 a.m.。
24小时制的12:00～12:59，是12小时制的12:00 p.m.～12:59 p.m.；
24小时制的13:00～23:59是十二小时制的1:00 p.m.～11:59 p.m.。
你设计一个时间类Time，使得main()函数能够正确运行。
函数调用格式见append.cc。
append.cc中已给出main()函数。main()函数内容稍微繁复，仅为测试对象的各种调用情况。
Input
输入的第一个整数n，表示有n组测试数据，每组3个整数：hh,mm,ss，分别表示时、分、秒，其值都在int范围内。
Output
开始部分为由main()函数产生的固定输出，用于测试对象的某些方法的调用情况。输出“Test data output :”之后为测试数据对应的输出：
每组测试数据对应一组输出，奇数行的输入对应输出24小时制时间“hh:mm:ss”，偶数行的输入对应输出12小时制时间：上午输出“hh:mm:ss a.m.”、下午输出“hh:mm:ss p.m.”，不足两位的输出需要前面补0。如果输入的时间不合法，则输出“Time error”。格式见sample。
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
输出格式用头文件<iomanip>中流操作算子：

setw(w)   ：设置数据的输出宽度为w个字符

setfill(c)：设置用字符c作为填充字符

Append Code
append.cc, */