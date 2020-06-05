#include <bits/stdc++.h>
using namespace std;

class Integer
{
private:
    int num$;
    int radix$;

public:
    Integer(int tt) : num$(tt), radix$(10) {} //������ʮ����
    Integer(const char *num, int radix) : radix$(radix), num$(0)
    {
        if (num[0] == '-' || num[0] == '+')
        {
            if (radix$ <= 10)
            {
                int len = strlen(num);
                for (int i = 1; i < len; i++)
                {
                    num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                }
                if(num[0] == '-')
                {
                    num$ = num$* (-1);
                }
                else
                {
                    /* code */
                }
                
            }
            else
            {
                int len = strlen(num);
                for (int i = 1; i < len; i++)
                {
                    if (num[i] >= '0' && num[i] <= '9')
                    {
                        num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                    }
                    else
                    {
                        num$ += ((int)(tolower(num[i]) - 'a') + 10) * pow(radix$, len - i - 1);
                    }
                }
                if(num[0] == '-')
                {
                    num$ = num$* (-1);
                }
                else
                {
                    /* code */
                }
            }
        }
        else
        {
            if (radix$ <= 10)
            {
                int len = strlen(num);
                for (int i = 0; i < len; i++)
                {
                    num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                }
            }
            else
            {
                int len = strlen(num);
                for (int i = 0; i < len; i++)
                {
                    if (num[i] >= '0' && num[i] <= '9')
                    {
                        num$ += ((int)(num[i] - '0')) * pow(radix$, len - i - 1);
                    }
                    else
                    {
                        num$ += ((int)(tolower(num[i]) - 'a') + 10) * pow(radix$, len - i - 1);
                    }
                }
            }
        }
    }
    int getValue() const { return num$; }
};

int main()
{
    char str[100];
    int numOfData, numOfStr;
    int data, i, radix;

    cin >> numOfData;
    for (i = 0; i < numOfData; i++)
    {
        cin >> data;
        Integer anInteger(data);
        cout << anInteger.getValue() << endl;
    }

    cin >> numOfStr;
    for (i = 0; i < numOfStr; i++)
    {
        cin >> str >> radix;
        Integer anInteger(str, radix);
        cout << anInteger.getValue() << endl;
    }
    return 0;
}


/* Problem A: �����ķ�װ
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 5050  Solved: 1968
[Submit][Status]
Description
���ڣ����дһ��Integer�࣬��������װ������Ŀǰ��ֻ��Ҫ����ʵ��������Ĺ��ܣ�

1. ����2�����캯����

��1��Integer::Integer(int)�����ݲ�������һ����������

��2��Integer::Integer(char*, int)�����ݸ������ַ����ͽ���������һ����������

2. ����һ��int Integer::getValue()���������ڷ���Integer��������װ�������ľ�����ֵ��

Input
�����Ϊ���С�

��һ����һ��������M����ʾ������M��ΪM��������ÿ��һ��������

��M+2����һ��������N����ʾ�����N�С�ÿ��������һ���ո������2������ɣ�ǰ�벿����һ���ַ�������벿���Ǹ��ַ�����ʹ�õĽ��ơ�

ע�⣺

1. ���е����룬����int���͵ı�ʾ��Χ�ڣ������е������Ϊ�Ϸ����롣

2. ����0~9��a~z�������Ա�ʾ36���Ƶ���ֵ��

Output
���ΪM+N�У�ÿ��Ϊһ��ʮ���������������˳��Ӧ������˳����ͬ��

Sample Input
 2
999
-1999
4
0111 2
1a 16
z 36
a 16
Sample Output
999
-1999
7
26
35
10
HINT
Append Code
append.cc, */