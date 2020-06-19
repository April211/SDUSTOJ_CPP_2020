#include <bits/stdc++.h>
using namespace std;

class Overload
{
protected:
    int a$;
    char c$;
public:
    Overload():a$(0), c$('0'){ cout << "Default constructor is called to make a = " << a$ << ", c = '" << c$ << "'." << endl;}
    Overload(int a):a$(a), c$('0'){ cout << "First constructor is called to make a = " << a$ << ", c = '" << c$ << "'." << endl;}
    Overload(char c):a$(0), c$(c){ cout << "Second constructor is called to make a = " << a$ << ", c = '" << c$ << "'." << endl;}
    Overload(int a, char c):a$(a), c$(c){  cout << "Third constructor is called to make a = " << a$ << ", c = '" << c$ << "'." << endl;}


};
/* 


Problem H: ��Ҫ������
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1851  Solved: 1267
[Submit][Status]
Description
����һ����Overload������һ��int���͵ĺ�һ��char�������ԡ��ڶ������Ķ���ʱ�������ָ���κγ�ʼֵ���������
Default constructor is called to make a = 0, c = '0'.
���ֻ����һ��int���͵ĳ�ʼֵ#���������
First constructor is called to make a = #, c = '0'.
���ֻ����һ��char���ͳ�ʼֵ$���������
Second constructor is called to make a = 0, c = '$'.
�������һ��int���ͳ�ʼֵ#��һ��char���ͳ�ʼֵ$���������
Third constructor is called to make a = #, c = '$'.

Input
һ��int���͵�ֵ��һ��char���͵�ֵ��

Output
��������

Sample Input
10 a
Sample Output
Default constructor is called to make a = 0, c = '0'.
First constructor is called to make a = 10, c = '0'.
Second constructor is called to make a = 0, c = 'a'.
Third constructor is called to make a = 10, c = 'a'.
HINT
Append Code
append.cc,




int main()
{
    int i;
    char ch;
    cin>>i>>ch;
    Overload t1, t2(i), t3(ch), t4(i, ch);
    return 0;
} */