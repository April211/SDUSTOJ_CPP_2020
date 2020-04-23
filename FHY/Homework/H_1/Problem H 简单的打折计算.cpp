#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double m, n, x;
    double s;

    cin >> m >> n >> x;
    s = m * x;
    if(s >= n)
    {

      cout << showpoint << fixed << setprecision(2) << s*0.88 ;

    }
    else
    {
      cout << showpoint << fixed << setprecision(2) << s;

    }


    return 0;
}
