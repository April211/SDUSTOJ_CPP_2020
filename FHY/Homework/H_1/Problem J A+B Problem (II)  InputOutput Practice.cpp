#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    int a = 0, b = 0;
    int N;
    int i;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> a >> b;
        if(N - i == 1)
        {
            cout << a + b;
        }
        else
        {
             cout << a + b << endl;
        }

    }






    return 0;
}
//Problem J: A+B Problem (II) : Input/Output Practice
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 12260  Solved: 8392
//[Submit][Status]
//Description
//计算a+b，0<=a,b<1000。
//
//Input
//输入的第一行是一个整数N，后面有N对整数a和b，每对a和b占一行，a,b用空格分开。
//
//Output
//每行输出一个a+b的和，顺序与输入对应。
//
//Sample Input
//2
//1 2
//10 20
//Sample Output
//3
//30
//HINT
//N给出了测试样例数，用for循环处理方便。
//
//Append Code
