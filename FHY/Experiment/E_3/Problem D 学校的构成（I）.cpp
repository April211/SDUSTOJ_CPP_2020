#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int grade$;
public:
    Student(int tt):grade$(tt){cout << "A student grade " << grade$ <<" is created." << endl;}
   // Student():grade$(0){}
    ~Student(){cout << "A student grade " << grade$ << " is erased." << endl;}
    //friend class School;

};
class Teacher
{
private:
    double salary$;
public:
    Teacher(double tt):salary$(tt){cout << "A teacher with salary " << salary$ <<" is created." << endl;}
   // Teacher():salary$(0){}
    ~Teacher(){cout << "A teacher with salary " << salary$ <<" is erased." << endl;}
    //friend class School;



};

class School
{
private:
    Student st$;
    Teacher tc$;
public:
    School(int tg, double ts):st$(tg),tc$(ts){  cout << "A school is created." << endl;}//此处调用了上面两个类的构造函数
    ~School(){cout << "A school is erased." << endl;}

};



int main()
{
    int g;
    double s;
    cin>>g>>s;
    School sch(g, s);
    cin>>g;
    Student stu(g);
    cin>>s;
    Teacher tea(s);
    School(g, s);
    return 0;
}


//Problem D: 学校的构成（I）
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 1664  Solved: 1232
//[Submit][Status]
//Description
//学校是老师和学生组成的。现在定义Student、Teacher和School三个类来模拟一个学校。
//Student类只有一个int类型的数据成员，表示学生的年级；Teacher类只有一个double类型的数据成员，表示该教师的工资；School类是由1个Student类的对象、1个Teacher类的对象组合而成。定义它们的构造函数和析构函数，使程序能产生样例所示的输出。
//
//Input
//输入4行，第1行和第3行是2个int类型的正整数；第2行和第4行是double类型的正数。
//
//Output
//见样例。
//
//Sample Input
//3
//1600.31
//4
//2451.34
//Sample Output
//A student grade 3 is created.
//A teacher with salary 1600.31 is created.
//A school is created.
//A student grade 4 is created.
//A teacher with salary 2451.34 is created.
//A student grade 4 is created.
//A teacher with salary 2451.34 is created.
//A school is created.
//A school is erased.
//A teacher with salary 2451.34 is erased.
//A student grade 4 is erased.
//A teacher with salary 2451.34 is erased.
//A student grade 4 is erased.
//A school is erased.
//A teacher with salary 1600.31 is erased.
//A student grade 3 is erased.
