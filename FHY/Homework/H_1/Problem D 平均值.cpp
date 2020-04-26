#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x, y, z;

    cin >> x >> y >> z;
    cout << showpoint << fixed << setprecision(3) << (x + y + z)/3.0 ;


    return 0;
}
//Problem D: 平均值
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 20386  Solved: 11563
//[Submit][Status]
//Description
//求3个数的平均值。
//
//Input
//输入只有一行，为3个较小的整数。
//
//Output
//输出为这3个整数的平均值，保留3位小数。
//
//Sample Input
//1 2 3
//Sample Output
//2.000
//HINT
//注意除法运算对整型数据和浮点型数据是不一样的。
//
//Append Code
