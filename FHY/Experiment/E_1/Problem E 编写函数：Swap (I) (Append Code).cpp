#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int Swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

    return 0;
}
int Swap(double &x, double &y)
{
    double temp;
    temp = x;
    x = y;
    y = temp;

    return 0;
}
int Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

    return 0;
}
int Swap(double *x, double *y)
{
    double temp;
    temp = *x;
    *x = *y;
    *y = temp;

    return 0;
}



int main()
{
    int x1, y1;

    cin>>x1>>y1;
    Swap(&x1, &y1);
    cout<<x1<<" "<<y1<<endl;

    cin>>x1>>y1;
    Swap(x1, y1);
    cout<<x1<<" "<<y1<<endl;

    double x2, y2;

    cin>>x2>>y2;
    Swap(&x2, &y2);
    cout<<x2<<" "<<y2<<endl;

    cin>>x2>>y2;
    Swap(x2, y2);
    cout<<x2<<" "<<y2<<endl;
}
/* 
Problem E: 编写函数：Swap (I) (Append Code)
Time Limit: 1 Sec  Memory Limit: 16 MB
Submit: 14175  Solved: 9575
[Submit][Status]
Description
编写用来交换两个数的函数，使得“Append Code”中的main()函数能正确运行。

-----------------------------------------------------------------------------

用C实现三个函数int_swap()、dbl_swap()、SWAP()，其中SWAP()是个带参宏。

用C++实现两个函数，都以Swap()命名。

以上函数的调用格式见“Append Code”。这里不给出函数原型，它们的参数请通过main()函数自行确定。

Input
输入为4行，每行2个数。

Output
输出为4行，每行2个数。每行输出的两数为每行输入的逆序。

Sample Input
12 57
9 -3
-12 4
3 5
Sample Output
57 12
-3 9
4 -12
5 3
HINT
“Append Code”中用到的头文件、全局变量或宏的定义应自行补充。

Append Code
append.c, append.cc, */