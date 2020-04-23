#include <iostream>
#include <iomanip>
#include <cstdio>
#define PI 3.14
using namespace std;

int main()
{
    double x;
    cin >> x ;
    cout << "Area: " << fixed << showpoint << setprecision(6) << PI * x *x << endl;
    cout << "Perimeter: " << 2 * PI * x ;

    return 0;
}
