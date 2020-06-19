#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
 
int a[100010];
int b[100010];

bool mjudge(int size)
{
    for(int j = 0; j< size; j++)
    {
        if(a[j] != b[j]) return false;
    }
    return true;
}
 
int main()
{
    int tt;
    int size = 0;
    while(cin >> tt)
    {
        a[size++] = tt;
    }
    b[0] = a[0];
    b[size-1] = a[size-1];
    while(1)
    {
        for(int j = 1; j < size-1; j++)
        {
            int ttt = b[j-1] + a[j+1];
            if(ttt % 2 ==0) 
            {
                b[j] = ttt / 2;
            }
            else
            {
                if(ttt > 0) 
                {
                    b[j] = ttt/2+1;
                }
                else 
                {
                    b[j] = ttt/2-1;
                }
            }
        }
        if(mjudge(size)) break;
        else
        {
            for(int j = 0; j < size; j++) 
                a[j] = b[j];
        }
        
    }
    
    for(int i = 0; i<size; i++)
    {
        if(i == 0) printf("%d", b[0]);
        else printf("%c%d", ' ', b[i]);
    }
        
    return 0;
}

/* 
Problem G: �����ƽ��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 1941  Solved: 342
[Submit][Status]
Description
����һ����int���͵�������ɵ����飬�����ƽ����ָ���������г���һ�������һ��Ԫ���⣬��������Ԫ�ص�ֵȡ���ڵ�����ֵ��ƽ��ֵ��������ԣ����Ƕ��ڸ���������a[n]�����Ƚ�a[1]ȡֵΪa[0]��a[2]��ƽ��ֵ��Ȼ��a[2]ȡֵΪa[1]�����º��ֵ����a[3]��ƽ��ֵ��һֱ���㵽a[n-2]��Ϊa[n-3]�����º��ֵ����a[n-1]��ƽ��ֵ���ظ��������̣�ֱ�����������Ԫ�ص�ֵ������Ϊֹ��

ע�⣬����������int���͵ģ�������ȡƽ��ֵʱ����Ҫ�����������롣
���磬ԭʼ����Ϊ��2 3 7 12����ô��һ��ƽ���Ľ���ǣ�2 5 9 12���ڶ���ƽ����Ľ��Ϊ2 6 9 12��֮���ƽ�����㶼����ı���������ֵ���������յĽ����2 6 9 12��

Input
���ɸ�int���ͷ�Χ�ڵ�������

Output
����ƽ��������ս�������ʱ������֮����һ���ո������

Sample Input
2 3 7 12
Sample Output
2 6 9 12
HINT
Append Code */