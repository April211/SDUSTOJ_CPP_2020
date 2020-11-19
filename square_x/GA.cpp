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
#define x2min 4.2     // 坐标 2 下限
#define accuracy 1e5  // 表示计算精度

#define bits_snum 39               // 二进制编码位数
#define bits_x1 21                 // 坐标 1 所占的二进制编码位数
#define bits_x2 18                 // 坐标 2 所占的二进制编码位数
#define cross_probability 0.5      // 交叉概率
#define mutation_probability 0.005 // 变异概率
#define population_size 10         // 种群规模

typedef int Status;

// 判断大小
int Max(const int &a, const int &b)
{
    return (a > b) ? a : b;
}

bool Fitness_Greater(const Info &a, const Info &b)
{
    return (a.fitness > b.fitness);
}

// 十进制数转二进制
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

// 整数类（对应到：染色体（个体））
class Digit
{
protected:
    double x1$;             // 自变量坐标 1
    double x2$;             // 自变量坐标 2
    double fitness$;        // 个体适应度（取与目标函数值一致）
    vector<int> x_bincode$; // 自变量二进制编码

public:
    // 构造函数
    Digit() : x1$(DEFAULT_SET), x2$(DEFAULT_SET), fitness$(DEFAULT_SET) {}

    Digit(double x1, double x2) : x1$(x1), x2$(x2)
    {
        // 初始适应度计算
        fitness$ = 21.5 + x1$ * sin(4.0 * PI * x1$) + x2$ * sin(20.0 * PI * x2$);
    }

    // 拷贝构造函数
    Digit(const Digit &tt) : x1$(tt.x1$), x2$(tt.x2$), fitness$(tt.fitness$)
    {
        x_bincode$.clear(); // 先清空，再深拷贝
        for (int i = 0; i < bits_snum; i++)
        {
            x_bincode$.push_back(tt.x_bincode$[i]);
        }
    }

    // 析构函数
    ~Digit() {}

    // 重载运算符
    bool operator==(const Digit &d)
    {
        // 十进制坐标一致即可判相等
        if ((this->x1$ == d.x1$) && (this->x2$ == d.x2$))
            return true;
        else
            return false;
    }

    bool operator!=(const Digit &d)
    {
        // 十进制坐标出现不一致即可以判不相等
        if ((this->x1$ != d.x1$) || (this->x2$ != d.x2$))
            return true;
        else
            return false;
    }

    Digit operator=(const Digit &tt)
    {
        x1$ = tt.x1$;
        x2$ = tt.x2$;
        fitness$ = tt.fitness$;

        x_bincode$.clear(); // 先清空，再深拷贝
        for (int i = 0; i < bits_snum; i++)
        {
            x_bincode$.push_back(tt.x_bincode$[i]);
        }
        return (*this);
    }

    // 获取坐标 1（十进制）
    int Get_X1() const { return x1$; }

    // 获取坐标 2（十进制）
    int Get_X2() const { return x2$; }

    // 获取该个体的适应度
    int Get_Fitness() const { return fitness$; }

    // 设置坐标 1（十进制）
    Status Set_X1(double x1)
    {
        x1$ = x1;
        return OK;
    }

    // 设置坐标 2（十进制）
    Status Set_X2(double x2)
    {
        x2$ = x2;
        return OK;
    }

    // 设置坐标（十进制）
    Status Set_Coordinate(double x1, double x2)
    {
        x1$ = x1, x2$ = x2;
        return OK;
    }

    // 编码 (Decimal to Binary)
    Status Encode()
    {
        // 针对非法十进制坐标返回错误代码
        if (x1$ > x1max || x1$ < x1min || x2$ > x2max || x2$ < x2min)
            return ERROR;

        // 由 十进制坐标 获得 十进制数字串 j
        int j1 = (x1$ - x1min) * accuracy;
        int j2 = (x2$ - x2min) * accuracy;
        stack<int> tt1, tt2;

        Dec_to_Bin(tt1, j1);
        Dec_to_Bin(tt2, j2);

        int size1 = tt1.size(), size2 = tt2.size();
        x_bincode$.clear();

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
    }

    // 解码并更新十进制坐标值 (Binary to Decimal)
    Status Decode()
    {
        int j1 = 0, j2 = 0;
        for (int i = 0; i < bits_x1; i++)
        {
            j1 += x_bincode$[i] * pow(2.0, bits_x1 - i - 1);
        }

        for (int i = bits_x1; i < bits_snum; i++)
        {
            j2 += x_bincode$[i] * pow(2.0, bits_snum - i - 1);
        }
        x1$ = x1min + j1 * ((x1max - x1min) * 1.0 / (pow(2.0, 1.0 * bits_x1) - 1.0));
        x2$ = x2min + j2 * ((x2max - x2min) * 1.0 / (pow(2.0, 1.0 * bits_x2) - 1.0));
    }

    // 刷新该个体的适应度（坐标值改变的情况下）
    Status Refresh_Fitness()
    {
        fitness$ = 21.5 + x1$ * sin(4.0 * PI * x1$) + x2$ * sin(20.0 * PI * x2$);
        return OK;
    }
};

// 存储个体的一些重要信息
typedef struct Info
{
    int id;             // 该个体在群体集的位置下标
    int maxc;           // 该个体的最大流程时间
    double fitness;     // 个体的适应度
    double cumula_prob; // 该个体的累计概率
} Info;

// 初始化种群
Status initialize()
{
    std::default_random_engine e1;
    e1.seed((unsigned int)time(NULL) * 10013);
    //std::uniform_int_distribution<unsigned> u1(1, jobs_num); //随机数分布对象


    return OK;
}

// 轮盘赌选择 + 复制
Status select()   // 个体适应度、种群
{
    
    return OK;
}

// 1 - 断点交叉算子
Status cross_over()
{
    std::default_random_engine e;
    e.seed((unsigned int)time(NULL) * 10013);
    std::uniform_real_distribution<double> u1(0.0, 1.0);
    std::uniform_int_distribution<unsigned> u2(0, population_size - 1);
    //std::uniform_int_distribution<unsigned> u3(1, jobs_num - 1);

   
    return OK;
}

// 变异算子
Status mutation()
{
    
    return OK;
}

int main()
{

    return 0;
}
