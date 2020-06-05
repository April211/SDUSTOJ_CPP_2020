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
            cin >> str2 >> str1;                  //值， 键
            source.insert(make_pair(str1, str2)); //键, 值
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
Problem F: STL——字典
Time Limit: 10 Sec  Memory Limit: 128 MB
Submit: 9507  Solved: 2536
[Submit][Status]
Description
输入n个字符串对（str1,str2），再输入k个查询字符串str，从字符串对中查找查询字符串，即如果str=str2,则输出str1，如果查询不到则输出"eh"（不包含引号）。输入保证所有字符串对的str2不相同,字符串只含有字母和数字,长度小于20！

Input
输入包含多组数据，直到文件结尾。

每组数据第一行包含一个整数n（0≤n≤10^5）。接下来n行，每行描述一个字符串对。

接下来包含一个整数m（0≤m≤10^5）。接下来m行，每行描述一个查询字符串。

见样例

Output
输出每个查询的结果。

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
用STL的map容易实现


Append Code */