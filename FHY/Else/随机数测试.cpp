#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <stack>
#include <vector>
using namespace std;

void f1()
{
    // 下面的 4行不可以放到 for循环中
    double m = 0.0, n = 1.0;
    default_random_engine e;
    e.seed((unsigned int)time(NULL) * 10013);
    uniform_real_distribution<double> u(m, n); //随机数分布对象
    std::uniform_int_distribution<unsigned> u2(0, 20 - 1);

    for (int i = 0; i < 10; i++)
    {
        double tt = u(e);
        printf("%lf %d\n", tt, u2(e));
    }
}

int main()
{
    f1();

    return 0;
}