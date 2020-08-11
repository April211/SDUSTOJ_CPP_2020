#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a = 3.1415;
    int    b = 3;
    double c = 3.10;
    double d = 3.0;
    cout << a <<endl;
    cout << b <<endl;
    cout << c <<endl;
    cout << d <<endl;
    cout << endl;
    cout << fixed << showpoint << setprecision(3) << d << endl ;//实际上，showpoint在这里不是必须的
    cout << noshowpoint;
    cout << fixed << b << endl ;
//    cout << setprecision(3) << b << endl ;
//    cout <<endl;
//    cout << setprecision(3) << a << endl ;
//    cout <<  showpoint << a << endl ;
//    cout << fixed  << a << endl ;







    return 0;
}
