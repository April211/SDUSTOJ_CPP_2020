#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    int cntl = 0, cntr = 0;
    while (cin >> str)
    {
        stack<char> ku;
        cntl = 0, cntr = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (ku.empty())//ÅÐ¶Ï¶ÑÕ»ÊÇ·ñÎª¿Õ
            {
                ku.push(str[i]);
            }
            else if (str[i] == ')')
            {
                cntl++;
                if (ku.top() == '(') {cntr++; ku.pop();}//Åä¶ÔÉ¾³ý
            }
            else//noempty || (
            {
                ku.push(str[i]);
            }
        }
        if (ku.empty())
        {
             cout << "YES" << endl;
        }
        else
        {
             cout << "NO" << endl;
        }
    }
    return 0;
}
