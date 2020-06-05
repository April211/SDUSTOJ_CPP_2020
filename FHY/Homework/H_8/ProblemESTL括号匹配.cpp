#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

int main()
{
    char ch1 = 0;
    char ch2 = 0;
    int cntl = 0, cntr = 0;
    string tt;
    stack<char> ku;
    while (cin >> ch2)
    {
        cntl = 0, cntr = 0;
        if (ch2 == '\n')
        {
            cout << "NO" << endl;
        }
        else
        {   
            
            if(ch2 == '('){ku.push(ch2); cntl++;}
            if(ch2 == ')'){ku.push(ch2); cntr++;}
            while ((ch1 = getchar()) != '\n')
            {
                ku.push(ch1);
                if(ch1 == '('){cntl++;}
                else if(ch1 == ')'){cntr++;}
            }
            if(cntl != cntr)
            {
                cout << "NO" << endl;
            }
            else
            {
                if(ku.top() == '('){cout << "NO" << endl;}
                else if(ch2 == ')'){cout << "NO" << endl;}
                else
                {
                    cout << "YES" << endl;
                }
            }
        }
        
    }

    return 0;
}


/* Problem E: STL��������ƥ��
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5667  Solved: 3648
[Submit][Status]
Description
����һ�����ţ������Ƿ�ƥ�䣬���� ()��()()��(()) ���������ž�ƥ�䣬
      )(��)()) �����������žͲ�ƥ��
Input
ÿһ�д���һ�����������ÿ���������ֻ����'('��')'���������Ȳ�����100���ַ�
Output
������е����Ŷ�ƥ�䣬��ô���YES���������NO
Sample Input
()
)(
Sample Output
YES
NO
HINT
ʹ��STL��stack����ʵ�֡�


Append Code */