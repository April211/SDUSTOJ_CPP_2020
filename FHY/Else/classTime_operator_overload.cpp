#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int sec$;
public:
    //Constructor & Destructor :
    Time() : sec$(0) {}
    Time(int second) : sec$(second) {}
    Time(const Time& tt) : sec$(tt.sec$) {}
    Time(int hour, int minute, int second) : sec$(0)
    {
        sec$ += (hour % 24) * 3600;
        sec$ += (minute % 60) * 60;
        sec$ += (second % 60);     //比较安全的写法，当sec$超过86400时取余（不考虑日期变化），以保证输出正确
    }
    ~Time() {}
    //Method in class Time :
    int getHour()const;
    int getMinute()const;
    int getSecond()const;
    friend ostream& operator<< (ostream& os, const Time& tt);//声明输出运算符重载，一般设为友元
    Time& operator++ (){ ++sec$; sec$ %= 86400; return *this;}//定义重载前自增，尽量保持总sec在一天的范围之内
    Time operator++ (int){ Time tt(*this); ++sec$; sec$ %= 86400; return tt;}//定义重载后自增，注意括号内的“int”和返回类型。
};

ostream& operator<< (ostream& os, const Time& tt)
{
    os << "Now time is : " << setw(2) << setfill('0') << tt.getHour() << ':' << setw(2) << setfill('0') << tt.getMinute()
    << ':' << setw(2) << setfill('0') << tt.getSecond();
    return os;
}

int Time::getHour()const
{
    int hour(0);
    hour = (sec$ / 3600) % 24;
    return hour;
}
int Time::getMinute()const
{
    int minute(0);
    minute = (sec$ % 3600) / 60;
    return minute;
}
int Time::getSecond()const
{
    int second(0);
    second = sec$ % 60;
    return second;
}


int main()
{
    int sec = 6722;
    Time t1(sec);

    cout << t1 << endl;   //调用运算符重载，按照hh:mm:ss格式显示时间，空缺处补零
    ++t1;
    cout << t1 << endl;
    Time t2(t1++);
    cout << t1 << endl;
    cout << t2 << endl;

    return 0;
}

//Ctrl + F 查找并替换关键字
