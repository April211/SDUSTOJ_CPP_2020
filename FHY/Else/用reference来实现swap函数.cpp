#include <iostream>
#include <cstdio>
using namespace std;

int Swap(int& x, int& y)
{

    int temp = x;
    x = y;
    y = temp;

    return 0;
}

int main()
{
    int a, b;
    a = 11;
    b = 14;
    cout << a << ' ' << b << endl;
    Swap(a, b);
    cout << a << ' ' << b << endl;


    return 0;

}
