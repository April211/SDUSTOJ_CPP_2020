#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string name$;
    int age$;
public:
    Person(string name, int age):name$(name), age$(age){cout << "A person " << name$ << " whose age is " << age$ << " is created." << endl;}
    ~Person(){cout << "A person " << name$ << " whose age is " << age$ << " is erased." << endl;}
    void show()const {cout << "Name is " << name$ << " and age is " << age$ << '.' << endl;}

};

class Student: public Person
{
protected:
    int grade$;
public:
    Student(string name, int age, int grade):Person(name, age),grade$(grade){cout << "A student whose grade is " << grade$ << " is created." << endl;}
    ~Student(){cout << "A student whose grade is " << grade$ << " is erased." << endl;}
    void show()const {cout << "Grade is " << grade$ << '.' << endl;}
};


int main()
{
    string n;
    int a, g;
    cin>>n>>a>>g;
    Student student(n, a, g);
    student.Person::show();
    student.show();
    return 0;
}


/* Problem C: Person����Student��Ĺ�ϵ
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4870  Solved: 3709
[Submit][Status]
Description
��Ȼ��һ��student������һ��person�����ԣ�Student����Person��������ࡣ�붨��Person�࣬������

1. ���ݳ�Աstring name��int age���ֱ��ʾ���������䡣

2. ���캯����������������������Ӧ���������������

3. void show()������������������ö����name��age����ֵ��

����Student�࣬��Person������ࣺ

1. ���ݳ�Աint grade����ʾѧ�������꼶��

2. ���캯����������������������Ӧ���������������

3. void show()������������������ö����grade����ֵ��

Input
ֻ��1�У���Ϊ�����֣�һ�������հ׷����ַ����Լ�����������

Output
��������

Sample Input
Tom 19 3
Sample Output
A person Tom whose age is 19 is created.
A student whose grade is 3 is created.
Name is Tom and age is 19.
Grade is 3.
A student whose grade is 3 is erased.
A person Tom whose age is 19 is erased.
HINT
Append Code
append.cc, */