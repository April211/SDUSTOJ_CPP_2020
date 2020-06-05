#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        char op = 0;
        double tt = 0;
        stack<double> mem;

        cin >> tt;
        mem.push(tt);

        for(int i = 0; i< n-1; i++)
        {
            cin >> op >> tt;
            if(op == '+')
            {
                mem.push(tt);
            }
            else if(op == '-')
            {
                mem.push(-tt);
            }
            else if(op == '*')
            {
                tt = tt* mem.top();
                mem.pop();
                mem.push(tt);
            }
            else// /
            {
                tt = mem.top() / tt;
                mem.pop();
                mem.push(tt);
            }
            

        }
        cin >> op;// =
        double ans = 0;
        int st = mem.size();//随着元素的删除，size在不断变化，必须取个初值
        for(int i = 0; i< st; i++)
        {
            ans = ans + mem.top();
            mem.pop();
        }

        cout << fixed << setprecision(2) << ans << endl;



    }



    return 0;
}


/* Problem D: STL——表达式求值
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4945  Solved: 3100
[Submit][Status]
Description
给出一个表达式，求出其值。表达式中只存在 +、-、*、三种运算，我们假设表达式是正确的，
      且不存在除数为零的情况。
Input
第一行输入一个正整数 n（1<=n<=30） ，表示有表达式 n 个数（每个数均小于100），表达式中只有数值（都是大于零的数）
      和运算符（包括+、-、*、=四种运算符，其中 = 只在表达式最后，表示一个表达式输出结束，且整个表达式不存在空格）
Output
表达式的值（表达式的值不会超出 double 的范围并保留两位小数）
Sample Input
5
1*2*3*4*5=
5
5-1-2+3+4=
Sample Output
120.00
9.00
HINT
使用STL的stack容易实现。


Append Code */