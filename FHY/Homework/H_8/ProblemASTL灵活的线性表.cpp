#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    string order, build;
    int startlen;
    int allele;
    cin >> build >> startlen >> allele;
    vector <int> huainian(startlen, allele);

    while(cin >> order)
    {
        if(order == "Modify")
        {
            int add, ele;
            cin >> add; cin >> ele;
            add--;
            huainian[add] = ele;
        }

        if(order == "Insert")
        {
            int add0, add1, add2;
            cin >> add0 >> add1 >> add2;
            huainian.insert(huainian.begin()+add0-1, huainian.begin()+add1-1, huainian.begin()+add2);
        }

        if(order == "Erase")
        {
            int add0, add1;
            cin >> add0; cin >> add1;
            huainian.erase(huainian.begin()+add0-1, huainian.begin()+add1);
        }

        if(order == "Print")
        {
            int add0, add1; 
            cin >> add0; cin >> add1;
            for(int i = add0; i<= add1; i++)
            {
                if(i == add0)
                {
                    cout << '[' << i << "]:" << huainian[i-1];
                }
                else
                {
                    cout << " [" << i << "]:" << huainian[i-1];
                }
            }
            cout << endl;
        }

    }
    


    return 0;
}

/* 
Problem A: STL�����������Ա�
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 8403  Solved: 3937
[Submit][Status]
Description
�����������������֪���������Խṹ���������ǲ���������ͬʱʵ��ֱ�Ӳ��롢ɾ���ͷ��ʲ����������������ֲ���������ͨ��һ������������ʵ�����ǵĹ�����
����1��Build a b ������һ����СΪa�����Ա���ֵȫ����Ϊb��ÿ������������һ�Σ�����ʼ�У�
����2��Modify a b �������Ա�ĵ�a��Ԫ�ص�ֵ��Ϊb��
����3��Insert a b c �������Ա�ĵ�a��λ�ò����b����c��λ�õ�����Ԫ�أ�
����4��Erase a b��ɾ�����Ա��a����b��λ�õ�����Ԫ�أ�
����5��Print a b ��������Ա�ĵ�a����b��Ԫ�أ�
������ִ�в���5��ʱ��Ҫ����������ʽ�硰[1]:3 [2]:4 [3]:5����[]��Ϊ���Ա��λ�ã���:������ΪԪ�ص�ֵ���������ţ�ÿ�����ռһ�У�
Input
�����ж��У���Ӧ5����������EOF����

Output
��Sample

Sample Input
Build 10 1
Modify 2 2
Insert 3 1 2
Modify 6 4
Erase 3 5
Print 1 8
Sample Output
[1]:1 [2]:2 [3]:4 [4]:1 [5]:1 [6]:1 [7]:1 [8]:1
HINT
?ʹ��vector���Ժ����׽��



Append Code */