#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

typedef struct Node
{
    int a;
    int b;
    Node(int a, int b):a(a), b(b){}
    // 建升序优先队列时，是小根堆，调用运算符：>，对应 greater<Node>。如果这里不写 friend，只能用一个参数
    friend bool operator> (const Node &tt1, const Node &tt2)          
    {                                                    // 上面是说：tt1 的优先级高于 tt2
        return (tt1.a > tt2.a);                          // 为什么呢？是因为 tt1的 a值比 tt2的小
    }
}Node;

// 升序队列，小根堆，注意不带圆括号，且与 sort有一定区别（堆的树形结构，下面的比上面的大）
priority_queue< Node, vector<Node>, greater<Node> > q;             

int main()
{
    Node n1(1, 2), n2(5, 4), n3(3, 6);
    q.push(n1);
    q.push(n2);
    q.push(n3);

    for(int i = 0; i< 3; i++)
    {
        Node tt = q.top();
        q.pop();
        printf("%2d", tt.a);
    }



    return 0;
}
