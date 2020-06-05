#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string name$;
    int age$;
    char sex$;
    string addr$;
    string tel$;
public:
    Person(string name, int age, char sex, string addr, string tel):name$(name), age$(age), sex$(sex), addr$(addr), tel$(tel){}
    ~Person(){}
    void setTel(const string& tt);
};

class Student: virtual public Person
{
protected:
    string major$;
public:
    Student(string name, int age, char sex, string addr, string tel, string major):Person(name, age, sex, addr, tel), major$(major){}
    ~Student(){}
};

class Cadre: virtual public Person
{
protected:
    string post$;
public:
    Cadre(string name, int age, char sex, string addr, string tel, string post):Person(name, age, sex, addr, tel), post$(post){}
    ~Cadre(){}
};

class Student_Cadre: public Student, public Cadre
{
protected:
    float wages$;
public:
    Student_Cadre(string name, int age, char sex, string addr, string tel, string major, string post, float wages):Person(name, age, sex, addr, tel), Student(name,  age, sex, addr, tel, major), Cadre(name,  age, sex, addr, tel, post), wages$(wages){}
    ~Student_Cadre(){}
    void display()const;
    void setAddr(const string&);


};

inline void Student_Cadre::display()const
{
    cout << "name:" << name$ << endl;
    cout << "age" << age$ << endl;
    cout << "sex:" << sex$ << endl;
    cout << "address:" << addr$ << endl;
    cout << "tel:" << tel$ << endl;
    cout << "major:" << major$ << endl;
    cout << "post:" << post$ << endl;
    cout << "wages:" << wages$ << endl;
}

inline void Student_Cadre::setAddr(const string& tt)
{
    addr$ = tt;
}

inline void Person::setTel(const string& tt)
{
    tel$ = tt;
}

int main( )
{
    string name, major, post, addr, tel;
    int age;
    char sex;
    float wage;
    cin>>name>>age>>sex>>addr>>tel>>major>>post>>wage;
 
    Student_Cadre st_ca(name, age, sex,  addr, tel, major, post,wage);
    st_ca.display( );
 
    cout<<endl;
    string newAddr, newTel1, newTel2;
    cin>>newAddr>>newTel1>>newTel2;
 
    st_ca.setAddr(newAddr);
    st_ca.Student::setTel(newTel1);
    st_ca.Cadre::setTel(newTel2);
    st_ca.display( );
    return 0;
}


/* Problem B: 学生干部虚基类
Time Limit: 1 Sec  Memory Limit: 2 MB
Submit: 3848  Solved: 2602
[Submit][Status]
Description
基于Student(学生)类和Cadre（干部）类，采用多重继承方式由这两个类派生出新类Student_Cadre（学生兼干部）。
这两个基类均继承自Person类，包含姓名、年龄、性别、地址、电话等数据成员。在Student类中还包含数据成员major(专业)，在Cadre类中还包含数据成员post（职务），
在Student_Cadre类中还包含数据成员wages(工资)。
注意使用虚基类使Student_Cadre只包含一份从Person类继承来的成员。
Input
学生干部的姓名，年龄，性别，专业，职位，地址，电话，薪水

修改该学生干部的新地址，新电话

Output
学生干部的信息

Sample Input
wangli
23
f
BeijingRoad
0532-61234567
software
president
1534.2
Taidonglu
0532-90827651
0531-28766143
Sample Output
name:wangli
age23
sex:f
address:BeijingRoad
tel:0532-61234567
major:software
post:president
wages:1534.2

name:wangli
age23
sex:f
address:Taidonglu
tel:0531-28766143
major:software
post:president
wages:1534.2
HINT
Append Code
append.cc, */