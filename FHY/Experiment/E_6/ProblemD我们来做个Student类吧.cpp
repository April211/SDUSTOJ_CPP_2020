#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    char *name$;
    int numOfScores$;
    int *scores$;
    int id$;
public:
    static int cnt;
    Student(const char* nm, const int* sc, int sum):numOfScores$(sum)
    {
        id$ = ++cnt;
        name$ = new char [strlen(nm)+10];
        memset(name$, 0, sizeof(name$));
        scores$ = new int [sum+10];
        strcpy(name$, nm);
        for(int i = 0; i< sum; i++)
        {
            scores$[i] = sc[i];
        }
        cout << "A student whose name is \"" << name$ << "\" and id is " << id$ << " is created!" << endl;
        
    }
    ~Student(){ cout << "A student whose name is \"" << name$ << "\" and id is " << id$ << " is erased!" << endl; delete []name$; delete []scores$; }
    void showStudent()
    {
        cout << "This student is \"" << name$ << "\" whose id is " << id$ << '.' << endl;
        cout << "This student's scores are:";
        for(int i = 0; i< numOfScores$; i++)
        { cout << ' ' << scores$[i];} 
        cout << endl;

    }

};

int Student::cnt = 0;

int main()
{
    int cases;
    char *str;
    int maxLenOfString, numOfCourses;
    int *scores;
 
    cin>>cases>>maxLenOfString>>numOfCourses;
    str = new char[maxLenOfString + 1];
    scores = new int[numOfCourses];
    for (int i = 0; i < cases; i++)
    {
        cin>>str;
        for (int j = 0; j < numOfCourses; j++)
            cin>>scores[j];
        Student stu(str,scores,numOfCourses);
        stu.showStudent();
    }
    return 0;
}


/* 
Problem D: ����������Student��ɣ�
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3438  Solved: 1769
[Submit][Status]
Description
�붨��һ��Student�࣬��4�����ԣ�

1.char *name��������

2.int numOfScores���γ�����

3.int *scores�����пγ̵ĳɼ���

4.int id��ѧ���ı�š�

ֻ��3��������

1. ���캯��

2.��������

3.void Student::showStudent()�������������ѧ������Ϣ��

��������������д�������ʵ�֡�

Input
�����Ϊ���С�

��һ�а���3��������M��N��P������M����֮������Ĳ�������������N��ʾÿ������������󳤶ȣ�P��ʾѧ��ѧϰ�Ŀγ̵�������

֮����M�У�����һ��ѧ��������û���κοհ׷�����P�ſγ̵ĳɼ���

Output
��������

ע�⣺���е��������֮����һ���ո��������ÿ���������β��û�пո�

Sample Input
3 10 5
Tom 60 61 72 56 89
Jack 99 100 98 89 77
Mary 88 88 88 88 88
Sample Output
A student whose name is "Tom" and id is 1 is created!
This student is "Tom" whose id is 1.
This student's scores are: 60 61 72 56 89
A student whose name is "Tom" and id is 1 is erased!
A student whose name is "Jack" and id is 2 is created!
This student is "Jack" whose id is 2.
This student's scores are: 99 100 98 89 77
A student whose name is "Jack" and id is 2 is erased!
A student whose name is "Mary" and id is 3 is created!
This student is "Mary" whose id is 3.
This student's scores are: 88 88 88 88 88
A student whose name is "Mary" and id is 3 is erased!
HINT
Append Code
append.cc, */