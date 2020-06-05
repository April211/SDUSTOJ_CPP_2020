#include <bits/stdc++.h>
using namespace std;

class Student
{
protected:
    string name$;
    bool sex$;
    int grade$;
    Student* next$;
public:
    Student(string name, bool sex, int grade):name$(name), sex$(sex), grade$(grade), next$(NULL){cout << "A student named by " << name$ << " is created!" << endl;}
    ~Student(){cout << "A student named by " << name$ << " is erased." << endl;}
    void showInfo()const { cout << "name = " << name$ << ", sex = " << sex$ << ", grade = " << grade$ << ';';}
    Student* getNext()const {return next$;}
    void setNext(Student* tpr){ next$ = tpr;}
};

class StudentCadre: public Student
{
private:
    string position$;
public:
    StudentCadre(string name, bool sex, int grade, string pos):Student(name, sex, grade), position$(pos){cout << "A student cadre with position " << position$ << " is created." << endl;}
    ~StudentCadre(){cout<<"A student named by "<< name$ <<" is erased."<<endl;}
    void showInfo()const { cout << "name = " << name$ << ", sex = " << sex$ << ", grade = " << grade$ << "; " << "position = " << position$ << '.';}
};


int main()
{
    int num;
    string name, position;
    bool sex;
    int grade;
    Student *header, *student, *curStudent;
 
    cin>>name>>sex>>grade>>position;
    header = new StudentCadre(name, sex, grade,position);
    curStudent = header;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cin>>name>>sex>>grade;
        student = new Student(name, sex, grade);
        curStudent -> setNext(student);
        curStudent = curStudent -> getNext();
    }
    ((StudentCadre*)header) -> showInfo();
    cout<<endl;
    curStudent = header;
    while (curStudent -> getNext() != NULL)
    {
        curStudent = curStudent -> getNext();
        curStudent->showInfo();
        cout<<endl;
    }
 
    curStudent = header;
    while (curStudent != NULL)
    {
        student = curStudent;
        curStudent = curStudent -> getNext();
        delete student;
    }
    return 0;
}


/* 


Problem C: ѡ�ٰ�ɲ��ˣ�
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5319  Solved: 3235
[Submit][Status]
Description
��ѧ����ʼ��ĳ��Ҫͨ�������ϸڷ�ʽ��ѡ��ɲ��������೤����֧��ȡ�������Ҫ�������2����Student��StudentCadre��ģ����һ���̡�

1.Student����ѧ���࣬����

��1�����ԣ�string name����������bool sex�����Ա�int grade�����꼶��Student *next����ָ����һ��ѧ��ָ�롣

��2��������

���캯��Student(string _name, bool _sex, int _grade)������ʼ��һ������ע�⣺���е�next��ʼ��ΪNULL��
����������
void showInfo()�������һ��ѧ������Ϣ��next���⡣
Student* getNext()�������nextָ�롣
void setNext(Student*)��������nextָ��ָ�����
2. StudentCadre����Student��������࣬������

��1�����ԣ�string position������ʾ��Ƹ��λ��

��2��������

StudentCadre(string _name, bool _sex, int _grade, string pos)�������캯������ʼ���������ԡ�
����������
void showInfo()������ʾ��Ϣ��
���캯��������������������������������

Input
�����ж��С�

��1����4���֣��������Ա�0��1�����꼶���������͸�λ��

��2����һ��������N����ʾ��N��ѧ��֧�ָ��˾�Ƹ��Ӧ��λ��֮����N�У�ÿ����3�����֣��ֱ���һ��ѧ�����������Ա���꼶��

Output
��������

Sample Input
Tom 0 2015 Monitor
3
Jack 1 2015
Mary 0 2015
Sherry 1 2015
Sample Output
A student named by Tom is created!
A student cadre with position Monitor is created.
A student named by Jack is created!
A student named by Mary is created!
A student named by Sherry is created!
name = Tom, sex = 0, grade = 2015; position = Monitor.
name = Jack, sex = 1, grade = 2015;
name = Mary, sex = 0, grade = 2015;
name = Sherry, sex = 1, grade = 2015;
A student named by Tom is erased.
A student named by Jack is erased.
A student named by Mary is erased.
A student named by Sherry is erased.
HINT
string����C++�ṩ���࣬��ͷ�ļ�string�У�������#include <string>��ʹ������ࡣ����Ķ������ֱ�����ø�ֵ�������=�����и��ƣ�Ҳ����ֱ������cout�����������cin���롣


Append Code
append.cc, */