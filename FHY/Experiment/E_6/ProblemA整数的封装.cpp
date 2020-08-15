#include <bits/stdc++.h>
using namespace std;

class Integer
{
private:
    int num$;
    int radix$;

public:
    Integer(int tt) : num$(tt), radix$(10) {} //单参数十进制
    Integer(const char *num, int radix) : radix$(radix), num$(0)
    {
        if (num[0] == '-' || num[0] == '+')
        {
            if (radix$ <= 10)
            {
                int len = strlen(num);
                for (int i = 1; i < len; i++)
                {
                    num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                }
                if(num[0] == '-')
                {
                    num$ = num$* (-1);
                }
                else
                {
                    /* code */
                }
                
            }
            else
            {
                int len = strlen(num);
                for (int i = 1; i < len; i++)
                {
                    if (num[i] >= '0' && num[i] <= '9')
                    {
                        num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                    }
                    else
                    {
                        num$ += ((int)(tolower(num[i]) - 'a') + 10) * pow(radix$, len - i - 1);
                    }
                }
                if(num[0] == '-')
                {
                    num$ = num$* (-1);
                }
                else
                {
                    /* code */
                }
            }
        }
        else
        {
            if (radix$ <= 10)
            {
                int len = strlen(num);
                for (int i = 0; i < len; i++)
                {
                    num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                }
            }
            else
            {
                int len = strlen(num);
                for (int i = 0; i < len; i++)
                {
                    if (num[i] >= '0' && num[i] <= '9')
                    {
                        num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                    }
                    else
                    {
                        num$ += ((int)(tolower(num[i]) - 'a') + 10) * pow(radix$, len - i - 1);
                    }
                }
            }
        }
    }
    int getValue() const { return num$; }
};

int main()
{
    char str[100];
    int numOfData, numOfStr;
    int data, i, radix;

    cin >> numOfData;
    for (i = 0; i < numOfData; i++)
    {
        cin >> data;
        Integer anInteger(data);
        cout << anInteger.getValue() << endl;
    }

    cin >> numOfStr;
    for (i = 0; i < numOfStr; i++)
    {
        cin >> str >> radix;
        Integer anInteger(str, radix);
        cout << anInteger.getValue() << endl;
    }
    return 0;
}


/* Problem A: 整数的封装
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5050  Solved: 1968
[Submit][Status]
Description
现在，请编写一个Integer类，将整数封装起来。目前，只需要你来实现最基本的功能：

1. 具有2个构造函数：

（1）Integer::Integer(int)：根据参数构建一个整数对象。

（2）Integer::Integer(char*, int)：根据给定的字符串和进制来构建一个整数对象。

2. 具有一个int Integer::getValue()方法，用于返回Integer类中所封装的整数的具体数值。

Input
输入分为多行。

第一行是一个正整数M，表示其后面的M行为M个整数，每行一个整数。

第M+2行是一个正整数N，表示其后有N行。每行由利用一个空格隔开的2部分组成：前半部分是一个字符串，后半部分是该字符串所使用的进制。

注意：

1. 所有的输入，均在int类型的表示范围内，且所有的输入均为合法输入。

2. 利用0~9和a~z可最大可以表示36进制的数值。

Output
输出为M+N行，每行为一个十进制整数，且输出顺序应与输入顺序相同。

Sample Input
 2
999
-1999
4
0111 2
1a 16
z 36
a 16
Sample Output
999
-1999
7
26
35
10
HINT
Append Code
append.cc, */