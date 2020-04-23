#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x, y, z;

    cin >> x >> y >> z;
    cout << showpoint << fixed << setprecision(3) << (x + y + z)/3.0 ;


    return 0;
}
