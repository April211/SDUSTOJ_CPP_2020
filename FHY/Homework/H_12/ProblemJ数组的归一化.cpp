#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
 

int main()
{
    double x;
    int size = 0;
    double summ = 0;
    vector<double> lib;
    while (scanf("%lf", &x)!=EOF)
    {
        lib.push_back(x);
        size++;
        summ += x;
    }
    for(int j = 0; j< size; j++)
    {
        if(lib[j] == 0.0 && summ == 0.0) //.....
        {
            if(j == 0)
                printf("1.00"); 
            else
                printf(" 1.00");
        }
        else if(j == 0)
            printf("%.2lf", lib[j] / summ); 
        else
            printf(" %.2lf", lib[j] / summ); 
    }


    return 0;
}

/* 

Problem J: ����Ĺ�һ��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2915  Solved: 396
[Submit][Status]
Description
���ڸ�����һ���ɷǸ���int���͵�������ɵ����飬��һ����ָ��ÿ��Ԫ�س�������Ԫ��֮�͡����磺����һ������1 2 3 4����ô��һ��֮����0.10 0.20 0.30 0.40����ÿ��Ԫ��ֵ����10������Ԫ��֮�ͣ���
���ڣ�����һ�������ɸ��Ǹ�������ɵ����飬������һ��֮��Ľ�������ʱ����2λС��������֮����һ���ո�������ٶ�����������1��Ԫ�أ�������Ԫ��֮�Ͳ�����int���͵ı�ʾ��Χ��

Input
���ɸ�int���ͷ�Χ�ڵ�������

Output
����Ҫ�������һ����Ľ����

Sample Input
1 2 3 4
Sample Output
0.10 0.20 0.30 0.40
HINT
Append Code */