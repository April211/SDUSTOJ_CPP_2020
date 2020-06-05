#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    string tt;
    map<string, string> source;
    map<string, string>::iterator p1;
    int cnto = 0, cnts = 0;

    while (cin >> cnto)
    {
        for (int i = 0; i < cnto; i++)
        {
            cin >> str2 >> str1;                  //ֵ�� ��
            source.insert(make_pair(str1, str2)); //��, ֵ
        }

        cin >> cnts;
        for (int i = 0; i < cnts; i++)
        {
            cin >> tt;
            p1 = source.find(tt);

            if (p1 != source.end())
            {
                cout << (p1->second) << endl;
            }
            else
            {
                cout << "eh" << endl;
            }
        }
        source.clear();
        
    }

    return 0;
}

/* 
Problem F: STL�����ֵ�
Time Limit: 10 Sec  Memory Limit: 128 MB
Submit: 9507  Solved: 2536
[Submit][Status]
Description
����n���ַ����ԣ�str1,str2����������k����ѯ�ַ���str�����ַ������в��Ҳ�ѯ�ַ����������str=str2,�����str1�������ѯ���������"eh"�����������ţ������뱣֤�����ַ����Ե�str2����ͬ,�ַ���ֻ������ĸ������,����С��20��

Input
��������������ݣ�ֱ���ļ���β��

ÿ�����ݵ�һ�а���һ������n��0��n��10^5����������n�У�ÿ������һ���ַ����ԡ�

����������һ������m��0��m��10^5����������m�У�ÿ������һ����ѯ�ַ�����

������

Output
���ÿ����ѯ�Ľ����

Sample Input
5
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay
3
atcay
ittenkay
oopslay
Sample Output
cat
eh
loops
HINT
��STL��map����ʵ��


Append Code */