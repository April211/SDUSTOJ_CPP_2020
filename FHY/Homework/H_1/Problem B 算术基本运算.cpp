#include <iostream>
using namespace std;

int main()
{
    int x, y;
    char a;
    cin >> a >> a >> x >> a >> a >> a >> y;
    cout << "x + y : " << x + y << endl;
    cout << "x - y : " << x - y << endl;
    cout << "x * y : " << x * y << endl;
    cout << "x / y quotient: " << x / y << ", remainder: " << x % y << endl;
    cout << "x ^ 2 : " << x * x << endl;
    cout << "y ^ 3 : " << y * y * y;

    return 0;
}
//Problem B: 算术基本运算
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 38313  Solved: 11306
//[Submit][Status]
//Description
//计算两整数x和y（0<x,y<1000）的和、差、积、商、余数、x的平方和y的三次方。
//
//Input
//输入只有一行，格式见sample。
//
//Output
//输出为多行，按顺序每行输出x,y的和、差、积、商、余数、x的平方和y的三次方，格式见sample
//
//Sample Input
//x = 11, y = 3
//Sample Output
//x + y : 14
//x - y : 8
//x * y : 33
//x / y quotient: 3, remainder: 2
//x ^ 2 : 121
//y ^ 3 : 27
//HINT
//注意输入输出格式。了解C语言整数除法运算符的特点，并且没有求幂的运算符。
//
//Append Code
