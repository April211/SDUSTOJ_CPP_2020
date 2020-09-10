#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


int main()
{
    double d1 = 0.0, d2 = 0.0;    
    double ans = 0.0;
    for(int i = 0; i< 5; i++)
    {
        cin >> d1 >> d2;
        ans += fabs(((2.0/50.0)*(d1 - d2)/5.0) - 0.00063104);
    }
    ans /= 5.0;
    printf("%lf", ans);

    return 0;
}
