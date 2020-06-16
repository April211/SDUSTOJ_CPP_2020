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

Problem D: 字符串折叠
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1938  Solved: 1437
[Submit][Status]
Description
定义MyString类，包括：
1. 一个字符数组或字符指针，用于存储字符串内容。
2. void input()：读取一个不含空白符的字符串。
3. void output()：输出字符串。如果字符串不是回文串，则输出原串。如果是回文串，则仅输出前半部分。如：
原串：abccba，则输出abc
原串：abcdcba，则输出abcd
原串：abcd，则输出abcd
Input
第一行是整数N>0，表示之后有N个测试用例。每个测试用例占一行，是一个不含空白符的字符串。每个串不超过1000个字符。
Output
见样例。

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