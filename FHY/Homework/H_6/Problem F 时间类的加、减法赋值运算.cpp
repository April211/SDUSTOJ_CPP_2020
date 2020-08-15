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


/* Problem F: 时间类的加、减法赋值运算
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 7746  Solved: 4814
[Submit][Status]
Description
封装一个时间类Time，在类上重载以下运算符，使得main()函数能够正确运行。
1. Time::Time()无参构造方法。
2. Time::inputTime()方法：按格式从标准输入读取数据修改Time对象的时分秒数值。该方法返回修改后的对象。
3. Time::showTime()方法：输出“hh:mm:ss”，不足两位的要前面补0。如果对象不是合法的时间，则输出“Time error”。
4. 运算符
加法赋值运算符“+=”和减法赋值运算符“-=”：把一个整数m加到Time对象自身，并且仅对合法的时间操作，不会产生不合法的时间，比如：
若原时间对象为“00:00:00”，减去2后的对象为“23:59:58”;
若原时间对象为“23:59:59”，加上1后的对象为“00:00:00”;
若原时间对象为“24:60:60”，加减后的对象仍为“24:60:60”
函数调用格式见append.cc。
append.cc中已给出main()函数
Input
输入的第一个整数n，表示有n组测试数据，每组4个整数，前三个整数为：hh,mm,ss，分别表示时、分、秒，其值都在int范围内，最后一个整数为m。
Output
每个输入对应两行输出，分别为时间“hh,mm,ss”加上m秒和减去m秒后的值。错误的时间输出“Time error”
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
输出格式用头文件<iomanip>中流操作算子：

setw(w)   ：设置数据的输出宽度为w个字符

setfill(c)：设置用字符c作为填充字符

left      ：设置输出左对齐

right     ：设置输出优对齐

Append Code
append.cc, */