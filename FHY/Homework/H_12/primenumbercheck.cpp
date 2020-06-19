#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

bool isprime(int x)
{
    if (x <= 1)
    {
        return false;
    }
    else
    {
        int flag = 0;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                flag++;
            }
        }
        if(flag == 0) return true;
        else          return false;
    }
    
}

bool sudu(int x){
    if(x <= 1){
        return false;
    }
    for(int i =2;i<=sqrt(x);i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int s;
    cin >> s;
    if(isprime(s)) cout << "yes";
    else cout << "no";
    return 0;
}
