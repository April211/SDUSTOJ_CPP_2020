#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    int a;
    getline(cin, s1);
    getline(cin, s2);
    cout << s1 << s2 << endl;
    if(s1 > s2)
    {
        cout << s2 << endl;
    }
    else
    {
        cout << s1 << endl;
    }

    string s3(s1.begin(), s1.begin()+4);//ÖÁ¶à4¸ö
    cout << s3;


    return 0;
}

// Problem G: string的初体验
// Time Limit: 1 Sec  Memory Limit: 128 MB
// Submit: 616  Solved: 173
// [Submit][Status]
// Description
// 练习string

// Input
// 两个字符串 s1,s2 10<=|S1|,|S2|<=10000;

// Output
// 第一行输出s1和s2的拼接字符串，即s1+s2

// 第二行输出s1,s2两者中字典序较小者

// 第三行输出s1的从头开始长度为4的子串

// Sample Input
// abcdesad
// dsadsad
// Sample Output
// abcdesaddsadsad
// abcdesad
// abcd
// HINT
// Append Code
