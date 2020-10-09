#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    double r1 = 0, r2 = 0, r3 = 0;
    double m_loop = 0.6363, m_pan = 0.5838;
    scanf("%lf%lf", &r1, &r2);
    scanf("%lf", &r3);
    printf("%.5lf\n", (0.5* m_loop* (r1* r1 + r2* r2)));
    printf("%.5lf\n", (0.5* m_pan* r3* r3));


    return 0;
}

/* 0.1 0.086
0.1
0.0055
0.0029 */
