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
        sec$ += (second % 60);     //�Ƚϰ�ȫ��д������sec$����86400ʱȡ�ࣨ���������ڱ仯�����Ա�֤�����ȷ
    }
    ~Time() {}
    //Method in class Time :
    int getHour()const;
    int getMinute()const;
    int getSecond()const;
    friend ostream& operator<< (ostream& os, const Time& tt);//���������������أ�һ����Ϊ��Ԫ
    Time& operator++ (){ ++sec$; sec$ %= 86400; return *this;}//��������ǰ����������������sec��һ��ķ�Χ֮��
    Time operator++ (int){ Time tt(*this); ++sec$; sec$ %= 86400; return tt;}//�������غ�������ע�������ڵġ�int���ͷ������͡�
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

    cout << t1 << endl;   //������������أ�����hh:mm:ss��ʽ��ʾʱ�䣬��ȱ������
    ++t1;
    cout << t1 << endl;
    Time t2(t1++);
    cout << t1 << endl;
    cout << t2 << endl;

    return 0;
}

//Ctrl + F ���Ҳ��滻�ؼ���
