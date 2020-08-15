#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;



class Person
{
protected:
    string name$;
    double  age$;
public:
    Person(string name = 0, double age = 0):name$(name), age$(age){}
    static int cnt;
    static int recnt();
    friend class Persons;
};

int Person::cnt = 0;

class Persons
{
protected:
    stack <Person> pp;
public:
    Persons(){}
    void addAPerson(string name, double age) { pp.push(Person(name, age)), ++Person::cnt;}
    double getAveAge()
    {
        double ans = 0;
        int size = pp.size();
        for(int i = 0; i< size; i++)
        {
            ans += pp.top().age$;
            pp.pop();
        }
        ans /= Person::cnt;
        return ans;
    }
};




int main()
{
    int cases, age;
    string name;
    Persons persons;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>name>>age;
        persons.addAPerson(name, age);
    }
    cout<<setprecision(2)<<fixed<<persons.getAveAge()<<endl;
}


/* 


Problem C: 求平均年龄
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2896  Solved: 1765
[Submit][Status]
Description
定义一个Persons类，用于保存若干个人的姓名（string类型）和年龄（int类型），定义其方法

void addAPerson(string,int)

用于添加1个人的信息；

double getAveAge()

用于获取所有人的平均年龄。

Input
第1行N>0表示有N个测试用例。

每个测试用例包括1个人的姓名及其年龄。

Output
所有人的平均年龄。见样例。

Sample Input
5
Zhang 10
Wang 20
Li 30
Zhao 40
Zhou 50
Sample Output
30.00
HINT
Append Code
append.cc, */