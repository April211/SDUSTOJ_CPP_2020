#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double p, w, m;
    double ans;

    scanf("%lf %lf %lf", &p, &w, &m);
    if(m <= 500)
    {
        ans = p*w*m;
    }
    else if(m <= 1000)
    {
        ans = p*w*500.0 + 0.95*p*w*(m - 500.0);
    }
    else if(m <= 2000)
    {
        ans = p*w*500.0 + 0.95*p*w*500.0 + 0.9*p*w*(m - 1000.0);
    }
    else
    {
        ans = p*w*500.0 + 0.95*p*w*500.0 + 0.9*p*w*1000.0 + 0.88*p*w*(m - 2000.0);

    }

    printf("%.2lf", ans);


    return 0;
}
