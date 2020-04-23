#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b, ans;
    char p;
    scanf("%d %c %d =", &a, &p, &b);
    (p == '+')?(ans = a + b):(ans = a - b);
    printf("%d %c %d = %d", a, p, b, ans);


    return 0;
}
