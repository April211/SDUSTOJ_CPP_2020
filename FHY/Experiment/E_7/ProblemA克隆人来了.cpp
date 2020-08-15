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
Problem A: 克隆人来了！
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5917  Solved: 3225
[Submit][Status]
Description
克隆技术飞速发展，克隆人已经成为现实了！！所以，现在由你来编写一个Person类，来模拟其中的克隆过程。这个类具有2个属性：name——姓名（char*类型），和age——年龄（int类型）。

该类具有无参构造函数（人名为“no name”，年龄是0）、带参数构造函数、拷贝构造函数以及析构函数外，还有以下3个成员函数：

1. void Person::showPerson()：按照指定格式显示人的信息。

2. Person& Person::setName(char *)：设定人的姓名。

3. Person& Person::setAge(int)：设定人的年龄。

Input
输入分多行，第一行是一个正整数N，表示其后有N行输入。每行分两部分：第一部分是一个没有空白符的字符串，表示一个人的姓名；第二部分是一个正整数，表示人的年龄。

Output
呃~比较复杂，见样例吧！注意：要根据样例编写相应函数中的输出语句，注意格式哦！

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
注意：输出中有“”！


Append Code
append.cc, */