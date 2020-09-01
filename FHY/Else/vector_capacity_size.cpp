#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


int main()
{
    vector<int> t(30, 1);    //开辟30个元素的空间，并全部赋值为 “1”
    cout << "The value of the 30th element: " << t[29] << endl;
    cout << t.capacity() << endl;
    cout << t.size() << endl;
    t.push_back(5);          //在末尾添加一个元素为 "5"
    cout << "The value of the 31st element: " << t[30] << endl;
    cout << t.capacity() << endl;
    cout << t.size() << endl;
    t.clear();
    cout << t.capacity() << endl;
    cout << t.size() << endl;
    return 0;
}

/* size返回的是实际存入的数据的个数；capacity返回的是容量，即能够容纳数据的最大个数 */
/* The value of the 30th element: 1
30
30
The value of the 31st element: 5
60
31
60
0 */
