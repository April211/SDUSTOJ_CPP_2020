#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>
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
#define DEFAULT_SET -1
#define FALSE 0
#define TRUE 1
#define mach_num 4          // 机器数目（工序数目）为 4
#define jobs_num 5          // 工件数目为 5
#define cross_possib 0.6    // 交叉概率 == 0.6
#define mutation_possib 0.1 // 变异概率 == 0.1
#define population_size 20  // 种群规模 == 20
#define num_of_iter 50      // 迭代次数 == 50

class Job
{
public:
    int id$;                  // 工件编号
    vector<int> expt_proc_t$; // 该工件在各工序中的预期加工时长
    vector<int> real_proc_t$; // 该工件在各工序中的实际加工时长
public:
    // 构造函数
    Job() : id$(DEFAULT_SET)
    {
        for (int i = 0; i < mach_num + 1; i++)
        {
            expt_proc_t$.push_back(DEFAULT_SET);
            real_proc_t$.push_back(DEFAULT_SET);
        }
    }

    Job(int id, int *proc_t) : id$(id)
    {
        for (int i = 0; i < mach_num + 1; i++)
        {
            real_proc_t$.push_back(DEFAULT_SET);
            expt_proc_t$.push_back(proc_t[i]);
        }
    }

    // 析构函数
    ~Job() {}

    // 重载运算符
    bool operator==(const Job &j1)
    {
        if (this->id$ == j1.id$)
            return true; // 编号一致即相等
        else
            return false;
    }

    bool operator!=(const Job &j1)
    {
        if (this->id$ != j1.id$)
            return true; // 编号不一致即不相等
        else
            return false;
    }

    Job operator=(Job &j)
    {
        this->id$ = j.id$;
        this->expt_proc_t$ = j.expt_proc_t$;
        this->real_proc_t$ = j.real_proc_t$;
        return (*this);
    }

    int GetId() const { return id$; }
};

class Machine
{
protected:
    int id$;           // 机器编号（工序编号）
    bool is_occupied$; // 机器是否已被占用
public:
    // 构造函数
    Machine() : id$(DEFAULT_SET), is_occupied$(FALSE) {}
    Machine(int id, bool is_occupied) : id$(id), is_occupied$(is_occupied) {}

    // 析构函数
    ~Machine() {}
};

// 初始化种群
/* int initialize()
{
} */

bool JobVecIsEqual(vector<Job> &v1, vector<Job> &v2)
{
    bool flag = true;
    for (int i = 0; i < jobs_num; i++)
    {
        if (v1[i] != v2[i])
            flag = false;
    }
    return flag;
}

int Max(const int &a, const int &b)
{
    return (a>b)?a:b;
}

int main()
{
    // 生成随机数种子
    int m = 1, n = jobs_num;

    std::default_random_engine e;
    e.seed((unsigned int)time(NULL) * 10013);
    std::uniform_int_distribution<unsigned> u(m, n); //随机数分布对象

    // 定义 5个工件在 4个工序的预期工作时间（第一个有效元素为下标为 1的元素，0号特殊处理）
    int ex_proc_t1[] = {0, 31, 41, 25, 30}, ex_proc_t2[] = {0, 19, 55, 3, 34}, ex_proc_t3[] = {0, 23, 42, 27, 6},
        ex_proc_t4[] = {0, 13, 22, 14, 13}, ex_proc_t5[] = {0, 33, 5, 57, 19};

    // 构建 4个机器，初始均为未占用
    Machine m1(1, FALSE), m2(2, FALSE), m3(3, FALSE), m4(4, FALSE);

    // 构建 5个工件
    Job j1(1, ex_proc_t1), j2(2, ex_proc_t2), j3(3, ex_proc_t3), j4(4, ex_proc_t4), j5(5, ex_proc_t5);

    // 按照工件的序号构建工件的索引，便于后期查找使用
    vector<Job> job_finder;

    // 这里为了使工件编号与数组下标一致，第一个元素特殊处理
    job_finder.push_back(j1), job_finder.push_back(j1), job_finder.push_back(j2);
    job_finder.push_back(j3), job_finder.push_back(j4), job_finder.push_back(j5);

    // 染色体（单个加工序列）
    vector<Job> single;

    // 种群（工件加工顺序集），需要初始化
    vector<vector<Job>> orders;

    // 初始化种群
    for (int i = 0; i < population_size; i++)
    {
        while (single.size() < jobs_num) // 当满足个数条件时执行
        {
            int pivot_id = u(e);                                               // 工件编号随机基准值（1~5）
            Job tt = job_finder[pivot_id];                                     // 调用工件索引进行复制
            vector<Job>::iterator pt = find(single.begin(), single.end(), tt); // 对该基因进行查找
            //printf("aha!-->%d\n", pivot_id);
            if (pt == single.end()) // 该染色体还没有该型基因，则可以加入
            {
                single.push_back(tt);
            }
            else
                continue;
        }
        vector<vector<Job>>::iterator it;
        bool already_have = false;
        for (it = orders.begin(); it!=orders.end(); it++)
        {
            if(JobVecIsEqual((*it), single))    // 如果找到一个相同的，放弃该记录
                already_have = true;
        }
        if (!already_have)
        {
            orders.push_back(single);
        }
        else
        {
            i--;
        }
        single.clear(); // 清空，准备下一次
    }

/*     for (int i = 0; i < population_size; i++)
    {
        for (int j = 0; j < jobs_num; j++)
        {
            printf("%d ", orders[i][j].GetId());
        }
        printf("\n");
    }// 检查初始种群
 */

    // 记录个体适应度
    vector<int> afitness;

    for(int i = 0; i< population_size; i++)
    {        
        // 工件顺序下标是从 0开始的
        // 序列中第一个工件在第一台机器上加工完成的时间就是它在第一台机器上的预计时间
        orders[i][0].real_proc_t$[1] = orders[i][0].expt_proc_t$[1];

        //第一个工件在第 K个机器上加工完成的时间
        for(int j = 2; j< mach_num+1; j++)
        {
            orders[i][0].real_proc_t$[j] = orders[i][0].real_proc_t$[j-1] + orders[i][0].expt_proc_t$[j];
        }

        // 第 m个工件完成第一道工序的时间等于它前一个工件在这个工序完成时的时刻加上这个工件在第一道工序的预期时间
        for(int m = 2; m< mach_num+1; m++)
        {
            orders[i][m-1].real_proc_t$[1] = orders[i][m-2].real_proc_t$[1] + orders[i][m-1].expt_proc_t$[1];
        }

        // 第 k个工件在第 j 道工序完成的时刻等于 max()
        for(int j = 2; j< mach_num+1; j++)
        {
            for(int k = 2; k< jobs_num; k++)
            {
                orders[i][k-1].real_proc_t$[j] = Max(orders[i][k-2].real_proc_t$[j], orders[i][k-1].real_proc_t$[j-1]) + orders[i][k-1].expt_proc_t$[j];
            }
        }
    }

    for(int i = 0; i< population_size; i++)
    {
        int cmax = 0;       // 该个体对应的最大流程时间
        int fitness;
        for(int j = 0; j <) 
        {
            
        }
        
    }






    return 0;
}
