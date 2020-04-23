#include <iostream>
#include <iomanip>
#include <string>
#define PI 3.14159
using namespace std;

int main()
{
    double r, h;
    double S;
    cin >> r >> h;
    S = 2.0*PI*r*r + 2.0*PI*r*h;
    cout << fixed << setprecision(3) << S;




}
