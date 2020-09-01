#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> t(30);
    cout << t.capacity() << endl;
    cout << t.size() << endl;
    t.push_back(5);
    cout << t.capacity() << endl;
    cout << t.size() << endl;
    return 0;
}