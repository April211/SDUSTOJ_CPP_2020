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
    School(int tg, double ts):st$(tg),tc$(ts){  cout << "A school is created." << endl;}//�˴�����������������Ĺ��캯��
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


//Problem D: ѧУ�Ĺ��ɣ�I��
//Time Limit: 1 Sec  Memory Limit: 128 MB
//Submit: 1664  Solved: 1232
//[Submit][Status]
//Description
//ѧУ����ʦ��ѧ����ɵġ����ڶ���Student��Teacher��School��������ģ��һ��ѧУ��
//Student��ֻ��һ��int���͵����ݳ�Ա����ʾѧ�����꼶��Teacher��ֻ��һ��double���͵����ݳ�Ա����ʾ�ý�ʦ�Ĺ��ʣ�School������1��Student��Ķ���1��Teacher��Ķ�����϶��ɡ��������ǵĹ��캯��������������ʹ�����ܲ���������ʾ�������
//
//Input
//����4�У���1�к͵�3����2��int���͵�����������2�к͵�4����double���͵�������
//
//Output
//��������
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
