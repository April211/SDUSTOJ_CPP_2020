#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    map<string, int, less<string> > sell;
    map<string, int, less<string> >::iterator p1;

    while(cin >> cnt)
    {
        for(int i = 0; i< cnt; i++)
        {
            string name;
            int price = 0;
            cin >> name >> price;
            sell[name] += price;
            //sell.insert(make_pair(name, price));
        }

        for(p1 = sell.begin(); p1 != sell.end(); p1++)
        {
            cout << p1->first << ':' << p1->second << endl;
        }

        sell.clear();

    }

    

    return 0;
}

/* 
Problem G: STL����ˮ����
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 7581  Solved: 3498
[Submit][Status]
Description
С����Ӫ��һ�������ˮ����.��������Ҫһ��ˮ�������������ϸ��,�����Ϳ��Ժ�������������ˮ�������������.

Input
���������������.ÿ��������ݵĵ�һ����һ������M(0<M<=100),��ʾ��M�γɹ��Ľ���.�����M������,ÿ�б�ʾһ�ν���,��ˮ������(���Ȳ�����80)�ͽ��׵�ˮ����Ŀ(������,������100)���.

Output
����ÿһ���������,�������һ���Ű��ʽ��ȷ(������������)��ˮ�����������ϸ��.�����ϸ���������ˮ�������ƺ���������������Ϣ.����ˮ���������򡣸�ʽ��������

 

Sample Input
3
apple 3
sugarcane 1
pineapple 3
Sample Output
apple:3
pineapple:3
sugarcane:1
HINT
 ��STL��map����ʵ��

Append Code */