#include <iostream>
using namespace std;

int main()
{
    int x, y;
    char a;
    cin >> a >> a >> x >> a >> a >> a >> y;
    cout << "x + y : " << x + y << endl;
    cout << "x - y : " << x - y << endl;
    cout << "x * y : " << x * y << endl;
    cout << "x / y quotient: " << x / y << ", remainder: " << x % y << endl;
    cout << "x ^ 2 : " << x * x << endl;
    cout << "y ^ 3 : " << y * y * y;

    return 0;
}
