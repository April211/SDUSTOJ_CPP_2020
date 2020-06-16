#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class MyString
{
protected:
    int   len$;
    string ss$;
public:
    MyString():len$(0){}
    ~MyString(){}
    void input(){ cin >> ss$, len$ = ss$.size();}
    void output()
    {
        string rr(len$, '\0');
        for(int i = 0; i< len$; i++)
        {
            rr[i] = ss$[len$ - i - 1];
        }
        if(rr == ss$)
        {
            if(len$ % 2 == 0)
            {
                for(int i = 0; i< len$/2; i++)
                {
                    cout << ss$[i];
                }
            }
            else
            {
                for(int i = 0; i< len$/2 + 1; i++)
                {
                    cout << ss$[i];
                }
            }
            cout << endl;
            
        }
        else
        {
            cout << ss$ << endl;;
        }
        
    }
};



int main()
{
    MyString str;
    int n, i;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        str.input();
        str.output();
    }
    return 0;
}

/* 

Problem D: �ַ����۵�
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1938  Solved: 1437
[Submit][Status]
Description
����MyString�࣬������
1. һ���ַ�������ַ�ָ�룬���ڴ洢�ַ������ݡ�
2. void input()����ȡһ�������հ׷����ַ�����
3. void output()������ַ���������ַ������ǻ��Ĵ��������ԭ��������ǻ��Ĵ���������ǰ�벿�֡��磺
ԭ����abccba�������abc
ԭ����abcdcba�������abcd
ԭ����abcd�������abcd
Input
��һ��������N>0����ʾ֮����N������������ÿ����������ռһ�У���һ�������հ׷����ַ�����ÿ����������1000���ַ���
Output
��������

Sample Input
4
abcdcba
abccba
abcdefgh
aaaaaaaa
Sample Output
abcd
abc
abcdefgh
aaaa
HINT
Append Code
append.cc, */