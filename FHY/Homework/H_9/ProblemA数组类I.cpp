#include <bits/stdc++.h>
using namespace std;

class Array
{
protected:
    int *numarr$;
    int len$;
public:
    //
    Array():numarr$(NULL), len$(0){}
    ~Array(){ delete []numarr$;}
    //
    int size()const { return len$;}
    void get(int);
    int operator[] (int i){return (*this).numarr$[i];}
};

void Array::get(int n)
{
    len$ = n;
    numarr$ = new int [len$*2];
    for(int i = 0; i< len$; i++)
    {
        int tt;
        cin >> tt;
        numarr$[i] = tt;
    }

}

int main()
{
    int cases;
    Array arr;
    cin >> cases;
    for(int ca = 1; ca <= cases; ca++)
    {
        int len;
        cin >> len;
        arr.get(len);
        for(int i = 0; i < arr.size(); i++)
            if(i + 1 == arr.size())
                cout << arr[i];
            else
                cout << arr[i] << " ";
        cout << endl;
    }
}


/* Problem A: �����ࣨI��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4680  Solved: 3529
[Submit][Status]
Description
��װһ�����������࣬���ڴ洢�����ʹ������ع��ܣ�֧�����²�����
1. Array::Array()�޲ι��췽��������һ�����������
2. Array::size()����������Array������Ԫ�ظ�����
3. Array::get(int n)����������ʽ�������ȡnԪ�ء�
4. �±�������������±���ָ��Ԫ�ء�
-----------------------------------------------------------------------------
�����һ��������Array��ʹ��main()�����ܹ���ȷ���С�
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()����
Input
����ĵ�һ������n����ʾ��n��������ݡ�
�����ÿ����һ������k��ͷ����ʾ������k��������
Output
����������飬���������ÿ�����ݶ�Ӧһ���������ʽ��sample��
Sample Input
4
2 10 20
1 0
0
3 1 2 3
Sample Output
10 20
0

1 2 3
HINT
Append Code
append.cc, */