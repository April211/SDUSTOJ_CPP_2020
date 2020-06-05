#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    char* name$;
    int   age$;
public:
    Person():name$(0), age$(0){ name$ = new char[100]; memset(name$, 0, sizeof(name$)); strcpy(name$, "no name"); cout << "A person whose name is \"" << name$ << "\" and age is " << age$ << " is created!" << endl;}
    Person(const char *str, int age):name$(0), age$(age){ name$ = new char[100]; memset(name$, 0, sizeof(name$)); strcpy(name$, str);cout << "A person whose name is \"" << name$ << "\" and age is " << age$ << " is created!" << endl;}
    Person(const Person& tt):name$(0), age$(tt.age$){ name$ = new char[100]; memset(name$, 0, sizeof(name$)); strcpy(name$, tt.name$);cout << "A person whose name is \"" << name$ << "\" and age is " << age$ << " is cloned!" << endl;}
    ~Person(){cout << "A person whose name is \"" << name$ << "\" and age is " << age$ << " is erased!" << endl;}
    void showPerson()const;
    Person& setName(char * str);
    Person& setAge(int);


};

void Person::showPerson()const
{
    cout << "This person is \"" << name$ << "\" whose age is " << age$ << '.' << endl;
}
Person& Person::setName(char *str)
{
    memset(name$, 0, sizeof(name$));
    strcpy(name$, str);
    return *this;
}
Person& Person::setAge(int age)
{
    age$ = age;
    return *this;
}

int main()
{
    //freopen("src.txt", "w", stdout);
    int cases;
    char str[80];
    int age;
 
    Person noname, Tom("Tom", 16), anotherTom(Tom);
    cin>>cases;
    for (int ca = 0; ca < cases; ca++)
    {
        cin>>str>>age;
        Person newPerson(str, age);
        newPerson.showPerson();
    }
    anotherTom.setName(str).setAge(18);
    anotherTom.showPerson();
    noname.showPerson();
    return 0;
}


/* 
Problem A: ��¡�����ˣ�
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5917  Solved: 3225
[Submit][Status]
Description
��¡�������ٷ�չ����¡���Ѿ���Ϊ��ʵ�ˣ������ԣ�������������дһ��Person�࣬��ģ�����еĿ�¡���̡���������2�����ԣ�name����������char*���ͣ�����age�������䣨int���ͣ���

��������޲ι��캯��������Ϊ��no name����������0�������������캯�����������캯���Լ����������⣬��������3����Ա������

1. void Person::showPerson()������ָ����ʽ��ʾ�˵���Ϣ��

2. Person& Person::setName(char *)���趨�˵�������

3. Person& Person::setAge(int)���趨�˵����䡣

Input
����ֶ��У���һ����һ��������N����ʾ�����N�����롣ÿ�з������֣���һ������һ��û�пհ׷����ַ�������ʾһ���˵��������ڶ�������һ������������ʾ�˵����䡣

Output
��~�Ƚϸ��ӣ��������ɣ�ע�⣺Ҫ����������д��Ӧ�����е������䣬ע���ʽŶ��

Sample Input
3
Zhang 20
Li 18
Zhao 99
Sample Output
A person whose name is "no name" and age is 0 is created!
A person whose name is "Tom" and age is 16 is created!
A person whose name is "Tom" and age is 16 is cloned!
A person whose name is "Zhang" and age is 20 is created!
This person is "Zhang" whose age is 20.
A person whose name is "Zhang" and age is 20 is erased!
A person whose name is "Li" and age is 18 is created!
This person is "Li" whose age is 18.
A person whose name is "Li" and age is 18 is erased!
A person whose name is "Zhao" and age is 99 is created!
This person is "Zhao" whose age is 99.
A person whose name is "Zhao" and age is 99 is erased!
This person is "Zhao" whose age is 18.
This person is "no name" whose age is 0.
A person whose name is "Zhao" and age is 18 is erased!
A person whose name is "Tom" and age is 16 is erased!
A person whose name is "no name" and age is 0 is erased!
HINT
ע�⣺������С�����


Append Code
append.cc, */