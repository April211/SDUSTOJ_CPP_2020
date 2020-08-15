#include <iostream>
using namespace std;

class Date
{
protected:
    int yy$, mm$, dd$;
public:
    Date(int yy, int mm, int dd):yy$(yy), mm$(mm), dd$(dd){ cout << "Date " << yy$ << '-' << mm$ << '-' << dd$ << " is created."<< endl;}
    ~Date(){cout << "Date " << yy$ << '-' << mm$ << '-' << dd$ << " is erased." << endl;}
    friend class Person;
    friend class Student;
};


class Person
{
protected:
    Date birth$;
    string name$;
public:
    Person():birth$(0, 0, 0){}
    Person(int yy, int mm, int dd, string name):birth$(yy, mm, dd), name$(name){ ++numOfPersons; cout << "The " << Person::numOfPersons << "th person " << name$ << " whose birthday is " << birth$.yy$ << '-' << birth$.mm$ << '-' << birth$.dd$ << " is created." << endl;}
    virtual ~Person(){  cout << "Person " << name$ << " whose birthday is " << birth$.yy$ << '-' << birth$.mm$ << '-' << birth$.dd$ <<" is erased."<< endl;}
    static int numOfPersons;
    friend class Student;
};

int Person::numOfPersons = 0;

class Student: public Person
{
protected:
    int id$;
public:
    static int numOfStudents;
    Student(int yy, int mm, int dd, string name, int id):Person(yy, mm, dd, name), id$(id){ ++numOfStudents; cout << "The " << Student::numOfStudents << "th student " << name$ << " whose birthday is " << birth$.yy$ << '-' << birth$.mm$ << '-' << birth$.dd$ << " and id is " << id$ << " is created." << endl;}
    ~Student(){ cout << "Student " << name$ << " whose birthday is " << birth$.yy$ << '-' << birth$.mm$ << '-' << birth$.dd$ << " and id is " << id$ << " is erased." << endl;}
};

int Student::numOfStudents = 0;

int main()
{
    int year, month, day, id, i;
    string name;
    int num;
    cin>>num;
    Student **students = new Student*[num];
    for (i = 0; i < num; i++)
    {
        cin>>year>>month>>day>>id>>name;
        students[i] = new Student(year, month, day, name, id);
    }
    for (i = 0;i <num; i++)
        delete students[i];
    delete[] students;
    return 0;
}


/* 

Problem F: 一帮学生
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2334  Solved: 1459
[Submit][Status]
Description
学生Student类是Person类的子类，而且每个人都有生日，生日是Date类的对象。所以，需要定义如下类：

1. Date类：拥有年、月、日三个int类型的属性。

2. Person类：有一个Date类型对象的属性（表示生日）、string类型属性（表示名字），以及一个int类型的静态属性numOfPersons（对象个数）。

3. Student类：是Person类的子类，并拥有一个int类型属性（表明学生学号），一个int类型的静态属性numOfStudents（对象个数）。
定义上述类的构造、析构函数，并根据样例输出格式输出相应的信息。

Input
第一行整数N>0表示之后有N行输入。

之后的N行，每行包括4个整数、1个字符串，分别表示年、月、日、学号和姓名。

Output
见样例~

Sample Input
3
2010 3 4 1 Tom
2010 3 5 2 Jack
2010 3 6 3 Mary
Sample Output
Date 2010-3-4 is created.
The 1th person Tom whose birthday is 2010-3-4 is created.
The 1th student Tom whose birthday is 2010-3-4 and id is 1 is created.
Date 2010-3-5 is created.
The 2th person Jack whose birthday is 2010-3-5 is created.
The 2th student Jack whose birthday is 2010-3-5 and id is 2 is created.
Date 2010-3-6 is created.
The 3th person Mary whose birthday is 2010-3-6 is created.
The 3th student Mary whose birthday is 2010-3-6 and id is 3 is created.
Student Tom whose birthday is 2010-3-4 and id is 1 is erased.
Person Tom whose birthday is 2010-3-4 is erased.
Date 2010-3-4 is erased.
Student Jack whose birthday is 2010-3-5 and id is 2 is erased.
Person Jack whose birthday is 2010-3-5 is erased.
Date 2010-3-5 is erased.
Student Mary whose birthday is 2010-3-6 and id is 3 is erased.
Person Mary whose birthday is 2010-3-6 is erased.
Date 2010-3-6 is erased.
HINT
Append Code
append.cc, */