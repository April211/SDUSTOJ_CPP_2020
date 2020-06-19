#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

bool isprime(int x)
{
    if (x <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

class Compute
{
protected:
    int m$, n$; //n为个数，有正负
public:
    Compute(int m, int n) : m$(m), n$(n) {}
    virtual ~Compute() {}
    int showResult() const;
};

int Compute::showResult() const
{
    if (n$ > 0)
    {
        int cnt = 0;
        for (int i = m$;; i++)
        {
            if (isprime(i))
            {
                cnt++;
                if (cnt == 1)
                {
                    printf("%d", i);
                }
                else
                {
                    printf(" %d", i);
                }
            }
            if (cnt == n$)
                return 0;
        }
    }
    else if (n$ == 0)
    {
        return 0;
    }
    else
    {
        int n = -n$;
        int cnt = 0;
        for (int i = m$; i > 1; i--)
        {
            if (isprime(i))
            {
                cnt++;
                if (cnt == 1)
                {
                    printf("%d", i);
                }
                else
                {
                    printf(" %d", i);
                }
            }
            if (cnt == n)
                return 0;
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    Compute compute(a, b);
    compute.showResult();
    return 0;
}
/* 

Problem F: 相邻的素数
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3662  Solved: 422
[Submit][Status]
Description
任何大于1的自然数（即正整数）,除了1与它自身外,再没有其它的正约数了,这样的自然数叫做质数或素数。现在，需要你来设计一个类Compute，有两个int类型的属性m和n，定义：
（1）构造函数Compute(int,int)用来初始化m和n。
（2）void showResult()：当n>0时，按照从小到大的顺序输出从m开始，不小于m的n个素数；当n<0时，按照从大到小的顺序输出从m开始，不大于m的|n|（n的绝对值）个素数。输出时，两两之间用一个空格隔开。
在计算过程中，所有数据不会超出int类型表示范围。

Input
两个int类型整数，分别是Compute类的对象的属性m和n的值。

Output
即为showResult()方法的输出。

Sample Input
4 6
Sample Output
5 7 11 13 17 19
HINT
Append Code
append.cc, */