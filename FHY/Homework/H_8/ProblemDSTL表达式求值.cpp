#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        char op = 0;
        double tt = 0;
        stack<double> mem;

        cin >> tt;
        mem.push(tt);

        for(int i = 0; i< n-1; i++)
        {
            cin >> op >> tt;
            if(op == '+')
            {
                mem.push(tt);
            }
            else if(op == '-')
            {
                mem.push(-tt);
            }
            else if(op == '*')
            {
                tt = tt* mem.top();
                mem.pop();
                mem.push(tt);
            }
            else// /
            {
                tt = mem.top() / tt;
                mem.pop();
                mem.push(tt);
            }
            

        }
        cin >> op;// =
        double ans = 0;
        int st = mem.size();//����Ԫ�ص�ɾ����size�ڲ��ϱ仯������ȡ����ֵ
        for(int i = 0; i< st; i++)
        {
            ans = ans + mem.top();
            mem.pop();
        }

        cout << fixed << setprecision(2) << ans << endl;



    }



    return 0;
}


/* Problem D: STL�������ʽ��ֵ
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4945  Solved: 3100
[Submit][Status]
Description
����һ�����ʽ�������ֵ�����ʽ��ֻ���� +��-��*���������㣬���Ǽ�����ʽ����ȷ�ģ�
      �Ҳ����ڳ���Ϊ��������
Input
��һ������һ�������� n��1<=n<=30�� ����ʾ�б��ʽ n ������ÿ������С��100�������ʽ��ֻ����ֵ�����Ǵ����������
      �������������+��-��*��=��������������� = ֻ�ڱ��ʽ��󣬱�ʾһ�����ʽ������������������ʽ�����ڿո�
Output
���ʽ��ֵ�����ʽ��ֵ���ᳬ�� double �ķ�Χ��������λС����
Sample Input
5
1*2*3*4*5=
5
5-1-2+3+4=
Sample Output
120.00
9.00
HINT
ʹ��STL��stack����ʵ�֡�


Append Code */