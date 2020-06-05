#include <iostream>
using namespace std;

class Person
{
protected:
    string name$;
public:
    Person(const string& name):name$(name){cout << "Person " << name$ << " is created." << endl;}
    ~Person(){cout << "Person " << name$ << " is erased." << endl;}
};

class Student: public Person
{
protected:
    int id$;
public:
    Student(const string& name, int id):Person(name), id$(id){cout << "Student " << name$ << " with id " << id$ << " is created." << endl;}
    ~Student(){cout << "Student " << name$ << " with id " << id$ << " is erased." << endl;}


};

class Teacher: public Person
{
protected:
    string position$;
public:
    Teacher(const string& name, const string& position):Person(name), position$(position){cout << "Teacher " << name$ << " with position " << position$ << " is created." << endl;}
    ~Teacher(){cout << "Teacher " << name$ << " with position " << position$ << " is erased." << endl;}


};

class Course
{
protected:
    Teacher teacher$;
    Student student$;
    string  course_name$;
public:
    Course(const string& name1, const string& name2, const string& position, const string& course_name, int id):teacher$(name2, position), student$(name2, id), course_name$(course_name){cout << "Course " << course_name$ << " is created." << endl;}
    ~Course(){cout << "Course " << course_name$ << " is erased." << endl;}
};


int main()
{
    string s1, s2, s3, s4;
    int i;
    cin>>s1>>s2>>s3>>s4>>i;
    Person person1(s1), person2(s2);
    Teacher teacher(s1, s3);
    Student student(s2, i);
    Course course(s1, s2, s3, s4, i);
    return 0;
}

/* 


Problem D: �ҽ̿γ�
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3634  Solved: 2321
[Submit][Status]
Description
��ʦ�������ˣ�������Ҫ����ȥ�������ְɶ�ġ����ǳ����ϿΣ�ɶҲ���ᰡ�����Ծ�ֻ�����ҽ��ˡ�������������������˼���������һ��ϵͳ�����������ࣺ

1. Person�ࣺ��һ��string���͵����ԣ�������������֡���Student��Teacher�ĸ��ࡣ

2. Student�ࣺ��Person������࣬ӵ��һ��int���͵����ԣ������������š�

3. Teacher�ࣺ��Person������࣬ӵ��һ��string���͵����ԣ����������ְ�ơ�

4. Course�ࣺ��һ������࣬��1��Teacher��Ķ���1��Student���͵Ķ����Լ�һ��string���͵����ԣ�������������ƣ���ɡ�

�붨��������Ĺ��캯�����������������ں����������Ӧ���ַ����������ʽ��������������

Input
����5�У�ǰ4����4���ַ������ֱ�����ʦ�����֡�ѧ�������֡���ʦ��ְ�ơ��γ̵����֡����һ����һ����������ʾѧ������š�

Output
������~

Sample Input
Tom
Jack
Prof
C++
10
Sample Output
Person Tom is created.
Person Jack is created.
Person Tom is created.
Teacher Tom with position Prof is created.
Person Jack is created.
Student Jack with id 10 is created.
Person Jack is created.
Teacher Jack with position Prof is created.
Person Jack is created.
Student Jack with id 10 is created.
Course C++ is created.
Course C++ is erased.
Student Jack with id 10 is erased.
Person Jack is erased.
Teacher Jack with position Prof is erased.
Person Jack is erased.
Student Jack with id 10 is erased.
Person Jack is erased.
Teacher Tom with position Prof is erased.
Person Tom is erased.
Person Jack is erased.
Person Tom is erased.
HINT
ע�����main���������������캯����ÿ�������ĺ��塣

Append Code
append.cc,

 */