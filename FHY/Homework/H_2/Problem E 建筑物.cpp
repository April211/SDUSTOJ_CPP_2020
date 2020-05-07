#include <iostream>
#include <cstdio>
using namespace std;

typedef class
{
private:
    int cnt;
public:
    void setCnt(int c)
    {
        cnt = c;
    }
    int getCnt()
    {
        return cnt;
    }

} Building;

int main()
{
    Building b;
    int i;
    cin>>i;
    b.setCnt(i);
    cout<<"The building has "<<b.getCnt()<<" floors."<<endl;
    return 0;
}

// Problem E: 建筑物
// Time Limit: 1 Sec  Memory Limit: 128 MB
// Submit: 1343  Solved: 1039
// [Submit][Status]
// Description
// 定义一个类Building，其中只有一个int属性cnt，表示建筑物的层数。有两个方法：
// 1.void setCnt(int c)：设置楼层数为c。
// 2.int getCnt()：获得楼层数。

// Input
// 一个非负整数。

// Output
// 见样例。

// Sample Input
// 3
// Sample Output
// The building has 3 floors.
// HINT
// Append Code
// append.cc,

