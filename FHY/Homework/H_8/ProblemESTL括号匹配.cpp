#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

int main()
{
    char ch1 = 0;
    char ch2 = 0;
    int cntl = 0, cntr = 0;
    string tt;
    stack<char> ku;
    while (cin >> ch2)
    {
        cntl = 0, cntr = 0;
        if (ch2 == '\n')
        {
            cout << "NO" << endl;
        }
        else
        {   
            
            if(ch2 == '('){ku.push(ch2); cntl++;}
            if(ch2 == ')'){ku.push(ch2); cntr++;}
            while ((ch1 = getchar()) != '\n')
            {
                ku.push(ch1);
                if(ch1 == '('){cntl++;}
                else if(ch1 == ')'){cntr++;}
            }
            if(cntl != cntr)
            {
                cout << "NO" << endl;
            }
            else
            {
                if(ku.top() == '('){cout << "NO" << endl;}
                else if(ch2 == ')'){cout << "NO" << endl;}
                else
                {
                    cout << "YES" << endl;
                }
            }
        }
        
    }

    return 0;
}


/* Problem E: STL——括号匹配
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5667  Solved: 3648
[Submit][Status]
Description
给出一堆括号，看其是否匹配，例如 ()、()()、(()) 这样的括号就匹配，
      )(、)()) 而这样的括号就不匹配
Input
每一行代表一组测试样例，每组测试样例只包含'('和')'，样例长度不超过100个字符
Output
如果所有的括号都匹配，那么输出YES，否则输出NO
Sample Input
()
)(
Sample Output
YES
NO
HINT
使用STL的stack容易实现。


Append Code */