#include <iostream>
#include <iomanip>
using namespace std;

class Teacher
{
protected:
    double basicsalary$;
public:
    Teacher(double basicsalary):basicsalary$(basicsalary){ cout << "Teacher's constructor." << endl;}
    virtual ~Teacher(){cout << "Teacher's deconstructor." << endl;}
    virtual double getSalary()const = 0;
};


class HighSchoolTeacher: public Teacher
{
protected:
    int entersum$;
public:
    HighSchoolTeacher(double basicsalary, int entersum):Teacher(basicsalary), entersum$(entersum){ cout << "HighSchoolTeacher's constructor." << endl;}
    ~HighSchoolTeacher(){cout << "HighSchoolTeacher's deconstructor." << endl;}
    virtual double getSalary()const {return (basicsalary$ + entersum$* 100);}
};

class UniversityTeacher: public Teacher
{
protected:
    double perfhour$;
public:
    UniversityTeacher(double basicsalary, int perfhour):Teacher(basicsalary), perfhour$(perfhour){ cout << "UniversityTeacher's constructor." << endl;}
    ~UniversityTeacher(){cout << "UniversityTeacher's deconstructor." << endl;}
    virtual double getSalary()const 
    {
        if(perfhour$ < 240)
        {
            return (basicsalary$ - 20* (240 - perfhour$));
        }
        else
        {
            return (basicsalary$ + 40* (perfhour$ - 240));
        }
    }
};




int main()
{
    int N, i, m;
    char ch;
    double basis;
    Teacher *t;
    cin>>N;
    for (i = 0; i < N; i++)
    {
        cin>>ch>>basis>>m;
        if (ch == 'h')
            t = new HighSchoolTeacher(basis, m);
        else if (ch == 'u')
            t  = new UniversityTeacher(basis, m);
        cout<<setprecision(2)<<setiosflags(ios::fixed)<<t->getSalary()<<endl;
        delete t;
    }
    return 0;
}
/* 



Problem B: ��ʦ�Ĺ���
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1101  Solved: 679
[Submit][Status]
Description
���������ʦ�ʹ�ѧ��ʦ�Ĺ��ʷֱ�����ô����ģ�

1.������ʦ�Ĺ����ǻ�������+�������н�������ѧ��ѧ��������100��

2.��ѧ��ʦ�Ĺ����ǻ�������+��Ч�����е���ѧ��Сʱ������240Сʱʱ��ÿ��1��Сʱ����20Ԫ����Сʱ������240Сʱʱ��ÿ��1��Сʱ���෢40Ԫ��

�磺����ʦ��һ��������ʦ�����Ļ���������1000Ԫ����5��ѧ���ɹ���ѧ�����乤����1000+5*100=1500Ԫ��

����ʦ��һ����ѧ��ʦ������������2000Ԫ�����ֻ�����200Сʱ���ڿΣ�������2000-40*20=1200Ԫ����������250Сʱ���ڿΣ�������2000+10*40=2400Ԫ��

���ڣ�����Teacher��HighSchoolTeacher��UniversityTeacher�Ĺ��캯��������������getSalary������ʹ��main��������ȷִ�в����������ʾ�Ľ����

Input
�����ж��С�

��1��N>0����ʾ������N������������

ÿ������ռ1�У�����1���ַ���1��double����1��int������Ϊ������

Output
��������

Sample Input
4
h 2900.13 20
u 3911.23 210
u 3911.34 250
h 3911.15 10
Sample Output
Teacher's constructor.
HighSchoolTeacher's constructor.
4900.13
HighSchoolTeacher's deconstructor.
Teacher's deconstructor.
Teacher's constructor.
UniversityTeacher's constructor.
3311.23
UniversityTeacher's deconstructor.
Teacher's deconstructor.
Teacher's constructor.
UniversityTeacher's constructor.
4311.34
UniversityTeacher's deconstructor.
Teacher's deconstructor.
Teacher's constructor.
HighSchoolTeacher's constructor.
4911.15
HighSchoolTeacher's deconstructor.
Teacher's deconstructor.
HINT
Append Code
append.cc, */