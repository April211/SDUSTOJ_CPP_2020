#include <iostream>
#include <iomanip>
#include <cstdio>
#define PI 3.14
using namespace std;

int main()
{
    double x;
    cin >> x ;
    cout << "Area: " << fixed << showpoint << setprecision(6) << PI * x *x << endl;
    cout << "Perimeter: " << 2 * PI * x ;

    return 0;
}


//Problem C: 求圆的面积和周长
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 28922  Solved: 12232
//[Submit][Status]
//Description
//从键盘输入圆的半径，求圆的面积和周长，圆周率取3.14。
//
//Input
//输入一个浮点型数据，有效数字不会超过十进制的6位。
//
//Output
//输出为两行。
//第一行为圆的面积，第二行为圆的周长，格式见sample。
//
//Sample Input
//3
//Sample Output
//Area: 28.260000
//Perimeter: 18.840000
//HINT
//了解浮点类型的输入、输出和算术运算符
//
//Append Code
