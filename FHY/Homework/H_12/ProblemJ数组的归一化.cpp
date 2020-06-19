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

Problem J: 数组的归一化
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 2915  Solved: 396
[Submit][Status]
Description
对于给定的一个由非负的int类型的整数组成的数组，归一化是指将每个元素除以数组元素之和。比如：给定一个数组1 2 3 4，那么归一化之后是0.10 0.20 0.30 0.40，即每个元素值除以10（数组元素之和）。
现在，给定一个由若干个非负整数组成的数组，输出其归一化之后的结果。输出时保留2位小数且两两之间用一个空格隔开。假定数组至少有1个元素，且数组元素之和不超过int类型的表示范围。

Input
若干个int类型范围内的整数。

Output
按照要求输出归一化后的结果。

Sample Input
1 2 3 4
Sample Output
0.10 0.20 0.30 0.40
HINT
Append Code */