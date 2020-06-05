#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Array
{
protected:
    T *numarr$;
    int len$;

public:
    //
    Array(int n) : numarr$(NULL), len$(n)
    {
        numarr$ = new T[len$ * 2];
        memset(numarr$, 0, sizeof(numarr$));
    }
    ~Array() { delete[] numarr$; }
    //
    int size() const { return len$; }
    void put(int l)
    {
        sort(numarr$, numarr$ + len$, greater<T>());//����ע�⣬��Ҫ�ټ�һ�����ţ�����
        if (l < len$)
        {
            for (int i = 0; i < l; i++)
            {
                if(i == 0)
                {
                    cout << numarr$[i];
                }
                else
                {
                    cout << ' ' << numarr$[i];
                    
                }
                
                
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < len$; i++)
            {
                if(i == 0)
                {
                    cout << numarr$[i];
                }
                else
                {
                    cout << ' ' << numarr$[i];
                    
                }
            }
            cout << endl;
            
        }
        
    }
    T& operator[](int i) { return (*this).numarr$[i]; }//���ص��Ǳ�������TҪ�������ã���
};



int main()
{
    int cases, len;
    cin >> cases;
    for (int ca = 1; ca <= cases; ca++)
    {
        cin >> len;
        if (ca % 3 == 0)
        {
            Array<char> chr_arr(len);
            for (int i = 0; i < chr_arr.size(); i++)
                cin >> chr_arr[i];
            chr_arr.put(10);
        }
        if (ca % 3 == 1)
        {
            Array<int> int_arr(len);
            for (int i = 0; i < int_arr.size(); i++)
                cin >> int_arr[i];
            int_arr.put(10);
        }
        if (ca % 3 == 2)
        {
            Array<double> dbl_arr(len);
            for (int i = 0; i < dbl_arr.size(); i++)
                cin >> dbl_arr[i];
            dbl_arr.put(10);
        }
    }
}

/* 
Problem B: �����ࣨII��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 6091  Solved: 2913
[Submit][Status]
Description
��װһ��ģ�������࣬���ڴ洢����ʹ������ع��ܣ�֧�����²�����
1. Array::Array(int l)���췽��������һ������Ϊl�������
2. Array::size()����������Array������Ԫ�ظ�����
3. Array::put(int n)���������Ӵ�С��˳�����ǰn��Ԫ�أ������鳤��С��n��Ӵ�С���ȫ��Ԫ�ء�
4. �±�������������±���ָ��Ԫ�ء�
-----------------------------------------------------------------------------
�����һ��ģ��������Array��ʹ��main()�����ܹ���ȷ���С�
�������ø�ʽ��append.cc��
append.cc���Ѹ���main()������
Input
����ĵ�һ������n����ʾ��n��������ݡ�
�����ÿ����һ������k��ͷ����ʾ������k��ͬ���͵�����Ԫ�ء�
����Ԫ���������������ͣ����������������ַ������Ұ��̶��Ĵ��������֡�
Output
����������飬��ֵ�Ӵ�С���ǰ10��Ԫ�أ������벻��10����ȫ�������ÿ�����ݶ�Ӧһ���������ʽ��sample��
Sample Input
3
10 1 2 3 4 5 6 7 8 9 0
5 1.1 2.2 3.3 4.4 5.5
20 ABCDEGHIJMNPRSTUVWXY
Sample Output
9 8 7 6 5 4 3 2 1 0
5.5 4.4 3.3 2.2 1.1
Y X W V U T S R P N
HINT
Append Code
append.cc, */