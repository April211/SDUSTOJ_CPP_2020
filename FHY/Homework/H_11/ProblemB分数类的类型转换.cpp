#include <bits/stdc++.h>
using namespace std;

class Fract
{
protected:
    int n$, m$;
public:
    Fract(int n, int m) : n$(n), m$(m)
    {
        if(m$ < 0){ m$ *= -1, n$ *= -1;}
        int gcd, num1 = abs(n$), num2 = abs(m$);
        gcd = __gcd(num1, num2);
        n$ /= gcd, m$ /= gcd;
    }
    operator double(){ return (double)n$ / m$;}
    void show() const
    {
        if (n$ == 0 || m$ == 1)  cout << n$ << endl;
        else cout << n$ << '/' << m$ << endl;
    }
};


int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        Fract fr(n, m);
        cout << (double)fr << " ";
        fr.show();
    }
}