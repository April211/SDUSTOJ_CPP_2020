#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double m, n, x;
    double s;

    cin >> m >> n >> x;
    s = m * x;
    if(s >= n)
    {

      cout << showpoint << fixed << setprecision(2) << s*0.88 ;

    }
    else
    {
      cout << showpoint << fixed << setprecision(2) << s;

    }


    return 0;
}
//Problem H: 简单的打折计算
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 19190  Solved: 10598
//[Submit][Status]
//Description
//商店规定：消费满n元，可以打八八折。设某件商品标价m元，输入购买的件数x，计算出需要支付的金额（单位：元），精确到分。
//
//Input
//输入只有一行，三个整数m、n和x，且0<x<m<n<1000。
//
//Output
//输出金额，精确到分。
//
//Sample Input
//95 300 4
//Sample Output
//334.40
//HINT
//了解浮点型的输出控制，注意整型和浮点型混合运算过程中的数据类型转换。
//
//Append Code
