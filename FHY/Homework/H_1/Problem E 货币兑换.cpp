#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double mei, ou, ri;
    double x, y;

    cin >> mei >> ou >> ri;
    cin >> x;
    cin >> y;
    mei = mei / 100.0;
    ou = ou / 100.0;
    ri = ri / 100.0;
    cout << showpoint << fixed << setprecision(2) << mei * x << ' '  << ou * x << ' ' << ri * x  << endl;
    cout << showpoint << fixed << setprecision(2) << y / mei << ' '  << y / ou << ' ' << y / ri ;


    return 0;
}
