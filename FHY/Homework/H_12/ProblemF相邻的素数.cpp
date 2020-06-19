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
    int m$, n$; //nΪ������������
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

Problem F: ���ڵ�����
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3662  Solved: 422
[Submit][Status]
Description
�κδ���1����Ȼ��������������,����1����������,��û����������Լ����,��������Ȼ���������������������ڣ���Ҫ�������һ����Compute��������int���͵�����m��n�����壺
��1�����캯��Compute(int,int)������ʼ��m��n��
��2��void showResult()����n>0ʱ�����մ�С�����˳�������m��ʼ����С��m��n����������n<0ʱ�����մӴ�С��˳�������m��ʼ��������m��|n|��n�ľ���ֵ�������������ʱ������֮����һ���ո������
�ڼ�������У��������ݲ��ᳬ��int���ͱ�ʾ��Χ��

Input
����int�����������ֱ���Compute��Ķ��������m��n��ֵ��

Output
��ΪshowResult()�����������

Sample Input
4 6
Sample Output
5 7 11 13 17 19
HINT
Append Code
append.cc, */