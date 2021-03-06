#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <stack>
#include <vector>

#define INF 0x3f3f3f3f
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR -2
#define DEFAULT_SET -1

#define PI 3.14159265 // 圆周率
#define x1max 12.0    // 坐标 1 上限
#define x1min -2.9    // 坐标 1 下限
#define x2max 5.7     // 坐标 2 上限
#define x2min 4.2     // 坐标 2 下限
#define accuracy 1e5  // 表示计算精度

#define bits_snum 39               // 二进制编码位数
#define bits_x1 21                 // 坐标 1 所占的二进制编码位数
#define bits_x2 18                 // 坐标 2 所占的二进制编码位数
#define cross_probability 0.5      // 交叉概率
#define mutation_probability 0.005 // 变异概率
#define population_size 30         // 种群规模
using namespace std;

void f1()
{
    /*     // 下面的 4行不可以放到 for循环中
    static default_random_engine e1, e2;
    e1.seed((unsigned int)time(NULL)), e2.seed((unsigned int)time(NULL));
    static uniform_real_distribution<double> u1(x1min, x1max); //随机数分布对象
    static uniform_real_distribution<double> u2(x2min, x2max); */
    // 下面的 4行不可以放到 for循环中
    static int ik = 0;
    ik++;
    static mt19937 e1, e2;
    e1.seed((unsigned int)time(NULL)* ik), e2.seed((unsigned int)time(NULL)* ik);
    uniform_real_distribution<double> u1(x1min, x1max); //随机数分布对象
    uniform_real_distribution<double> u2(x2min, x2max);

    for (int i = 0; i < 5; i++)
    {
        double tt1 = u1(e1);
        double tt2 = u2(e2);
        printf("%lf %lf\n", tt1, tt2);
    }
}

int main()
{
    f1();
    f1();
    f1();

    return 0;
}