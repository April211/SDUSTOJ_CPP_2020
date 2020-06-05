#include <bits/stdc++.h>
using namespace std;

class Student
{
protected:
    string name$;
    int    score$;
public:
    Student():name$(""), score$(0){}
    void setStudent(string ttn, int tts){name$ = ttn; score$ = tts;}
    friend bool operator> (Student, Student);
    friend ostream& operator<< (ostream&, const Student&);
};

ostream& operator<< (ostream& os, const Student& tt)
{
    os << tt.score$ << ' ' << tt.name$;
    return os;
}

bool operator> (Student s1, Student s2)
{
    if((s1.score$ > s2.score$) || ((s1.score$ == s2.score$)&&(s1.name$ < s2.name$))){return true;}
    else {return false;}
}



int main()
{
    int cases;
    string name;
    int score;
    cin>>cases;
    Student students[cases], temp;
    for (int i = 0; i < cases; i++)
    {
       cin>>name>>score;
       students[i].setStudent(name, score);
    }
    for (int i = 0; i < cases; i++)
    {
        for (int j = 0; j < cases - i - 1; j++)
        {
            if (!(students[j] > students[j + 1]))
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < cases; i++)
        cout<<students[i]<<endl;
    return 0;
}


/* Problem D: �ɼ�����
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3971  Solved: 3101
[Submit][Status]
Description
����Student�ࣺ

1. ���ݳ�Աstring name��int score��ʾһ��ѧ�����������ɼ���

2. �޲ι��캯����

3. void setStudent(string,int)��������������һ��ѧ��������ֵ��

4. ����>���������������Student��Ķ���A��B�Ĵ�С��ϵ��A>B����ΪA.score>B.score������A.score=B.score��A.name<B.name��

5.���������<<�������ѧ����Ϣ��������ɼ�������������м���һ���ո������

Input
�ֶ��С���һ��M>0��ʾ��M��ѧ����Ϣ��

֮����M�У�ÿһ����һ��ѧ����Ϣ����һ������ѧ���������ڶ�������ѧ���ɼ���

Output
���ΪM�У����մӴ�С��˳���������ÿ��ѧ���ĳɼ����������ٶ�������������ѧ����

Sample Input
5
Tom 98
Jack 97
Mary 98
Sherry 99
Dock 97
Sample Output
99 Sherry
98 Mary
98 Tom
97 Dock
97 Jack
HINT
string���и�������int compare(const string &s) const;���ڱȽϵ�ǰ�ַ�����s�Ĵ�С����ԭ���ͬ��C���ԵĿ⺯��strcmp��


Append Code
append.cc, */