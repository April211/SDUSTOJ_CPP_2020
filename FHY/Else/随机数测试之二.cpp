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

vector<unsigned> good_randVec()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 5; ++i)
    {
        ret.push_back(u(e));
    }
    return ret;
}

int main()
{
    vector<unsigned> rt1(good_randVec()), rt2(good_randVec());
    for(int i = 0; i< rt1.size(); i++)
    {
        printf("%u\n", rt1[i]);
    }

    printf("---------------------\n");

    for(int i = 0; i< rt1.size(); i++)
    {
        printf("%u\n", rt2[i]);
    }

    return 0;
}
