#include <iostream>
#include <iomanip>
#include <string>
#define PI 3.14159
using namespace std;

int main()
{
    double r, h;
    double S;
    cin >> r >> h;
    S = 2.0*PI*r*r + 2.0*PI*r*h;
    cout << fixed << setprecision(3) << S;




}


// Problem H: 圆柱体的表面积
// Time Limit: 1 Sec  Memory Limit: 2 MB
// Submit: 2507  Solved: 1558
// [Submit][Status]
// Description
// 圆柱体表面积由两部分组成：两个底面圆面积和一个卷起来的矩形面积。现给出一个圆柱体的底面圆半径r和高h，求其表面积。其中，圆周率取3.14159。

// Input
// 输入两个实数r和h。

// Output
// 输出圆柱体的表面积，精确到小数点后3位。

// Sample Input
// 2 2
// Sample Output
// 50.265
// HINT
// Append Code
