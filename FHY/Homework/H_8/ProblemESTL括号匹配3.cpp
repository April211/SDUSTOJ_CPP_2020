#include <iostream>
using namespace std;
#include <algorithm>
#include <iomanip>
#include <stack>
int main()
{
    string s1;
    while (cin >> s1)
    {
        stack<int> s;
        int i;
        for (i = 0; i < s1.length(); i++)
        {
            if (s1[i] == '(') //
                s.push(1);
            else if (!s.empty())
                s.pop();
            else
                break;
        }

        if (i == s1.length() && s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}