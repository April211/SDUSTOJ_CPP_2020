#include <bits/stdc++.h>
using namespace std;

class Difficult
{
protected:
    int x$;
public:
    Difficult(int x):x$(x){}
    ~Difficult(){}
    void show()const { cout << abs(x$);}
};



int main()
{
    int a;
    cin>>a;
    Difficult difficult(a);
    difficult.show();
    return 0;
}


/* 
Problem I: ���ѵ���
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1621  Solved: 1375
[Submit][Status]
Description
����һ����Difficult��ֻ��һ��int���͵����ݳ�Ա�������乹�캯�����Լ�����������ݳ�Ա�ľ���ֵ�ĳ�Ա������void show()�����ݳ�Ա�������ֵ����int���ͷ�Χ�ڡ�

Input
һ��int���ͷ�Χ�ڵ�������

Output
��������ݵľ���ֵ��

Sample Input
-100
Sample Output
100
HINT
Append Code
append.cc, */