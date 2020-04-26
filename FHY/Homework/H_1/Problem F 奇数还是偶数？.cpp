#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    cin >> x;
    if(x % 2 == 0)
    {
        cout << "even";
    }
    else
    {
        cout << "odd";
    }


    return 0;
}

//Problem F: 奇数还是偶数？
//Time Limit: 1 Sec  Memory Limit: 2 MB
//Submit: 14783  Solved: 11293
//[Submit][Status]
//Description
//输入一个整数，判读它是奇数还是偶数。
//
//Input
//输入只有一行，为一个100以内的正整数。
//
//Output
//输出为一行。
//若输入为偶数则输出“even”，奇数输出“odd”。
//
//Sample Input
//30
//Sample Output
//even
//HINT
//用整数运算可以解决，练习“?:”表达式。
//
//Append Code
