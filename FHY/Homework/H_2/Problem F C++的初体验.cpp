#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, d;
    double b;
    long long int c;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << a << endl;
    cout << fixed << setprecision(7) << b << endl;
    cout.unsetf(ios::fixed);
    cout.precision(6);
    cout << c << endl;
    cout.width(16);//cout <<setw(16)<<d<<endl;
    cout << setiosflags(ios::right) << d << endl;





    return 0;
}

// Problem F: C++的初体验
// Time Limit: 1 Sec  Memory Limit: 128 MB
// Submit: 651  Solved: 347
// [Submit][Status]
// Description
// 通过cin，cout进行C++程序的输入和输出

// Input
// 1.输入一个整数a
// 2.输入一个浮点数b
// 3.输入一个长整型数c
// 4.输入一个整数d

// Output
// 第一行输出整数a
// 第二行输出浮点数b，保留小数点后7位
// 第三行输出长整型数c
// 第四行输出整数d，宽度为16，右对齐

// Sample Input
// 1
// 2.323
// 2314213435435543
// 213
// Sample Output
// 1
// 2.3230000
// 2314213435435543
//              213
// HINT
// Append Code
