#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    int a = 0, b = 0;
    while(scanf("%d %d",&a, &b) != EOF)
    {
        cout << a + b << endl;
    }






    return 0;
}
////Problem H: 简单的打折计算
////Time Limit: 1 Sec  Memory Limit: 2 MB
////Submit: 19190  Solved: 10598
////[Submit][Status]
////Description
////商店规定：消费满n元，可以打八八折。设某件商品标价m元，输入购买的件数x，计算出需要支付的金额（单位：元），精确到分。
////
////Input
////输入只有一行，三个整数m、n和x，且0<x<m<n<1000。
////
////Output
////输出金额，精确到分。
////
////Sample Input
////95 300 4
////Sample Output
////334.40
////HINT
////了解浮点型的输出控制，注意整型和浮点型混合运算过程中的数据类型转换。
////
////Append CodeProblem I: A+B Problem
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 14008  Solved: 8890
//[Submit][Status]
//Description
//计算a+b，0<=a,b<1000。
//
//Input
//输入有多对整数a和b组成，每对a和b占一行，a,b用空格分开。
//
//Output
//每行输出一个a+b的值，顺序与输入对应。
//
//Sample Input
//1 2
//10 20
//Sample Output
//3
//30
//HINT
//OJ系统上测试输入结束符为EOF（End Of File），其值为-1。用scanf()把文件所有内容读完后，会读到EOF，所以可以用来判断输入是否完成，测试时可以用Ctrl+Z产生EOF。本题解法参看FAQ。
//
//Append Code
