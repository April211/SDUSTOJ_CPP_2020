#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::vector;

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
#define x2min 4.2   // 坐标 2 下限
#define accuracy 1e5  // 表示计算精度

#define bits_snum 39               // 二进制编码位数
#define bits_x1 21                 // 坐标 1 所占的二进制编码位数
#define bits_x2 18                 // 坐标 2 所占的二进制编码位数
#define cross_probability 0.5      // 交叉概率
#define mutation_probability 0.005 // 变异概率
#define population_size 30         // 种群规模

vector<int> x_bincode$; // 自变量二进制编码

void Dec_to_Bin(stack<int> &x_binary, int j)
{
    if (j == 0)
        return;
    else
    {
        x_binary.push(j % 2);
        Dec_to_Bin(x_binary, j / 2);
    }
}

int main()
{
    stack<int> tt1, tt2;

    Dec_to_Bin(tt1, 2097152-1);
    Dec_to_Bin(tt2, 262144-1);

    int size1 = tt1.size(), size2 = tt2.size();

    // 前导零
    for (int i = 0; i < bits_x1 - size1; i++)
    {
        x_bincode$.push_back(0);
    }

    for (int i = 0; i < size1; i++)
    {
        x_bincode$.push_back(tt1.top());
        tt1.pop();
    }

    // 前导零
    for (int i = 0; i < bits_x2 - size2; i++)
    {
        x_bincode$.push_back(0);
    }

    for (int i = 0; i < size2; i++)
    {
        x_bincode$.push_back(tt2.top());
        tt2.pop();
    }

    printf("%d\n", x_bincode$.size());
    for (int i = 0; i < bits_snum; i++)
    {
        printf("%d", x_bincode$[i]);
    }
    printf("\n");

    int j1 = 0, j2 = 0;
    for (int i = 0; i < bits_x1; i++)
    {
        j1 += x_bincode$[i] * pow(2.0, 1.0 * (bits_x1 - i - 1));
    }

    for (int i = bits_x1; i < bits_snum; i++)
    {
        j2 += x_bincode$[i] * pow(2.0, 1.0 * (bits_snum - i - 1));
    }

    double mi1 = 1.0, mi2 = 1.0;
    for(int i = 0; i< bits_x1; i++)
    {
        mi1 *= 2;
    }

    for(int i = 0; i< bits_x2; i++)
    {
        mi2 *= 2;
    }

    printf("%.5lf %.5lf\n", mi1, mi2);
    double x1$ = x1min + j1 * ((x1max - x1min) / (pow(2.0, 1.0 * bits_x1) - 1.0));
    double x2$ = x2min + j2 * ((x2max - x2min) / (pow(2.0, 1.0 * bits_x2) - 1.0));
    
    printf("%d %d\n", j1, j2);
    printf("%.5lf %.5lf\n", x1$, x2$);

    return 0;
}
