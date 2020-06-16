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

Problem F: һ��ѧ��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2334  Solved: 1459
[Submit][Status]
Description
ѧ��Student����Person������࣬����ÿ���˶������գ�������Date��Ķ������ԣ���Ҫ���������ࣺ

1. Date�ࣺӵ���ꡢ�¡�������int���͵����ԡ�

2. Person�ࣺ��һ��Date���Ͷ�������ԣ���ʾ���գ���string�������ԣ���ʾ���֣����Լ�һ��int���͵ľ�̬����numOfPersons�������������

3. Student�ࣺ��Person������࣬��ӵ��һ��int�������ԣ�����ѧ��ѧ�ţ���һ��int���͵ľ�̬����numOfStudents�������������
����������Ĺ��졢�������������������������ʽ�����Ӧ����Ϣ��

Input
��һ������N>0��ʾ֮����N�����롣

֮���N�У�ÿ�а���4��������1���ַ������ֱ��ʾ�ꡢ�¡��ա�ѧ�ź�������

Output
������~

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