#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double mei, ou, ri;
    double x, y;

    cin >> mei >> ou >> ri;
    cin >> x;
    cin >> y;
    mei = mei / 100.0;
    ou = ou / 100.0;
    ri = ri / 100.0;
    cout << showpoint << fixed << setprecision(2) << mei * x << ' '  << ou * x << ' ' << ri * x  << endl;
    cout << showpoint << fixed << setprecision(2) << y / mei << ' '  << y / ou << ' ' << y / ri ;


    return 0;
}
//Problem E: 货币兑换
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 23072  Solved: 10425
//[Submit][Status]
//Description
//给出人民币对美元、欧元、日元的当日汇率，求给定金额的人民币能兑换成外币的金额，求给定金额的外币能兑换成人民币的金额。
//要计算的外币有三种：美元、欧元、日元。
//
//Input
//输入有三行。
//第一行依次为美元、欧元、日元外币汇率，用空格分开。汇率用100外币为单位，精确到小数点后4位，如668.5200表示“100美元=668.5200人民币”。汇率浮动范围为(0,10000)。
//第二行为外币金额x，第三行为人民币金额y。x,y均为整数，且0<x,y<10000。
//
//Output
//输出为两行。
//第一行是金额为x的美元、欧元、日元兑换成人民币的金额，用空格分开。
//第二行是金额为y的人民币兑换成美元、欧元、日元的金额，用空格分开。
//所有金额精确到小数点后两位。
//
//Sample Input
//668.5200 908.0685 7.9852
//1500
//1500
//Sample Output
//10027.80 13621.03 119.78
//224.38 165.19 18784.75
//HINT
//了解浮点数据类型的精确度和输出控制。
//
//Append Code
