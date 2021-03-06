#include <bits/stdc++.h>
using namespace std;

class newInt
{
protected:
    int x$;

public:
    newInt() : x$(0) {}
    newInt(int x) : x$(x) {}
    newInt(const newInt &tt) : x$(tt.x$) {}
    ~newInt() {}
    friend newInt operator+(newInt i1, newInt i2);
    friend istream &operator>>(istream &is, newInt &tt);
    friend ostream &operator<<(ostream &os, newInt &tt);
};

newInt operator+(newInt i1, newInt i2)
{
    int x1 = i1.x$, x2 = i2.x$;
    int cnt = 1;
    int ans = 0;
    //cout << "zzz" << endl;
    while ((x1 != 0) || (x2 != 0))
    {
        ans += ((x1 % 10 + x2 % 10) % 10) * cnt;
        x1 /= 10;
        x2 /= 10;
        cnt *= 10;
    }
    //cout << ans << ' ' << cnt << endl;
    newInt ansob(ans);
    return ansob;
}

inline istream &operator>>(istream &is, newInt &tt)
{
    is >> tt.x$;
    return is;
}

inline ostream &operator<<(ostream &os, newInt &tt)
{
    os << tt.x$;
    return os;
}

int main()
{
    int cases;
    newInt a, b, c;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> a >> b;
        c = a + b;
        cout << a << " + " << b << " = " << c << endl;
    }
    return 0;
}


/* Problem D: 新奇的加法运算
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3858  Solved: 2479
[Submit][Status]
Description
定义类newInt，包括：

1. int类型的数据成员。

2. 重载运算符“+”。计算规则为：将A、B对应位置上的数字相加，只保留个位数作为结果的对应位置上的数字。比如：876 + 543 = 319。注意：该运算不改变两个操作数的值。

3. 重载输入和输出运算符，用于输入和输出对象的属性值。

4. 无参构造函数和带参构造函数。

Input
第1行N>0，表示测试用例数量。

每个测试用例包括2个非负整数，用空格隔开。

Output
见样例。

Sample Input
4
876 543
999 9999
9 1999
199 88
Sample Output
876 + 543 = 319
999 + 9999 = 9888
9 + 1999 = 1998
199 + 88 = 177
HINT
 不能使用string、char等字符或字符串类型。

Append Code
append.cc, */