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


/* Problem D: ����ļӷ�����
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 3858  Solved: 2479
[Submit][Status]
Description
������newInt��������

1. int���͵����ݳ�Ա��

2. �����������+�����������Ϊ����A��B��Ӧλ���ϵ�������ӣ�ֻ������λ����Ϊ����Ķ�Ӧλ���ϵ����֡����磺876 + 543 = 319��ע�⣺�����㲻�ı�������������ֵ��

3. ����������������������������������������ֵ��

4. �޲ι��캯���ʹ��ι��캯����

Input
��1��N>0����ʾ��������������

ÿ��������������2���Ǹ��������ÿո������

Output
��������

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
 ����ʹ��string��char���ַ����ַ������͡�

Append Code
append.cc, */