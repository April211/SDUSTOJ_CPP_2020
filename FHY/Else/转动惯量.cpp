#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    double g = 9.8;
    double r = 0.019, m = 0.1726;
    double beta1 = 0, beta2 = 0;
    while (scanf("%lf%lf", &beta2, &beta1)!=EOF)
    {
        double ans = ((m * g * r) / (beta2 - beta1)) - ((beta2 / (beta2 - beta1)) * m * r * r);
        printf("%.4lf\n", ans);
    }

    return 0;
}


/* 0.983 -0.184
0.0275
1.313 -0.241
0.0206
1.854 -0.378
0.0143
1.554 -0.324
0.0171
1.554 -0.378
0.0166
^Z */