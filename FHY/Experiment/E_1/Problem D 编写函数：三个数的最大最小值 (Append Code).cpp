#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int get_num(int &x,int &y,int &z)
{
    cin >> x >> y >> z;
    return 0;
}
int max_min(int &nmax,int &nmin, int x, int y, int z)
{
    int t;
    if(x<y)
    {
        t = x;
        x = y;
        y = t;
    }
    if(y<z)
    {
        t = y;
        y = z;
        z = t;
    }
    if(x<y)
    {
        t = x;
        x = y;
        y = t;
    }
    nmax = x;
    nmin = z;
    return 0;
}

int main()
{
    int cases;
    int mmax, mmin, a, b, c;

    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        get_num(a, b, c);
        max_min(mmax, mmin, a, b, c);
        cout<<"case "<<i<<" : "<<mmax<<", "<<mmin<<endl;
    }
}
/* 
Problem D: 编写函数：三个数的最大最小值 (Append Code)
Time Limit: 1 Sec  Memory Limit: 2 MB
Submit: 15296  Solved: 9326
[Submit][Status]
Description
给出三个数a,b,c，最大值是？最小值是？

-----------------------------------------------------------------------------

编写以下两个函数：

get_num()的功能是读取输入的三个整数a,b,c；

max_min()的功能是求出a,b,c的最大值和最小值。

以上函数的调用格式见“Append Code”。这里不给出函数原型，请通过main()函数自行确定。

Input
输入的第一个整数n，表示有n组测试数据，每组3个整数：a,b,c。a,b,c都在int类型范围内。
Output
每组测试数据对应输出一行：为a,b,c的最大值和最小值，格式见sample。
Sample Input
5
20 15 10
10 15 20
100 100 0
0 1 -1
0 0 0
Sample Output
case 1 : 20, 10
case 2 : 20, 10
case 3 : 100, 0
case 4 : 1, -1
case 5 : 0, 0
HINT
Append Code
append.c, append.cc, */
