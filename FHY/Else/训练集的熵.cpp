#include <cstdio>
#include <cmath>
#include <cstdlib>


int main()
{
    double entropy = 0.9179;
    double gain = entropy - (8.0/9.0)* (-(5.0/8.0)* (log(5.0/8.0)/log(2.0)) - (3.0/8.0)* (log(3.0/8.0)/log(2.0)));
    printf("%lf\n", gain);


    return 0;
}
