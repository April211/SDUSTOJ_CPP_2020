#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b, ans;
    char p;
    scanf("%d %c %d =", &a, &p, &b);
    (p == '+')?(ans = a + b):(ans = a - b);
    printf("%d %c %d = %d", a, p, b, ans);


    return 0;
}
// Problem C: 帮小明算算数（II）
// Time Limit: 1 Sec  Memory Limit: 128 MB
// Submit: 4037  Solved: 1901
// [Submit][Status]
// Description
// 小明现在正在学习加法和减法，完成家庭作业后，经常需要借助计算机来验证自己做的答案是否正确。请帮小明写一个程序，辅助他进行验证答案。

// Input
// 输入只有一行，格式为
// a o b =
// 其中a、b是两个int类型的整数，且它们的运算结果也在int类型范围内。o是一个'+'或者'-‘。’注意a、o、b、=之间都有一个空格隔开。
// Output
// 输出也只有一行，格式为：
// a o b = c
// 其中a、o、b与输入相同，c是a和b的和或差，取决于o是‘+‘还是’-’。注意a、o、b、=、c之间都有一个空格隔开。
// Sample Input
// 1 + 2 =
// Sample Output
// 1 + 2 = 3
// HINT
// 注意：不能使用分支语句。应使用条件表达式。


// Append Code
