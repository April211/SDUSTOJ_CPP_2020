#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
 
int a[100010];
int b[100010];

bool mjudge(int size)
{
    for(int j = 0; j< size; j++)
    {
        if(a[j] != b[j]) return false;
    }
    return true;
}
 
int main()
{
    int tt;
    int size = 0;
    while(cin >> tt)
    {
        a[size++] = tt;
    }
    b[0] = a[0];
    b[size-1] = a[size-1];
    while(1)
    {
        for(int j = 1; j < size-1; j++)
        {
            int ttt = b[j-1] + a[j+1];
            if(ttt % 2 ==0) 
            {
                b[j] = ttt / 2;
            }
            else
            {
                if(ttt > 0) 
                {
                    b[j] = ttt/2+1;
                }
                else 
                {
                    b[j] = ttt/2-1;
                }
            }
        }
        if(mjudge(size)) break;
        else
        {
            for(int j = 0; j < size; j++) 
                a[j] = b[j];
        }
        
    }
    
    for(int i = 0; i<size; i++)
    {
        if(i == 0) printf("%d", b[0]);
        else printf("%c%d", ' ', b[i]);
    }
        
    return 0;
}

/* 
Problem G: 数组的平滑
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1941  Solved: 342
[Submit][Status]
Description
给定一个由int类型的整数组成的数组，数组的平滑是指，将数组中除第一个和最后一个元素外，其他各个元素的值取相邻的两个值的平均值。具体而言，就是对于给定的数组a[n]，首先将a[1]取值为a[0]和a[2]的平均值；然后a[2]取值为a[1]（更新后的值）和a[3]的平均值；一直计算到a[n-2]，为a[n-3]（更新后的值）和a[n-1]的平均值。重复上述过程，直到数组的所有元素的值都不变为止。

注意，由于数组是int类型的，所有在取平均值时，需要进行四舍五入。
比如，原始数组为：2 3 7 12。那么第一次平滑的结果是：2 5 9 12；第二次平滑后的结果为2 6 9 12，之后的平滑计算都不会改变这个数组的值。所以最终的结果是2 6 9 12。

Input
若干个int类型范围内的整数。

Output
经过平滑后的最终结果。输出时，两两之间用一个空格隔开。

Sample Input
2 3 7 12
Sample Output
2 6 9 12
HINT
Append Code */