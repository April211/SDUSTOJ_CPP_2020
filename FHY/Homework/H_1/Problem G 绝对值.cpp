#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int x;
    double y;

    cin >> x;
    cin >> y;
    cout << abs(x) << endl;
    cout << fabs(y);


    return 0;
}
//Problem G: 绝对值
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 23934  Solved: 9598
//[Submit][Status]
//Description
//求整型数据和浮点型数据的绝对值。
//
//Input
//输入两个数，第一个是整数，第二个是浮点数。
//
//Output
//输出为两行，第一行为整数的绝对值，第二行为浮点数的绝对值，注意浮点数的绝对值不输出无意义的0。
//
//Sample Input
//-1
//1
//Sample Output
//1
//1
//HINT
//求绝对值可以用标准库函数来完成，也可以自己判断。注意浮点数的输出格式。求绝对值的函数在哪个头文件？貌似很多人会搞错，包括很多编书的人！
//
//Append Code
