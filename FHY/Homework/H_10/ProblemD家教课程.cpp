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


Problem D: 家教课程
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3634  Solved: 2321
[Submit][Status]
Description
老师都是穷人，所以需要经常去外面搞点兼职啥的。可是除了上课，啥也不会啊。所以就只好做家教了。现在请利用面向对象的思想设计这样一个系统。具有如下类：

1. Person类：有一个string类型的属性，表明对象的名字。是Student和Teacher的父类。

2. Student类：是Person类的子类，拥有一个int类型的属性，表明对象的序号。

3. Teacher类：是Person类的子类，拥有一个string类型的属性，表明对象的职称。

4. Course类：是一个组合类，有1个Teacher类的对象、1个Student类型的对象，以及一个string类型的属性（表明对象的名称）组成。

请定义上述类的构造函数和析构函数，并在函数中输出相应的字符串。具体格式请参照样例输出。

Input
输入5行，前4个是4个字符串，分别是老师的名字、学生的名字、老师的职称、课程的名字。最后一行是一个整数，表示学生的序号。

Output
见样例~

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
注意根据main函数分析各个构造函数的每个参数的含义。

Append Code
append.cc,

 */