#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int h$, m$, s$;
public:
    Time(int h, int m, int s):h$(h), m$(m), s$(s){}
    Time():h$(0), m$(0), s$(0){}

    int hour()const{return h$;}
    int minute()const{return m$;}
    int second()const{return s$;}
    void hour(int hh){ h$ = hh; }
    void minute(int mm){ m$ = mm; }
    void second(int ss){ s$ = ss; }
//    void showTime()const;
};
//void Time::showTime()const
//{
//    cout << setw(2) << setfill('0') << h$ << ':' << setw(2) << setfill('0') << m$ << ':' << setw(2) << setfill('0') << s$ << endl;
//}




int main()
{
    Time t;
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        int hour, minute, second;
        cin>>hour>>minute>>second;
        t.hour(hour);
        t.minute(minute);
        t.second(second);
        cout<<setw(2)<<setfill('0')<<t.hour()<<":";
        cout<<setw(2)<<setfill('0')<<t.minute()<<":";
        cout<<setw(2)<<setfill('0')<<t.second()<<endl;
    }
}



//Problem I: ʱ����ĳ�Ա��д
//Time Limit: 4 Sec  Memory Limit: 128 MB
//Submit: 6038  Solved: 5105
//[Submit][Status]
//Description
//��װһ��ʱ����Time������ʱ�䴦�����ع��ܣ�֧�����²�����
//1. Time::Time()�޲ι��췽����
//2. ��Ա��������
//   Time::hour()  ������Time��Сʱ����
//   Time::minute()������Time�ķ�������
//   Time::second()������Time��������
//3. ��Աд������
//   Time::hour(int)  �������޸�Time��Сʱ����
//   Time::minute(int)�������޸�Time�ķ�������
//   Time::second(int)�������޸�Time��������
//�����һ��ʱ����Time��ʹ��main()�����ܹ���ȷ���С�
//�������ø�ʽ��append.cc��
//append.cc���Ѹ���main()������
//Input
//����ĵ�һ������n����ʾ��n��������ݣ�ÿ��3��������hh,mm,ss���ֱ��ʾʱ���֡��룬��ֵ���ںϷ���ʱ�䷶Χ�ڡ�
//Output
//ÿ��������ݶ�Ӧһ�������hh:mm:ss����������λ�������Ҫǰ�油0����ʽ��sample��
//Sample Input
//5
//0 0 1
//0 59 59
//1 1 1
//23 0 0
//23 59 59
//Sample Output
//00:00:01
//00:59:59
//01:01:01
//23:00:00
//23:59:59
//HINT
//�����ʽ��ͷ�ļ�<iomanip>�����������ӣ�
//
//setw(w)   ���������ݵ�������Ϊw���ַ�
//
//setfill(c)���������ַ�c��Ϊ����ַ�
//
//Append Code
//append.cc,
