#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, d;
    double b;
    long long int c;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << a << endl;
    cout << fixed << setprecision(7) << b << endl;
    cout.unsetf(ios::fixed);
    cout.precision(6);
    cout << c << endl;
    cout.width(16);//cout <<setw(16)<<d<<endl;
    cout << setiosflags(ios::right) << d << endl;





    return 0;
}
