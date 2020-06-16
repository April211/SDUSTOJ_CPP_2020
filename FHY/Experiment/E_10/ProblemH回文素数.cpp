#include <bits/stdc++.h>
#define MAX_SIZE 1000010
using namespace std;

bool lib[MAX_SIZE] = {
    1,
    1,
}; //0 and 1 are both not primes.
int flag = 0;

bool isRenum(int num)
{
    int k = num, j = 0;
    while (k)
    {
        j = j * 10 + k % 10;
        k = k / 10;
    }
    if (num == j) return true;
    else return false;
}

class SpecialPrime
{
public:
    static bool judge(int);
};

bool SpecialPrime::judge(int num)
{
    if (lib[num] == 1 || isRenum(num) == false)
    {
        return false;
    }
    if (flag == 0)
    {
        int ceil = (int)(sqrt(1000000) + 0.5);
        for (int i = 2; i < ceil; i++)
        {
            if (lib[i] == 0)
            {
                for (int j = i * i; j <= 1000000; j += i)
                {
                    lib[j] = -1;
                }
            }
        }
        flag++;
    }

    if (lib[num] == 0)
    {
        return true;
    }
}

int main()
{
    int m, n, i;
    cin >> m >> n;
    for (i = m; i < n; i++)
    {
        if (SpecialPrime::judge(i))
            cout << i << endl;
    }
    return 0;
}


/* 
Problem H: 回文素数
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1169  Solved: 505
[Submit][Status]
Description
定义一个类SpecialPrime，只有一个静态成员函数

bool judge(int value)

用于判断value是否是一个回文素数。所谓回文素数是指一个数既是回文数又是素数。

Input
输入两个数m和n，0<m<n。

Output
区间[m,n]内的所有回文素数。

Sample Input
2 1000
Sample Output
2
3
5
7
11
101
131
151
181
191
313
353
373
383
727
757
787
797
919
929
HINT
Append Code
append.cc, */