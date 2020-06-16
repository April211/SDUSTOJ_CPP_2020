#include <bits/stdc++.h>
#define MAX_SIZE 100000
using namespace std;

bool isRenum(int num)
{
    string ss(MAX_SIZE, '\0'), rr(MAX_SIZE, '\0');
    int len = 0, tt = num;
    while(tt)
    {
        tt /= 10;
        len++;
    }
    tt = num;
    for(int i = 0; i< len; i++)
    {
        ss[i] = tt % 10;
        tt /= 10;
    }
    for(int i = 0; i< len; i++)
    {
        rr[i] = ss[len - i - 1];
    }
    if(ss == rr) return true;
    else         return false;
}

int main()
{
    int num;
    while(cin>> num)
    {
        if(isRenum(num)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    



    return 0;
}